#ifndef AESFUNCTIONS_H_
#define AESFUNCTIONS_H_

#include "../bitset/bitset.h"
#include "../bitsetmatrix/bitsetmatrix.h"
#include <boost/regex.hpp>

class AesFunctions {
public:
	AesFunctions() {}
	virtual ~AesFunctions() {}
	static Vector RCON;
	static Vector SBOX;
	static Vector initRCON();
	static Vector initSBOX();
	static Bitset SubBytes(const Bitset original, const int size = 32);
	static BitsetMatrix SubBytes(const BitsetMatrix original);
	static BitsetMatrix ShiftRows(const BitsetMatrix original);
	static BitsetMatrix MixColumns(const BitsetMatrix original);
	static BitsetMatrix AddRoundKey(const BitsetMatrix original, const BitsetMatrix clave);
	//Convetir un entero en una cadena binaria
	static string int2bin(unsigned int number);
	//Rellenar con ceros a la izquierda
	static string padZeros(const string str, const int length);
	//Convertir de hex (string) a bin (string)
	static string hex2bin(string hex);
	static string processString(string cad);
};

#endif /* AESFUNCTIONS_H_ */
