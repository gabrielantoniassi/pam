#include <iostream>
#include <stdio.h>
#include "SMatrix.h"
#include "4x4Strassen.cpp"
#include "4x4hybrid.cpp"
#include <chrono> 
using namespace std; 
using namespace std::chrono; 

int main() {

	long int iter = 100000000;

	double a, b, sum, prod;

	// sum
	auto start = high_resolution_clock::now();
		
	for (int i = 0; i < iter; i++) {
		a = rand() % 1000;
		b = rand() % 1000;
		sum = a + b;
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by sum: "
        	<< duration.count() << " microseconds" << endl;

	// product
	start = high_resolution_clock::now();
		
	for (int i = 0; i < iter; i++) {
		a = rand() % 1000;
		b = rand() % 1000;
		prod = a*b;
	}

	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by pro: "
        	<< duration.count() << " microseconds" << endl;

	return 0;
}
