#ifndef SKC_H_
#define SKC_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Estructura vector de la STL
typedef vector<int> Vector;
const char BIN = 'B';
const char HEX = 'H';
const char DEC = 'D';
const char DEBUG = 'd';
const char STD = 's';

class Skc {
protected:
	Vector _message;
    //Convertir string de numeros en vector de enteros
    Vector s_to_v(string s);
    string int2bin(int number);
private:
    string int2hex(int number);
public:
	Skc() {};
	virtual void code(string msg, const char MODE = STD) {};
	virtual void set_seed(string new_seed) {};
	string to_s(const char MODE);
};


#endif /* SKC_H_ */
