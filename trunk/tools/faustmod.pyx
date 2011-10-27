#
# Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
# Copyright (C) 2011 Pete Shorthose
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
import numpy as np
cimport numpy as np
from cython.operator cimport dereference as deref, preincrement as inc

cdef extern from "time.h":
    cdef struct timespec:
        int tv_sec
        int tv_nsec
    ctypedef int clockid_t
    int CLOCK_MONOTONIC
    int clock_gettime(clockid_t clk_id, timespec *tp)

cdef extern from "alloca.h":
    void *alloca(size_t size)

cdef extern from "faustwrap.cpp":
    cppclass param:
        float* fZone
        float fMin
        float fMax

    cppclass string:
        char *c_str()

    cppclass fKeyType
    cppclass fKeyIter:
        fKeyIter operator++()
        bint operator!=(fKeyIter)
        bint operator==(fKeyIter)
        fKeyType operator*()

    cppclass fKeyType:
        string first
        param second
        fKeyIter begin()
        fKeyIter end()
        fKeyIter find(char *s)

    cppclass UI:
        pass

    cppclass mydsp:
        void buildUserInterface(UI* interface)
        int getNumInputs()
        int getNumOutputs()
        void init(int samplingRate)
        void compute(int len, float** inputs, float** outputs)

    cppclass CMDUI(UI):
        fKeyType fKeyParam

ctypedef np.float32_t f32_t
ctypedef float *floatp

cdef inline double ts_diff(timespec ts1, timespec ts2):
    cdef double df = ts1.tv_sec - ts2.tv_sec
    return df * 1e9 + (ts1.tv_nsec - ts2.tv_nsec)

cdef class dsp(object):
    cdef mydsp *Cdsp
    cdef CMDUI *interface
    cdef dict Cparameter
    cdef int defsize
    cdef double time_per_sample

    def __cinit__(self):
        self.Cdsp = new mydsp()
        self.interface = new CMDUI()
        self.Cdsp.buildUserInterface(self.interface)
        cdef fKeyIter i
        i = self.interface.fKeyParam.begin()
        p = {}
        while i != self.interface.fKeyParam.end():
            p[deref(i).first.c_str()] = (deref(i).second.fMin, deref(i).second.fMax)
            inc(i)
        self.Cparameter = p
        self.defsize = 128
        self.time_per_sample = 0

    def __dealloc__(self):
        del self.Cdsp
        del self.interface

    property nanosec_per_sample:
        def __get__(self):
            return self.time_per_sample

    property default_size:
        def __get__(self):
            return self.defsize
        def __set__(self, int n):
            self.defsize = n

    def keys(self):
        return self.Cparameter.keys()

    def get_range(self, key):
        return self.Cparameter[key]

    def __getitem__(self, char* pname):
        cdef fKeyIter p = self.interface.fKeyParam.find(pname)
        if p == self.interface.fKeyParam.end():
            raise KeyError("not found: %s" % pname)
        return deref(p).second.fZone[0]
    
    def __setitem__(self, char* pname, float pval):
        cdef fKeyIter p = self.interface.fKeyParam.find(pname)
        if p == self.interface.fKeyParam.end():
            raise KeyError("not found: %s" % pname)
        if pval < deref(p).second.fMin:
            pval = deref(p).second.fMin
        if pval > deref(p).second.fMax:
            pval = deref(p).second.fMax
        deref(p).second.fZone[0] = pval

    property num_inputs:
        def __get__(self):
            return self.Cdsp.getNumInputs()

    property num_outputs:
        def __get__(self):
            return self.Cdsp.getNumOutputs()

    def init(self, int samplingRate):
        self.Cdsp.init(samplingRate)

    def compute(self, np.ndarray inp = None):
        cdef int ni = self.Cdsp.getNumInputs()
        cdef int count
        if ni == 0 and inp is None:
            count = self.defsize
        else:
            if not isinstance(inp, np.ndarray):
                raise ValueError("need ndarray")
            if inp.dtype != np.float32:
                raise ValueError("need float32")
            count = inp.shape[inp.ndim-1]
        if ni == 1:
            if not (inp.ndim == 1 or (inp.ndim == 2 and inp.shape[1] >= 1)):
                raise ValueError("need vector or 2-dim array with 1 row")
        elif ni > 1:
            if not (inp.ndim == 2 and inp.shape[1] >= ni):
                raise ValueError("need 2-dim array with at least %d rows" % ni)
        cdef floatp *ina = <floatp*>alloca(ni*sizeof(floatp))
        cdef floatp basep = <floatp>inp.data
        cdef int i, n
        n = inp.strides[0]
        for i in range(ni):
            ina[i] = <floatp>(inp.data+i*n)
        cdef int no = self.Cdsp.getNumOutputs()
        cdef floatp *oa = <floatp*>alloca(no*sizeof(floatp))
        cdef np.ndarray o
        if no == 1:
            o = np.empty(count,dtype=np.float32)
        else:
            o = np.empty((no,count),dtype=np.float32)
        for i in range(no):
            oa[i] = <floatp>(o.data + i*n)
        cdef timespec t0, t1
        clock_gettime(CLOCK_MONOTONIC, &t0)
        self.Cdsp.compute(count, ina, oa)
        clock_gettime(CLOCK_MONOTONIC, &t1)
        self.time_per_sample = ts_diff(t1,t0)/count
        return o