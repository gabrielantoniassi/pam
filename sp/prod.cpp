#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
int main() {

	long int iter = 1000000000;
	double a = rand() % 100, b = rand() % 100, c;

	auto start = high_resolution_clock::now();

	asm("# antes");
	for (int i = 0; i < iter; i++) 
		c = a*b;
	asm("# depois");
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by prod: "
        	<< duration.count() << " microseconds" << endl;
/*
	start = high_resolution_clock::now();

	asm("# antes2");
	for (int i = 0; i < iter; i++) {
		a = rand() % 100;
		b = rand() % 100;
	}
	asm("# depois2");
	
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by prod: "
        	<< duration.count() << " microseconds" << endl;
*/
	return 0;
}
