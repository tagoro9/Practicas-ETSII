#ifndef GUI_H_
#define GUI_H_

#include <gtkmm/button.h>
#include <gtkmm/fixed.h>
#include <gtkmm/window.h>
#include <gtkmm/stock.h>
#include <gtkmm/main.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/radiobutton.h>
#include "../skc/rc4/rc4.h"
#include "../skc/a5/a5.h"

//using namespace std;

class Gui : public Gtk::Window {
public:
	Gui();
	~Gui() {};
private:
	void components();
	void rc4_components();
	void a5_components();
protected:
	//Signal handlers:
	void on_btn_code_clicked();
	void on_btn_quit_clicked();
	void on_btn_toggle_clicked();
	void on_radio_clicked();
	//Radio button
	Gtk::RadioButton m_rc4, m_a5;
    //Skc
	Skc *skc;
	//Member widgets:
	//FIxed rc4
	Gtk::Fixed fixed_rc4;
	//Fixed a5
	Gtk::Fixed fixed_a5;
	//Fixed
	Gtk::Fixed fixed;
	Gtk::Button btn_code, btn_quit, btn_toggle;
	//Etiquetas
	Gtk::Label lbl_seed, lbl_message, lbl_result, lbl_algorithm;
	//Entradas de texto
	Gtk::Entry in_seed, in_message, in_result;
	//Elementos del a5
	//Entradas de texto
	Gtk::Entry in_r1, in_r2, in_r3;
};

#endif /* GUI_H_ */
