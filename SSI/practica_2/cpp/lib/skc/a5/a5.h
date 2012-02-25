#ifndef A5_H_
#define A5_H_

#include "../skc.h"
#include <stdio.h>

class A5 : public Skc{
private:
	///Registros de desplazamiento
	//19 bits
	int LFSR1;
	//22 bits
	int LFSR2;
	//23 bits
	int LFSR3;
	int shiftR1(int majorty);
	int shiftR2(int majorty);
	int shiftR3(int majorty);
	int majority();
public:
	A5(int lfsr1, int lfsr2, int lfsr3);
	~A5() {};
	void code(string msg);
};

#endif /* A5_H_ */
