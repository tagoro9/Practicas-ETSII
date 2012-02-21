#include "a5.h"

A5::A5(int lfsr1, int lfsr2, int lfsr3) {
   LFSR1 = lfsr1;
   LFSR2 = lfsr2;
   LFSR3 = lfsr3;
   printf("%X\n",LFSR1);
   cout << DecToBin(LFSR1) << endl;
   printf("%X\n",LFSR2);
   cout << DecToBin(LFSR2) << endl;
   printf("%X\n",LFSR3);
   cout << DecToBin(LFSR3) << endl;
}

string A5::DecToBin(int number) {
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

//Funcion mayoria
int A5::majority() {
   //cout << "Mayoria" << endl;
   //cout << (5 & 3) << endl;
   //R1 bit 9
   int maskR1 = 256;
   int b9R1 = LFSR1 & maskR1;
   //cout << "Enmascarado: " << DecToBin(b9R1) << endl;
   b9R1 = b9R1 >> 8;
   //cout << b9R1 << endl;
   //cout << DecToBin(maskR1) << endl;
   //cout << maskR1 << endl;
   //R2 bit 11
   int maskR2 = 1024;
   int b11R2 = LFSR2 & maskR2;
   //cout << DecToBin(1024) << endl;
   //cout << DecToBin(LFSR2) << endl;
   //cout << "Enmascarado: " << DecToBin(b11R2) << endl;
   b11R2 = b11R2 >> 10;
   cout << b11R2 << endl;
   //R3 bit 11
   int maskR3 = 1024;
   int b11R3 = LFSR3 & maskR3;
   //cout << DecToBin(maskR3) << endl;
   //cout << DecToBin(LFSR3) << endl;
   //cout << "Enmascarado: " << DecToBin(b11R3) << endl;
   b11R3 = b11R3 >> 10;
   //cout << b11R3 << endl;
   return ((b9R1 & b11R2) ^ (b9R1 & b11R3) ^ (b11R2 & b11R3));
}

int A5::shiftR1(int majority) {
   //Bits 14, 17, 18 y 19
   int m14(8192),m17(65536),m18(131072),m19(262144);
   int b14 = (m14 & LFSR1) >> 13;
   int b17 = (m17 & LFSR1) >> 16;
   int b18 = (m18 & LFSR1) >> 17;
   int b19 = (m19 & LFSR1) >> 18;
   cout << "b14: " << b14 << " b17: " << b17 << " b18: " << b18 << " b19: " << b19 << endl;
   int seq = b14 ^ b17 ^ b18 ^ b19;
   //¿Hay que desplazar?
   int m9 = 256;
   int b9 = (m9 & LFSR1) >> 8;
   if (majority == b9) {
      cout << "Desplazamos" << endl;
      //Meter seq como primer bit
      //Desplazar
      cout << LFSR1 << endl;
      LFSR1 = LFSR1 << 1;
      //Hay que ver si es necesario quitar el ultimo bit al hacer el desplazamineto (en principio no creo)
      cout << LFSR1 << endl;
      if (seq != 0) {
         int md(0x00000001);
         LFSR1 = md | LFSR1;
      }
   }
   cout << "Seq: " << seq << endl;
   cout << "R1: " << DecToBin(LFSR1) << endl;
   cout << "b19: " << b19 << endl;
   return b19;
}

int A5::shiftR2(int majority) {
   //Bits 21 y 22
   int m21(1048576), m22(2097152);
   int b21 = (LFSR2 & m21) >> 20;
   int b22 = (LFSR2 & m22) >> 21;
   cout << "b21: " << b21 << " b22: " << b22 << endl;
   int seq = b21 ^ b22;
   //¿hay que desplazar?
   int m11 = 1024;
   int b11 = (m11 & LFSR2) >> 10;
   if (majority == b11) {
      cout << "Desplazamos" << endl;
      LFSR2 = LFSR2 << 1;
      if (seq != 0) {
         int md(0x00000001);
         LFSR2 = md | LFSR2;
      }
   }
   cout << "Seq: " << seq << endl;
   cout << "R1: " << DecToBin(LFSR2) << endl;
   cout << "b22: " << b22 << endl;
   return b22;
}

int A5::shiftR3(int majority) {
   //Bits 8, 21,22 y 23
   int m8(128),m21(1048576),m22(2097152),m23(4194304);
   int b8 = (m8 & LFSR3) >> 7;
   int b21 = (m21 & LFSR3) >> 20;
   int b22 = (m22 & LFSR3) >> 21;
   int b23 = (m23 & LFSR3) >> 22;
   cout << "b8: " << b8 << " b21: " << b21 << " b22: " << b22 << " b23: " << b23 << endl;
   int seq = b8 ^ b21 ^ b22 ^ b23;
   int m11 = 1024;
   int b11 = (m11 & LFSR3) >> 10;
   //¿Hay que desplazar?
   if (majority == b11) {
      cout << "Desplazamos" << endl;
      LFSR3 = LFSR3 << 1;
      if (seq != 0) {
         int md(0x00000001);
         LFSR3 = md | LFSR3;
      }
   }
   cout << "Seq: " << seq << endl;
   cout << "R3: " << DecToBin(LFSR3) << endl;
   cout << "b23: " << b23 << endl;
   return b23;
}

void A5::code(string message) {
   cout << "Code" << endl;
   cout << "Mayoria: " << majority() << endl;
   //Meter en un bucle en funcion de la longitud del mensaje y listo
   int mjrty = majority();
   cout << shiftR1(mjrty) << endl;
   cout << shiftR2(mjrty) << endl;
   cout << shiftR3(mjrty) << endl;


}

string A5::to_s() {
   return "to_s";
}
