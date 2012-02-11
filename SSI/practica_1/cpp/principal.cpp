#include "rc4.h"
#include <fstream>

using namespace std;

//Leer desde pantalla el contenido de un mensaje o una clave
Vector leer() {
   Vector aux;
   int lectura;
   while (cin.peek() != '\n') {
      cin >> lectura;
      aux.push_back((unsigned char) lectura);
   }
   cin.get();
   return aux;
}

int main(int argc, char *argv[]) {
   cout << "Introduzca el valor de la semilla separada por espacios: ";
   Vector clave = leer();
   cout << "Introduzca el valor del mensaje separado por espacios: ";
   Vector mensaje = leer();
   rc4 prueba(clave);
   Vector cifrado = prueba.cifrar(mensaje);
   cout << "Salida: ";
   prueba.imprimir(cifrado);
}
