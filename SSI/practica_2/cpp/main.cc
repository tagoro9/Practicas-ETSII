#include "lib/skc/a5/a5.h"
#include "lib/skc/rc4/rc4.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

int main(int argc, char *argv[]) {
	A5 a5(297169,1472666,6188815);
	a5.code("1 34");
	cout << a5.to_s(DEC) << endl;
	Rc4 rc4("2 5");
	rc4.code("1 34");
	cout << rc4.to_s(DEC) << endl;
}
