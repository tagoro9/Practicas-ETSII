#include "keys.h"

Vector Keys::PC1 = Keys::initPC1();
Vector Keys::PC2 = Keys::initPC2();
Vector Keys::Rotations = Keys::initRotations();

Vector Keys::initRotations() {
	int Rotations[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	Vector aux(Rotations,Rotations + sizeof(Rotations) / sizeof(long));
	return aux;
}

Vector Keys::initPC1() {
	int PC[] = {0x39, 0x31, 0x29, 0x21, 0x19, 0x11, 0x09,
			0x01, 0x3a, 0x32, 0x2a, 0x22, 0x1a, 0x12,
			0x0a, 0x02, 0x3b, 0x33, 0x2b, 0x23, 0x1b,
			0x13, 0x0b, 0x03, 0x3c, 0x34, 0x2c, 0x24,
			0x3f, 0x37, 0x2f, 0x27, 0x1f, 0x17, 0x0f,
			0x07, 0x3e, 0x36, 0x2e, 0x26, 0x1e, 0x16,
			0x0e, 0x06, 0x3d, 0x35, 0x2d, 0x25, 0x1d,
			0x15, 0x0d, 0x05, 0x1c, 0x14, 0x0c, 0x04};
	Vector aux(PC,PC + sizeof(PC) / sizeof(long));
	return aux;
}

Vector Keys::initPC2() {
	int PC[] = {0x0e, 0x11, 0x0b, 0x18, 0x01, 0x05,
	          0x03, 0x1c, 0x0f, 0x06, 0x15, 0x0a,
	          0x17, 0x13, 0x0c, 0x04, 0x1a, 0x08,
	          0x10, 0x07, 0x1b, 0x14, 0x0d, 0x02,
	          0x29, 0x34, 0x1f, 0x25, 0x2f, 0x37,
	          0x1e, 0x28, 0x33, 0x2d, 0x21, 0x30,
	          0x2c, 0x31, 0x27, 0x38, 0x22, 0x35,
	          0x2e, 0x2a, 0x32, 0x24, 0x1d, 0x20};
	Vector aux(PC,PC + sizeof(PC) / sizeof(long));
	return aux;
}

Keys::Keys(const Bitset key, char MODE) {
	_key = key;
	//Permutar y dividir en dos mitades
	if (MODE != STD) cout << "\n\t***************************\n\n";
	//if (MODE == DEBUG) cout << _key.size() << endl;
	if (MODE != STD) cout << "Clave inicial: " << _key.to_s(BIN,8) << endl;
	Bitset pc1key = PPC1();
	if (MODE != STD) cout << "\nP1: " << pc1key.to_s(BIN,8) << endl;
	//Dividir en dos mitades
	Bitset L = pc1key.subset(28,28);
	Bitset R = pc1key.subset(0,28);
	//if (MODE == DEBUG) cout << "LI: " << L << endl;
	//if (MODE == DEBUG) cout << "RI: " << R << endl;
	vector<Bitset> Lkeys;
	vector<Bitset> Rkeys;
	Lkeys.push_back(L);
	Rkeys.push_back(R);
	//Generacion de las 16 subclaves
	for (int i = 0; i < 16; i++) {
		Lkeys.push_back(Lkeys[i]);
		Rkeys.push_back(Rkeys[i]);
		//Rotaciones
		Lkeys[i+1].rotate(Rotations[i]);
		Rkeys[i+1].rotate(Rotations[i]);
		//if (MODE == DEBUG) cout << "L" << i <<": " << Lkeys[i+1] << endl;
		//if (MODE == DEBUG) cout << "R" << i <<": " << Rkeys[i+1] << endl;
		//Intorducir la clave en el vector de claves y hacer PC2
		_keys.push_back(PPC2(Bitset(Lkeys[i+1].to_s() + Rkeys[i+1].to_s())));
		if (MODE != STD) cout << "Subclave " << i << ":\t" <<_keys[i].to_s(BIN,8) << endl;
	}
	if (MODE != STD) cout << "\n\t***************************\n\n";
}

Keys::~Keys() {
}

Bitset Keys::PPC1() {
	Bitset pc1_(0,56);
	for (int i = 0; i < 56; i++) {
		pc1_[56 - i - 1] = _key[64 - (PC1[i]-1) -1];
	}
	return pc1_;
}

Bitset Keys::PPC2(Bitset o) {
	Bitset pc2_(0,48);
	for (int i = 0; i < 48; i++) {
		pc2_[48 - i - 1] = o[56 - (PC2[i]-1) -1];
	}
	return pc2_;
}


Bitset Keys::operator[](const int pos) const {
	return _keys[pos];
}
