#ifndef RC4_H_
#define RC4_H_

#include "../skc.h"

using namespace std;

int const SIZE = 256;

class Rc4 : public Skc{
private:
    ///Vector de bytes S (unsigned char)
    int S[SIZE];
    ///Vector de bytes K (unsigend char)
    int K[SIZE];
    ///Semilla
    Vector seed;
    ///Inicializar vectores S y K
    void initialize_seed();
    ///Intercambiar dos elementos de S
    void swap(int i, int j);
public:
	Rc4(string sd);
	~Rc4() {};
    ///Modificar la semilla
    void set_seed(string new_seed);
    ///Cifrar
    void code(string msg, const char MODE = STD);
};

#endif /* RC4_H_ */
