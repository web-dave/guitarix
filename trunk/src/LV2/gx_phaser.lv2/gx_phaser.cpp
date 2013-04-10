/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */


////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gx_phaser.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "phaser_mono.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gx_phaser
{
private:
  // pointer to buffer
  float*                       output;
  float*                       input;
  // pointer to dsp class
  PluginLV2*                   phaser_st;
  // private functions
  inline void run_dsp_mono(uint32_t n_samples);
  inline void connect_mono(uint32_t port,void* data);
  inline void init_dsp_mono(uint32_t rate);
  inline void connect_all_mono_ports(uint32_t port, void* data);
  inline void activate_f();
  inline void deactivate_f();
  inline void clean_up();
  
public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  Gx_phaser();
  ~Gx_phaser();
};

// constructor
Gx_phaser::Gx_phaser() :
  output(NULL),
  input(NULL),
  phaser_st(phaser_mono::plugin()) {};

// destructor
Gx_phaser::~Gx_phaser()
{
  // just to be sure the plug have given free the allocated mem
  // check if the function is valid
  // it didn't hurd if the mem is already given free by clean_up()
  if ( phaser_st->activate_plugin !=0)
    phaser_st->activate_plugin(false, phaser_st);
  // delete DSP class
  phaser_st->delete_instance(phaser_st);
};

////////////////////////////// PRIVATE CLASS  FUNCTIONS ////////////////

void Gx_phaser::init_dsp_mono(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  phaser_st->set_samplerate(rate, phaser_st); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_phaser::connect_mono(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_phaser::activate_f()
{
  // allocate the internal DSP mem
  // check if the function is valid
  if (phaser_st->activate_plugin !=0)
    phaser_st->activate_plugin(true, phaser_st);
}

void Gx_phaser::deactivate_f()
{
  // free the allocated internal DSP mem
  // check if the function is valid
  if (phaser_st->activate_plugin !=0)
    phaser_st->activate_plugin(false, phaser_st);
}

void Gx_phaser::clean_up()
{
  // delete the internal DSP mem
  // check if the function is valid
  if (phaser_st->activate_plugin !=0)
    phaser_st->activate_plugin(false, phaser_st);
}

void Gx_phaser::run_dsp_mono(uint32_t n_samples)
{
  phaser_st->mono_audio(static_cast<int>(n_samples), input,
                        output, phaser_st);
}

void Gx_phaser::connect_all_mono_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_mono(port,data); 
  // connect the Ports used by the DSP class
  phaser_st->connect_ports(port,  data, phaser_st);
}

///////////////////// STATIC CLASS  FUNCTIONS  /////////////////////////

LV2_Handle
Gx_phaser::instantiate( const LV2_Descriptor*     descriptor,
                        double                    rate,
                        const char*               bundle_path,
                        const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_phaser *self = new Gx_phaser();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_mono((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_phaser::connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
  // connect all ports
  static_cast<Gx_phaser*>(instance)->connect_all_mono_ports(port, data);
}

void Gx_phaser::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_phaser*>(instance)->activate_f();
}

void Gx_phaser::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_phaser*>(instance)->run_dsp_mono(n_samples);
}

void Gx_phaser::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_phaser*>(instance)->deactivate_f();
}

void Gx_phaser::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_phaser* self = static_cast<Gx_phaser*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gx_phaser::descriptor =
{
  GXPLUGIN_URI "#_phaser",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  NULL
};

///////////////////////////// LV2 DESCRIPTOR ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &Gx_phaser::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
