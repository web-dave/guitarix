namespace gxamp14 {
// generated from file '../src/faust/gxamp14.dsp'

double 	fConst0;
double 	fConst1;
double 	fConst2;
double 	fConst3;
double 	fConst4;
double 	fConst5;
double 	fConst6;
double 	fConst7;
double 	fConst8;
double 	fConst9;
double 	fConst10;
double 	fConst11;
double 	fConst12;
double 	fConst13;
double 	fConst14;
double 	fConst15;
double 	fConst16;
double 	fConst17;
double 	fVec0[2];
double 	fConst18;
double 	fRec5[2];
FAUSTFLOAT&	fslider0 = get_alias("amp2.stage2.gain1");
double 	fRec6[2];
FAUSTFLOAT&	fslider1 = get_alias("gxdistortion.wet_dry");
double 	fRec8[2];
double 	fConst19;
double 	fConst20;
double 	fConst21;
double 	fConst22;
double 	fConst23;
double 	fConst24;
double 	fConst25;
double 	fConst26;
double 	fConst27;
double 	fConst28;
double 	fVec1[2];
double 	fConst29;
double 	fRec21[2];
double 	fRec20[2];
double 	fRec19[3];
double 	fRec18[3];
FAUSTFLOAT&	fslider2 = get_alias("amp2.stage1.Pregain");
double 	fRec22[2];
double 	fConst30;
double 	fConst31;
double 	fConst32;
double 	fConst33;
double 	fVec2[2];
double 	fConst34;
double 	fRec23[2];
double 	fRec17[2];
double 	fConst35;
double 	fConst36;
double 	fRec16[2];
double 	fConst37;
double 	fConst38;
double 	fConst39;
double 	fVec3[2];
double 	fConst40;
double 	fRec26[2];
double 	fRec25[2];
double 	fRec24[2];
double 	fRec15[2];
double 	fConst41;
double 	fRec14[2];
double 	fVec4[2];
double 	fRec27[2];
double 	fRec13[2];
double 	fRec12[2];
double 	fConst42;
double 	fConst43;
double 	fConst44;
double 	fVec5[2];
double 	fConst45;
double 	fRec30[2];
double 	fRec29[2];
double 	fRec28[2];
double 	fRec11[2];
double 	fVec6[2];
double 	fRec31[2];
double 	fRec10[2];
double 	fRec9[2];
FAUSTFLOAT&	fslider3 = get_alias("gxdistortion.drive");
double 	fRec35[2];
double 	fRec34[2];
int 	IOTA;
double 	fVec7[65536];
int 	iConst46;
double 	fRec33[2];
double 	fConst47;
double 	fRec32[2];
double 	fConst48;
double 	fConst49;
double 	fConst50;
double 	fConst51;
double 	fConst52;
double 	fConst53;
double 	fConst54;
double 	fConst55;
double 	fConst56;
double 	fConst57;
double 	fConst58;
double 	fConst59;
double 	fConst60;
double 	fConst61;
double 	fConst62;
double 	fConst63;
double 	fConst64;
double 	fConst65;
double 	fConst66;
double 	fConst67;
double 	fConst68;
double 	fConst69;
double 	fConst70;
double 	fConst71;
double 	fConst72;
double 	fConst73;
double 	fConst74;
double 	fRec42[3];
double 	fVec8[2];
double 	fConst75;
double 	fRec41[2];
double 	fConst76;
double 	fConst77;
double 	fRec40[2];
double 	fRec39[3];
double 	fConst78;
double 	fRec38[3];
double 	fRec37[3];
double 	fConst79;
double 	fConst80;
double 	fConst81;
double 	fConst82;
double 	fConst83;
double 	fConst84;
double 	fConst85;
double 	fConst86;
double 	fConst87;
double 	fRec48[2];
double 	fRec47[3];
double 	fVec9[2];
double 	fConst88;
double 	fRec46[2];
double 	fRec45[3];
double 	fVec10[2];
double 	fConst89;
double 	fConst90;
double 	fRec44[2];
double 	fRec43[3];
double 	fConst91;
double 	fRec50[2];
double 	fRec49[3];
double 	fConst92;
double 	fRec53[2];
double 	fRec52[3];
double 	fConst93;
double 	fRec51[3];
double 	fVec11[2];
double 	fConst94;
double 	fRec36[2];
double 	fVec12[2];
double 	fRec7[2];
double 	fRec4[2];
double 	fConst95;
double 	fRec3[2];
double 	fVec13[2];
double 	fRec56[2];
double 	fRec55[2];
double 	fRec54[2];
double 	fVec14[3];
double 	fConst96;
double 	fConst97;
double 	fRec2[3];
double 	fConst98;
double 	fConst99;
double 	fRec1[3];
double 	fConst100;
double 	fConst101;
double 	fRec0[3];
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = (31704.95306002819 / fSamplingFreq);
	fConst1 = (2 * cos(fConst0));
	fConst2 = (0.026178010471204185 * sin(fConst0));
	fConst3 = (fConst2 - 1);
	fConst4 = (49574.33207364693 / fSamplingFreq);
	fConst5 = (2 * cos(fConst4));
	fConst6 = (0.07042253521126761 * sin(fConst4));
	fConst7 = (fConst6 - 1);
	fConst8 = (60601.32228774711 / fSamplingFreq);
	fConst9 = (2 * cos(fConst8));
	fConst10 = (0.03546099290780142 * sin(fConst8));
	fConst11 = (fConst10 - 1);
	fConst12 = (1.0 / tan((97.38937226128358 / fSamplingFreq)));
	fConst13 = (1 + fConst12);
	fConst14 = (0 - ((1 - fConst12) / fConst13));
	fConst15 = (1.0 / tan((20517.741620594938 / fSamplingFreq)));
	fConst16 = (1 + fConst15);
	fConst17 = (0 - ((1 - fConst15) / fConst16));
	for (int i=0; i<2; i++) fVec0[i] = 0;
	fConst18 = (0.0041 / fConst16);
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	fConst19 = tan((37699.11184307752 / fSamplingFreq));
	fConst20 = (2 * (1 - (1.0 / faustpower<2>(fConst19))));
	fConst21 = (1.0 / fConst19);
	fConst22 = (1 + ((fConst21 - 0.7653668647301795) / fConst19));
	fConst23 = (1 + ((0.7653668647301795 + fConst21) / fConst19));
	fConst24 = (1.0 / fConst23);
	fConst25 = (1 + ((fConst21 - 1.8477590650225735) / fConst19));
	fConst26 = (1.0 / (1 + ((fConst21 + 1.8477590650225735) / fConst19)));
	fConst27 = (973.8937226128359 / fSamplingFreq);
	fConst28 = (1 - fConst27);
	for (int i=0; i<2; i++) fVec1[i] = 0;
	fConst29 = (1.0 / (1 + fConst27));
	for (int i=0; i<2; i++) fRec21[i] = 0;
	for (int i=0; i<2; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<3; i++) fRec18[i] = 0;
	for (int i=0; i<2; i++) fRec22[i] = 0;
	fConst30 = (2.0 / fConst23);
	fConst31 = (1.0 / tan((270.1769682087222 / fSamplingFreq)));
	fConst32 = (1 + fConst31);
	fConst33 = (0 - ((1 - fConst31) / fConst32));
	for (int i=0; i<2; i++) fVec2[i] = 0;
	fConst34 = (0.027 / fConst32);
	for (int i=0; i<2; i++) fRec23[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	fConst35 = (0 - fConst12);
	fConst36 = (0.05 / fConst13);
	for (int i=0; i<2; i++) fRec16[i] = 0;
	fConst37 = (1.0 / tan((414.6902302738527 / fSamplingFreq)));
	fConst38 = (1 + fConst37);
	fConst39 = (0 - ((1 - fConst37) / fConst38));
	for (int i=0; i<2; i++) fVec3[i] = 0;
	fConst40 = (0.015 / fConst38);
	for (int i=0; i<2; i++) fRec26[i] = 0;
	for (int i=0; i<2; i++) fRec25[i] = 0;
	for (int i=0; i<2; i++) fRec24[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	fConst41 = (1.0 / fConst16);
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec27[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	fConst42 = (1.0 / tan((609.4689747964198 / fSamplingFreq)));
	fConst43 = (1 + fConst42);
	fConst44 = (0 - ((1 - fConst42) / fConst43));
	for (int i=0; i<2; i++) fVec5[i] = 0;
	fConst45 = (0.0082 / fConst43);
	for (int i=0; i<2; i++) fRec30[i] = 0;
	for (int i=0; i<2; i++) fRec29[i] = 0;
	for (int i=0; i<2; i++) fRec28[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2; i++) fVec6[i] = 0;
	for (int i=0; i<2; i++) fRec31[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec35[i] = 0;
	for (int i=0; i<2; i++) fRec34[i] = 0;
	IOTA = 0;
	for (int i=0; i<65536; i++) fVec7[i] = 0;
	iConst46 = int((int((0.1111111111111111 * fSamplingFreq)) & 65535));
	for (int i=0; i<2; i++) fRec33[i] = 0;
	fConst47 = (0.009000000000000008 / fSamplingFreq);
	for (int i=0; i<2; i++) fRec32[i] = 0;
	fConst48 = tan((942.4777960769379 / fSamplingFreq));
	fConst49 = (1.0 / faustpower<2>(fConst48));
	fConst50 = (2 * (1 - fConst49));
	fConst51 = (1.0 / fConst48);
	fConst52 = (1 + ((fConst51 - 1.0) / fConst48));
	fConst53 = (1.0 / (1 + ((1.0 + fConst51) / fConst48)));
	fConst54 = tan((3769.9111843077517 / fSamplingFreq));
	fConst55 = (1.0 / faustpower<2>(fConst54));
	fConst56 = (2 * (1 - fConst55));
	fConst57 = (1.0 / fConst54);
	fConst58 = (1 + ((fConst57 - 1.0) / fConst54));
	fConst59 = (1.0 / (1 + ((1.0 + fConst57) / fConst54)));
	fConst60 = tan((10053.096491487338 / fSamplingFreq));
	fConst61 = (1.0 / faustpower<2>(fConst60));
	fConst62 = (2 * (1 - fConst61));
	fConst63 = (1.0 / fConst60);
	fConst64 = (1 + ((fConst63 - 1.0000000000000004) / fConst60));
	fConst65 = (1 + ((1.0000000000000004 + fConst63) / fConst60));
	fConst66 = (1.0 / fConst65);
	fConst67 = (1 + fConst63);
	fConst68 = (0 - ((1 - fConst63) / fConst67));
	fConst69 = tan((47123.8898038469 / fSamplingFreq));
	fConst70 = (2 * (1 - (1.0 / faustpower<2>(fConst69))));
	fConst71 = (1.0 / fConst69);
	fConst72 = (1 + ((fConst71 - 1.414213562373095) / fConst69));
	fConst73 = (1 + ((1.414213562373095 + fConst71) / fConst69));
	fConst74 = (1.0 / fConst73);
	for (int i=0; i<3; i++) fRec42[i] = 0;
	for (int i=0; i<2; i++) fVec8[i] = 0;
	fConst75 = (1.0 / (fConst13 * fConst73));
	for (int i=0; i<2; i++) fRec41[i] = 0;
	fConst76 = (0 - fConst63);
	fConst77 = (1.0 / fConst67);
	for (int i=0; i<2; i++) fRec40[i] = 0;
	for (int i=0; i<3; i++) fRec39[i] = 0;
	fConst78 = (2 * (0 - fConst61));
	for (int i=0; i<3; i++) fRec38[i] = 0;
	for (int i=0; i<3; i++) fRec37[i] = 0;
	fConst79 = (1 + ((fConst51 - 1.0000000000000004) / fConst48));
	fConst80 = (1.0 / (1 + ((fConst51 + 1.0000000000000004) / fConst48)));
	fConst81 = (1 + fConst51);
	fConst82 = (0 - ((1 - fConst51) / fConst81));
	fConst83 = (1 + ((fConst57 - 1.0000000000000004) / fConst54));
	fConst84 = (1 + ((fConst57 + 1.0000000000000004) / fConst54));
	fConst85 = (1.0 / fConst84);
	fConst86 = (1 + fConst57);
	fConst87 = (0 - ((1 - fConst57) / fConst86));
	for (int i=0; i<2; i++) fRec48[i] = 0;
	for (int i=0; i<3; i++) fRec47[i] = 0;
	for (int i=0; i<2; i++) fVec9[i] = 0;
	fConst88 = (1.0 / (fConst86 * fConst65));
	for (int i=0; i<2; i++) fRec46[i] = 0;
	for (int i=0; i<3; i++) fRec45[i] = 0;
	for (int i=0; i<2; i++) fVec10[i] = 0;
	fConst89 = (0 - fConst51);
	fConst90 = (1.0 / (fConst81 * fConst84));
	for (int i=0; i<2; i++) fRec44[i] = 0;
	for (int i=0; i<3; i++) fRec43[i] = 0;
	fConst91 = (2 * (0 - fConst49));
	for (int i=0; i<2; i++) fRec50[i] = 0;
	for (int i=0; i<3; i++) fRec49[i] = 0;
	fConst92 = (0 - fConst57);
	for (int i=0; i<2; i++) fRec53[i] = 0;
	for (int i=0; i<3; i++) fRec52[i] = 0;
	fConst93 = (2 * (0 - fConst55));
	for (int i=0; i<3; i++) fRec51[i] = 0;
	for (int i=0; i<2; i++) fVec11[i] = 0;
	fConst94 = (1.5848931924611136 / fConst16);
	for (int i=0; i<2; i++) fRec36[i] = 0;
	for (int i=0; i<2; i++) fVec12[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	fConst95 = (0.025 / fConst13);
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec13[i] = 0;
	for (int i=0; i<2; i++) fRec56[i] = 0;
	for (int i=0; i<2; i++) fRec55[i] = 0;
	for (int i=0; i<2; i++) fRec54[i] = 0;
	for (int i=0; i<3; i++) fVec14[i] = 0;
	fConst96 = (0 - fConst9);
	fConst97 = (1.0 / (1 + fConst10));
	for (int i=0; i<3; i++) fRec2[i] = 0;
	fConst98 = (0 - fConst5);
	fConst99 = (1.0 / (1 + fConst6));
	for (int i=0; i<3; i++) fRec1[i] = 0;
	fConst100 = (0 - fConst1);
	fConst101 = (1.0 / (1 + fConst2));
	for (int i=0; i<3; i++) fRec0[i] = 0;
}

void compute(int count, float *input0, float *output0)
{
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * fslider0)));
	double 	fSlow1 = fslider1;
	double 	fSlow2 = (0.0010000000000000009 * (1 - (0.01 * fSlow1)));
	double 	fSlow3 = (0.0010000000000000009 * pow(10,(0.05 * fslider2)));
	double 	fSlow4 = fslider3;
	double 	fSlow5 = (1.25 * fSlow4);
	double 	fSlow6 = (1.000000000000001e-05 * fSlow1);
	double 	fSlow7 = (2 * (fSlow4 - 0.5));
	double 	fSlow8 = (0.024937655860349125 * (1 - max(0, fSlow7)));
	double 	fSlow9 = pow(1e+01,(0.8 * fSlow4));
	double 	fSlow10 = (fConst80 * pow(1e+01,(2 * fSlow4)));
	double 	fSlow11 = (fConst80 * pow(1e+01,(0.9 * fSlow4)));
	double 	fSlow12 = pow(1e+01,(1.2 * fSlow4));
	double 	fSlow13 = (1 - max(0, (0 - fSlow7)));
	for (int i=0; i<count; i++) {
		double fTemp0 = (fRec4[1] - 2.5e+02);
		fVec0[0] = fTemp0;
		fRec5[0] = ((fConst18 * (fVec0[0] + fVec0[1])) + (fConst17 * fRec5[1]));
		fRec6[0] = (fSlow0 + (0.999 * fRec6[1]));
		fRec8[0] = (fSlow2 + (0.999 * fRec8[1]));
		double fTemp1 = (double)input0[i];
		fVec1[0] = fTemp1;
		fRec21[0] = (fConst29 * ((fVec1[0] - fVec1[1]) + (fConst28 * fRec21[1])));
		fRec20[0] = (fConst29 * ((fRec21[0] - fRec21[1]) + (fConst28 * fRec20[1])));
		fRec19[0] = (fRec20[0] - (fConst26 * ((fConst25 * fRec19[2]) + (fConst20 * fRec19[1]))));
		fRec18[0] = ((fConst26 * (fRec19[2] + (fRec19[0] + (2 * fRec19[1])))) - (fConst24 * ((fConst22 * fRec18[2]) + (fConst20 * fRec18[1]))));
		fRec22[0] = (fSlow3 + (0.999 * fRec22[1]));
		double fTemp2 = (fRec17[1] - 1.3e+02);
		fVec2[0] = fTemp2;
		fRec23[0] = ((fConst34 * (fVec2[0] + fVec2[1])) + (fConst33 * fRec23[1]));
		fRec17[0] = Ftube4(0, (fRec23[0] + (fConst30 * (fRec22[0] * (fRec18[2] + (fRec18[0] + (2 * fRec18[1])))))));
		fRec16[0] = ((fConst36 * ((fConst35 * fRec17[1]) + (fConst12 * fRec17[0]))) + (fConst14 * fRec16[1]));
		double fTemp3 = (fRec25[1] - 1.3e+02);
		fVec3[0] = fTemp3;
		fRec26[0] = ((fConst40 * (fVec3[0] + fVec3[1])) + (fConst39 * fRec26[1]));
		fRec25[0] = Ftube4(1, (fRec26[0] + fRec15[1]));
		fRec24[0] = ((fConst36 * ((fConst35 * fRec25[1]) + (fConst12 * fRec25[0]))) + (fConst14 * fRec24[1]));
		fRec15[0] = (fRec24[0] + fRec16[0]);
		fRec14[0] = ((fConst41 * (fRec15[0] + fRec15[1])) + (fConst17 * fRec14[1]));
		double fTemp4 = (fRec13[1] - 1.3e+02);
		fVec4[0] = fTemp4;
		fRec27[0] = ((fConst40 * (fVec4[0] + fVec4[1])) + (fConst39 * fRec27[1]));
		fRec13[0] = Ftube4(1, (fRec27[0] + fRec14[0]));
		fRec12[0] = ((fConst36 * ((fConst35 * fRec13[1]) + (fConst12 * fRec13[0]))) + (fConst14 * fRec12[1]));
		double fTemp5 = (fRec29[1] - 1.3e+02);
		fVec5[0] = fTemp5;
		fRec30[0] = ((fConst45 * (fVec5[0] + fVec5[1])) + (fConst44 * fRec30[1]));
		fRec29[0] = Ftube4(1, (fRec30[0] + fRec11[1]));
		fRec28[0] = ((fConst36 * ((fConst35 * fRec29[1]) + (fConst12 * fRec29[0]))) + (fConst14 * fRec28[1]));
		fRec11[0] = (fRec28[0] + fRec12[0]);
		double fTemp6 = (fRec10[1] - 1.3e+02);
		fVec6[0] = fTemp6;
		fRec31[0] = ((fConst45 * (fVec6[0] + fVec6[1])) + (fConst44 * fRec31[1]));
		fRec10[0] = Ftube4(1, (fRec31[0] + fRec11[0]));
		fRec9[0] = ((fConst36 * ((fConst35 * fRec10[1]) + (fConst12 * fRec10[0]))) + (fConst14 * fRec9[1]));
		double fTemp7 = (fRec9[0] * fRec8[0]);
		fRec35[0] = (fSlow6 + (0.999 * fRec35[1]));
		double fTemp8 = (fRec9[0] * fRec35[0]);
		double fTemp9 = fabs(fTemp8);
		fRec34[0] = ((9.999999999998899e-05 * fTemp9) + (0.9999 * fRec34[1]));
		double fTemp10 = max(fRec34[0], fTemp9);
		fVec7[IOTA&65535] = fTemp10;
		fRec33[0] = ((fVec7[IOTA&65535] + fRec33[1]) - fVec7[(IOTA-iConst46)&65535]);
		fRec32[0] = ((fConst47 * fRec33[0]) + (0.999 * fRec32[1]));
		double fTemp11 = max(-1.0, min(-0.01, (fVec7[IOTA&65535] - (1.0 + (1.02 * fRec32[0])))));
		double fTemp12 = (0 - fTemp11);
		double fTemp13 = (40.1 * fTemp12);
		double fTemp14 = max(-600, fTemp13);
		double fTemp15 = (0 - fTemp14);
		double fTemp16 = (fTemp8 - fTemp11);
		double fTemp17 = (40.1 * fTemp16);
		double fTemp18 = max(-600, fTemp17);
		double fTemp19 = (0 - fTemp18);
		double fTemp20 = (((int((fabs(fTemp17) > 0.0001)))?((int((fTemp18 < -50)))?(exp(fTemp18) * fTemp19):(fTemp18 / (1 - exp(fTemp19)))):(1 + (fTemp16 * (20.05 + (134.00083333333336 * fTemp16))))) - ((int((fabs(fTemp13) > 0.0001)))?((int((fTemp14 < -50)))?(exp(fTemp14) * fTemp15):(fTemp14 / (1 - exp(fTemp15)))):(1 + (fTemp12 * (20.05 + (134.00083333333336 * fTemp12))))));
		double fTemp21 = (fConst50 * fRec37[1]);
		double fTemp22 = (fConst56 * fRec38[1]);
		fRec42[0] = ((0.024937655860349125 * fTemp20) - (fConst74 * ((fConst72 * fRec42[2]) + (fConst70 * fRec42[1]))));
		double fTemp23 = (fRec42[2] + (fRec42[0] + (2 * fRec42[1])));
		fVec8[0] = fTemp23;
		fRec41[0] = ((fConst75 * ((fConst35 * fVec8[1]) + (fConst12 * fVec8[0]))) + (fConst14 * fRec41[1]));
		fRec40[0] = ((fConst77 * ((fConst76 * fRec41[1]) + (fConst63 * fRec41[0]))) + (fConst68 * fRec40[1]));
		fRec39[0] = (fRec40[0] - (fConst66 * ((fConst64 * fRec39[2]) + (fConst62 * fRec39[1]))));
		fRec38[0] = ((fConst66 * (((fConst61 * fRec39[0]) + (fConst78 * fRec39[1])) + (fConst61 * fRec39[2]))) - (fConst59 * ((fConst58 * fRec38[2]) + fTemp22)));
		fRec37[0] = ((fRec38[2] + (fConst59 * (fTemp22 + (fConst58 * fRec38[0])))) - (fConst53 * ((fConst52 * fRec37[2]) + fTemp21)));
		double fTemp24 = max(-1, min(1, (fSlow9 * (fRec37[2] + (fConst53 * (fTemp21 + (fConst52 * fRec37[0])))))));
		fRec48[0] = ((fConst77 * (fRec41[0] + fRec41[1])) + (fConst68 * fRec48[1]));
		fRec47[0] = (fRec48[0] - (fConst66 * ((fConst64 * fRec47[2]) + (fConst62 * fRec47[1]))));
		double fTemp25 = (fRec47[2] + (fRec47[0] + (2 * fRec47[1])));
		fVec9[0] = fTemp25;
		fRec46[0] = ((fConst88 * (fVec9[0] + fVec9[1])) + (fConst87 * fRec46[1]));
		fRec45[0] = (fRec46[0] - (fConst85 * ((fConst83 * fRec45[2]) + (fConst56 * fRec45[1]))));
		double fTemp26 = (fRec45[2] + (fRec45[0] + (2 * fRec45[1])));
		fVec10[0] = fTemp26;
		fRec44[0] = ((fConst90 * ((fConst89 * fVec10[1]) + (fConst51 * fVec10[0]))) + (fConst82 * fRec44[1]));
		fRec43[0] = (fRec44[0] - (fConst80 * ((fConst79 * fRec43[2]) + (fConst50 * fRec43[1]))));
		double fTemp27 = max(-1, min(1, (fSlow10 * (((fConst49 * fRec43[0]) + (fConst91 * fRec43[1])) + (fConst49 * fRec43[2])))));
		fRec50[0] = ((fConst90 * (fVec10[0] + fVec10[1])) + (fConst82 * fRec50[1]));
		fRec49[0] = (fRec50[0] - (fConst80 * ((fConst79 * fRec49[2]) + (fConst50 * fRec49[1]))));
		double fTemp28 = max(-1, min(1, (fSlow11 * (fRec49[2] + (fRec49[0] + (2 * fRec49[1]))))));
		double fTemp29 = (fConst50 * fRec51[1]);
		fRec53[0] = ((fConst88 * ((fConst92 * fVec9[1]) + (fConst57 * fVec9[0]))) + (fConst87 * fRec53[1]));
		fRec52[0] = (fRec53[0] - (fConst85 * ((fConst83 * fRec52[2]) + (fConst56 * fRec52[1]))));
		fRec51[0] = ((fConst85 * (((fConst55 * fRec52[0]) + (fConst93 * fRec52[1])) + (fConst55 * fRec52[2]))) - (fConst53 * ((fConst52 * fRec51[2]) + fTemp29)));
		double fTemp30 = max(-1, min(1, (fSlow12 * (fRec51[2] + (fConst53 * (fTemp29 + (fConst52 * fRec51[0])))))));
		double fTemp31 = (((fTemp30 * (1 - (0.3333333333333333 * faustpower<2>(fTemp30)))) + ((fTemp28 * (1 - (0.3333333333333333 * faustpower<2>(fTemp28)))) + (0.841395141645195 * (fTemp27 * (1 - (0.3333333333333333 * faustpower<2>(fTemp27))))))) + (0.7943282347242815 * (fTemp24 * (1 - (0.3333333333333333 * faustpower<2>(fTemp24))))));
		fVec11[0] = fTemp31;
		fRec36[0] = ((fConst94 * (fVec11[0] + fVec11[1])) + (fConst17 * fRec36[1]));
		double fTemp32 = (((fSlow13 * fRec36[0]) + (fSlow8 * fTemp20)) + (fTemp7 * (1 + (fSlow5 * ((4 - (4 * fabs(fTemp7))) - 1)))));
		fVec12[0] = fTemp32;
		fRec7[0] = ((fConst41 * (fVec12[0] + fVec12[1])) + (fConst17 * fRec7[1]));
		double fTemp33 = (fRec7[0] * fRec6[0]);
		fRec4[0] = Ftube5(0, (fTemp33 + fRec5[0]));
		fRec3[0] = ((fConst95 * ((fConst35 * fRec4[1]) + (fConst12 * fRec4[0]))) + (fConst14 * fRec3[1]));
		double fTemp34 = (fRec55[1] - 2.5e+02);
		fVec13[0] = fTemp34;
		fRec56[0] = ((fConst18 * (fVec13[0] + fVec13[1])) + (fConst17 * fRec56[1]));
		fRec55[0] = Ftube5(1, (fRec56[0] + fTemp33));
		fRec54[0] = ((fConst95 * ((fConst35 * fRec55[1]) + (fConst12 * fRec55[0]))) + (fConst14 * fRec54[1]));
		double fTemp35 = (min(0.7, fRec54[0]) + max(-0.75, fRec3[0]));
		fVec14[0] = fTemp35;
		fRec2[0] = (fConst97 * ((fVec14[2] + (fVec14[0] + (fConst96 * fVec14[1]))) + ((fConst11 * fRec2[2]) + (fConst9 * fRec2[1]))));
		fRec1[0] = (fConst99 * ((fRec2[2] + (fRec2[0] + (fConst98 * fRec2[1]))) + ((fConst7 * fRec1[2]) + (fConst5 * fRec1[1]))));
		fRec0[0] = (fConst101 * ((fRec1[2] + (fRec1[0] + (fConst100 * fRec1[1]))) + ((fConst3 * fRec0[2]) + (fConst1 * fRec0[1]))));
		output0[i] = (FAUSTFLOAT)fRec0[0];
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fVec14[2] = fVec14[1]; fVec14[1] = fVec14[0];
		fRec54[1] = fRec54[0];
		fRec55[1] = fRec55[0];
		fRec56[1] = fRec56[0];
		fVec13[1] = fVec13[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec7[1] = fRec7[0];
		fVec12[1] = fVec12[0];
		fRec36[1] = fRec36[0];
		fVec11[1] = fVec11[0];
		fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
		fRec52[2] = fRec52[1]; fRec52[1] = fRec52[0];
		fRec53[1] = fRec53[0];
		fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
		fRec50[1] = fRec50[0];
		fRec43[2] = fRec43[1]; fRec43[1] = fRec43[0];
		fRec44[1] = fRec44[0];
		fVec10[1] = fVec10[0];
		fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
		fRec46[1] = fRec46[0];
		fVec9[1] = fVec9[0];
		fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
		fRec48[1] = fRec48[0];
		fRec37[2] = fRec37[1]; fRec37[1] = fRec37[0];
		fRec38[2] = fRec38[1]; fRec38[1] = fRec38[0];
		fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
		fRec40[1] = fRec40[0];
		fRec41[1] = fRec41[0];
		fVec8[1] = fVec8[0];
		fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
		fRec32[1] = fRec32[0];
		fRec33[1] = fRec33[0];
		IOTA = IOTA+1;
		fRec34[1] = fRec34[0];
		fRec35[1] = fRec35[0];
		fRec9[1] = fRec9[0];
		fRec10[1] = fRec10[0];
		fRec31[1] = fRec31[0];
		fVec6[1] = fVec6[0];
		fRec11[1] = fRec11[0];
		fRec28[1] = fRec28[0];
		fRec29[1] = fRec29[0];
		fRec30[1] = fRec30[0];
		fVec5[1] = fVec5[0];
		fRec12[1] = fRec12[0];
		fRec13[1] = fRec13[0];
		fRec27[1] = fRec27[0];
		fVec4[1] = fVec4[0];
		fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		fRec24[1] = fRec24[0];
		fRec25[1] = fRec25[0];
		fRec26[1] = fRec26[0];
		fVec3[1] = fVec3[0];
		fRec16[1] = fRec16[0];
		fRec17[1] = fRec17[0];
		fRec23[1] = fRec23[0];
		fVec2[1] = fVec2[0];
		fRec22[1] = fRec22[0];
		fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fRec21[1] = fRec21[0];
		fVec1[1] = fVec1[0];
		fRec8[1] = fRec8[0];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fVec0[1] = fVec0[0];
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerInit("amp2", init);
}

} // end namespace gxamp14
