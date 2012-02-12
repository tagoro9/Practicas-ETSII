#include "rc4.h"

using namespace std;

int main() {
	Rc4 rc4("2 5");
	rc4.code("1 34");
	cout << rc4.to_s() << endl;
}
