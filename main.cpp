#include <iostream>
#include <altivec.h>
using namespace std;

#include "matrix1.h"

int main () {

	SMatrix<double, 4, 4> m1(1);
	SMatrix<double, 4, 4> m2(1);

	for (int i = 0; i < 4*4; i++) {
		m1.m_data[i] = i + 1f;
		m2.m_data[i] = i + 4*4 + 1f;
	}

	cout << m1 << endl << m2 << endl;


	SMatrix<double, 4, 4> mr =  m1.mul4x4(m2);

	cout << mr;

	return 0;
}
