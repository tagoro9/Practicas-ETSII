//Programa principal

#include "lib/gui/desGui.h"


int main(int argc, char *argv[]) {
	//Des des("0001001100110100010101110111100110011011101111001101111111110001");
	//Des des("133457799bbcdff1");
	//des.code("0123456789abcdef");
	//Des des("LALALELE");
	//Des des("0e329232ea6d0d73");
	//des.code("8787878787878787");
	//des.code("LALALALA");
	//des.code("0000000100100011010001010110011110001001101010111100110111101111");
	Gtk::Main kit(argc, argv);

	DesGui gui(argv[0]);
	Gtk::Main::run(*(gui.get_window()));

	return 0;

}
