/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
 * Copyright (C) 2011 Pete Shorthose
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
 * ---------------------------------------------------------------------------
 *
 *    This file is part of the gx_head GUI main class
 *
 * ----------------------------------------------------------------------------
 */
 
#include <iomanip>
#include <cstring>
#include <gdk/gdkkeysyms.h>
#include "guitarix.h"

#include <glibmm/i18n.h>

namespace gx_gui
{

/****************************************************************
 ** predefined gtkmm widget classes used in main GUI
 */

void ToggleCheckButton::on_my_toggled()
{
	param->set(get_active());
}

SwitchParameter* ToggleCheckButton::get_parameter()
{
	return param;
}

void ToggleCheckButton::set_parameter(SwitchParameter *p)
{
	param = p;
	p->changed.connect(sigc::mem_fun(*this, &ToggleCheckButton::set_active));
	signal_toggled().connect(
		sigc::mem_fun(*this, &ToggleCheckButton::on_my_toggled));
}

ToggleCheckButton::~ToggleCheckButton()
{
}

ToggleCheckButton::ToggleCheckButton() 
{
	set_name("barbutton");
	Pango::FontDescription font = m_label.get_style()->get_font();
	font.set_size(8*Pango::SCALE);
	font.set_weight(Pango::WEIGHT_BOLD);
	m_label.modify_font(font);
	m_label.set_name("barbuttonlabel");
	add(m_label);
}
/****************************************************************/

GxTBox::~GxTBox()
{
}

GxTBox::GxTBox(gx_ui::GxUI& ui)
{
}
/****************************************************************/

GxVBox::~GxVBox()
{
}

GxVBox::GxVBox(gx_ui::GxUI& ui)
{
}
/****************************************************************/

GxHBox::~GxHBox()
{
}

GxHBox::GxHBox(gx_ui::GxUI& ui)
{
}
/****************************************************************/

GxFixedBox::~GxFixedBox()
{
}

GxFixedBox::GxFixedBox(gx_ui::GxUI& ui)
{
	m_fixed.put(m_box,0,0);
}
/****************************************************************/

GxPaintBox::~GxPaintBox()
{
}

GxPaintBox::GxPaintBox(gx_ui::GxUI& ui,const char *expose_funk):
	m_box(false, 0)
{
	m_paintbox.property_paint_func() = expose_funk;
	m_paintbox.add(m_box);
}
/****************************************************************/

GxEventBox::~GxEventBox()
{
}

GxEventBox::GxEventBox(gx_ui::GxUI& ui)
{
	
	m_eventbox.add(m_box);
	m_fixedbox.add(m_eventbox);
	m_hbox.add(m_pbox);
	m_hbox.pack_start(m_fbox,false,false);
	m_fbox.pack_start(m_fixedbox,false,false);
	m_hbox.add(m_tbox);
}
/****************************************************************/

GxMainBox::~GxMainBox()
{
}

GxMainBox::GxMainBox(gx_ui::GxUI& ui,const char *expose_funk)
{
	m_paintbox.add(m_box);
	m_eventbox.add(m_paintbox);
	m_paintbox.property_paint_func() = expose_funk;
	m_fixedbox.put(m_eventbox,0,0);
}
/****************************************************************/

GxMidiBox::~GxMidiBox()
{
	delete unit_on_off;
}

GxMidiBox::GxMidiBox(gx_ui::GxUI& ui,const char *expose_funk):
unit_on_off( UiSwitch::new_switch(ui, sw_led, "midi_out.on_off"))
{
	m_bbox.pack_start(m_tcb,true,true);
	m_bbox.pack_end(*unit_on_off,false,false);
	m_paintbox.property_paint_func() = expose_funk;
	m_eventbox.add(m_paintbox);
	m_paintbox.add(m_box);
	m_eventbox.set_border_width(0);
	m_eventbox.set_name("black_box");
	m_box.set_homogeneous(false);
	m_box.set_spacing(0);
	m_box.set_border_width(4);
	m_box.pack_end(m_fixedbox,false, false, 0 );
	m_fixedbox.set_size_request ( 25, -1);
}
/****************************************************************/

GxNotebookBox::~GxNotebookBox()
{
}

GxNotebookBox::GxNotebookBox(gx_ui::GxUI& ui)
{
	m_box.set_name("tab_rack");
}
/****************************************************************/

GxMoveBox::~GxMoveBox()
{
}

GxMoveBox::GxMoveBox(gx_ui::GxUI& ui)
{
	m_paintbox.property_paint_func() = "rectangle_skin_color_expose";
	m_label.set_text("▼");
	m_label.set_name ("rack_slider");
	m_label1.set_text("▲");
	m_label1.set_name ("rack_slider");
	m_button.add(m_label);
	m_button.set_size_request (20, 15);
	m_button.set_name ("effect_reset");
	m_button1.add(m_label1);
	m_button1.set_size_request (20, 15);
	m_button1.set_name ("effect_reset");
	GtkStyle *style = gtk_widget_get_style(GTK_WIDGET(m_label.gobj()));
	pango_font_description_set_size(style->font_desc, 6*PANGO_SCALE);
	pango_font_description_set_weight(style->font_desc, PANGO_WEIGHT_BOLD);
	gtk_widget_modify_font(GTK_WIDGET(m_label.gobj()), style->font_desc);
	gtk_widget_modify_font(GTK_WIDGET(m_label1.gobj()), style->font_desc);
	m_fixed.set_size_request (25, -1);
	m_fixed.put(m_button1, 2, 5);
	m_fixed.put(m_button, 2, 20);
	m_paintbox.pack_end(m_fixed,false, false, 0 );
	m_fixed.show_all();
	m_paintbox.set_border_width (4);
	m_paintbox.property_spacing() = 0;
	m_paintbox.property_homogeneous() = false;
}

/****************************************************************/


GxDialogButtonBox::GxDialogButtonBox(gx_ui::GxUI& ui, Parameter& param_dialog):
	box(false, 0),
	show_dialog(ui, sw_button, param_dialog.getBool())
{
	box.set_border_width(0);
	box.show_all();
}


/****************************************************************/

void GxDialogWindowBox::on_dialog_button_toggled()
{
	if (dialog_button.get_active()){
		const gchar * title = gtk_widget_get_name(GTK_WIDGET(paintbox.gobj()));
		string p = "ui.";
		p +=title;
		string group = group_id;
		group += ".on_off";
		parameter_map[p].set_std_value();
		parameter_map[group].set_std_value();
		dialog_button.set_active(false);
	}
}

void GxDialogWindowBox::on_dialog_menu_activate()
{
	gx_show_extended_settings(GTK_WIDGET(menuitem.gobj()), (gpointer)paintbox.gobj());

	if (!menuitem.get_active()){
		string group = group_id;
		group += ".on_off";
		parameter_map[group].set_std_value();
	}
}

void GxDialogWindowBox::on_reset_button_pressed()
{
	gx_reset_units(group_id);
}

GxDialogWindowBox::~GxDialogWindowBox()
{
	delete unit_on_off;
}

GxDialogWindowBox::GxDialogWindowBox(gx_ui::GxUI& ui,const char *expose_funk, Parameter& param_dialog,
                                     Parameter& param_switch, Gtk::ToggleButton& button,GtkWidget * Caller):
	box(false, 0),
	unit_on_off( UiSwitch::new_switch(ui, sw_led, param_switch)),
	dialog_button(button),
	m_regler_tooltip_window(Gtk::WINDOW_POPUP)
{
	group_id = param_dialog.id().substr(0, param_dialog.id().find_last_of(".")).c_str();
	Glib::ustring title = param_dialog.group();
	box1.pack_end(*unit_on_off,false,false);
	box.set_border_width(2);
	box4.set_spacing(2);
	box4.set_border_width(2);
	box5.set_border_width(4);
	box6.set_border_width(4);
	paintbox.property_paint_func() = expose_funk;
	paintbox.set_name(title);
	reset_button.set_name("effect_reset");
	reset_button1.set_name("effect_reset");
	box5.add(reset_button);
	box6.add(reset_button1);
	box5.set_size_request(15,-1); 
	box6.set_size_request(15,-1); 
	reset_button.signal_pressed().connect(
		sigc::mem_fun(*this, &GxDialogWindowBox::on_reset_button_pressed));
	reset_button1.signal_pressed().connect(
		sigc::mem_fun(*this, &GxDialogWindowBox::on_reset_button_pressed));
	reset_button.set_tooltip_text(_("Reset Button, press to reset settings"));
	reset_button1.set_tooltip_text(_("Reset Button, press to reset settings"));
	box4.pack_start(box6,false,false,0);
	box4.pack_start(box,true,true,0);	
	box4.pack_end(box5,false,false,0);
	paintbox.add(box4);
	paintbox.set_tooltip_text(_(title.c_str()));
	m_tcb.m_label.set_text(_(title.c_str()));
	dialog_button.signal_toggled().connect(
		sigc::mem_fun(*this, &GxDialogWindowBox::on_dialog_button_toggled));
	menuitem.signal_activate().connect(
		sigc::mem_fun(*this, &GxDialogWindowBox::on_dialog_menu_activate));
}

/****************************************************************/

bool GxWindowBox::on_window_delete_event(GdkEventAny*, gpointer d)
{
	gtk_check_menu_item_set_active(
				GTK_CHECK_MENU_ITEM(GTK_WIDGET(d)), FALSE
				);
	return false;
}

bool GxWindowBox::on_button_pressed(GdkEventButton* event)
{
	//fprintf(stderr, "butto pressed\n" );
	if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) ){
		const gchar * title = gtk_widget_get_name(GTK_WIDGET(window.gobj()));
		if(strcmp(title,"MonoRack")==0) {
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_mono_rack),NULL,NULL,NULL,(gpointer) gw.menu_mono_rack,2,tim);
		return true;
		}
		else if (strcmp(title,"StereoRack")==0){
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_stereo_rack),NULL,NULL,NULL,(gpointer) gw.menu_stereo_rack,2,tim);
		return true;
		}
	}

	return false;
}

GxWindowBox::GxWindowBox(gx_ui::GxUI& ui, 
	Glib::ustring titl,GtkWidget * d):
	window(Gtk::WINDOW_TOPLEVEL),
	rbox(false, 0),
	m_regler_tooltip_window(Gtk::WINDOW_POPUP)
{
	Glib::ustring title = titl;
	window.add_events(Gdk::BUTTON_PRESS_MASK);
	window.signal_delete_event().connect(
		 sigc::bind<gpointer>(sigc::mem_fun(*this, &GxWindowBox::on_window_delete_event),d));
	window.add(box);
	window.signal_button_press_event().connect(
		sigc::mem_fun(*this, &GxWindowBox::on_button_pressed));
	box.show();
	rbox.show();
}

/****************************************************************/

bool GxScrollBox::on_window_delete_event(GdkEventAny*, gpointer d)
{
	gtk_check_menu_item_set_active(
				GTK_CHECK_MENU_ITEM(GTK_WIDGET(d)), FALSE
				);
	return false;
}

bool GxScrollBox::on_button_pressed(GdkEventButton* event)
{
	//fprintf(stderr, "butto pressed\n" );
	if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) ){
		const gchar * title = gtk_widget_get_name(GTK_WIDGET(window.gobj()));
		if(strcmp(title,"MonoRack")==0) {
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_mono_rack),NULL,NULL,NULL,(gpointer) gw.menu_mono_rack,2,tim);
		return true;
		}
		else if (strcmp(title,"StereoRack")==0){
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_stereo_rack),NULL,NULL,NULL,(gpointer) gw.menu_stereo_rack,2,tim);
		return true;
		}
	}

	return false;
}

void GxScrollBox::on_rack_reorder_horizontal()
{
	if (fOrderhRack.get_active()) { //horizontal
		
		if(gx_gui::gw.srack_widget) {
			paintbox1.hide();
			gx_gui::GxMainInterface* gui = gx_gui::GxMainInterface::instance();
			if(gtk_window_get_resizable(GTK_WINDOW (gw.fWindow)))
				gtk_window_set_resizable(GTK_WINDOW (gw.fWindow) , FALSE);
			gtk_widget_ref(gx_gui::gw.srack_widget);
			GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(gx_gui::gw.srack_widget));
			gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.srack_widget);
			gtk_box_pack_start(GTK_BOX(box1.gobj()), gx_gui::gw.srack_widget, false, true, 0);
			gtk_widget_unref(gx_gui::gw.srack_widget);
			if (gui->fShowSRack.get_active()) m_scrolled_window2.show();
			paintbox1.show();
			parent = gtk_widget_get_parent(GTK_WIDGET(gx_gui::gw.rack_tool_bar));
			
			if (strcmp(gtk_widget_get_name(parent),"gtkmm__GtkVBox")==0) {
				gtk_widget_ref(gx_gui::gw.rack_tool_bar);
				gtk_widget_ref(gx_gui::gw.tuner_widget);
				gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.rack_tool_bar);
				gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.tuner_widget);
				parent = gtk_widget_get_parent(GTK_WIDGET(parent));
				GList*   child_list =  gtk_container_get_children(GTK_CONTAINER(parent));
				parent = (GtkWidget *) g_list_nth_data(child_list,1);
				child_list =  gtk_container_get_children(GTK_CONTAINER(parent));
				parent = (GtkWidget *) g_list_nth_data(child_list,0);
				child_list =  gtk_container_get_children(GTK_CONTAINER(parent));
				parent = (GtkWidget *) g_list_nth_data(child_list,2);
				gtk_container_add(GTK_CONTAINER(parent), gx_gui::gw.tuner_widget);
				parent = (GtkWidget *) g_list_nth_data(child_list,0);
				gtk_container_add(GTK_CONTAINER(parent), gx_gui::gw.rack_tool_bar);
				gtk_widget_unref(gx_gui::gw.rack_tool_bar);
				gtk_widget_unref(gx_gui::gw.tuner_widget);
				g_list_free(child_list);
			}
			
			gtk_widget_set_size_request (GTK_WIDGET (gui->RBox),-1, 460 );
			if (g_threads[7] == 0 || g_main_context_find_source_by_id(NULL, g_threads[7]) == NULL)
				g_threads[7] = g_timeout_add_full(G_PRIORITY_HIGH_IDLE + 10, 40, gx_gui::gx_set_resizeable,gpointer(gw.fWindow),NULL);
			if (g_threads[6] == 0 || g_main_context_find_source_by_id(NULL, g_threads[6]) == NULL)
				g_threads[6] = g_timeout_add_full(G_PRIORITY_HIGH_IDLE + 10, 50, gx_gui::gx_set_default,gpointer(gui->RBox),NULL);
		}
	}
}

void GxScrollBox::on_rack_reorder_vertical()
{
	if (fOrdervRack.get_active()) { //vertical
		
		if(gx_gui::gw.srack_widget) {
			paintbox1.hide();
			gx_gui::GxMainInterface* gui = gx_gui::GxMainInterface::instance();
			if(gtk_window_get_resizable(GTK_WINDOW (gw.fWindow)))
				gtk_window_set_resizable(GTK_WINDOW (gw.fWindow) , FALSE);
			gtk_widget_ref(gx_gui::gw.srack_widget);
			GtkWidget *parent = gtk_widget_get_parent(GTK_WIDGET(gx_gui::gw.srack_widget));
			gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.srack_widget);
			gtk_box_pack_start(GTK_BOX(rbox.gobj()), gx_gui::gw.srack_widget, false, true, 0);
			gtk_widget_unref(gx_gui::gw.srack_widget);
			m_scrolled_window2.hide();
			paintbox1.show();
			parent = gtk_widget_get_parent(GTK_WIDGET(gx_gui::gw.rack_tool_bar));
			
			if (strcmp(gtk_widget_get_name(parent),"gtkmm__GtkHBox")==0) {
				gtk_widget_ref(gx_gui::gw.rack_tool_bar);
				gtk_widget_ref(gx_gui::gw.tuner_widget);
				gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.rack_tool_bar);
				parent = gtk_widget_get_parent(GTK_WIDGET(gx_gui::gw.tuner_widget));
				gtk_container_remove(GTK_CONTAINER(parent), gx_gui::gw.tuner_widget);
				parent = gtk_widget_get_parent(GTK_WIDGET(parent));
				parent = gtk_widget_get_parent(GTK_WIDGET(parent));
				parent = gtk_widget_get_parent(GTK_WIDGET(parent));
				GList*   child_list =  gtk_container_get_children(GTK_CONTAINER(parent));
				parent = (GtkWidget *) g_list_nth_data(child_list,0);
				gtk_container_add(GTK_CONTAINER(parent), gx_gui::gw.rack_tool_bar);
				gtk_container_add(GTK_CONTAINER(parent), gx_gui::gw.tuner_widget);
				gtk_widget_unref(gx_gui::gw.rack_tool_bar);
				gtk_widget_unref(gx_gui::gw.tuner_widget);
				g_list_free(child_list);
			}
			
			gtk_widget_set_size_request (GTK_WIDGET (gui->RBox),-1, 460 );
			if (g_threads[7] == 0 || g_main_context_find_source_by_id(NULL, g_threads[7]) == NULL)
				g_threads[7] = g_timeout_add_full(G_PRIORITY_HIGH_IDLE + 10, 40, gx_gui::gx_set_resizeable,gpointer(gw.fWindow),NULL);
			if (g_threads[6] == 0 || g_main_context_find_source_by_id(NULL, g_threads[6]) == NULL)
				g_threads[6] = g_timeout_add_full(G_PRIORITY_HIGH_IDLE + 10, 50, gx_gui::gx_set_default,gpointer(gui->RBox),NULL);
		}
	} 
}

GxScrollBox::GxScrollBox(gx_ui::GxUI& ui, 
	const char *pb_2, Glib::ustring titl,GtkWidget * d):
	window(Gtk::WINDOW_TOPLEVEL),
	rbox(false, 4)
{
	Glib::ustring title = titl;
	window.add_events(Gdk::BUTTON_PRESS_MASK);
	m_scrolled_window.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_ALWAYS); 
	m_scrolled_window.set_shadow_type(Gtk::SHADOW_NONE);
	m_scrolled_window2.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_ALWAYS); 
	m_scrolled_window2.set_shadow_type(Gtk::SHADOW_NONE);
	m_scrolled_window2.set_name("HorizontalStereoBox");
	rbox.set_name("MonoBox");
	box1.set_name("SereoBox");
	paintbox1.set_border_width(18);
	paintbox1.property_paint_func() = pb_2;
	window.signal_delete_event().connect(
		 sigc::bind<gpointer>(sigc::mem_fun(*this, &GxScrollBox::on_window_delete_event),d));
	paintbox1.add(m_scrolled_window);
	paintbox1.add(m_scrolled_window2);
	m_scrolled_window.add(box);
	m_scrolled_window2.add(vbox);
	window.add(paintbox1);
	window.signal_button_press_event().connect(
		sigc::mem_fun(*this, &GxScrollBox::on_button_pressed));
	fOrderhRack.signal_activate().connect(
		sigc::mem_fun(*this, &GxScrollBox::on_rack_reorder_horizontal));
	fOrdervRack.signal_activate().connect(
		sigc::mem_fun(*this, &GxScrollBox::on_rack_reorder_vertical));
		
	const gchar * mtitle = "Order Rack Vertically";
	set_label(fOrdervRack, _(mtitle));
	group = fOrdervRack.get_group();
	gx_gui::GxMainInterface* gui = gx_gui::GxMainInterface::instance();
	gtk_menu_shell_append(GTK_MENU_SHELL(gui->getMenu("PluginMenu")), GTK_WIDGET(fOrdervRack.gobj()));
	fOrdervRack.set_parameter(new SwitchParameter("system.order_rack_v",true,false));
	fOrdervRack.show();
	
	mtitle = "Order Rack Horizontally";
	set_label(fOrderhRack, _(mtitle));
	fOrderhRack.set_group(group);
	gtk_menu_shell_append(GTK_MENU_SHELL(gui->getMenu("PluginMenu")), GTK_WIDGET(fOrderhRack.gobj()));
	fOrderhRack.set_active(false);
	fOrderhRack.set_parameter(new SwitchParameter("system.order_rack_h",true,false));
	fOrderhRack.show();
	
	paintbox1.show();
	box.show();
	m_scrolled_window.show();
	//m_scrolled_window2.show();
	rbox.show();
}

/****************************************************************/

bool GxToolBox::on_window_delete_event(GdkEventAny*, gpointer d)
{
	gtk_check_menu_item_set_active(
				GTK_CHECK_MENU_ITEM(GTK_WIDGET(d)), FALSE
				);
	return false;
}

bool GxToolBox::on_button_pressed(GdkEventButton* event)
{
	if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) ){
		const gchar * title = gtk_widget_get_name(GTK_WIDGET(window.gobj()));
		if(strcmp(title,"MonoRack")==0) {
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_mono_rack),NULL,NULL,NULL,(gpointer) gw.menu_mono_rack,2,tim);
		return true;
		}
		else if (strcmp(title,"StereoRack")==0){
			guint32 tim = gtk_get_current_event_time ();
			gtk_menu_popup (GTK_MENU(gw.menu_stereo_rack),NULL,NULL,NULL,(gpointer) gw.menu_stereo_rack,2,tim);
		return true;
		}
	}
	return false;
}

GxToolBox::GxToolBox(gx_ui::GxUI& ui, 
	const char *pb_2, Glib::ustring titl,GtkWidget * d):
	rbox(false, 4),
	m_regler_tooltip_window(Gtk::WINDOW_POPUP)
{
	Glib::ustring title = titl;
	window.add_events(Gdk::BUTTON_PRESS_MASK);
	m_scrolled_window.set_policy(Gtk::POLICY_NEVER,Gtk::POLICY_AUTOMATIC); 
	paintbox1.set_border_width(18);
	paintbox.set_border_width(4);
	paintbox1.property_paint_func() = pb_2;
	paintbox.property_paint_func() = pb_rectangle_skin_color_expose;
	window.signal_delete_event().connect(
		 sigc::bind<gpointer>(sigc::mem_fun(*this, &GxToolBox::on_window_delete_event),d));
	box.add(rbox);
	paintbox1.add(m_scrolled_window);
	m_scrolled_window.add(paintbox);
	paintbox.add(box);
	window.add(paintbox1);
	window.signal_button_press_event().connect(
		sigc::mem_fun(*this, &GxToolBox::on_button_pressed));
	paintbox1.show();
	box.show();
	m_scrolled_window.show();
	rbox.show();
}

/****************************************************************/

}