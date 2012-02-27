#include "gui.h"

Gui::Gui(char* path): btn_quit(Gtk::Stock::QUIT),
			  lbl_seed("Semilla"),
			  lbl_message("Mensaje"),
			  lbl_result("Resultado"),
			  lbl_algorithm("Seleccione algortimo"),
			  m_a5("a5"),
			  m_rc4("rc4"),
			  b_debug("Debug"),
			  _path(path)
{
  // Sets the border width of the window.
  set_default_size(400,250);
  set_title("Cifrado de clave secreta- rc4");
  //set_window_position(Gtk::Window::POS_CENTER);
  _path.erase(_path.length() -5, _path.length() -1);
  cout << _path+"/../image/logo.png" << endl;
  set_icon(Gdk::Pixbuf::create_from_file(_path+"/../image/logo.png"));
  set_position(Gtk::WIN_POS_CENTER);
  components();
  show_all_children();
  //Inicializar el skc
  skc = new Rc4("2 5");
}

void Gui::components() {
	//Radio buttons
	Gtk::RadioButton::Group group = m_rc4.get_group();
	m_a5.set_group(group);
	fixed.put(m_a5,135,40);
	fixed.put(m_rc4,205,40);
	fixed.put(b_debug,30,40);
	fixed.put(lbl_algorithm,125,15);
	m_rc4.set_active();
	m_rc4.signal_clicked().connect(sigc::mem_fun(*this,&Gui::on_radio_clicked));
	//Fixed del rc4
	//Boton para cifrar
	btn_code.add_label("Cifrar");
	btn_code.set_tooltip_text("Cifrar mensaje");
	btn_code.signal_clicked().connect(sigc::mem_fun(*this,&Gui::on_btn_code_clicked));
	//Boton salir
	btn_quit.signal_clicked().connect(sigc::mem_fun(*this,&Gui::on_btn_quit_clicked));
	//Boton toggle
	btn_toggle.set_label("HEX");
	btn_toggle.set_size_request(40,30);
	btn_toggle.signal_clicked().connect(sigc::mem_fun(*this,&Gui::on_btn_toggle_clicked));
	//Inputs
	in_seed.set_size_request(250,26);
	in_seed.set_text("2 5");
	in_message.set_size_request(250,26);
	in_message.set_text("1 34");
	in_result.set_size_request(250,26);
	in_r1.set_size_request(80,26);
	in_r3.set_size_request(80,26);
	in_r2.set_size_request(80,26);
	in_r1.set_text("297169");
	in_r2.set_text("1472666");
	in_r3.set_text("6188815");
	//Introducir botones en el fixed
	fixed.put(btn_code,150,190);
	fixed.put(btn_toggle,214,190);
	fixed.put(btn_quit,266,190);
	//Introducir etiquetas en el fixed
	fixed.put(lbl_seed,20,80);
	fixed.put(lbl_message,20,110);
	fixed.put(lbl_result,20,140);
	//Introducir inputs en el fixed
	fixed_rc4.put(in_seed,120,75);
	fixed_a5.put(in_r1,120,75);
	fixed_a5.put(in_r2,205,75);
	fixed_a5.put(in_r3,289,75);
	fixed.put(in_message,120,105);
	fixed.put(in_result,120,135);
	//Introducir el fixed en la ventana
	fixed.put(fixed_a5,0,0);
	fixed.put(fixed_rc4,0,0);
	fixed_a5.hide();
	add(fixed);
}

string Gui::get_working_path()
{
   char temp[100];
   string aux;
   getcwd(temp, 100) ? aux = string( temp ) : aux = string("");
   //return aux + _path.substr(1,_path.length()-1);
   return aux;
}

void Gui::on_btn_code_clicked()
{
	if (m_a5.get_active() == true) {
		string aux_seed = "";
		aux_seed += in_r1.get_text() + " ";
		aux_seed += in_r2.get_text() + " ";
		aux_seed += in_r3.get_text() + " ";
		std::cout << "Semilla: " << aux_seed << std::endl;
		skc->set_seed(aux_seed);
	}
	else {
		std::cout << "Semilla: " << in_seed.get_text() << std::endl;
		skc->set_seed(in_seed.get_text());
	}
	btn_toggle.set_label("HEX");
	std::cout << "Mensaje: " << in_message.get_text() << std::endl;
	if (b_debug.get_active() == true)
		skc->code(in_message.get_text(),DEBUG);
	else
		skc->code(in_message.get_text());
	std::cout << "Salida: " << skc->to_s(DEC) << std::endl;
	in_result.set_text(skc->to_s(DEC));
}

void Gui::on_btn_toggle_clicked() {
	if (btn_toggle.get_label() == "HEX") {
		btn_toggle.set_label("BIN");
		in_result.set_text(skc->to_s(HEX));
		std::cout << "Salida: " << skc->to_s(HEX) << std::endl;
	}
	else if (btn_toggle.get_label() == "BIN") {
		btn_toggle.set_label("DEC");
		in_result.set_text(skc->to_s(BIN));
		std::cout << "Salida: " << skc->to_s(BIN) << std::endl;
	}
	else {
		btn_toggle.set_label("HEX");
		in_result.set_text(skc->to_s(DEC));
		std::cout << "Salida: " << skc->to_s(DEC) << std::endl;
	}
}

void Gui::on_radio_clicked()
{
	delete skc;
	if (m_rc4.get_active() == true) {
		std::cout << "rc4" << std::endl;
		fixed_a5.hide();
		fixed_rc4.show();
		set_title("Cifrado de clave secreta - rc4");
		skc = new Rc4("2 5");

	}
	else if (m_a5.get_active() == true) {
		std::cout << "a5" << std::endl;
		set_title("Cifrado de clave secreta - a5");
		fixed_rc4.hide();
		fixed_a5.show();
		skc = new A5(1,1,1);
	}
	btn_toggle.set_label("DEC");
}

void Gui::on_btn_quit_clicked()
{
	Gtk::Main::quit();
	std::cout << "App terminada" << std::endl;
}

