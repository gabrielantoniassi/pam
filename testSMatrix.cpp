#include <iostream>
#include <stdio.h>
#include "SMatrix.h"

int main()
{
	//9x9
	for (int i = 0; i < 1000; i++) {
		SMatrix<double, 9, 9> sm1(i), sm2(i);
		SMatrix<double, 9, 9> sm3;
	       sm3 = sm1.mul<9>(sm2);
	}
	std::cout << sm3 << std::endl;

 return 0;
}
