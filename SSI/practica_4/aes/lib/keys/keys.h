#ifndef KEYS_H_
#define KEYS_H_

#include "../bitsetmatrix/bitsetmatrix.h"
#include "../functions/aesfunctions.h"

using namespace std;

class Keys {
private:
	//Matriz con la clave inicial de 128 bits
	BitsetMatrix *_key;
	BitsetMatrix *_keys;
public:
	Keys(const Bitset key, char MODE = STD);
	virtual ~Keys();
	BitsetMatrix get_key() const;
	//Devolver una matriz con la subclave de ronda i
	BitsetMatrix get_key(const int i);
	//Obtener en un bitset una subclave de ronda
	BitsetMatrix operator[](const int j) const;

};

#endif /* KEYS_H_ */
