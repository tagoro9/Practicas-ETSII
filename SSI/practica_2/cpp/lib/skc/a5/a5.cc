#include "a5.h"

A5::A5(int lfsr1, int lfsr2, int lfsr3) {
   LFSR1 = lfsr1;
   LFSR2 = lfsr2;
   LFSR3 = lfsr3;
}

//Funcion mayoria
int A5::majority() {
   //R1 bit 9
   int maskR1 = 256;
   int b9R1 = LFSR1 & maskR1;
   b9R1 = b9R1 >> 8;
   //R2 bit 11
   int maskR2 = 1024;
   int b11R2 = LFSR2 & maskR2;
   b11R2 = b11R2 >> 10;
   //R3 bit 11
   int maskR3 = 1024;
   int b11R3 = LFSR3 & maskR3;
   b11R3 = b11R3 >> 10;
   return ((b9R1 & b11R2) ^ (b9R1 & b11R3) ^ (b11R2 & b11R3));
}

int A5::shiftR1(int majority) {
   //Bits 14, 17, 18 y 19
   int m14(8192),m17(65536),m18(131072),m19(262144);
   int b14 = (m14 & LFSR1) >> 13;
   int b17 = (m17 & LFSR1) >> 16;
   int b18 = (m18 & LFSR1) >> 17;
   int b19 = (m19 & LFSR1) >> 18;
   int seq = b14 ^ b17 ^ b18 ^ b19;
   //¿Hay que desplazar?
   int m9 = 256;
   int b9 = (m9 & LFSR1) >> 8;
   if (majority == b9) {
      //Meter seq como primer bit
      //Desplazar
      LFSR1 = LFSR1 << 1;
      if (seq != 0) {
         int md(0x00000001);
         LFSR1 = md | LFSR1;
      }
   }
   return b19;
}

int A5::shiftR2(int majority) {
   //Bits 21 y 22
   int m21(1048576), m22(2097152);
   int b21 = (LFSR2 & m21) >> 20;
   int b22 = (LFSR2 & m22) >> 21;
   int seq = b21 ^ b22;
   //¿hay que desplazar?
   int m11 = 1024;
   int b11 = (m11 & LFSR2) >> 10;
   if (majority == b11) {
      LFSR2 = LFSR2 << 1;
      if (seq != 0) {
         int md(0x00000001);
         LFSR2 = md | LFSR2;
      }
   }
   return b22;
}

int A5::shiftR3(int majority) {
   //Bits 8, 21,22 y 23
   int m8(128),m21(1048576),m22(2097152),m23(4194304);
   int b8 = (m8 & LFSR3) >> 7;
   int b21 = (m21 & LFSR3) >> 20;
   int b22 = (m22 & LFSR3) >> 21;
   int b23 = (m23 & LFSR3) >> 22;
   int seq = b8 ^ b21 ^ b22 ^ b23;
   int m11 = 1024;
   int b11 = (m11 & LFSR3) >> 10;
   //¿Hay que desplazar?
   if (majority == b11) {
      LFSR3 = LFSR3 << 1;
      if (seq != 0) {
         int md(0x00000001);
         LFSR3 = md | LFSR3;
      }
   }
   return b23;
}

void A5::code(string msg) {
   Vector in_message = s_to_v(msg);
   _message.clear();
   for (int k=0; k < in_message.size(); k++) {
      int byte_cifr = 0;
      int bit_cifr = 0;
      for (int i =0; i < 8;i++) {
         int mjrty = majority();
         bit_cifr = (shiftR1(mjrty) ^ shiftR2(mjrty) ^ shiftR3(mjrty));
         byte_cifr = byte_cifr << 1;
         if (bit_cifr != 0) {
            int md(0x00000001);
            byte_cifr = md | byte_cifr;
         }
      }
      _message.push_back((in_message[k] ^ byte_cifr));
   }
}

