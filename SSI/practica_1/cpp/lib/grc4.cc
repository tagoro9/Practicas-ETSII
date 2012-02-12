#include "grc4.h"
#include <iostream>

Grc4::Grc4(): btn_quit(Gtk::Stock::QUIT),
			  btn_info(Gtk::Stock::INFO),
			  lbl_seed("Semilla"),
			  lbl_message("Mensaje"),
			  lbl_result("Resultado"),
			  about(),
			  rc4()
{
  // Sets the border width of the window.
  set_default_size(400,200);
  set_title("Algoritmo Rc4");
  //set_window_position(Gtk::Window::POS_CENTER);
  set_icon(Gdk::Pixbuf::create_from_file("image/logo.png"));
  set_position(Gtk::WIN_POS_CENTER);
  components();
  show_all_children();
}

void Grc4::components() {
	//Boton para cifrar
	btn_code.add_label("Cifrar");
	btn_code.set_tooltip_text("Cifrar mensaje");
	btn_code.signal_clicked().connect(sigc::mem_fun(*this,&Grc4::on_btn_code_clicked));
	//Boton salir
	btn_quit.signal_clicked().connect(sigc::mem_fun(*this,&Grc4::on_btn_quit_clicked));
	//Boton boton about
	btn_info.signal_clicked().connect(sigc::mem_fun(*this,&Grc4::on_btn_info_clicked));
	//Inputs
	in_seed.set_size_request(250,26);
	in_message.set_size_request(250,26);
	in_result.set_size_request(250,26);
	//Introducir botones en el fixed
	fixed.put(btn_code,100,140);
	fixed.put(btn_info,164,140);
	fixed.put(btn_quit,290,140);
	//Introducir etiquetas en el fixed
	fixed.put(lbl_seed,20,30);
	fixed.put(lbl_message,20,60);
	fixed.put(lbl_result,20,90);
	//Introducir inputs en el fixed
	fixed.put(in_seed,120,25);
	fixed.put(in_message,120,55);
	fixed.put(in_result,120,85);
	//Introducir el fixed en la ventana
	add(fixed);
}

void Grc4::on_btn_code_clicked()
{
	rc4.set_seed(in_seed.get_text());
	rc4.code(in_message.get_text());
	std::cout << rc4.to_s() << std::endl;
	in_result.set_text(rc4.to_s());
}

void Grc4::on_btn_info_clicked()
{
	about.set_size_request(50,50);
	about.set_program_name("Algoritmo Rc4");
	about.set_version("0.1");
	about.set_copyright("(c) Victor Mora");
	about.run();
	about.~AboutDialog();
}

void Grc4::on_btn_quit_clicked()
{
	Gtk::Main::quit();
	std::cout << "App terminada" << std::endl;
}


