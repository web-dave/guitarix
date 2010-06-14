namespace distortion {
// generated from file '../src/faust/distortion.dsp'

int 	iVec0[2];
double 	fConst0;
double 	fConst1;
double 	fConst2;
double 	fConst3;
double 	fConst4;
double 	fConst5;
double 	fConst6;
FAUSTFLOAT 	fslider0;
double 	fRec1[2];
FAUSTFLOAT 	fslider1;
double 	fRec2[2];
FAUSTFLOAT 	fentry0;
double 	fConst7;
FAUSTFLOAT 	fentry1;
double 	fRec7[2];
FAUSTFLOAT 	fslider2;
int 	IOTA;
double 	fVec1[4096];
FAUSTFLOAT 	fslider3;
double 	fRec8[2];
FAUSTFLOAT 	fcheckbox0;
FAUSTFLOAT 	fentry2;
double 	fConst8;
double 	fVec2[2];
double 	fRec10[2];
FAUSTFLOAT 	fentry3;
double 	fConst9;
double 	fConst10;
double 	fVec3[2];
double 	fRec9[2];
FAUSTFLOAT 	fcheckbox1;
FAUSTFLOAT 	fslider4;
FAUSTFLOAT 	fslider5;
double 	fVec4[2];
double 	fRec14[2];
double 	fVec5[2];
double 	fRec13[2];
double 	fRec12[3];
double 	fRec11[3];
FAUSTFLOAT 	fcheckbox2;
double 	fVec6[3];
double 	fConst11;
double 	fConst12;
double 	fConst13;
double 	fConst14;
double 	fConst15;
double 	fRec6[3];
double 	fRec5[3];
double 	fRec4[3];
FAUSTFLOAT 	fslider6;
FAUSTFLOAT 	fslider7;
FAUSTFLOAT 	fslider8;
double 	fVec7[2];
double 	fRec3[2];
FAUSTFLOAT 	fslider9;
double 	fRec15[2];
FAUSTFLOAT 	fslider10;
double 	fVec8[2];
double 	fRec16[2];
FAUSTFLOAT 	fslider11;
double 	fRec17[2];
double 	fRec19[3];
FAUSTFLOAT 	fslider12;
double 	fVec9[2];
double 	fRec18[2];
double 	fVec10[3];
double 	fRec0[3];
double 	fVec11[2];
double 	fRec23[2];
double 	fVec12[2];
double 	fRec22[2];
double 	fRec21[3];
double 	fRec20[3];
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	for (int i=0; i<2; i++) iVec0[i] = 0;
	fConst0 = (6.283185307179586 * (max(0, ((0.5 * fSamplingFreq) - 1e+02)) / fSamplingFreq));
	fConst1 = cos(fConst0);
	fConst2 = (1.316227766016838 * fConst1);
	fConst3 = (0 - (2 * (0 - (0.683772233983162 + fConst2))));
	fConst4 = (0.683772233983162 * fConst1);
	fConst5 = (0.005623413251903491 * sin(fConst0));
	fConst6 = (fConst5 - (fConst4 + 1.316227766016838));
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec2[i] = 0;
	fConst7 = (6.283185307179586 / fSamplingFreq);
	for (int i=0; i<2; i++) fRec7[i] = 0;
	IOTA = 0;
	for (int i=0; i<4096; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	fConst8 = (3.141592653589793 / fSamplingFreq);
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	fConst9 = (3.141592653589793 * fSamplingFreq);
	fConst10 = (0.5 / fSamplingFreq);
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fVec5[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<3; i++) fRec12[i] = 0;
	for (int i=0; i<3; i++) fRec11[i] = 0;
	for (int i=0; i<3; i++) fVec6[i] = 0;
	fConst11 = (fConst5 + fConst4);
	fConst12 = (0.31622776601683794 * (1.316227766016838 - fConst11));
	fConst13 = (0.31622776601683794 * ((fConst5 + 1.316227766016838) - fConst4));
	fConst14 = (0 - (0.6324555320336759 * (fConst2 - 0.683772233983162)));
	fConst15 = (1.0 / (1.316227766016838 + fConst11));
	for (int i=0; i<3; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<3; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fVec7[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fVec8[i] = 0;
	for (int i=0; i<2; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<2; i++) fVec9[i] = 0;
	for (int i=0; i<2; i++) fRec18[i] = 0;
	for (int i=0; i<3; i++) fVec10[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fVec11[i] = 0;
	for (int i=0; i<2; i++) fRec23[i] = 0;
	for (int i=0; i<2; i++) fVec12[i] = 0;
	for (int i=0; i<2; i++) fRec22[i] = 0;
	for (int i=0; i<3; i++) fRec21[i] = 0;
	for (int i=0; i<3; i++) fRec20[i] = 0;
}

void compute(int count, float *input0, float *output0)
{
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * (fslider0 - 10))));
	double 	fSlow1 = (0.0010000000000000009 * pow(10,(0.05 * (fslider1 - 10))));
	double 	fSlow2 = (fConst7 * max(0, fentry0));
	double 	fSlow3 = cos(fSlow2);
	double 	fSlow4 = (1.251188643150958 * fSlow3);
	double 	fSlow5 = (0 - (2 * (0 - (0.748811356849042 + fSlow4))));
	double 	fSlow6 = (0.748811356849042 * fSlow3);
	double 	fSlow7 = (0.5011872336272722 * sin(fSlow2));
	double 	fSlow8 = (fSlow7 - (fSlow6 + 1.251188643150958));
	double 	fSlow9 = (fConst7 * max(0, fentry1));
	double 	fSlow10 = cos(fSlow9);
	double 	fSlow11 = (1.251188643150958 * fSlow10);
	double 	fSlow12 = (2 * (fSlow11 - 0.748811356849042));
	double 	fSlow13 = (0.748811356849042 * fSlow10);
	double 	fSlow14 = (0.5011872336272722 * sin(fSlow9));
	double 	fSlow15 = (fSlow14 + fSlow13);
	double 	fSlow16 = (fSlow15 - 1.251188643150958);
	double 	fSlow17 = (1.0 - fslider2);
	double 	fSlow18 = fslider3;
	int 	iSlow19 = int((int((fSlow18 - 1)) & 4095));
	int 	iSlow20 = int((int(fSlow18) & 4095));
	int 	iSlow21 = int(fcheckbox0);
	double 	fSlow22 = (1.0 / tan((fConst8 * fentry2)));
	double 	fSlow23 = (fSlow22 - 1);
	double 	fSlow24 = (1.0 / (1 + fSlow22));
	double 	fSlow25 = (1.0 / tan((fConst10 * (fConst9 - (6.283185307179586 * fentry3)))));
	double 	fSlow26 = (1 + fSlow25);
	double 	fSlow27 = (1.0 / fSlow26);
	double 	fSlow28 = (0 - ((fSlow25 - 1) / fSlow26));
	int 	iSlow29 = int(fcheckbox1);
	double 	fSlow30 = tan((fConst8 * fslider4));
	double 	fSlow31 = (2 * (1 - (1.0 / faustpower<2>(fSlow30))));
	double 	fSlow32 = (1.0 / fSlow30);
	double 	fSlow33 = (1 + ((fSlow32 - 0.76536686473018) / fSlow30));
	double 	fSlow34 = (1.0 / (1 + ((0.76536686473018 + fSlow32) / fSlow30)));
	double 	fSlow35 = (1 + ((fSlow32 - 1.847759065022573) / fSlow30));
	double 	fSlow36 = (1.0 / (1 + ((1.847759065022573 + fSlow32) / fSlow30)));
	double 	fSlow37 = (fConst8 * fslider5);
	double 	fSlow38 = (1.0 / (1 + fSlow37));
	double 	fSlow39 = (1 - fSlow37);
	int 	iSlow40 = int(fcheckbox2);
	double 	fSlow41 = (0.251188643150958 * ((1.251188643150958 + fSlow13) - fSlow14));
	double 	fSlow42 = (0.251188643150958 * (1.251188643150958 + fSlow15));
	double 	fSlow43 = (0.502377286301916 * (0 - (0.748811356849042 + fSlow11)));
	double 	fSlow44 = (1.0 / ((1.251188643150958 + fSlow14) - fSlow13));
	double 	fSlow45 = (fSlow7 + fSlow6);
	double 	fSlow46 = (0.251188643150958 * (1.251188643150958 - fSlow45));
	double 	fSlow47 = (0.251188643150958 * ((fSlow7 + 1.251188643150958) - fSlow6));
	double 	fSlow48 = (0 - (0.502377286301916 * (fSlow4 - 0.748811356849042)));
	double 	fSlow49 = (1.0 / (1.251188643150958 + fSlow45));
	double 	fSlow50 = fslider6;
	double 	fSlow51 = fslider8;
	double 	fSlow52 = pow(1e+01,(2 * (fSlow51 * fslider7)));
	double 	fSlow53 = (0.0010000000000000009 * pow(10,(0.05 * (fslider9 - 10))));
	double 	fSlow54 = pow(1e+01,(2 * (fSlow51 * fslider10)));
	double 	fSlow55 = (0.0010000000000000009 * pow(10,(0.05 * (fslider11 - 10))));
	double 	fSlow56 = pow(1e+01,(2 * (fSlow51 * fslider12)));
	for (int i=0; i<count; i++) {
		iVec0[0] = 1;
		fRec1[0] = (fSlow0 + (0.999 * fRec1[1]));
		fRec2[0] = (fSlow1 + (0.999 * fRec2[1]));
		fRec7[0] = ((1e-20 * (1 - iVec0[1])) - fRec7[1]);
		double fTemp0 = (double)input0[i];
		double fTemp1 = (fTemp0 + (fSlow17 * fRec8[1]));
		fVec1[IOTA&4095] = fTemp1;
		fRec8[0] = (0.5 * (fVec1[(IOTA-iSlow20)&4095] + fVec1[(IOTA-iSlow19)&4095]));
		double fTemp2 = ((iSlow21)?fRec8[0]:fTemp0);
		double fTemp3 = (fTemp2 + (2 * fRec7[0]));
		fVec2[0] = (fSlow24 * fTemp3);
		fRec10[0] = (fVec2[1] + (fSlow24 * (fTemp3 + (fSlow23 * fRec10[1]))));
		double fTemp4 = (fSlow27 * fRec10[0]);
		fVec3[0] = fTemp4;
		fRec9[0] = ((fVec3[0] + (fSlow28 * fRec9[1])) - fVec3[1]);
		double fTemp5 = ((iSlow29)?fRec9[0]:(fTemp2 + fRec7[0]));
		double fTemp6 = (fRec7[0] + fTemp5);
		fVec4[0] = (fSlow38 * fTemp6);
		fRec14[0] = ((fSlow38 * (fTemp6 + (fSlow39 * fRec14[1]))) - fVec4[1]);
		fVec5[0] = (fSlow38 * fRec14[0]);
		fRec13[0] = ((fSlow38 * (fRec14[0] + (fSlow39 * fRec13[1]))) - fVec5[1]);
		fRec12[0] = (fRec13[0] - (fSlow36 * ((fSlow35 * fRec12[2]) + (fSlow31 * fRec12[1]))));
		fRec11[0] = ((fSlow36 * (fRec12[2] + (fRec12[0] + (2 * fRec12[1])))) - (fSlow34 * ((fSlow33 * fRec11[2]) + (fSlow31 * fRec11[1]))));
		double fTemp7 = ((iSlow40)?(fSlow34 * (fRec11[2] + (fRec11[0] + (2 * fRec11[1])))):fTemp5);
		fVec6[0] = fTemp7;
		fRec6[0] = (fConst15 * ((((fConst14 * fVec6[1]) + (fConst13 * fVec6[0])) + (fConst12 * fVec6[2])) + ((fConst6 * fRec6[2]) + (fConst3 * fRec6[1]))));
		fRec5[0] = (fSlow44 * ((((fSlow43 * fRec6[1]) + (fSlow42 * fRec6[0])) + (fSlow41 * fRec6[2])) + ((fSlow16 * fRec5[2]) + (fSlow12 * fRec5[1]))));
		fRec4[0] = (fSlow49 * ((((fSlow48 * fRec5[1]) + (fSlow47 * fRec5[0])) + (fSlow46 * fRec5[2])) + ((fSlow8 * fRec4[2]) + (fSlow5 * fRec4[1]))));
		double fTemp8 = max(-1, min(1, (fSlow52 * (fSlow50 + fRec4[0]))));
		double fTemp9 = (fTemp8 * (1 - (0.3333333333333333 * faustpower<2>(fTemp8))));
		fVec7[0] = fTemp9;
		fRec3[0] = ((fVec7[0] + (0.995 * fRec3[1])) - fVec7[1]);
		fRec15[0] = (fSlow53 + (0.999 * fRec15[1]));
		double fTemp10 = max(-1, min(1, (fSlow54 * (fSlow50 + fRec5[0]))));
		double fTemp11 = (fTemp10 * (1 - (0.3333333333333333 * faustpower<2>(fTemp10))));
		fVec8[0] = fTemp11;
		fRec16[0] = ((fVec8[0] + (0.995 * fRec16[1])) - fVec8[1]);
		fRec17[0] = (fSlow55 + (0.999 * fRec17[1]));
		fRec19[0] = (fSlow49 * ((((fSlow48 * fRec6[1]) + (fSlow47 * fRec6[0])) + (fSlow46 * fRec6[2])) + ((fSlow8 * fRec19[2]) + (fSlow5 * fRec19[1]))));
		double fTemp12 = max(-1, min(1, (fSlow56 * (fSlow50 + fRec19[0]))));
		double fTemp13 = (fTemp12 * (1 - (0.3333333333333333 * faustpower<2>(fTemp12))));
		fVec9[0] = fTemp13;
		fRec18[0] = ((fVec9[0] + (0.995 * fRec18[1])) - fVec9[1]);
		double fTemp14 = ((((fRec18[0] * fRec17[0]) + (fRec16[0] * fRec15[0])) + (fRec3[0] * fRec2[0])) * fRec1[0]);
		fVec10[0] = fTemp14;
		fRec0[0] = (fConst15 * ((((fConst14 * fVec10[1]) + (fConst13 * fVec10[0])) + (fConst12 * fVec10[2])) + ((fConst6 * fRec0[2]) + (fConst3 * fRec0[1]))));
		double fTemp15 = (fRec7[0] + fRec0[0]);
		fVec11[0] = (fSlow38 * fTemp15);
		fRec23[0] = ((fSlow38 * (fTemp15 + (fSlow39 * fRec23[1]))) - fVec11[1]);
		fVec12[0] = (fSlow38 * fRec23[0]);
		fRec22[0] = ((fSlow38 * (fRec23[0] + (fSlow39 * fRec22[1]))) - fVec12[1]);
		fRec21[0] = (fRec22[0] - (fSlow36 * ((fSlow35 * fRec21[2]) + (fSlow31 * fRec21[1]))));
		fRec20[0] = ((fSlow36 * (fRec21[2] + (fRec21[0] + (2 * fRec21[1])))) - (fSlow34 * ((fSlow33 * fRec20[2]) + (fSlow31 * fRec20[1]))));
		output0[i] = (FAUSTFLOAT)((iSlow40)?(fSlow34 * (fRec20[2] + (fRec20[0] + (2 * fRec20[1])))):fRec0[0]);
		// post processing
		fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
		fRec21[2] = fRec21[1]; fRec21[1] = fRec21[0];
		fRec22[1] = fRec22[0];
		fVec12[1] = fVec12[0];
		fRec23[1] = fRec23[0];
		fVec11[1] = fVec11[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fVec10[2] = fVec10[1]; fVec10[1] = fVec10[0];
		fRec18[1] = fRec18[0];
		fVec9[1] = fVec9[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec17[1] = fRec17[0];
		fRec16[1] = fRec16[0];
		fVec8[1] = fVec8[0];
		fRec15[1] = fRec15[0];
		fRec3[1] = fRec3[0];
		fVec7[1] = fVec7[0];
		fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
		fVec6[2] = fVec6[1]; fVec6[1] = fVec6[0];
		fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
		fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
		fRec13[1] = fRec13[0];
		fVec5[1] = fVec5[0];
		fRec14[1] = fRec14[0];
		fVec4[1] = fVec4[0];
		fRec9[1] = fRec9[0];
		fVec3[1] = fVec3[0];
		fRec10[1] = fRec10[0];
		fVec2[1] = fVec2[0];
		fRec8[1] = fRec8[0];
		IOTA = IOTA+1;
		fRec7[1] = fRec7[0];
		fRec2[1] = fRec2[0];
		fRec1[1] = fRec1[0];
		iVec0[1] = iVec0[0];
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerVar("distortion.low_drive","","S","",&fslider12, 1.0, 0.0, 1.0, 0.01);
	registerVar("distortion.low_gain","","S","",&fslider11, 1e+01, -1e+01, 2e+01, 0.1);
	registerVar("distortion.high_drive","","S","",&fslider10, 1.0, 0.0, 1.0, 0.01);
	registerVar("distortion.low_highpass.on_off","low highpass","B","",&fcheckbox1, 0.0, 0.0, 1.0, 1.0);
	registerVar("distortion.resonator.on_off","resonat","B","",&fcheckbox0, 0.0, 0.0, 1.0, 1.0);
	registerVar("distortion.low_highcutoff.on_off","low highcutoff","B","",&fcheckbox2, 0.0, 0.0, 1.0, 1.0);
	registerVar("distortion.split_low_freq","","S","",&fentry1, 2.5e+02, 2e+01, 6e+02, 1e+01);
	registerVar("distortion.split_high_freq","","S","",&fentry0, 6.5e+02, 6e+02, 1.25e+03, 1e+01);
	registerVar("distortion.low_highpass.high_freq","high freq","S","",&fentry3, 1.3e+02, 2e+01, 7.04e+03, 1e+01);
	registerVar("distortion.low_highpass.low_freq","low freq","S","",&fentry2, 5e+03, 2e+01, 1.2e+04, 1e+01);
	registerVar("distortion.middle_drive","","S","",&fslider7, 1.0, 0.0, 1.0, 0.01);
	registerVar("distortion.level","","S","",&fslider6, 0.01, 0.0, 0.5, 0.01);
	registerVar("distortion.low_highcutoff.low_freq","low freq","S","low-freq cutoff Hz",&fslider5, 1.3e+02, 2e+01, 1e+03, 1e+01);
	registerVar("distortion.low_highcutoff.high_freq","high freq","S","high-freq cutoff Hz",&fslider4, 5e+03, 1e+03, 1.2e+04, 1e+01);
	registerVar("distortion.vibrato","","S","",&fslider3, 1.0, 0.0, 1.0, 0.01);
	registerVar("distortion.trigger","","S","",&fslider2, 0.12, 0.0, 1.0, 0.01);
	registerVar("distortion.middle_gain","","S","",&fslider1, 1e+01, -1e+01, 2e+01, 0.1);
	registerVar("distortion.gain","","S","",&fslider0, 2.0, -1e+01, 1e+01, 0.1);
	registerVar("distortion.high_gain","","S","",&fslider9, 1e+01, -1e+01, 2e+01, 0.1);
	registerVar("distortion.drive","","S","",&fslider8, 0.64, 0.0, 1.0, 0.01);
	registerInit(init);
}

} // end namespace distortion
