#ifndef DESGUI_H_
#define DESGUI_H_

#include <gtkmm.h>
#include "../des/des.h"

using namespace Glib;

typedef struct _Data Data;
struct _Data
{
    /* Buffers that will display output */
	Glib::RefPtr<Gtk::TextBuffer> out;
	Glib::RefPtr<Gtk::TextBuffer> err;
	//Salida del mensaje codificado
	Gtk::Entry *entry;
};


class DesGui : public Gtk::Window
{

public:
  DesGui(char* path);
  virtual ~DesGui();
  Gtk::Window* get_window();
  //static void on_cifrar_clicked();
  void on_cifrar_clicked();
  void on_debug_toggled();
  void on_ext_debug_toggled();
  static void cb_child_watch( GPid  pid, gint  status);
  static gboolean cb_out_watch( GIOChannel *channel, GIOCondition  cond, Data *out);
  static gboolean cb_err_watch( GIOChannel   *channel, GIOCondition  cond, Data *err);
private:
  	Data dat;
    Des _des;
	string _path;
	string get_working_path();
	Gtk::Button *boton;
	Gtk::Entry *key_e, *message_e, *coded_e;
	Gtk::TextView *text;
	Gtk::CheckButton *debug, *ext_debug;
protected:
   Gtk::Window *window;
   Glib::RefPtr<Gtk::Builder> builder;
};

#endif /* DESGUI_H_ */
