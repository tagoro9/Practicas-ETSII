#ifndef RC4_H_
#define RC4_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int const SIZE = 256;
//Estructura vector de la STL
typedef vector <int> Vector;

class Rc4 {
private:
    ///Vector de bytes S (unsigned char)
    int S[SIZE];
    ///Vector de bytes K (unsigend char)
    int K[SIZE];
    ///Semilla
    Vector seed;
    ///Mensaje
    Vector message;
    ///Inicializar vectores S y K
    void initialize_seed();
    ///Intercambiar dos elementos de S
    void swap(int i, int j);
    //Convertir string de numeros en vector de enteros
    Vector s_to_v(string s);
public:
	Rc4(string sd);
	Rc4() {};
	~Rc4() {};
	///Cifrar
    void code(string msg);
    ///Modificar la semilla
    void set_seed(string new_seed);
    ///Devolver cadena con mensaje cifrado
    string to_s();
};

#endif /* RC4_H_ */
