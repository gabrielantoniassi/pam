#include <iostream>
#include <stdio.h>
#include "SMatrix.h"
#include "4x4hybridvec.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {

	int iter = 3000000;

	// // Strassen
	// auto start = high_resolution_clock::now();
	//
	// for (int i = 0; i < iter; i++) {
	// 	SMatrix<double, 4, 4> sm1(i), sm2(i);
	// 	SMatrix<double, 4, 4> sm3 = Strassen(sm1, sm2);
	// }
	//
	// auto stop = high_resolution_clock::now();
	// auto duration = duration_cast<microseconds>(stop - start);
	// cout << "Time taken by Strassen function: "
    //     	<< duration.count() << " microseconds" << endl;

	// hybrid
	auto start = high_resolution_clock::now();

	for (int i = 0; i < iter; i++) {
		SMatrix<double, 4, 4> sm1(i), sm2(i);
		SMatrix<double, 4, 4> sm3;
		hhybrid((double*) sm1.m_data, (double*) sm2.m_data, (double*) sm3.m_data);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by hydrid function: "
        	<< duration.count() << " microseconds" << endl;

	// mul
	start = high_resolution_clock::now();

	for (int i = 0; i < iter; i++) {
		SMatrix<double, 4, 4> sm1(i), sm2(i);
		SMatrix<double, 4, 4> sm3 = sm1.mul<4>(sm2);
	}

	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by mul function: "
        	<< duration.count() << " microseconds" << endl;


	return 0;
}
