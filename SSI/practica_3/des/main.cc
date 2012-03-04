//Programa principal

#include "lib/des/des.h"

int main(int argc, char *argv[]) {
	/*cout << "Xor: " << endl;
	Bitset xora("11110000101010101111000010101010");
	Bitset xorb("000110110000001011101111111111000111000001110010");
	Bitset subset = xorb.subset(47,1);
	cout << "A: " << xora << endl;
	cout << "B: " << xorb << endl;
	cout << "S: " << subset << endl;*/
	//cout << "X: " << (xora ^ xorb) << endl;


	//cout << "\t\tMe crean desde una cadena" << endl;
 	Bitset a("11110000101010101111000010101010");
	Bitset b("000110110000001011101111111111000111000001110010");
	//cout << "En decimal: " << b.to_s(DEC) << endl;
	//cout << "En hexadecimal: " << b.to_s(HEX) << endl;


	//cout << "\n\n\n";
	/*cout << "SBOX" << endl;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	Sbox c;
	Bitset result = c.run(a,b);
	cout << "R0: " << result << endl;
	cin.get();*/
	/*cout << "Testing Keys" << endl;
	Bitset clave("0001001100110100010101110111100110011011101111001101111111110001");
	//Bitset clave("0101001101100001011011100111010001101001011000010110011101101111");
	cout << "K: " << clave << endl;
	Keys k(clave);*/

	cout << "Testing Des" << endl;
	Des des("0001001100110100010101110111100110011011101111001101111111110001");
	des.code("0000000100100011010001010110011110001001101010111100110111101111");
}
