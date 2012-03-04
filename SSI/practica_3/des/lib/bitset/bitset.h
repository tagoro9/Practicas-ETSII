#ifndef BITSET_H_
#define BITSET_H_

#include <iostream>
#include <sstream>
#include <boost/dynamic_bitset.hpp>

using namespace std;
using namespace boost;

typedef vector<long> Vector;

const char BIN = 'B';
const char HEX = 'H';
const char DEC = 'D';
const char LEFT = 'L';
const char RIGHT = 'R';

class Bitset {
private:
	//Convertir un UL en una cadena en formato HEX
	string ul2hex(unsigned long number) const;
	//Puntero a bitset (para que pueda tener tamaño variable)
	dynamic_bitset<unsigned char> *_bitset;
public:
	//Constructor a partir de un string con un num binario
	Bitset(string bitset);
	//Constructor a partir de un dynamic_bitset
	Bitset(dynamic_bitset<unsigned char> bitset);
	//Constructor a partir de un entero (se convierte a binario)
	Bitset(int bitset, int size = 0);
	//Constructor de copia
	Bitset(const Bitset &other);
	//Constructor por defecto
	Bitset() {_bitset = NULL;};
	//Destructor
	virtual ~Bitset();
	dynamic_bitset<unsigned char> getBitset() const;
	//Tamño del bitset
	int size() const;
	//Rotar tantas posicones a la izqda o dcha
	void rotate(const int n, const char MODE = LEFT);
	//Intercambiar dos posiciones del bitset
	void swap(const int a, const int b);
	//Devolver en un string el contenido del bitset en formato BIN, DEC o HEX
	string to_s(const char MODE = BIN, int sep = 0) const;
	//Devolver en un ul el contenido del bitset
	unsigned long to_ul() const;
	//Modificar una posicion del bitset
	dynamic_bitset<unsigned char>::reference operator[](const int pos);
	//Acceder a una posicion del bitset
	int operator[](const int pos) const;
	//Operador XOR
	Bitset operator^(const Bitset &other);
	//Operador =
	Bitset &operator= (const Bitset other);
	//Invertir el bitset
	Bitset reverse();
	//Obtener un nuevo Bitset suboconjunto del original
	Bitset subset(const int start,const int length)const;
};

//Convetir un entero en una cadena binaria
string int2bin(int number);
//Imprimir en flujo
ostream &operator<< (ostream &sout, const Bitset &other);

#endif /* BITSET_H_ */
