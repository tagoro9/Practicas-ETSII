#include "lib/aes/aes.h"

int main(int argc, char* argv[]) {
	//Tercer argumento el modo
	//Primer argumento la semilla
	Aes aes(argv[1],argv[3][0]);
	//Segundo argumento el mensaje
	aes.code(argv[2],argv[3][0]);
	return 0;
}
