/*
 * Copyright (C) 2013 Andreas Degert
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
 */

#pragma once

#ifndef SRC_HEADERS_MACHINE_H_
#define SRC_HEADERS_MACHINE_H_

#include <ext/stdio_filebuf.h>
#include "jsonrpc_methods.h"

namespace gx_gui { class UiBuilderImpl; }

namespace gx_engine {

class bank_iterator {
private:
    gx_system::PresetBanks::iterator it;
public:
    bank_iterator(gx_system::PresetBanks::iterator it_): it(it_) {}
    ~bank_iterator() {}
    bool operator!=(const bank_iterator& i) const { return i.it != it; }
    bank_iterator& operator++() { ++it; return *this; }
    gx_system::PresetFileGui* operator->() { return (*it)->get_guiwrapper(); }
    gx_system::PresetFileGui* operator*() { return (*it)->get_guiwrapper(); }
};

class GxMachineBase {
private:
    virtual int _get_parameter_value_int(const std::string& id) = 0;
    virtual int _get_parameter_value_bool(const std::string& id) = 0;
    virtual float _get_parameter_value_float(const std::string& id) = 0;
    virtual std::string _get_parameter_value_string(const std::string& id) = 0;
    virtual sigc::signal<void, int>& _signal_parameter_value_int(const std::string& id) = 0;
    virtual sigc::signal<void, bool>& _signal_parameter_value_bool(const std::string& id) = 0;
    virtual sigc::signal<void, float>& _signal_parameter_value_float(const std::string& id) = 0;
protected:
    sigc::signal<void, bool> rack_unit_order_changed;
    GxMachineBase();
public:
    virtual ~GxMachineBase();
    // engine
    virtual void set_state(GxEngineState state) = 0;
    virtual GxEngineState get_state() = 0;
    virtual void init_plugin(PluginDef *p) = 0;
    virtual bool ladspaloader_load(const gx_system::CmdlineOptions& options, LadspaLoader::pluginarray& p) = 0;
    virtual LadspaLoader::pluginarray::iterator ladspaloader_begin() = 0;
    virtual LadspaLoader::pluginarray::iterator ladspaloader_end() = 0;
    virtual void ladspaloader_update_instance(PluginDef *pdef, plugdesc *pdesc) = 0;
    virtual void ladspaloader_update_plugins(
	const std::vector<gx_engine::Plugin*>& to_remove, LadspaLoader::pluginarray& ml,
	std::vector<PluginDef*>& pv) = 0;
    virtual Plugin *pluginlist_lookup_plugin(const char *id) const = 0;
    virtual bool load_unit(gx_gui::UiBuilderImpl& builder, PluginDef* pdef) = 0;
    virtual LadspaLoader::pluginarray::iterator ladspaloader_find(unsigned long uniqueid) = 0;
    virtual void ladspaloader_set_plugins(LadspaLoader::pluginarray& new_plugins) = 0;
    virtual void pluginlist_append_rack(UiBuilderBase& ui) = 0;
    virtual void pluginlist_registerPlugin(Plugin *pl) = 0;
    virtual const std::string& conv_getIRFile(const char *id) = 0;
    virtual float get_tuner_freq() = 0;
    virtual void set_oscilloscope_mul_buffer(int a) = 0;
    virtual int get_oscilloscope_mul_buffer() = 0;
    virtual const float *get_oscilloscope_buffer() = 0;
    virtual void clear_oscilloscope_buffer() = 0;
    virtual bool oscilloscope_plugin_box_visible() = 0;
    virtual sigc::signal<void, int>& signal_oscilloscope_post_pre() = 0;
    virtual sigc::signal<void, bool>& signal_oscilloscope_visible() = 0;
    virtual sigc::signal<int, bool>& signal_oscilloscope_activation() = 0;
    virtual sigc::signal<void, unsigned int>& signal_oscilloscope_size_change() = 0;
    virtual void maxlevel_get(int channels, float *values) = 0;
    virtual bool midiaudiobuffer_get_midistat() = 0;
    virtual MidiAudioBuffer::Load midiaudiobuffer_jack_load_status() = 0;
    virtual void get_oscilloscope_info(int& load, int& frames, bool& is_rt, jack_nframes_t& bsize) = 0;
    virtual gx_system::CmdlineOptions& get_options() const = 0;
    virtual void start_socket(sigc::slot<void> quit_mainloop, int port) = 0;
    virtual sigc::signal<void>& signal_conv_settings_changed(const char *id) = 0;
    virtual sigc::signal<void,const Glib::ustring&,const Glib::ustring&>& tuner_switcher_signal_display() = 0;
    virtual sigc::signal<void,TunerSwitcher::SwitcherState>& tuner_switcher_signal_set_state() = 0;
    virtual sigc::signal<void>& tuner_switcher_signal_selection_done() = 0;
    virtual sigc::signal<void,GxEngineState>& signal_state_change() = 0;
    virtual Glib::Dispatcher& signal_jack_load_change() = 0;
    virtual void tuner_used_for_display(bool on) = 0;
    virtual void tuner_used_for_livedisplay(bool on) = 0;
    virtual const std::vector<std::string>& get_rack_unit_order(bool stereo) = 0;
    sigc::signal<void, bool>& signal_rack_unit_order_changed();
    virtual void remove_rack_unit(const std::string& unit, bool stereo) = 0;
    virtual void insert_rack_unit(const std::string& unit, const std::string& before, bool stereo) = 0;
    // tuner_switcher
    virtual bool get_tuner_switcher_active() = 0;
    virtual void tuner_switcher_activate(bool v) = 0;
    virtual bool tuner_switcher_deactivate() = 0;
    // preset
    virtual bool setting_is_preset() = 0;
    virtual const Glib::ustring& get_current_bank() = 0;
    virtual gx_system::PresetFileGui *get_current_bank_file() = 0;
    virtual const Glib::ustring& get_current_name() = 0;
    virtual gx_system::PresetFileGui* get_bank_file(const Glib::ustring& bank) const = 0;
    virtual Glib::ustring get_bank_name(int n) = 0;
    virtual void load_preset(gx_system::PresetFileGui *pf, const Glib::ustring& name) = 0;
    virtual void loadstate() = 0;
    virtual int bank_size() = 0;
    virtual void create_default_scratch_preset() = 0;
    virtual void set_statefilename(const std::string& fn) = 0;
    virtual void save_to_state(bool preserve_preset=false) = 0;
    virtual Glib::RefPtr<gx_preset::PluginPresetList> load_plugin_preset_list(const Glib::ustring& id, bool factory) const = 0;
    virtual void disable_autosave(bool v) = 0;
    virtual sigc::signal<void>& signal_selection_changed() = 0;
    virtual sigc::signal<void>& signal_presetlist_changed() = 0;
    virtual gx_system::PresetFileGui *bank_insert_uri(const Glib::ustring& uri, bool move) = 0;
    virtual gx_system::PresetFileGui *bank_insert_new(const Glib::ustring& newname) = 0;
    virtual bool rename_bank(const Glib::ustring& oldname, Glib::ustring& newname) = 0;
    virtual bool rename_preset(gx_system::PresetFileGui& pf, const Glib::ustring& oldname, const Glib::ustring& newname) = 0;
    virtual void bank_reorder(const std::vector<Glib::ustring>& neworder) = 0;
    virtual void reorder_preset(gx_system::PresetFileGui& pf, const std::vector<Glib::ustring>& neworder) = 0;
    virtual bool bank_check_reparse() = 0;
    virtual void erase_preset(gx_system::PresetFileGui& pf, const Glib::ustring& name) = 0;
    virtual void bank_set_flag(gx_system::PresetFileGui *pf, int flag, bool v) = 0;
    virtual std::string bank_get_filename(const Glib::ustring& bank) = 0;
    virtual void bank_drag_begin() = 0;
    virtual gx_system::PresetFileGui *bank_get_file(const Glib::ustring& bank) const = 0;
    virtual bank_iterator bank_begin() = 0;
    virtual bank_iterator bank_end() = 0;
    virtual void pf_append(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& name) = 0;
    virtual void pf_insert_before(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name) = 0;
    virtual void pf_insert_after(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name) = 0;
    virtual bool convert_preset(gx_system::PresetFileGui& pf) = 0;
    virtual bool bank_remove(const Glib::ustring& bank) = 0;
    virtual void bank_save() = 0;
    virtual void pf_save(gx_system::PresetFileGui& pf, const Glib::ustring& name) = 0;

    // jack
    virtual gx_jack::GxJack *get_jack() = 0;
    // pmap
    virtual Parameter& get_parameter(const std::string& id) = 0;
    virtual void set_init_values() = 0;
    virtual bool parameter_hasId(const char *p) = 0;
    virtual bool parameter_hasId(const std::string& id) = 0;
    virtual void reset_unit(Glib::ustring group_id) const = 0;
    virtual bool parameter_unit_has_std_values(Glib::ustring group_id) const = 0;
    virtual void set_parameter_value(const std::string& id, int value) = 0;
    virtual void set_parameter_value(const std::string& id, float value) = 0;
    virtual void set_parameter_value(const std::string& id, bool value) = 0;
    virtual void set_parameter_value(const std::string& id, const std::string& value) = 0;
    void set_parameter_value(const std::string& id, double value) { set_parameter_value(id, (float)value); }
    template <class T> T get_parameter_value (const std::string& id);
    template <class T> sigc::signal<void, T>& signal_parameter_value(const std::string& id);
    // MidiControllerList
    virtual bool midi_get_config_mode(int *ctl = 0) = 0;
    virtual void midi_set_config_mode(bool v, int ctl=-1) = 0;
    virtual sigc::signal<void>& signal_midi_changed() = 0;
    virtual sigc::signal<void, int, int>& signal_midi_value_changed() = 0;
    virtual void request_midi_value_update() = 0;
    virtual int midi_size() = 0;
    virtual midi_controller_list& midi_get(int n) = 0;
    virtual void midi_deleteParameter(Parameter& param) = 0;
    virtual void midi_set_current_control(int v) = 0;
    virtual void midi_modifyCurrent(Parameter& param, float lower, float upper, bool toggle) = 0;
    virtual int midi_param2controller(Parameter& param, const MidiController** p) = 0;
    // cheat
    virtual ConvolverMonoAdapter& get_mono_convolver() = 0;
    virtual ConvolverStereoAdapter& get_stereo_convolver() = 0;
};

template <> inline float GxMachineBase::get_parameter_value(const std::string& id) {
    return _get_parameter_value_float(id);
}

template <> inline int GxMachineBase::get_parameter_value(const std::string& id) {
    return _get_parameter_value_int(id);
}

template <> inline bool GxMachineBase::get_parameter_value(const std::string& id) {
    return _get_parameter_value_bool(id);
}

template <> inline std::string GxMachineBase::get_parameter_value(const std::string& id) {
    return _get_parameter_value_string(id);
}

template <> inline sigc::signal<void, float>& GxMachineBase::signal_parameter_value(const std::string& id) {
    return _signal_parameter_value_float(id);
}

template <> inline sigc::signal<void, int>& GxMachineBase::signal_parameter_value(const std::string& id) {
    return _signal_parameter_value_int(id);
}

template <> inline sigc::signal<void, bool>& GxMachineBase::signal_parameter_value(const std::string& id) {
    return _signal_parameter_value_bool(id);
}

class GxMachine: public GxMachineBase {
private:
    gx_system::CmdlineOptions& options;
    GxEngine  engine;
    gx_jack::GxJack       jack;
    gx_preset::GxSettings settings;
    TunerSwitcher tuner_switcher;
    MyService *sock;
    ParamMap& pmap;
private:
    void do_program_change(int pgm);
    virtual int _get_parameter_value_int(const std::string& id);
    virtual int _get_parameter_value_bool(const std::string& id);
    virtual float _get_parameter_value_float(const std::string& id);
    virtual std::string _get_parameter_value_string(const std::string& id);
    virtual sigc::signal<void, int>& _signal_parameter_value_int(const std::string& id);
    virtual sigc::signal<void, bool>& _signal_parameter_value_bool(const std::string& id);
    virtual sigc::signal<void, float>& _signal_parameter_value_float(const std::string& id);
public:
    GxMachine(gx_system::CmdlineOptions& options);
    virtual ~GxMachine();
    virtual void set_state(GxEngineState state);
    virtual GxEngineState get_state();
    virtual void init_plugin(PluginDef *p);
    virtual bool ladspaloader_load(const gx_system::CmdlineOptions& options, LadspaLoader::pluginarray& p);
    virtual LadspaLoader::pluginarray::iterator ladspaloader_begin();
    virtual LadspaLoader::pluginarray::iterator ladspaloader_end();
    virtual void ladspaloader_update_instance(PluginDef *pdef, plugdesc *pdesc);
    virtual void ladspaloader_update_plugins(
	const std::vector<gx_engine::Plugin*>& to_remove, LadspaLoader::pluginarray& ml,
	std::vector<PluginDef*>& pv);
    virtual Plugin *pluginlist_lookup_plugin(const char *id) const;
    virtual bool load_unit(gx_gui::UiBuilderImpl& builder, PluginDef* pdef);
    virtual LadspaLoader::pluginarray::iterator ladspaloader_find(unsigned long uniqueid);
    virtual void ladspaloader_set_plugins(LadspaLoader::pluginarray& new_plugins);
    virtual void pluginlist_append_rack(UiBuilderBase& ui);
    virtual void pluginlist_registerPlugin(Plugin *pl);
    virtual const std::string& conv_getIRFile(const char *id);
    virtual float get_tuner_freq();
    virtual void set_oscilloscope_mul_buffer(int a);
    virtual int get_oscilloscope_mul_buffer();
    virtual const float *get_oscilloscope_buffer();
    virtual void clear_oscilloscope_buffer();
    virtual bool oscilloscope_plugin_box_visible();
    virtual sigc::signal<void, int>& signal_oscilloscope_post_pre();
    virtual sigc::signal<void, bool>& signal_oscilloscope_visible();
    virtual sigc::signal<int, bool>& signal_oscilloscope_activation();
    virtual sigc::signal<void, unsigned int>& signal_oscilloscope_size_change();
    virtual void maxlevel_get(int channels, float *values);
    virtual bool midiaudiobuffer_get_midistat();
    virtual MidiAudioBuffer::Load midiaudiobuffer_jack_load_status();
    virtual void get_oscilloscope_info(int& load, int& frames, bool& is_rt, jack_nframes_t& bsize);
    virtual gx_system::CmdlineOptions& get_options() const;
    virtual void start_socket(sigc::slot<void> quit_mainloop, int port);
    virtual sigc::signal<void>& signal_conv_settings_changed(const char *id);
    virtual sigc::signal<void,const Glib::ustring&,const Glib::ustring&>& tuner_switcher_signal_display();
    virtual sigc::signal<void,TunerSwitcher::SwitcherState>& tuner_switcher_signal_set_state();
    virtual sigc::signal<void>& tuner_switcher_signal_selection_done();
    virtual sigc::signal<void,GxEngineState>& signal_state_change();
    virtual Glib::Dispatcher& signal_jack_load_change();
    virtual void tuner_used_for_display(bool on);
    virtual void tuner_used_for_livedisplay(bool on);
    virtual const std::vector<std::string>& get_rack_unit_order(bool stereo);
    virtual void remove_rack_unit(const std::string& unit, bool stereo);
    virtual void insert_rack_unit(const std::string& unit, const std::string& before, bool stereo);
    // tuner_switcher
    virtual bool get_tuner_switcher_active();
    virtual void tuner_switcher_activate(bool v);
    virtual bool tuner_switcher_deactivate();
    // preset
    virtual bool setting_is_preset();
    virtual const Glib::ustring& get_current_bank();
    virtual gx_system::PresetFileGui *get_current_bank_file();
    virtual const Glib::ustring& get_current_name();
    virtual gx_system::PresetFileGui* get_bank_file(const Glib::ustring& bank) const;
    virtual Glib::ustring get_bank_name(int n);
    virtual void load_preset(gx_system::PresetFileGui *pf, const Glib::ustring& name);
    virtual void loadstate();
    virtual int bank_size();
    virtual void create_default_scratch_preset();
    virtual void set_statefilename(const std::string& fn);
    virtual void save_to_state(bool preserve_preset=false);
    virtual Glib::RefPtr<gx_preset::PluginPresetList> load_plugin_preset_list(const Glib::ustring& id, bool factory) const;
    virtual void disable_autosave(bool v);
    virtual sigc::signal<void>& signal_selection_changed();
    virtual sigc::signal<void>& signal_presetlist_changed();
    virtual gx_system::PresetFileGui *bank_insert_uri(const Glib::ustring& uri, bool move);
    virtual gx_system::PresetFileGui *bank_insert_new(const Glib::ustring& newname);
    virtual bool rename_bank(const Glib::ustring& oldname, Glib::ustring& newname);
    virtual bool rename_preset(gx_system::PresetFileGui& pf, const Glib::ustring& oldname, const Glib::ustring& newname);
    virtual void bank_reorder(const std::vector<Glib::ustring>& neworder);
    virtual void reorder_preset(gx_system::PresetFileGui& pf, const std::vector<Glib::ustring>& neworder);
    virtual bool bank_check_reparse();
    virtual void erase_preset(gx_system::PresetFileGui& pf, const Glib::ustring& name);
    virtual void bank_set_flag(gx_system::PresetFileGui *pf, int flag, bool v);
    virtual std::string bank_get_filename(const Glib::ustring& bank);
    virtual void bank_drag_begin();
    virtual gx_system::PresetFileGui *bank_get_file(const Glib::ustring& bank) const;
    virtual bank_iterator bank_begin();
    virtual bank_iterator bank_end();
    virtual void pf_append(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& name);
    virtual void pf_insert_before(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name);
    virtual void pf_insert_after(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name);
    virtual bool convert_preset(gx_system::PresetFileGui& pf);
    virtual bool bank_remove(const Glib::ustring& bank);
    virtual void bank_save();
    virtual void pf_save(gx_system::PresetFileGui& pf, const Glib::ustring& name);

    // jack
    virtual gx_jack::GxJack *get_jack();
    // pmap
    virtual Parameter& get_parameter(const char *p);
    virtual Parameter& get_parameter(const std::string& id);
    virtual void set_init_values();
    virtual bool parameter_hasId(const char *p);
    virtual bool parameter_hasId(const std::string& id);
    virtual void reset_unit(Glib::ustring group_id) const;
    virtual bool parameter_unit_has_std_values(Glib::ustring group_id) const;
    virtual void set_parameter_value(const std::string& id, int value);
    virtual void set_parameter_value(const std::string& id, bool value);
    virtual void set_parameter_value(const std::string& id, float value);
    virtual void set_parameter_value(const std::string& id, const std::string& value);

    // MidiControllerList
    virtual bool midi_get_config_mode(int *ctl = 0);
    virtual void midi_set_config_mode(bool v, int ctl=-1);
    virtual sigc::signal<void>& signal_midi_changed();
    virtual sigc::signal<void, int, int>& signal_midi_value_changed();
    virtual void request_midi_value_update();
    virtual int midi_size();
    virtual midi_controller_list& midi_get(int n);
    virtual void midi_deleteParameter(Parameter& param);
    virtual void midi_set_current_control(int v);
    virtual void midi_modifyCurrent(Parameter& param, float lower, float upper, bool toggle);
    virtual int midi_param2controller(Parameter& param, const MidiController** p);
    // cheat
    virtual ConvolverMonoAdapter& get_mono_convolver();
    virtual ConvolverStereoAdapter& get_stereo_convolver();
};

class GxMachineRemote: public GxMachineBase {
private:
    gx_system::CmdlineOptions& options;
    ParamMap  pmap;
    PluginListBase pluginlist;
    gx_system::PresetBanks banks;
    sigc::signal<void,GxEngineState> engine_state_change;
    sigc::signal<void> selection_changed;
    sigc::signal<void> presetlist_changed;
    Glib::RefPtr<Gio::Socket> socket;
    __gnu_cxx::stdio_filebuf<char> *writebuf;
    ostream *os;
    gx_system::JsonWriter *jw;
    std::vector<gx_system::JsonStringParser*> notify_list;
    sigc::connection idle_conn;
    gx_preset::UnitRacks rack_units;
    sigc::signal<void> midi_changed;
    sigc::signal<void, int, int> midi_value_changed;
    ControllerArray midi_controller_map;
    Glib::ustring current_bank;
    Glib::ustring current_preset;
    int bank_drag_get_counter;
    std::string bank_drag_get_path;
    sigc::signal<int, bool> oscilloscope_activation;
    sigc::signal<void, unsigned int> oscilloscope_size_change;
    float *oscilloscope_buffer;
    unsigned int oscilloscope_buffer_size;

private:
    const jsonrpc_method_def& start_call(jsonrpc_method m_id);
    void send();
    gx_system::JsonStringParser *receive(bool verbose=false);
    bool get_bool(gx_system::JsonStringParser *jp);
    bool socket_input_handler(Glib::IOCondition cond);
    void add_idle_handler();
    bool idle_notify_handler();
    void handle_notify(gx_system::JsonStringParser *jp);
    void parameter_changed(gx_system::JsonStringParser *jp);
    static int load_remote_ui_static(const UiBuilder& builder);
    int load_remote_ui(const UiBuilder& builder);
    void report_rpc_error(gx_system::JsonStringParser *jp,
			  const gx_system::JsonException& e, const char *method=0);
    void throw_error(gx_system::JsonStringParser *jp);
    void param_signal_int(int v, IntParameter *p);
    void param_signal_bool(bool v, BoolParameter *p);
    void param_signal_float(float v, FloatParameter *p);
    void param_signal_string(const Glib::ustring& v, StringParameter *p);
    virtual int _get_parameter_value_int(const std::string& id);
    virtual int _get_parameter_value_bool(const std::string& id);
    virtual float _get_parameter_value_float(const std::string& id);
    virtual std::string _get_parameter_value_string(const std::string& id);
    virtual sigc::signal<void, int>& _signal_parameter_value_int(const std::string& id);
    virtual sigc::signal<void, bool>& _signal_parameter_value_bool(const std::string& id);
    virtual sigc::signal<void, float>& _signal_parameter_value_float(const std::string& id);

public:
    GxMachineRemote(gx_system::CmdlineOptions& options);
    virtual ~GxMachineRemote();
    virtual void set_state(GxEngineState state);
    virtual GxEngineState get_state();
    virtual void init_plugin(PluginDef *p);
    virtual bool ladspaloader_load(const gx_system::CmdlineOptions& options, LadspaLoader::pluginarray& p);
    virtual LadspaLoader::pluginarray::iterator ladspaloader_begin();
    virtual LadspaLoader::pluginarray::iterator ladspaloader_end();
    virtual void ladspaloader_update_instance(PluginDef *pdef, plugdesc *pdesc);
    virtual void ladspaloader_update_plugins(
	const std::vector<gx_engine::Plugin*>& to_remove, LadspaLoader::pluginarray& ml,
	std::vector<PluginDef*>& pv);
    virtual Plugin *pluginlist_lookup_plugin(const char *id) const;
    virtual bool load_unit(gx_gui::UiBuilderImpl& builder, PluginDef* pdef);
    virtual LadspaLoader::pluginarray::iterator ladspaloader_find(unsigned long uniqueid);
    virtual void ladspaloader_set_plugins(LadspaLoader::pluginarray& new_plugins);
    virtual void pluginlist_append_rack(UiBuilderBase& ui);
    virtual void pluginlist_registerPlugin(Plugin *pl);
    virtual const std::string& conv_getIRFile(const char *id);
    virtual float get_tuner_freq();
    virtual void set_oscilloscope_mul_buffer(int a);
    virtual int get_oscilloscope_mul_buffer();
    virtual const float *get_oscilloscope_buffer();
    virtual void clear_oscilloscope_buffer();
    virtual bool oscilloscope_plugin_box_visible();
    virtual sigc::signal<void, int>& signal_oscilloscope_post_pre();
    virtual sigc::signal<void, bool>& signal_oscilloscope_visible();
    virtual sigc::signal<int, bool>& signal_oscilloscope_activation();
    virtual sigc::signal<void, unsigned int>& signal_oscilloscope_size_change();
    virtual void maxlevel_get(int channels, float *values);
    virtual bool midiaudiobuffer_get_midistat();
    virtual MidiAudioBuffer::Load midiaudiobuffer_jack_load_status();
    virtual void get_oscilloscope_info(int& load, int& frames, bool& is_rt, jack_nframes_t& bsize);
    virtual gx_system::CmdlineOptions& get_options() const;
    virtual void start_socket(sigc::slot<void> quit_mainloop, int port);
    virtual sigc::signal<void>& signal_conv_settings_changed(const char *id);
    virtual sigc::signal<void,const Glib::ustring&,const Glib::ustring&>& tuner_switcher_signal_display();
    virtual sigc::signal<void,TunerSwitcher::SwitcherState>& tuner_switcher_signal_set_state();
    virtual sigc::signal<void>& tuner_switcher_signal_selection_done();
    virtual sigc::signal<void,GxEngineState>& signal_state_change();
    virtual Glib::Dispatcher& signal_jack_load_change();
    virtual void tuner_used_for_display(bool on);
    virtual void tuner_used_for_livedisplay(bool on);
    virtual const std::vector<std::string>& get_rack_unit_order(bool stereo);
    virtual void remove_rack_unit(const std::string& unit, bool stereo);
    virtual void insert_rack_unit(const std::string& unit, const std::string& before, bool stereo);
    // tuner_switcher
    virtual bool get_tuner_switcher_active();
    virtual void tuner_switcher_activate(bool v);
    virtual bool tuner_switcher_deactivate();
    // preset
    virtual bool setting_is_preset();
    virtual const Glib::ustring& get_current_bank();
    virtual gx_system::PresetFileGui *get_current_bank_file();
    virtual const Glib::ustring& get_current_name();
    virtual gx_system::PresetFileGui* get_bank_file(const Glib::ustring& bank) const;
    virtual Glib::ustring get_bank_name(int n);
    virtual void load_preset(gx_system::PresetFileGui *pf, const Glib::ustring& name);
    virtual void loadstate();
    virtual int bank_size();
    virtual void create_default_scratch_preset();
    virtual void set_statefilename(const std::string& fn);
    virtual void save_to_state(bool preserve_preset=false);
    virtual Glib::RefPtr<gx_preset::PluginPresetList> load_plugin_preset_list(const Glib::ustring& id, bool factory) const;
    virtual void disable_autosave(bool v);
    virtual sigc::signal<void>& signal_selection_changed();
    virtual sigc::signal<void>& signal_presetlist_changed();
    virtual gx_system::PresetFileGui *bank_insert_uri(const Glib::ustring& uri, bool move);
    virtual gx_system::PresetFileGui *bank_insert_new(const Glib::ustring& newname);
    virtual bool rename_bank(const Glib::ustring& oldname, Glib::ustring& newname);
    virtual bool rename_preset(gx_system::PresetFileGui& pf, const Glib::ustring& oldname, const Glib::ustring& newname);
    virtual void bank_reorder(const std::vector<Glib::ustring>& neworder);
    virtual void reorder_preset(gx_system::PresetFileGui& pf, const std::vector<Glib::ustring>& neworder);
    virtual bool bank_check_reparse();
    virtual void erase_preset(gx_system::PresetFileGui& pf, const Glib::ustring& name);
    virtual void bank_set_flag(gx_system::PresetFileGui *pf, int flag, bool v);
    virtual std::string bank_get_filename(const Glib::ustring& bank);
    virtual void bank_drag_begin();
    virtual gx_system::PresetFileGui *bank_get_file(const Glib::ustring& bank) const;
    virtual bank_iterator bank_begin();
    virtual bank_iterator bank_end();
    virtual void pf_append(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& name);
    virtual void pf_insert_before(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name);
    virtual void pf_insert_after(gx_system::PresetFileGui& pf, const Glib::ustring& src, gx_system::PresetFileGui& pftgt, const Glib::ustring& pos, const Glib::ustring& name);
    virtual bool convert_preset(gx_system::PresetFileGui& pf);
    virtual bool bank_remove(const Glib::ustring& bank);
    virtual void bank_save();
    virtual void pf_save(gx_system::PresetFileGui& pf, const Glib::ustring& name);

    // jack
    virtual gx_jack::GxJack *get_jack();
    // pmap
    virtual Parameter& get_parameter(const char *p);
    virtual Parameter& get_parameter(const std::string& id);
    virtual void set_init_values();
    virtual bool parameter_hasId(const char *p);
    virtual bool parameter_hasId(const std::string& id);
    virtual void reset_unit(Glib::ustring group_id) const;
    virtual bool parameter_unit_has_std_values(Glib::ustring group_id) const;
    virtual void set_parameter_value(const std::string& id, int value);
    virtual void set_parameter_value(const std::string& id, bool value);
    virtual void set_parameter_value(const std::string& id, float value);
    virtual void set_parameter_value(const std::string& id, const std::string& value);

    // MidiControllerList
    virtual bool midi_get_config_mode(int *ctl = 0);
    virtual void midi_set_config_mode(bool v, int ctl=-1);
    virtual sigc::signal<void>& signal_midi_changed();
    virtual sigc::signal<void, int, int>& signal_midi_value_changed();
    virtual void request_midi_value_update();
    virtual int midi_size();
    virtual midi_controller_list& midi_get(int n);
    virtual void midi_deleteParameter(Parameter& param);
    virtual void midi_set_current_control(int v);
    virtual void midi_modifyCurrent(Parameter& param, float lower, float upper, bool toggle);
    virtual int midi_param2controller(Parameter& param, const MidiController** p);
    // cheat
    virtual ConvolverMonoAdapter& get_mono_convolver();
    virtual ConvolverStereoAdapter& get_stereo_convolver();
};

} // namespace gx_engine

#endif  // SRC_HEADERS_MACHINE_H_
