#include "des.h"

//Inicializar las variables estaticas
Vector Des::IP = Des::initIP();
Vector Des::FP = Des::initFP();


Vector Des::initIP() {
	int P[] = {0x3a, 0x32, 0x2a, 0x22, 0x1a, 0x12, 0x0a, 0x02,
	          0x3c, 0x34, 0x2c, 0x24, 0x1c, 0x14, 0x0c, 0x04,
	          0x3e, 0x36, 0x2e, 0x26, 0x1e, 0x16, 0x0e, 0x06,
	          0x40, 0x38, 0x30, 0x28, 0x20, 0x18, 0x10, 0x08,
	          0x39, 0x31, 0x29, 0x21, 0x19, 0x11, 0x09, 0x01,
			  0x3b, 0x33, 0x2b, 0x23, 0x1b, 0x13, 0x0b, 0x03,
			  0x3d, 0x35, 0x2d, 0x25, 0x1d, 0x15, 0x0d, 0x05,
			  0x3f, 0x37, 0x2f, 0x27, 0x1f, 0x17, 0x0f, 0x07};
	Vector aux(P,P + sizeof(P) / sizeof(long));
	return aux;
}

Vector Des::initFP() {
	int P[] = {0x28, 0x08, 0x30, 0x10, 0x38, 0x18, 0x40, 0x20,
	        0x27, 0x07, 0x2f, 0x0f, 0x37, 0x17, 0x3f, 0x1f,
	        0x26, 0x06, 0x2e, 0x0e, 0x36, 0x16, 0x3e, 0x1e,
	        0x25, 0x05, 0x2d, 0x0d, 0x35, 0x15, 0x3d, 0x1d,
	        0x24, 0x04, 0x2c, 0x0c, 0x34, 0x14, 0x3c, 0x1c,
	        0x23, 0x03, 0x2b, 0x0b, 0x33, 0x13, 0x3b, 0x1b,
	        0x22, 0x02, 0x2a, 0x0a, 0x32, 0x12, 0x3a, 0x1a,
	        0x21, 0x01, 0x29, 0x09, 0x31, 0x11, 0x39, 0x19};
	Vector aux(P,P + sizeof(P) / sizeof(long));
	return aux;
}

string Des::hex2bin(string hex) {
	string bin = "";
	for (int i = 0; i < 16; i++) {
		switch (hex[i])
		{
			case '0': bin += ("0000"); break;
			case '1': bin += ("0001"); break;
			case '2': bin += ("0010"); break;
			case '3': bin += ("0011"); break;
			case '4': bin +=  ("0100"); break;
			case '5': bin +=  ("0101"); break;
			case '6': bin +=  ("0110"); break;
			case '7': bin +=  ("0111"); break;
			case '8': bin +=  ("1000"); break;
			case '9': bin +=  ("1001"); break;
			case 'a': bin +=  ("1010"); break;
			case 'b': bin +=  ("1011"); break;
			case 'c': bin +=  ("1100"); break;
			case 'd': bin +=  ("1101"); break;
			case 'e': bin +=  ("1110"); break;
			case 'f': bin +=  ("1111"); break;
		}
	}
	return bin;
}

string Des::processString(string cad) {
	try {
		regex bin_rx("^[0,1]{64}$");
		regex hex_rx("^[\\d,a-f]{16}$");
		if (regex_match(cad,bin_rx))
			return cad;
		else if (regex_match(cad,hex_rx))
			return hex2bin(cad);
		else if (cad.length() <= 8) {
			//Se trata de texto plano (longitud 8 caracteres maxima)
			string aux_cad = "";
			for (int i = 0; i < cad.length(); i++) {
				//Convertir cada byte a binario
				aux_cad += padZeros(int2bin((int)cad[i]),8);
			}
			//Si es menor de 8 rellenar con \0
			for (int i = cad.length(); i < 8; i++) {
				aux_cad += padZeros(int2bin((int)'\0'),8);
			}
			return aux_cad;
		}
		else {
			//Lanzar excepcion
			throw 1;
		}
	}
	catch (int exception) {
		cout << "Error: La clave ha de ser 64 bits, 16 digitos hexadecimales o texto de longitud maxima 8" << endl;
		exit(1);
	}
}

Des::Des() {
   _sbox = new Sbox();
   _keys = NULL;
}

Des::Des(string seed, const char MODE) {
	//Inicializar claves
	_keys = new Keys(Bitset(processString(seed)), MODE);
	_sbox = new Sbox();
}

Des::~Des() {
	delete _sbox;
	delete _keys;
}

void Des::set_seed(string new_seed, const char MODE) {
	delete _keys;
	_keys = new Keys(Bitset(processString(new_seed)), MODE);
}

void Des::code(string msg, const char MODE) {
	//Hay que convertir el mensaje a un bitset
	_msg = Bitset(processString(msg));
	cout << "Mensaje inicial: " << _msg.to_s(HEX,8) << endl;
	if (MODE != STD) cout << "Mensaje inicial: " <<_msg.to_s(BIN,8) << endl;
	//Permutacion inicial
	Bitset pip = PIP(_msg);
	if (MODE != STD) cout << "\nPermutacion inicial: " << PIP(_msg).to_s(BIN,8) << "\n\n";
	//Dividir en dos mitades
	vector<Bitset> lmsg;
	lmsg.push_back(pip.subset(32,32));
	vector<Bitset> rmsg;
	rmsg.push_back(pip.subset(0,32));
	//cout << "LM: " << lmsg[0] << endl;
	//cout << "RM: " << rmsg[0] << endl;
	//Se comienza la cifrar. 16 iteraciones
	for (int i = 0; i < 16; i++) {
		lmsg.push_back(rmsg[i]);
		//cout << "K" << i << ": " << (*_keys)[i] << endl;
		Bitset ssbox = (*_sbox).run(rmsg[i],(*_keys)[i], MODE);
		//cout << "*************************" << endl;
		if (MODE != STD) cout << "Salida Feistel " << i << ":\t" << ssbox.to_s(BIN,8) << endl;
		rmsg.push_back(ssbox^(lmsg[i]));
		//cout << "L" << i << ": " << lmsg[i+1] << endl;
		//cout << "R" << i << ": " << rmsg[i+1] << endl;
		//cout << "************************" << endl;
		//cin.get();
	}
	//Una vez se tiene L16 y R16 hay que unirlos y aplicar IP
	Bitset lrjoint = Bitset(rmsg[16].to_s() + lmsg[16].to_s());
	if (MODE != STD) cout << "\nUltima ronda: " << lrjoint.to_s(BIN,8) << endl;
	_msg = PFP(lrjoint);
	if (MODE != STD) cout << "\nMensaje cifrado: " <<_msg.to_s(BIN,8) << endl;
	cerr << _msg.to_s(HEX,8);
}

Bitset Des::PIP(Bitset o) {
	Bitset ip_(0,64);
	for (int i = 0; i < 64; i++) {
		ip_[64 - i - 1] = o[64 - (IP[i]-1) -1];
	}
	return ip_;
}
Bitset Des::PFP(Bitset o) {
	Bitset fp_(0,64);
	for (int i = 0; i < 64; i++) {
		fp_[64 - i - 1] = o[64 - (FP[i]-1) -1];
	}
	return fp_;
}
string Des::to_s(const char MODE, int sep) const {
	return _msg.to_s(MODE,sep);
}
