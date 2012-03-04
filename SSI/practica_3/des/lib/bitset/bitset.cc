#include "bitset.h"

Bitset::Bitset(string bitset) {
	//Se inicializa el bitset a partir de la cadena
	_bitset = new dynamic_bitset<unsigned char>(bitset);
}

Bitset::Bitset(dynamic_bitset<unsigned char> bitset) {
	_bitset = new dynamic_bitset<unsigned char>(bitset);
}

Bitset::Bitset(int bitset, int size) {
	if (size == 0)
		_bitset = new dynamic_bitset<unsigned char>(int2bin(bitset));
	else if (size > 0)
		_bitset = new dynamic_bitset<unsigned char>(size);
}

Bitset::Bitset(const Bitset &other) {
	_bitset = new dynamic_bitset<unsigned char>(other.getBitset());
}

Bitset::~Bitset() {
	//Borrar el puntero del bitset
	delete _bitset;
}

string Bitset::to_s(const char MODE, int sep) const {
	//Meter en un sstream la cadena binaria
	switch (MODE) {
		case BIN: {
			if (sep == 0) {
				stringstream ss;
				ss << (*_bitset);
				string msg;
				ss >> msg;
				return msg;
			}
			else {
				//Separado por un espacio cada 'sep' bits
				string msg = "";
				stringstream ss;
				int times = size() / sep;
				for (int i = times; i > 0; i--)
					msg = msg + " " + subset((i-1)*sep,sep).to_s(BIN);
				return msg;
			}
		}
		case HEX: {
			if (sep == 0)
				return ul2hex((*_bitset).to_ulong());
			else {
				string msg = "";
				int times = size() / 4;
				for (int i = times; i > 0; i--) {
					string aux = subset((i-1)*4,4).to_s(HEX);
					msg = msg + subset((i-1)*4,4).to_s(HEX);
					if ((times > 0) && ((i+1) % 2 == 0))
						msg += " ";
				}
				return msg;
			}
		}
		case DEC: {
			stringstream ss;
			ss << (*_bitset).to_ulong();
			string msg;
			ss >> msg;
			return msg;
		}
	}
}

unsigned long Bitset::to_ul() const {
	return (*_bitset).to_ulong();
}

string int2bin(int number) {
	if ( number == 0 ) return "0";
	if ( number == 1 ) return "1";

	if ( number % 2 == 0 )
		return int2bin(number / 2) + "0";
	else
		return int2bin(number / 2) + "1";
}

int Bitset::size() const {
	return (*_bitset).size();
}

string Bitset::ul2hex(unsigned long number) const {
	stringstream ss;
	ss << hex << number;
	string hexn;
	ss >> hexn;
	return hexn;
}

void Bitset::swap(const int a, const int b) {
	bool aux = (*_bitset)[a];
	(*_bitset)[a] = (*_bitset)[b];
	(*_bitset)[b] = aux;
}

//Rotar el bitset n posiciones
void Bitset::rotate(const int n, const char MODE) {
	int times = n % size();
	switch (MODE) {
		case LEFT: {
			//Hay que cambiar cada bit por el anterior y el primero por el ultimo
			for (int i = 0; i < times; i++) {
				bool ultimo = (*_bitset)[size()-1];
				(*_bitset)<<=1;
				(*_bitset)[0] = ultimo;
			}
			break;
		}
		case RIGHT: {
			//Hay que cambiar cada bit por el siguiente y el ultimo por el primero
			for (int i = 0; i < times; i++) {
				bool primero = (*_bitset)[0];
				(*_bitset)>>=1;
				(*_bitset)[size() -1] = primero;
			}
			break;
		}
	}
}

dynamic_bitset<unsigned char>::reference Bitset::operator[](const int pos) {
	return (*_bitset)[pos];
}

int Bitset::operator[](const int pos) const {
	if (pos < size())
		//Es necesario invertir la posicion pues en el bitset se almacena
		//al reves
		return (*_bitset)[size() - pos - 1];
	else
		return -1;
}

dynamic_bitset<unsigned char> Bitset::getBitset() const {
	return (*_bitset);
}

Bitset &Bitset::operator= (const Bitset other) {
	_bitset = new dynamic_bitset<unsigned char>(other.getBitset());
}

ostream &operator<< (ostream &sout, const Bitset &other) {
	sout << other.to_s(BIN);
	return sout;
}

Bitset Bitset::operator^(const Bitset &other) {
	Bitset result((getBitset() ^ other.getBitset()));
	return result;
}

Bitset Bitset::reverse() {
	string bin = to_s(BIN);
	return Bitset(string(bin.rbegin(),bin.rend()));
}

Bitset Bitset::subset(const int start,const int length)const {
	string bin = to_s(BIN);
	return Bitset(bin.substr(bin.length()-start-length,length));
}
