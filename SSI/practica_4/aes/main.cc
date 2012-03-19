#include "lib/gui/aesgui.h"

int main(int argc, char* argv[]) {
	//Aes aes("2b7e151628aed2a6abf7158809cf4f3c");
	//aes.code("3243f6a8885a308d313198a2e0370734",STD);

	Gtk::Main kit(argc, argv);

	AesGui gui(argv[0]);
	Gtk::Main::run(*(gui.get_window()));

	return 0;
}

