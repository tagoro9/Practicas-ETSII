#include "lib/a5.h"

using namespace std;

int main(int argc, char *argv[]) {
   A5 a5(297169,1472666,6188815);
   cout << "Hello cipher" << endl;
   a5.code("hola");
   cout << a5.to_s() << endl;
}
