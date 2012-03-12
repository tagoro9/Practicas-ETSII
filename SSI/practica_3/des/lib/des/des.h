#ifndef DES_H_
#define DES_H_

#include "../sbox/sbox.h"
#include "../keys/keys.h"
#include <boost/regex.hpp>

class Des {
private:
	//Permutacion inicial
	static Vector IP;
	//Permutacion final
	static Vector FP;
	//Cajas S
	Sbox *_sbox;
	//Subclaves
	Keys *_keys;
	//Mensaje
	Bitset _msg;
	//Calculo de las permutaciones
	Bitset PIP(Bitset o);
	Bitset PFP(Bitset o);
	//Convertir de hex (string) a bin (string)
	string hex2bin(string hex);
	//Procesar cadena para determinar si esta en binario, hex o texto plano
	string processString(string cad);
public:
	static Vector initIP();
	static Vector initFP();
	Des();
	Des(string seed, const char MODE = STD);
	void set_seed(string new_seed, const char MODE = STD);
	void code(string msg, const char MODE = STD);
	virtual ~Des();
	string to_s(const char MODE = BIN, int sep = 0) const;
};

#endif /* DES_H_ */
