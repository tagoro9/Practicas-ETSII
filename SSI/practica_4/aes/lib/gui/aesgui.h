#ifndef AESGUI_H_
#define AESGUI_H_

#include <gtkmm.h>
#include "../aes/aes.h"

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

class AesGui {
public:
	AesGui(char *path);
	virtual ~AesGui();
	  Gtk::Window* get_window();
	  //static void on_cifrar_clicked();
	  void on_cifrar_clicked();
	  static void cb_child_watch( GPid  pid, gint  status);
	  static gboolean cb_out_watch( GIOChannel *channel, GIOCondition  cond, Data *out);
	  static gboolean cb_err_watch( GIOChannel   *channel, GIOCondition  cond, Data *err);
private:
  	Data dat;
    Aes _aes;
	string _path;
	string get_working_path();
	Gtk::Button *boton;
	Gtk::Entry *key_e, *message_e, *coded_e;
	Gtk::TextView *text;
	Gtk::CheckButton *debug;
protected:
   Gtk::Window *window;
   Glib::RefPtr<Gtk::Builder> builder;
};

#endif /* AESGUI_H_ */
