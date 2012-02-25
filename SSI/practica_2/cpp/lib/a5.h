#include <string>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

//Estructura vector de la STL
typedef vector <int> Vector;

class A5 {
private:
   ///Registros de desplazamiento
   //19 bits
   int LFSR1;
   //22 bits
   int LFSR2;
   //23 bits
   int LFSR3;
   ///Convertir a binario
   string DecToBin(int number);
   int shiftR1(int majorty);
   int shiftR2(int majorty);
   int shiftR3(int majorty);
   //Convertir string de numeros en vector de enteros
   Vector s_to_v(string s);
    ///Mensaje
    Vector message;
public:
   A5(int lfsr1, int lfsr2, int lfsr3);
   ~A5() {};
   void code(string message);
   int majority();
   string to_s();
};
