#ifndef DES_H_
#define DES_H_

#include "../sbox/sbox.h"
#include "../keys/keys.h"

const char DEBUG = 'd';
const char STD = 's';

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
public:
	static Vector initIP();
	static Vector initFP();
	Des(string seed);
	void set_seed(string new_seed);
	void code(string msg, const char MODE = STD);
	virtual ~Des();
};

#endif /* DES_H_ */
