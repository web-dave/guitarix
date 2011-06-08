/*
 * Copyright (C) 2009-2010 Hermann Meyer, James Warden, Andreas Degert
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * --------------------------------------------------------------------------
 *
 *
 *    This is the Guitarix Audio Engine
 *
 *
 * --------------------------------------------------------------------------
 */

#include <cstring>
#include <fstream>
#include <errno.h>
#include "guitarix.h"
#include <glibmm/i18n.h>


using namespace gx_resample;

namespace gx_engine {

#include "gx_engine_tubetable.cc"

/****************************************************************
 ** registering of audio variables
 */

inline void registerNonMidiParam(const char*a, float*c, bool d, float std=0, float lower=0, float upper=1)
{
	gx_gui::parameter_map.insert(new gx_gui::FloatParameter(a,"",gx_gui::Parameter::None,d,*c,std,lower,upper,0,false));
}

inline void registerNonMidiParam(const char*a, bool*c, bool d, float std=false)
{
	gx_gui::parameter_map.insert(new gx_gui::BoolParameter(a,"",gx_gui::Parameter::None,d,*c,std,0,false));
}

// should be int
inline void registerEnumParam(const char*a,const char*b,const char** vl,float*c,int std=0,bool exp=false)
{
	gx_gui::parameter_map.insert(new gx_gui::FloatEnumParameter(a,b,vl,true,*c,std,true,exp)); //false == no_midi_var
}

inline void registerEnumParam(const char*a,const char*b,const char** vl, int*c,int std=0,bool exp=false)
{
	gx_gui::parameter_map.insert(new gx_gui::EnumParameter(a,b,vl,true,*c,std,true,exp)); //false == no_midi_var
}

/****************************************************************
 ** definitions for code generated with faust / dsp2cc
 */

#include "gx_faust_includes.cc"

/****************************************************************
 ** register audio variables to paramtable
 */

void AudioVariables::register_parameter()
{
	static const char *on_off = N_("on/off");
	gx_gui::registerParam("amp.bass_boost.on_off", on_off, &fboost, 0);
	gx_gui::registerParam("compressor.on_off", on_off, &fcheckboxcom1, 0);
	gx_gui::registerParam("jconv.on_off", "Run", &gx_jconv::GxJConvSettings::checkbutton7);
	gx_gui::registerParam("crybaby.on_off", on_off, &fcheckbox5, 0);
	gx_gui::registerParam("cab.on_off", "Cabinet", &fcab,0);
	gx_gui::registerParam("con.on_off", "Contrast-ImpResp", &fcon,0);
	gx_gui::registerParam("overdrive.on_off", on_off, &foverdrive4, 0);
	gx_gui::registerParam("gx_distortion.on_off", on_off, &fcheckbox4, 0);
	gx_gui::registerParam("freeverb.on_off", on_off, &fcheckbox6, 0);
	gx_gui::registerParam("IR.on_off", on_off, &fcheckbox8, 0);
	gx_gui::registerParam("echo.on_off", on_off, (float*) &fcheckbox7, 0.);
	gx_gui::registerParam("delay.on_off", on_off, (float*) &fdelay, 0.);
	gx_gui::registerParam("chorus.on_off", on_off, (float*) &fchorus, 0.);
	gx_gui::registerParam("eqs.on_off", on_off, &feq, 0);
	gx_gui::registerParam("moog.on_off", on_off, &fmoog, 0);
	gx_gui::registerParam("biquad.on_off", "on_off", &fbiquad, 0);
	gx_gui::registerParam("flanger.on_off", on_off, &fflanger, 0);
	//gx_gui::registerParam("SampleLooper.on_off", "on_off", (float*) &fsloop, 0.);
	gx_gui::registerParam("phaser.on_off", on_off, (float*) &fphaser, 0.);
	gx_gui::registerParam("shaper.on_off", on_off, &fng, 0);
	gx_gui::registerParam("low_highpass.on_off", on_off, &flh, 0);
	gx_gui::registerParam("stereodelay.on_off", on_off,(float*) &fsd, 0);
	gx_gui::registerParam("stereoecho.on_off", on_off,(float*) &fse, 0);
	gx_gui::registerParam("midi_out.on_off", on_off, &fmi, 0);
	gx_gui::registerParam("oscilloscope.on_off", on_off, &fwv, 0);
	gx_gui::registerParam("ampmodul.on_off", on_off, &famp, 0);
	gx_gui::registerParam("noise_gate.on_off", "on/off", &fnoise_g, 0);
	gx_gui::registerParam("amp.on_off", on_off, &fampout, 0);
	gx_gui::registerParam("amp.clip.on_off", on_off, &ftube, 0);
	gx_gui::registerParam("tonemodul.on_off", on_off, &ftone, 0);
	gx_gui::registerParam("tremolo.on_off", on_off, &ftremolo, 0);
	gx_gui::registerParam("phaser_mono.on_off", on_off, &fpm, 0);
	gx_gui::registerParam("chorus_mono.on_off", on_off, (float*) &fchorus_mono, 0.);
	gx_gui::registerParam("flanger_mono.on_off", on_off, &fflanger_mono, 0.);
	gx_gui::registerParam("feedback.on_off", on_off, &ffeedback, 0.);
	gx_gui::registerParam("amp.tonestack.on_off", on_off, &ftonestack, 0.);
	
	gx_gui::registerParam("noise_gate.threshold", "Threshold", &fnglevel, 0.017f, 0.01f, 0.31f, 0.001f);
	
	static const char *tonestack_model[] = {N_("default"),N_("Bassman"),N_("Twin Reverb"),
		N_("Princeton"),N_("JCM-800"),N_("JCM-2000"),N_("M-Lead"),N_("M2199"),N_("AC-30"),
		N_("Mesa Boogie"),N_("SOL 100"),N_("JTM-45"),N_("AC-15"),N_("Peavey"),N_("Ibanez"),
		N_("Roland"),N_("Ampeg"),0};
	registerEnumParam("amp.tonestack.select","select",tonestack_model,&tonestack, 0);
	static const char *cabinet_model[] = {N_("4x12"),N_("2x12"),N_("1x12"),N_("4x10"),
	N_("2x10"),N_("HighGain"),N_("Twin"),N_("Bassman"),N_("Marshall"),N_("AC-30"),
	N_("Princeton"),N_("A2"),0};
	registerEnumParam("cab.select","select",cabinet_model,&cabinet, 0);
	
	static const char *post_pre[] = {N_("post"),N_("pre"),0};
	registerEnumParam("compressor.pp","select",post_pre,&compressorpp, 0);
	registerEnumParam("crybaby.pp","select",post_pre,&crybabypp, 0);
	registerEnumParam("overdrive.pp","select",post_pre,&overdrivepp, 0);
	registerEnumParam("gx_distortion.pp","select",post_pre,&distortionpp, 0);
	registerEnumParam("freeverb.pp","select",post_pre,&freeverbpp, 0);
	registerEnumParam("IR.pp","select",post_pre,&IRpp, 0);
	registerEnumParam("echo.pp","select",post_pre,&echopp, 0);
	registerEnumParam("delay.pp","select",post_pre,&delaypp, 0);
	registerEnumParam("eqs.pp","select",post_pre,&eqpp, 0);
	registerEnumParam("low_highpass.pp","select",post_pre,&lhpp, 0);
	registerEnumParam("oscilloscope.pp","select",post_pre,&wvpp, 0);
	registerEnumParam("biquad.pp","select",post_pre,&bipp, 0);
	registerEnumParam("tremolo.pp","select",post_pre,&trpp, 0);
	registerEnumParam("phaser_mono.pp","select",post_pre,&pmpp, 0);
	registerEnumParam("chorus_mono.pp","select",post_pre,&chpp, 0);
	registerEnumParam("flanger_mono.pp","select",post_pre,&flpp, 0);
	registerEnumParam("feedback.pp","select",post_pre,&ffb, 0);
	registerEnumParam("amp.tonestack.pp","select",post_pre,&fts, 0);
	registerEnumParam("cab.pp","select",post_pre,&fcb, 0);
	
	static const char *crybaby_autowah[] = {N_("manual"),N_("auto"),0};
	registerEnumParam("crybaby.autowah", "select", crybaby_autowah, &fautowah, 0);
	
	
	
	//static const char *eqt_onetwo[] = {"fixed","scale",0};
	//registerEnumParam("eqt.onetwo", "select", eqt_onetwo, &witcheq, 0);
	
	registerNonMidiParam("compressor.position", &posit5, true, 6, 1, 22);
	registerNonMidiParam("crybaby.position", &posit0, true, 3, 1, 22);
	registerNonMidiParam("overdrive.position", &posit1, true, 7, 1, 22);
	registerNonMidiParam("gx_distortion.position", &posit2, true, 4, 1, 22);
	registerNonMidiParam("freeverb.position", &posit3, true, 10, 1, 22);
	registerNonMidiParam("IR.position", &posit4, true, 5, 1, 22);
	registerNonMidiParam("echo.position", &posit6, true, 8, 1, 22);
	registerNonMidiParam("delay.position", &posit7, true, 9, 1, 22);
	registerNonMidiParam("eqs.position", &posit10, true, 2, 1, 22);
	registerNonMidiParam("chorus.position", &posit8, true, 1, 1, 10);
	registerNonMidiParam("flanger.position", &posit9, true, 2, 1, 10);
	registerNonMidiParam("moog.position", &posit11, true, 6, 1, 10);
	registerNonMidiParam("phaser.position", &posit12, true, 3, 1, 10);
	registerNonMidiParam("low_highpass.position", &posit14, true, 1, 1, 22);
	registerNonMidiParam("stereodelay.position", &posit15, true, 4, 1, 10);
	registerNonMidiParam("stereoecho.position", &posit16, true, 5, 1, 10);
	registerNonMidiParam("oscilloscope.position", &posit17, true, 11, 1, 22);
	registerNonMidiParam("biquad.position", &posit18, true, 12, 1, 22);
	registerNonMidiParam("midi_out.position", &posit00, true, 20, 1, 22);
	registerNonMidiParam("ampmodul.position", &posit19, true, 7, 1, 10);
	registerNonMidiParam("tonemodul.position", &posit20, true, 8, 1, 10);
	registerNonMidiParam("tremolo.position", &posit21, true, 13, 1, 22);
	registerNonMidiParam("phaser_mono.position", &posit22, true, 14, 1, 22);
	registerNonMidiParam("chorus_mono.position", &posit23, true, 15, 1, 22);
	registerNonMidiParam("flanger_mono.position", &posit24, true, 16, 1, 22);
	registerNonMidiParam("feedback.position", &posit25, true, 17, 1, 22);
	registerNonMidiParam("amp.tonestack.position", &posit26, true, 18, 1, 22);
	registerNonMidiParam("cab.position", &posit27, true, 19, 1, 22);
	
	
	registerNonMidiParam("system.waveview", &viv, false);
	registerNonMidiParam("midi_out.midistat", &midistat, false);
	registerNonMidiParam("midi_out.midistat1", &midistat1, false);
	registerNonMidiParam("midi_out.midistat2", &midistat2, false);
	registerNonMidiParam("midi_out.midistat3", &midistat3, false);

	// user interface options
	registerNonMidiParam("ui.latency_nowarn", &fwarn, false, 0);
	registerNonMidiParam("ui.skin", &fskin, false, 0, 0, 100);
	
}

AudioVariables audio;

inline float noise_gate(int sf, float* input, float ngate)
{
	float sumnoise = 0;
	for (int i = 0; i < sf; i++) {
		sumnoise += sqrf(fabs(input[i]));
	}
	float noisepulse = sqrtf(sumnoise/sf);
	if (noisepulse > audio.fnglevel * 0.01) {
		return 1; // -75db 0.001 = 65db
	} else if (ngate > 0.01) {
		return ngate * 0.996;
	} else {
		return ngate;
	}
}

inline void run_tonestack(int count, float *output0) {
	switch (audio.tonestack) {
    case 0: //"default"
	    gx_tonestacks::tonestack_default::compute(count, output0, output0);
	    break;
    case 1: //"Bassman"
	    gx_tonestacks::tonestack_bassman::compute(count, output0, output0);
	    break;
    case 2: //"Twin Reverb"
	    gx_tonestacks::tonestack_twin::compute(count, output0, output0);
	    break;
    case 3: //"Princeton"
	    gx_tonestacks::tonestack_princeton::compute(count, output0, output0);
	    break;
    case 4: //"JCM-800"
	    gx_tonestacks::tonestack_jcm800::compute(count, output0, output0);
	    break;
    case 5: //"JCM-2000"
	    gx_tonestacks::tonestack_jcm2000::compute(count, output0, output0);
	    break;
    case 6: //"M-Lead"
	    gx_tonestacks::tonestack_mlead::compute(count, output0, output0);
	    break;
    case 7: //"M2199"
	    gx_tonestacks::tonestack_m2199::compute(count, output0, output0);
	    break;
    case 8: //"AC-30"
	    gx_tonestacks::tonestack_ac30::compute(count, output0, output0);
	    break;
	case 9: //"Mesa"
	    gx_tonestacks::tonestack_mesa::compute(count, output0, output0);
	    break;
	case 10: //"Soldano"
	    gx_tonestacks::tonestack_soldano::compute(count, output0, output0);
	    break;
	case 11: //"jtm45"
	    gx_tonestacks::tonestack_jtm45::compute(count, output0, output0);
	    break;
	case 12: //"ac15"
	    gx_tonestacks::tonestack_ac15::compute(count, output0, output0);
	    break;
	case 13: //"peavey"
	    gx_tonestacks::tonestack_peavey::compute(count, output0, output0);
	    break;
	case 14: //"ibanez"
	    gx_tonestacks::tonestack_ibanez::compute(count, output0, output0);
	    break;
	case 15: //"roland"
	    gx_tonestacks::tonestack_roland::compute(count, output0, output0);
	    break;
	case 16: //"ampeg"
	    gx_tonestacks::tonestack_ampeg::compute(count, output0, output0);
	    break;
    case 17: //"Off"
	    break;
    }
}

inline void compensate_cab(int count, float *input0, float *output0)
{
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * (-audio.cab_level*2.0))));
	static double 	fRec0[2] = {0,0};
	for (int i=0; i<count; i++) {
		fRec0[0] = (fSlow0 + (0.999 * fRec0[1]));
		output0[i] = (FAUSTFLOAT)((double)input0[i] * fRec0[0]);
		// post processing
		fRec0[1] = fRec0[0];
	}
}

void cab_conv_restart()
{
	cab_conv.stop();
	gx_gui::cab_conv_restart();
}

/****************************************************************
 **  this is the process callback called from jack
 **
 ***************************************************************/
void compute_insert (int count, float* input1, float* output0, float* output1)
{
// retrieve engine state
	const GxEngineState estate = checky;

	//------------ determine processing type
	unsigned short process_type = ZEROIZE_BUFFERS;

	if (gx_jack::NO_CONNECTION == 0) { // ports connected
		switch (estate) {
		case kEngineOn:
			process_type = PROCESS_BUFFERS;
			break;

		case kEngineBypass:
			process_type = JUSTCOPY_BUFFERS;
			break;

		default: // engine off or whatever: zeroize
			break;
		}
	}

	//------------ main processing routine
	switch (process_type) {

	case PROCESS_BUFFERS:
		process_insert_buffers(count, input1, output0,output1);
		break;

		// --------- just copy input to outputs
	case JUSTCOPY_BUFFERS:
		if (conv.is_runnable()) {
			conv.checkstate();
		}
	    gx_effects::balance1::compute(count, input1, output0,output1);
        (void)memcpy(get_frame, output0, sizeof(float)*count);
        (void)memcpy(get_frame1, output1, sizeof(float)*count);
		break;

		// ------- zeroize buffers
	case ZEROIZE_BUFFERS:
	default:

		if (conv.is_runnable()) {
			conv.checkstate();
		}

		// no need of loop.

		(void)memset(output0, 0, count*sizeof(float));
		(void)memset(output1, 0, count*sizeof(float));
		break;
	}
}

void compute (int count, float* input, float* output0)
{
	// retrieve engine state
	const GxEngineState estate = checky;

	//------------ determine processing type
	unsigned short process_type = ZEROIZE_BUFFERS;

	if (gx_jack::NO_CONNECTION == 0) { // ports connected
		switch (estate) {
		case kEngineOn:
			process_type = PROCESS_BUFFERS;
			break;

		case kEngineBypass:
			process_type = JUSTCOPY_BUFFERS;
			break;

		default: // engine off or whatever: zeroize
			break;
		}
	}
	if(audio.fmi && !isMidiOn()) turnOnMidi();
	else if(!audio.fmi && isMidiOn()) turnOffMidi();
	
	if(audio.fwv != audio.fwv_on) {
		(void)memset(result, 0, count*sizeof(float));
		audio.fwv_on = audio.fwv;
	}

	//------------ main processing routine
	switch (process_type) {

	case PROCESS_BUFFERS:
		
		process_buffers(count, input, output0);
		break;

		// --------- just copy input to outputs
	case JUSTCOPY_BUFFERS:
		if (conv.is_runnable()) {
			conv.checkstate();
		}
	   // balance1::compute(count, input, output0);
	   (void)memcpy( output0, input, sizeof(float)*count);
		break;


		// ------- zeroize buffers
	case ZEROIZE_BUFFERS:
	default:

		if (conv.is_runnable()) {
			conv.checkstate();
		}
		if(audio.fwv)(void)memset(result, 0, count*sizeof(float));
		// no need of loop.
		
		(void)memset(output0, 0, count*sizeof(float));
  		break;
	}
}

/****************************************************************
 ** this is the gx_head audio engine
 */


void process_buffers(int count, float* input, float* output0)
{
	int tuner_on = gx_gui::shownote + (int)isMidiOn() + 1;
	if (tuner_on > 0) {
		if (gx_gui::shownote == 0) {
			gx_gui::shownote = -1;
		} else {
			pitch_tracker.add(count, input);
			//moving_filter(input, checkfreq, count);
			(void)memcpy(checkfreq, input, sizeof(float)*count);
		}
	}
	
	memcpy(output0, input, count*sizeof(float));
	
	if (audio.fnoise_g) {
		gx_effects::noisegate::ngate = noise_gate(count,output0, gx_effects::noisegate::ngate);
    } else {
		gx_effects::noisegate::ngate = 1;
    }
	
	if (audio.fng) {
	    gx_effects::noise_shaper::compute(count, output0, output0);
    }
	
	for (int m = 1; m < audio.mono_plug_counter; m++) {
	    if (audio.posit0 == m && audio.fcheckbox5 && !audio.fautowah && audio.crybabypp) {
		    gx_effects::crybaby::compute(count, output0, output0);
	    } else if (audio.posit0 == m && audio.fcheckbox5 && audio.fautowah && audio.crybabypp) {
		    gx_effects::autowah::compute(count, output0, output0);
	    } else if (audio.posit5 == m && audio.fcheckboxcom1 && audio.compressorpp) {
		    gx_effects::compressor::compute(count, output0, output0);
	    } else if (audio.posit1 == m && audio.foverdrive4 && audio.overdrivepp) {
		    gx_effects::overdrive::compute(count, output0, output0);
	    } else if (audio.posit2 == m && audio.fcheckbox4 && audio.distortionpp) {
	         gx_effects::gx_distortion::compute(count, output0, output0);
	    } else if (audio.posit3 == m && audio.fcheckbox6 && audio.freeverbpp) {
		    gx_effects::freeverb::compute(count, output0, output0);
	    } else if (audio.posit6 == m && audio.fcheckbox7 && gx_effects::echo::is_inited() && audio.echopp) {
		    gx_effects::echo::compute(count, output0, output0);
	    } else if (audio.posit4 == m && audio.fcheckbox8 && audio.IRpp) {
		    gx_effects::impulseresponse::compute(count, output0, output0);
	    } else if (audio.posit7 == m && audio.fdelay && gx_effects::delay::is_inited() && audio.delaypp) {
		    gx_effects::delay::compute(count, output0, output0);
	    } else if (audio.posit10 == m && audio.feq && audio.eqpp) {
		    gx_effects::selecteq::compute(count, output0, output0);
	    } else if (audio.posit14 == m && audio.flh && audio.lhpp) {
		    gx_effects::low_high_pass::compute(count, output0, output0);
	    } else if (audio.posit17 == m && audio.fwv && audio.wvpp) {
		    (void)memcpy(result, output0, sizeof(float)*count);
	    } else if (audio.posit18 == m && audio.fbiquad && audio.bipp) {
		    gx_effects::biquad::compute(count, output0, output0);
	    } else if (audio.posit21 == m && audio.ftremolo && audio.trpp) {
		    gx_effects::tremolo::compute(count, output0, output0);
	    } else if (audio.posit22 == m && audio.fpm && audio.pmpp) {
		    gx_effects::phaser_mono::compute(count, output0, output0);
	    } else if (audio.posit23 == m && audio.fchorus_mono && audio.chpp && gx_effects::chorus_mono::is_inited()) {
			gx_effects::chorus_mono::compute(count, output0, output0);
		} else if (audio.posit24 == m && audio.fflanger_mono && audio.flpp) {
			gx_effects::flanger_mono::compute(count, output0, output0);
		} else if (audio.posit25 == m && audio.ffeedback && audio.ffb) {
			gx_effects::gx_feedback::compute(count, output0, output0);
		} else if (audio.posit26 == m && audio.ftonestack && audio.fts ) {
			run_tonestack(count, output0);
		} else if (audio.posit27 == m && audio.fcab && audio.fcb) {
			compensate_cab(count,output0 , output0);
			if (!cab_conv.compute(count, output0))
				cout << "overload" << endl;
				//FIXME error message??
			if(audio.cab_switched != audio.cabinet || fabs( audio.cab_sum -(audio.cab_level+audio.cab_bass+audio.cab_treble))<0.01
			|| fabs( audio.cab_sum -(audio.cab_level+audio.cab_bass+audio.cab_treble))>0.01)
			cab_conv_restart();
		}
    }

	switch (audio.gxtube) {
	case 0: //"never"
		gx_amps::gxamp::compute(count, output0, output0);
		break;
	case 1: //"default"
		gx_amps::gxamp::compute(count, output0, output0);
		break;
	case 2: 
		gx_amps::gxamp3::compute(count, output0, output0);
		break;
	case 3: 
		gx_amps::gxamp2::compute(count, output0, output0);
		break;
	case 4: 
		gx_amps::gxamp4::compute(count, output0, output0);
		break;
	case 5: 
		gx_amps::gxamp5::compute(count, output0, output0);
		break;
	case 6: 
		gx_amps::gxamp10::compute(count, output0, output0);
		break;
	case 7: 
		gx_amps::gxamp12::compute(count, output0, output0);
		break;
	}
	
	if (audio.ftube) {
        gx_effects::softclip::compute(count, output0, output0);
    }
    
    for (int m = 1; m < audio.mono_plug_counter; m++) {
	    if (audio.posit0 == m && audio.fcheckbox5 && !audio.fautowah && !audio.crybabypp) {
		    gx_effects::crybaby::compute(count, output0, output0);
	    } else if (audio.posit0 == m && audio.fcheckbox5 && audio.fautowah && !audio.crybabypp) {
		    gx_effects::autowah::compute(count, output0, output0);
	    } else if (audio.posit5 == m && audio.fcheckboxcom1 && !audio.compressorpp) {
		    gx_effects::compressor::compute(count, output0, output0);
	    } else if (audio.posit1 == m && audio.foverdrive4 && !audio.overdrivepp) {
		    gx_effects::overdrive::compute(count, output0, output0);
	    } else if (audio.posit2 == m && audio.fcheckbox4 && !audio.distortionpp) {
	         gx_effects::gx_distortion::compute(count, output0, output0);
	    } else if (audio.posit3 == m && audio.fcheckbox6 && !audio.freeverbpp) {
		    gx_effects::freeverb::compute(count, output0, output0);
	    } else if (audio.posit6 == m && audio.fcheckbox7 && gx_effects::echo::is_inited() && !audio.echopp) {
		    gx_effects::echo::compute(count, output0, output0);
	    } else if (audio.posit4 == m && audio.fcheckbox8 && !audio.IRpp) {
		    gx_effects::impulseresponse::compute(count, output0, output0);
	    } else if (audio.posit7 == m && audio.fdelay && gx_effects::delay::is_inited() && !audio.delaypp) {
		    gx_effects::delay::compute(count, output0, output0);
	    } else if (audio.posit10 == m && audio.feq && !audio.eqpp) {
		    gx_effects::selecteq::compute(count, output0, output0);
	    } else if (audio.posit14 == m && audio.flh && !audio.lhpp) {
		    gx_effects::low_high_pass::compute(count, output0, output0);
	    } else if (audio.posit17 == m && audio.fwv && !audio.wvpp) {
		    (void)memcpy(result, output0, sizeof(float)*count);
	    } else if (audio.posit18 == m && audio.fbiquad && !audio.bipp) {
		    gx_effects::biquad::compute(count, output0, output0);
	    } else if (audio.posit21 == m && audio.ftremolo && !audio.trpp) {
		    gx_effects::tremolo::compute(count, output0, output0);
	    } else if (audio.posit22 == m && audio.fpm && !audio.pmpp) {
		    gx_effects::phaser_mono::compute(count, output0, output0);
	    } else if (audio.posit23 == m && audio.fchorus_mono && !audio.chpp && gx_effects::chorus_mono::is_inited()) {
			gx_effects::chorus_mono::compute(count, output0, output0);
		} else if (audio.posit24 == m && audio.fflanger_mono && !audio.flpp ) {
			gx_effects::flanger_mono::compute(count, output0, output0);
		} else if (audio.posit25 == m && audio.ffeedback && !audio.ffb ) {
			gx_effects::gx_feedback::compute(count, output0, output0);
		} else if (audio.posit26 == m && audio.ftonestack && !audio.fts ) {
			run_tonestack(count, output0);
		} else if (audio.posit27 == m && audio.fcab && !audio.fcb) {
			compensate_cab(count,output0 , output0);
			if (!cab_conv.compute(count, output0))
				cout << "overload" << endl;
				//FIXME error message??
			if(audio.cab_switched != audio.cabinet || audio.cab_sum !=(audio.cab_level+audio.cab_bass+audio.cab_treble))cab_conv_restart();
		}
    }
    
    if (audio.fboost) {
		gx_effects::bassbooster::compute(count, output0, output0);
	}

    if (audio.fampout) {
        gx_effects::gx_ampout::compute(count, output0, output0);
    }
    
    if (audio.fnoise_g) {
		gx_effects::noisegate::compute(count,output0, output0);
    }
    
    if(audio.fcon) {
		if (!contrast_conv.compute(count, output0))
		cout << "overload contrast" << endl;
        //FIXME error message??
    }
}

void process_insert_buffers (int count, float* input1, float* output0, float* output1)
{
	
    memcpy(output0, input1, count*sizeof(float));
    gx_effects::gxfeed::compute(count, output0, output0, output1);
    
    for (int m = 1; m < audio.stereo_plug_counter; m++) {
		if (audio.posit8 == m && audio.fchorus && gx_effects::chorus::is_inited()) {
			gx_effects::chorus::compute(count, output0, output1, output0, output1);
		} else if (audio.posit9 == m && audio.fflanger) {
			gx_effects::flanger::compute(count, output0, output1, output0, output1);
		} else if (audio.posit11 == m && audio.fmoog) {
			gx_effects::moog::compute(count, output0, output1, output0, output1);
		} else if (audio.posit12 == m && audio.fphaser) {
			gx_effects::phaser::compute(count, output0, output1, output0, output1);
		} else if (audio.posit15 == m && audio.fsd && gx_effects::stereodelay::is_inited()) {
			gx_effects::stereodelay::compute(count, output0, output1, output0, output1);
		}else if (audio.posit16 == m && audio.fse && gx_effects::stereoecho::is_inited()) {
			gx_effects::stereoecho::compute(count, output0, output1, output0, output1);
		}else if (audio.posit19 == m && audio.famp ) {
			gx_amps::gx_ampmodul::compute(count, output0, output1, output0, output1);
		}else if (audio.posit20 == m && audio.ftone ) {
			gx_effects::tonecontroll::compute(count, output0, output1, output0, output1);
		}
	}

    if (conv.is_runnable()) {
	    // reuse oversampling buffer
	    float *conv_out0 = oversample;
	    float *conv_out1 = oversample+count;
	    if (!conv.compute(count, output0, output1, conv_out0, conv_out1)) {
		    gx_jconv::GxJConvSettings::checkbutton7 = 0;
		    cout << "overload" << endl;
		    //FIXME error message??
	    } else {
		    gx_effects::jconv_post::compute(count, output0, output1, conv_out0, conv_out1, output0, output1);
	    }
    }
    gx_effects::gx_outputlevel::compute(count, output0, output1, output0, output1);
	(void)memcpy(get_frame, output0, sizeof(float)*count);
	(void)memcpy(get_frame1, output1, sizeof(float)*count);
}

} // namespace gx_engine

