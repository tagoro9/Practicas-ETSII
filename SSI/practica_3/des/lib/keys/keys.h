#ifndef KEYS_H_
#define KEYS_H_

#include "../bitset/bitset.h"

using namespace std;

class Keys {
private:
	static Vector PC1;
	static Vector PC2;
	static Vector Rotations;
	//Clave original de 64 bits
	Bitset _key;
	//Vector de Bitsets con cada una de las claves
	vector<Bitset> _keys;
	//Realizar permutacion PC1
	Bitset PPC1();
	Bitset PPC2(Bitset o);
public:
	static Vector initPC1();
	static Vector initPC2();
	static Vector initRotations();
	Keys(const Bitset key);
	virtual ~Keys();
	Bitset operator[](const int pos) const;
};

#endif /* KEYS_H_ */
