#include <vector>
#include <iostream>

using namespace std;

int const SIZE = 256;
//Estructura vector de la STL
typedef vector <unsigned char> Vector;

class rc4 {
   private:
      ///Vector de bytes S (unsigned char)
      unsigned char S[SIZE];
      ///Vector de bytes K (unsigend char)
      unsigned char K[SIZE];
   public:
      /**
      Constructor en el que se inicializan los vectores S y K a partir de la clave
      que se pasa como parametro
      @param Valor de la semilla
      **/
      rc4(Vector clave);
      ///Destructor. No se hace nada
      ~rc4() {};
      /**
      Funcion cifra. Aqui se genera la secuencia cifrante y se devuelve el mensaje cifrado
      @param Mensaje que se quiere cifrar
      @return Mensaje cifrado
      **/
      Vector cifrar(Vector mensaje);
      /**
      Esta funcion permite mostrar por pantalla el contenido de cualquier mensaje
      @param Mensaje que se desea mostrar por pantalla
      **/
      void imprimir(Vector mensaje);
};
