//#include "lib/skc/a5/a5.h"
//#include "lib/skc/rc4/rc4.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include "lib/gui/gui.h"

using namespace std;

int main(int argc, char *argv[]) {
	/*A5 a5(297169,1472666,6188815);
	a5.code("1 34");
	cout << a5.to_s(DEC) << endl;
	Rc4 rc4("2 5");
	rc4.code("1 34");
	cout << rc4.to_s(DEC) << endl;*/

	Gtk::Main kit(argc, argv);

	Gui gui(argv[0]);
	//Shows the window and returns when it is closed.
	Gtk::Main::run(gui);
	return 0;

}
