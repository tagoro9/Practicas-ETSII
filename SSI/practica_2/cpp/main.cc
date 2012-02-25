#include "lib/a5.h"

using namespace std;

int main(int argc, char *argv[]) {
   A5 a5(297169,1472666,6188815);
   cout << "Hello cipher" << endl;
   a5.code("2 5");
   cout << a5.to_s() << endl;
   cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
   A5 a52(297169,1472666,6188815);
   a52.code("63 215");
}
