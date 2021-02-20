#include <iostream>
#include "4x4hybridvec.h"
using namespace std;

int main () {

	double *a = new double[16];
	double *b = new double[16];
	double *c = new double[16];

	for (int i = 0; i < 16; i++) {
		a[i] = 1 + i;
		b[i] = 1 + i;
	}

	hhybrid(a, b, c);

	for (int i = 0; i < 16; i++) {
		cout << c[i] << endl;
	}		

	return 0;
}
