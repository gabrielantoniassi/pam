#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
#include <altivec.h>

int main() {

	long int iter = 1000000000;
	double a_aux[2], b_aux[2];
	double *c = new double[2];
	
	a_aux[0] = rand() % 100;
	a_aux[1] = rand() % 100;
	b_aux[0] = rand() % 100;
	b_aux[1] = rand() % 100;

	__vector double a = vec_xl(0, a_aux);
	__vector double b = vec_xl(0, b_aux);

	auto start = high_resolution_clock::now();

	asm("# antes");
	for (int i = 0; i < iter; i++) 
		vec_xst(vec_mul(a, b), 0, c);
	asm("# depois");
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken: "
        	<< duration.count() << " microseconds" << endl;


	return 0;
}
