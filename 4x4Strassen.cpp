#include <iostream>
using namespace std;
#include "SMatrix.h"

SMatrix<double, 4, 4> Strassen(SMatrix<double, 4, 4> A, SMatrix<double, 4, 4> B) {


	double m[50];

	m[1] = (A(0,0)+A(1,1)+A(2,2)+A(3,3))*(B(0,0)+B(1,1)+B(2,2)+B(3,3));
	m[2] = (A(0,1)-A(1,1)+A(2,3)-A(3,3))*(B(1,0)+B(1,1)+B(3,2)+B(3,3));
	m[3] = (A(1,0)-A(0,0)-A(2,2)+A(3,2))*(B(0,0)+B(0,1)+B(2,2)+B(2,3));
	m[4] = (A(0,0)+A(0,1)+A(2,2)+A(2,3))*(B(1,1)+B(3,3));
	m[5] = (A(0,0)+A(2,2))*(-B(1,1)+B(0,1)+B(2,3)-B(3,3));
	m[6] = (A(1,1)+A(3,3))*(B(1,0)-B(0,0)-B(2,2)+B(3,2));
	m[7] = (A(1,0)+A(1,1)+A(3,2)+A(3,3))*(B(0,0)+B(2,2));

	m[8] = (A(0,2)-A(2,2)+A(1,3)-A(3,3))*(B(2,0)+B(3,1)+B(2,2)+B(3,3));
	m[9] = (A(0,3)-A(1,3)-A(2,3)+A(3,3))*(B(3,0)+B(3,1)+B(3,2)+B(3,3));
	m[10] = (-A(0,2)+A(1,2)+A(2,2)-A(3,2))*(B(2,0)+B(2,1)+B(2,2)+B(2,3));
	m[11] = (A(0,2)-A(2,2)+A(0,3)-A(2,3))*(B(3,1)+B(3,3));
	m[12] = (A(0,2)-A(2,2))*(B(2,1)-B(3,1)+B(2,3)-B(3,3));
	m[13] = (A(1,3)-A(3,3))*(-B(2,0)+B(3,0)-B(2,2)+B(3,2));
	m[14] = (A(1,2)-A(3,2)+A(1,3)-A(3,3))*(B(2,0)+B(2,2));

	m[15] = (-A(0,0)+A(2,0)-A(1,1)+A(3,1))*(B(0,0)+B(1,1)+B(0,2)+B(1,3));
	m[16] = (-A(0,1)+A(1,1)+A(2,1)-A(3,1))*(B(1,0)+B(1,1)+B(1,2)+B(1,3));
	m[17] = (A(0,0)-A(1,0)-A(2,0)+A(3,0))*(B(0,0)+B(0,1)+B(0,2)+B(0,3));
	m[18] = (-A(0,0)+A(2,0)-A(0,1)+A(2,1))*(B(1,1)+B(1,3));
	m[19] = (-A(0,0)+A(2,0))*(-B(1,1)+B(0,1)+B(0,3)-B(1,3));
	m[20] = (-A(1,1)+A(3,1))*(B(1,0)-B(0,0)+B(1,2)-B(0,2));
	m[21] = (-A(1,0)+A(3,0)-A(1,1)+A(3,1))*(B(0,0)+B(0,2));

	m[22] = (A(0,0)+A(1,1)+A(0,2)+A(1,3))*(B(2,2)+B(3,3));
	m[23] = (A(0,1)-A(1,1)+A(0,3)-A(1,3))*(B(3,2)+B(3,3));
	m[24] = (A(1,0)-A(0,0)+A(1,2)-A(0,2))*(B(2,2)+B(2,3));
	m[25] = (A(0,0)+A(0,1)+A(0,2)+A(0,3))*(B(3,3));
	m[26] = (A(0,0)+A(0,2))*(B(2,3)-B(3,3));
	m[27] = (A(1,1)+A(1,3))*(-B(2,2)+B(3,2));
	m[28] = (A(1,0)+A(1,1)+A(1,2)+A(1,3))*(B(2,2));

	m[29] = (A(0,0)+A(1,1))*(B(0,2)-B(2,2)+B(1,3)-B(3,3));
	m[30] = (A(0,1)-A(1,1))*(B(1,2)-B(3,2)+B(1,3)-B(3,3));
	m[31] = (A(1,0)-A(0,0))*(B(0,2)-B(2,2)+B(0,3)-B(2,3));
	m[32] = (A(0,1)+A(0,0))*(B(1,3)-B(3,3));
	m[33] = (A(0,0))*(B(0,3)-B(1,3)-B(2,3)+B(3,3));
	m[34] = (A(1,1))*(-B(0,2)+B(1,2)+B(2,2)-B(3,2));
	m[35] = (A(1,1)+A(1,0))*(B(0,2)-B(2,2));

	m[36] = (A(2,2)+A(3,3))*(-B(0,0)+B(2,0)-B(1,1)+B(3,1));
	m[37] = (A(2,3)-A(3,3))*(-B(1,0)+B(3,0)-B(1,1)+B(3,1));
	m[38] = (-A(2,2)+A(3,2))*(-B(0,0)+B(2,0)-B(0,1)+B(2,1));
	m[39] = (A(2,3)+A(2,2))*(-B(1,1)+B(3,1));
	m[40] = (A(2,2))*(-B(0,1)+B(1,1)+B(2,1)-B(3,1));
	m[41] = (A(3,3))*(B(0,0)-B(1,0)-B(2,0)+B(3,0));
	m[42] = (A(3,2)+A(3,3))*(-B(0,0)+B(2,0));

	m[43] = (A(2,0)+A(3,1)+A(2,2)+A(3,3))*(B(1,1)+B(0,0));
	m[44] = (-A(3,1)+A(2,1)+A(2,3)-A(3,3))*(B(1,0)+B(1,1));
	m[45] = (-A(2,0)+A(3,0)-A(2,2)+A(3,2))*(B(0,0)+B(0,1));
	m[46] = (A(2,0)+A(2,1)+A(2,2)+A(2,3))*(B(1,1));
	m[47] = (A(2,0)+A(2,2))*(-B(1,1)+B(0,1));
	m[48] = (A(3,1)+A(3,3))*(B(1,0)-B(0,0));
	m[49] = (A(3,0)+A(3,1)+A(3,2)+A(3,3))*(B(0,0));

	SMatrix<double, 4, 4> C(0);

	C(0,0) = m[41]+m[6]+m[8]+m[9]-m[11]+m[13]-m[22]-m[23]+m[25]-m[27]+m[36]+m[37]-m[39]+m[1]+m[2]-m[4];
	C(1,0) = m[41]+m[42]+m[6]+m[7]+m[13]+m[14]-m[27]-m[28];
	C(2,0) = m[41]+m[43]+m[44]-m[46]+m[48]+m[36]+m[37]-m[39];
	C(3,0) = m[41]+m[42]+m[48]+m[49];

	C(0,1) = m[40]+m[11]+m[12]-m[25]-m[26]+m[39]+m[4]+m[5];
	C(1,1) = m[40]-m[42]-m[7]+m[8]+m[10]+m[12]-m[14]-m[22]-m[24]-m[26]+m[28]+m[36]+m[38]+m[1]+m[3]+m[5];
	C(2,1) = m[40]+m[46]+m[47]+m[39];
	C(3,1) = m[40]-m[42]+m[43]+m[45]+m[47]-m[49]+m[36]+m[38];

	C(0,2) = m[22]+m[23]-m[25]+m[27]+m[29]+m[30]-m[32]+m[34];
	C(1,2) = m[27]+m[28]+m[34]+m[35];
	C(2,2) = -m[43]-m[44]+m[46]-m[48]+m[6]+m[15]+m[16]-m[18]+m[20]+m[29]+m[30]-m[32]+m[34]+m[1]+m[2]-m[4];
	C(3,2) = -m[48]-m[49]+m[6]+m[7]+m[20]+m[21]+m[34]+m[35];

	C(0,3) = m[25]+m[26]+m[32]+m[33];
	C(1,3) = m[22]+m[24]+m[26]-m[28]+m[29]+m[31]+m[33]-m[35];
	C(2,3) = -m[46]-m[47]+m[18]+m[19]+m[32]+m[33]+m[4]+m[5];
	C(3,3) = -m[43]-m[45]-m[47]+m[49]-m[7]+m[15]+m[17]+m[19]-m[21]+m[29]+m[31]+m[33]-m[35]+m[1]+m[3]+m[5];

	return C;
}

/*
void randMat(double data[], int tam) {
	for (int i = 0; i < tam*tam; i++)
		data[i] = rand() % 100; // random number between 0 and 99
}

int main() {

	SMatrix<double, 4, 4> A, B, C(0);

	randMat(A.m_data, 4);
	randMat(B.m_data, 4);

	double m[50];

	m[1] = (A(0,0)+A(1,1)+A(2,2)+A(3,3))*(B(0,0)+B(1,1)+B(2,2)+B(3,3));
	m[2] = (A(0,1)-A(1,1)+A(2,3)-A(3,3))*(B(1,0)+B(1,1)+B(3,2)+B(3,3));
	m[3] = (A(1,0)-A(0,0)-A(2,2)+A(3,2))*(B(0,0)+B(0,1)+B(2,2)+B(2,3));
	m[4] = (A(0,0)+A(0,1)+A(2,2)+A(2,3))*(B(1,1)+B(3,3));
	m[5] = (A(0,0)+A(2,2))*(-B(1,1)+B(0,1)+B(2,3)-B(3,3));
	m[6] = (A(1,1)+A(3,3))*(B(1,0)-B(0,0)-B(2,2)+B(3,2));
	m[7] = (A(1,0)+A(1,1)+A(3,2)+A(3,3))*(B(0,0)+B(2,2));

	m[8] = (A(0,2)-A(2,2)+A(1,3)-A(3,3))*(B(2,0)+B(3,1)+B(2,2)+B(3,3));
	m[9] = (A(0,3)-A(1,3)-A(2,3)+A(3,3))*(B(3,0)+B(3,1)+B(3,2)+B(3,3));
	m[10] = (-A(0,2)+A(1,2)+A(2,2)-A(3,2))*(B(2,0)+B(2,1)+B(2,2)+B(2,3));
	m[11] = (A(0,2)-A(2,2)+A(0,3)-A(2,3))*(B(3,1)+B(3,3));
	m[12] = (A(0,2)-A(2,2))*(B(2,1)-B(3,1)+B(2,3)-B(3,3));
	m[13] = (A(1,3)-A(3,3))*(-B(2,0)+B(3,0)-B(2,2)+B(3,2));
	m[14] = (A(1,2)-A(3,2)+A(1,3)-A(3,3))*(B(2,0)+B(2,2));

	m[15] = (-A(0,0)+A(2,0)-A(1,1)+A(3,1))*(B(0,0)+B(1,1)+B(0,2)+B(1,3));
	m[16] = (-A(0,1)+A(1,1)+A(2,1)-A(3,1))*(B(1,0)+B(1,1)+B(1,2)+B(1,3));
	m[17] = (A(0,0)-A(1,0)-A(2,0)+A(3,0))*(B(0,0)+B(0,1)+B(0,2)+B(0,3));
	m[18] = (-A(0,0)+A(2,0)-A(0,1)+A(2,1))*(B(1,1)+B(1,3));
	m[19] = (-A(0,0)+A(2,0))*(-B(1,1)+B(0,1)+B(0,3)-B(1,3));
	m[20] = (-A(1,1)+A(3,1))*(B(1,0)-B(0,0)+B(1,2)-B(0,2));
	m[21] = (-A(1,0)+A(3,0)-A(1,1)+A(3,1))*(B(0,0)+B(0,2));

	m[22] = (A(0,0)+A(1,1)+A(0,2)+A(1,3))*(B(2,2)+B(3,3));
	m[23] = (A(0,1)-A(1,1)+A(0,3)-A(1,3))*(B(3,2)+B(3,3));
	m[24] = (A(1,0)-A(0,0)+A(1,2)-A(0,2))*(B(2,2)+B(2,3));
	m[25] = (A(0,0)+A(0,1)+A(0,2)+A(0,3))*(B(3,3));
	m[26] = (A(0,0)+A(0,2))*(B(2,3)-B(3,3));
	m[27] = (A(1,1)+A(1,3))*(-B(2,2)+B(3,2));
	m[28] = (A(1,0)+A(1,1)+A(1,2)+A(1,3))*(B(2,2));

	m[29] = (A(0,0)+A(1,1))*(B(0,2)-B(2,2)+B(1,3)-B(3,3));
	m[30] = (A(0,1)-A(1,1))*(B(1,2)-B(3,2)+B(1,3)-B(3,3));
	m[31] = (A(1,0)-A(0,0))*(B(0,2)-B(2,2)+B(0,3)-B(2,3));
	m[32] = (A(0,1)+A(0,0))*(B(1,3)-B(3,3));
	m[33] = (A(0,0))*(B(0,3)-B(1,3)-B(2,3)+B(3,3));
	m[34] = (A(1,1))*(-B(0,2)+B(1,2)+B(2,2)-B(3,2));
	m[35] = (A(1,1)+A(1,0))*(B(0,2)-B(2,2));

	m[36] = (A(2,2)+A(3,3))*(-B(0,0)+B(2,0)-B(1,1)+B(3,1));
	m[37] = (A(2,3)-A(3,3))*(-B(1,0)+B(3,0)-B(1,1)+B(3,1));
	m[38] = (-A(2,2)+A(3,2))*(-B(0,0)+B(2,0)-B(0,1)+B(2,1));
	m[39] = (A(2,3)+A(2,2))*(-B(1,1)+B(3,1));
	m[40] = (A(2,2))*(-B(0,1)+B(1,1)+B(2,1)-B(3,1));
	m[41] = (A(3,3))*(B(0,0)-B(1,0)-B(2,0)+B(3,0));
	m[42] = (A(3,2)+A(3,3))*(-B(0,0)+B(2,0));

	m[43] = (A(2,0)+A(3,1)+A(2,2)+A(3,3))*(B(1,1)+B(0,0));
	m[44] = (-A(3,1)+A(2,1)+A(2,3)-A(3,3))*(B(1,0)+B(1,1));
	m[45] = (-A(2,0)+A(3,0)-A(2,2)+A(3,2))*(B(0,0)+B(0,1));
	m[46] = (A(2,0)+A(2,1)+A(2,2)+A(2,3))*(B(1,1));
	m[47] = (A(2,0)+A(2,2))*(-B(1,1)+B(0,1));
	m[48] = (A(3,1)+A(3,3))*(B(1,0)-B(0,0));
	m[49] = (A(3,0)+A(3,1)+A(3,2)+A(3,3))*(B(0,0));

	C(0,0) = m[41]+m[6]+m[8]+m[9]-m[11]+m[13]-m[22]-m[23]+m[25]-m[27]+m[36]+m[37]-m[39]+m[1]+m[2]-m[4];
	C(1,0) = m[41]+m[42]+m[6]+m[7]+m[13]+m[14]-m[27]-m[28];
	C(2,0) = m[41]+m[43]+m[44]-m[46]+m[48]+m[36]+m[37]-m[39];
	C(3,0) = m[41]+m[42]+m[48]+m[49];

	C(0,1) = m[40]+m[11]+m[12]-m[25]-m[26]+m[39]+m[4]+m[5];
	C(1,1) = m[40]-m[42]-m[7]+m[8]+m[10]+m[12]-m[14]-m[22]-m[24]-m[26]+m[28]+m[36]+m[38]+m[1]+m[3]+m[5];
	C(2,1) = m[40]+m[46]+m[47]+m[39];
	C(3,1) = m[40]-m[42]+m[43]+m[45]+m[47]-m[49]+m[36]+m[38];

	C(0,2) = m[22]+m[23]-m[25]+m[27]+m[29]+m[30]-m[32]+m[34];
	C(1,2) = m[27]+m[28]+m[34]+m[35];
	C(2,2) = -m[43]-m[44]+m[46]-m[48]+m[6]+m[15]+m[16]-m[18]+m[20]+m[29]+m[30]-m[32]+m[34]+m[1]+m[2]-m[4];
	C(3,2) = -m[48]-m[49]+m[6]+m[7]+m[20]+m[21]+m[34]+m[35];

	C(0,3) = m[25]+m[26]+m[32]+m[33];
	C(1,3) = m[22]+m[24]+m[26]-m[28]+m[29]+m[31]+m[33]-m[35];
	C(2,3) = -m[46]-m[47]+m[18]+m[19]+m[32]+m[33]+m[4]+m[5];
	C(3,3) = -m[43]-m[45]-m[47]+m[49]-m[7]+m[15]+m[17]+m[19]-m[21]+m[29]+m[31]+m[33]-m[35]+m[1]+m[3]+m[5];

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << C - A.mul<4>(B) << endl;
}
*/
