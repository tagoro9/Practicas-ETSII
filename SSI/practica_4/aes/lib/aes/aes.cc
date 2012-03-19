#include "aes.h"

Aes::~Aes() {
	delete _keys;
	delete _msg;
}

Aes::Aes(string seed, const char MODE) {
	_keys = new Keys(Bitset(AesFunctions::processString(seed)), MODE);
	_msg = NULL;
}

void Aes::set_seed(string new_seed, const char MODE) {
	delete _keys;
	_keys = new Keys(Bitset(AesFunctions::processString(new_seed)), MODE);
}

void Aes::code(string msg, const char MODE) {
	//Convertir el mensaje a bitsetmatrix
	BitsetMatrix roundMsg(4,4,AesFunctions::processString(msg));
	//Ronda inicial
	BitsetMatrix roundKey = _keys->get_key(0);
	roundMsg = AesFunctions::AddRoundKey(roundMsg,roundKey);
	if (MODE != STD) {
		cout << "\n\t\t*******" << " Ronda " << 0 << " ********\n\n";
		cout << "Clave:\t\t\t" << roundKey.to_s(LINEAL) << endl;
		cout << "Resultado:\t" << roundMsg.to_s(LINEAL) << endl;
	}
	//Rondas principales
	for (int i = 1; i < 10; i++) {
		roundKey = _keys->get_key(i);
		roundMsg = AesFunctions::SubBytes(roundMsg);
		roundMsg = AesFunctions::ShiftRows(roundMsg);
		roundMsg = AesFunctions::MixColumns(roundMsg);
		roundMsg = AesFunctions::AddRoundKey(roundMsg,roundKey);
		if (MODE != STD) {
			cout << "\n\t\t*******" << " Ronda " << i << " ********\n\n";
			cout << "Clave:\t\t\t" << roundKey.to_s(LINEAL) << endl;
			cout << "Resultado:\t" << roundMsg.to_s(LINEAL) << endl;
		}
	}
	//Ronda final
	roundKey = _keys->get_key(10);
	roundMsg = AesFunctions::SubBytes(roundMsg);
	roundMsg = AesFunctions::ShiftRows(roundMsg);
	roundMsg = AesFunctions::AddRoundKey(roundMsg,roundKey);
	if (MODE != STD) {
		cout << "\n\t\t*******" << " Ronda " << 10 << " ********\n\n";
		cout << "Clave:\t\t\t" << roundKey.to_s(LINEAL) << endl;
		cout << "Resultado:\t" << roundMsg.to_s(LINEAL) << endl;
	}
	_msg = new BitsetMatrix(roundMsg);
	cerr << _msg->to_s(LINEAL);
}

string Aes::to_s(const char STYLE, const char MODE) const {
	return _msg->to_s(STYLE,MODE);
}

