//Programa principal

#include "lib/des/des.h"


int main(int argc, char *argv[]) {
	//Tercer argumento el modo
	//Primer argumento la semilla
	Des des(argv[1],argv[3][0]);
	//Segundo argumento el mensaje
	des.code(argv[2],argv[3][0]);
	return 0;
}
