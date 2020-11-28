#include <iostream>
#include "Matrix_12inside.h"
using namespace std;

int main() {

	SMatrix<double, 12, 12> m1, m2;

	for (int i = 0; i < 12*12; i++) {
		m1.m_data[i] = i + 1;
		m2.m_data[i] = i + 1 + 12*12;
	}

	SMatrix<double, 12, 12> m3 = m1.mul<12, 12>(m2);

	cout << m3;

	return 0;
}
