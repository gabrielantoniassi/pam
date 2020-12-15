#include <iostream>
#include <stdio.h>
#include "SMatrix.h"
#include <chrono> 
using namespace std; 
using namespace std::chrono; 

int main()
{
	auto start = high_resolution_clock::now();
		
	for (int i = 0; i < 20000000; i++) {
		SMatrix<double, 9, 9> sm1(i), sm2(i);
		SMatrix<double, 9, 9> sm3 = sm1.mul<9>(sm2);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
        	<< duration.count() << " seconds" << endl;


 return 0;
}
