#include <iostream>
#include <altivec.h>
using namespace std;

#include "matrix1.h"

int main () {

	SMatrix<double, 4, 4> m1;
	SMatrix<double, 4, 4> m2;
	SMatrix<double, 4, 4> mr;

	for (int i = 0; i < 4*4; i++) {
		m1.m_data[i] = i + 1;
		m2.m_data[i] = i + 4*4 + 1;
	}

	m1.printMat();
	cout << "\n";
	m2.printMat();
	cout << "\n";

	mr = m1.mul(m2);

	mr.printMat();

	return 0;
}
