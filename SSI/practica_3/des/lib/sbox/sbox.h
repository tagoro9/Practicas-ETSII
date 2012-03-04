#ifndef SBOX_H_
#define SBOX_H_

#include <vector>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include "../bitset/bitset.h"

using namespace std;

class Sbox {
private:
	static vector<Vector> S1_8;
	static Vector Extension;
	static Vector Fperm;
	Bitset _reg;
	Bitset _key;
	//COnvertir cadena binaria en entero
	int s2i(string bin);
	//Extension al comienzo
	Bitset Expand();
	//Rellenar con ceros a la izquierda
	string padZeros(const string str, const int length);
	Bitset Fpermf(Bitset bin);
public:
	static vector<Vector> initS1_8();
	static Vector initExtension();
	static Vector initFperm();
	Sbox();
	virtual ~Sbox();
	//Realizar calculo cajas S
	Bitset run(const Bitset reg, const Bitset key);
	//Getters y setters
	Bitset getKey() const;
	Bitset getReg() const;
};

#endif /* SBOX_H_ */
