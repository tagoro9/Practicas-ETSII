#include "rc4.h"

using namespace std;

//Constructor
//Se inicializan los vectores S y K tomando como entrada la semilla
rc4::rc4(Vector clave) {
   for (int i = 0; i < SIZE; i++) {
      S[i] = i;
      K[i] = clave[i % (clave.size())];
   }
   for (int i(0),f(0),aux; i < SIZE; i++) {
      f = (f + S[i] + K[i]) % SIZE;
      aux = S[i];
      S[i] = S[f];
      S[f] = aux;
   }
}

//En esta funcion a la que se pasa como argumento el mensaje, se obtiene la secuencia cifrante y
//se devuelve el mensaje cifrado
Vector rc4::cifrar(Vector mensaje) {
      Vector cifrado;
   for (int j(0),f(0),i(0),aux; j < mensaje.size(); j++) {
      i = (i + 1) % SIZE;
      f = (f + S[i]) % SIZE;
      aux = S[i];
      S[i] = S[f];
      S[f] = aux;
      cifrado.push_back(mensaje[j] ^ S[(S[i] + S[f]) % SIZE]); //XOR entre el byte del mensaje y S[t]
   }
   return cifrado;
}

//Esta funcion permite mostrar por pantalla el contenido de un mensaje
void rc4::imprimir(Vector mensaje) {
   for (int i = 0; i < mensaje.size(); i++)
      cout << (int) mensaje[i] << " ";
   cout << endl;
}
