#ifndef AES_H_
#define AES_H_

#include "../keys/keys.h"

class Aes {
private:
	//Subclaves
	Keys *_keys;
	//Mensaje
	BitsetMatrix *_msg;
public:
	Aes() {_keys = NULL; _msg = NULL;};
	Aes(string seed, const char MODE = STD);
	virtual ~Aes();
	void set_seed(string new_seed, const char MODE = STD);
	void code(string msg, const char MODE = STD);
	string to_s(const char STYLE = MATRIX, const char MODE = HEX) const;
};

#endif /* AES_H_ */
