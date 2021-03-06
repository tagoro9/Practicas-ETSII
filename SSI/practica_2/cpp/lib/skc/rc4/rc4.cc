#include "rc4.h"

Rc4::Rc4(string sd) {
	seed = s_to_v(sd);
	initialize_seed();
}

void Rc4::initialize_seed() {
	if (seed.size() > SIZE) {
		throw "Error Seed size too long.";
	}
	for (int i = 0; i < SIZE; i++) {
		S[i] = i;
		K[i] = seed[i % seed.size()];
	}
	int j = 0;
	for (int i=0; i < SIZE; i++) {
		j = (j + S[i] + K[i]) % SIZE;
		swap(i,j);
	}
}

void Rc4::code(string msg, const char MODE) {
	Vector in_message = s_to_v(msg);
	_message.clear();
    if (MODE == DEBUG) {
    	cout << "/*      DEBUGGING     */" << endl;
    }
	int i = 0;
	int j = 0;
	for (int k = 0;k < in_message.size();k++) {
		i = (i + 1) % SIZE;
		j = (j + S[i]) % SIZE;
		swap(i,j);
	    if (MODE == DEBUG) {
	    	cout << "****** Byte: " << k << " ******" << endl;
	    	cout << "Secuencia cifrante: " << S[(S[i] + S[j]) % SIZE] << endl;
	    }
		_message.push_back(in_message[k] ^ S[(S[i] + S[j]) % SIZE]);
	}
    if (MODE == DEBUG) {
    	cout << "/*      END     */" << endl;
    }
}

void Rc4::set_seed(string new_seed) {
	seed = s_to_v(new_seed);
	initialize_seed();
}

void Rc4::swap(int i,int j) {
	int aux = S[i];
	S[i] = S[j];
	S[j] = aux;
}
