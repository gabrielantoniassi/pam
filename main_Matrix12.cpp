#include <iostream>
#include "Matrix12.h"

int main() {

	SMatrix<double, 12, 12, ColMajor> m1;
	SMatrix<double, 12, 12> m2;

	for (int i = 0; i < 12*12; i++) {
		m1.m_data[i] = i + 1;
		m2.m_data[i] = i + 1 + 12*12;
	}

	SMatrix<double, 12, 12> m3 = m1.mul<12, 12>(m2);

	std::cout << m3;

	return 0;
}
