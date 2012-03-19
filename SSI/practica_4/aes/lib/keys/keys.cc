#include "keys.h"

Keys::Keys(const Bitset key, char MODE) {
	//Inicializar la clave
	_key = new BitsetMatrix(4,4,key.to_s());
	//Generacion de la clave expandida
	BitsetMatrix exp_key(4,44);
	//Copiar las 4 primeras columnas de la clave
	for (int i = 0; i < 4;i++)
		exp_key.set_column(i,(_key->get_column(i)));
	for (int i(4),j(1); i < exp_key.get_columns(); i++) {
		//Si la columna es multiplo de 4
		if ((i % 4) == 0) {
			//RotWord
			exp_key.set_column(i,exp_key.get_column(i-1));
			exp_key.rotate(i,1);
			//SubBytes
			exp_key.set_column(i,AesFunctions::SubBytes(exp_key[i]));
			//Xor final
			Bitset Xor = ((exp_key.get_column(i)) ^ (exp_key.get_column(i-4)))^ ( Bitset( AesFunctions::padZeros( AesFunctions::int2bin(AesFunctions::RCON[j]),32 ) )) ;
			exp_key.set_column(i,Xor);
			j++;
		}
		else {
			exp_key.set_column(i,(exp_key[i-1])^(exp_key[i-4]));
		}
	}
	_keys = new BitsetMatrix(exp_key);
}

BitsetMatrix Keys::get_key() const {
	return (*_key);
}

BitsetMatrix Keys::get_key(const int i) {
	BitsetMatrix result(4,4);
	for (int j = 0; j < 4 ; j++) {
		result.set_column(j,_keys->get_column(i*(_keys->get_rows())+j));
	}
	return result;
}

BitsetMatrix Keys::operator[](const int j) const {
	//j ha de estar entre 0 y 10
	int start = j*4;
	int end = start + 4;
	string aux;
	for (int i = start; i < end; i++) {
		aux += (*_keys)[i].to_s();
	}
	return BitsetMatrix(4,4,aux);
}

Keys::~Keys() {
	delete _key;
}

