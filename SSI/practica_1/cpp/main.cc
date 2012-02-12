#include "lib/grc4.h"

int main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  Grc4 grc4;
  //Shows the window and returns when it is closed.
  Gtk::Main::run(grc4);
  return 0;
}
