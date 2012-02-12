/*
 * grc4.h
 *
 *  Created on: 12/02/2012
 *      Author: victor
 */

#ifndef GRC4_H_
#define GRC4_H_

#include <gtkmm/button.h>
#include <gtkmm/fixed.h>
#include <gtkmm/window.h>
#include <gtkmm/stock.h>
#include <gtkmm/main.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/aboutdialog.h>
#include "rc4.h"


class Grc4 : public Gtk::Window {

public:
	Grc4();
	~Grc4() {};
private:
	void components();
protected:
  //Signal handlers:
  void on_btn_code_clicked();
  void on_btn_info_clicked();
  void on_btn_quit_clicked();
  //Rc4
  Rc4 rc4;
  //About
  Gtk::AboutDialog about;
  //Member widgets:
  //Fixed
  Gtk::Fixed fixed;
  //La interfaz tendra tres botones
  Gtk::Button btn_code, btn_info, btn_quit;
  //Etiquetas
  Gtk::Label lbl_seed, lbl_message, lbl_result;
  //Entradas de texto
  Gtk::Entry in_seed, in_message, in_result;
};

#endif /* GRC4_H_ */
