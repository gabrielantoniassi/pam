#include <iostream>
using namespace std;
#include <altivec.h>
#include <cstdlib>

// le um ponteiro de tamanho tam 
void readVec (double* vec, int tam) {
	cout << "insira um vetor de tamanho " << tam << '\n';
	for (int i = 0; i < tam; i++) {
		cin >> vec[i];
	}
}

// printa um ponteiro de tamanho tam
void printAr (double* vec, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

// printa um vetor de tamanho tam
void printVec (__vector double vec, int tam) {
	cout << "printVec:\n";
	for (int i = 0; i < tam; i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

// printa a multiplicacao de duas matrizes a e b de tamanho 4x4
void result (double* a, double* b) {
	double aux;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			aux = 0;
			for (int k = 0; k < 4; k++) {
				aux += a[4*i + k]*b[4*k + j];				
			}
			cout << aux << " ";
		}
		cout << "\n";
	}
}

int main () {
	
	double* ar1 = new double[16];
	double*	ar2 = new double[16];

//	readVec(ar1, 16);
//	readVec(ar2, 16);

	for (int i = 0; i < 16; i++) {
		ar1[i] = rand() % 10;
		ar2[i] = rand() % 10;
	}

	
//	result(ar1, ar2)

	// xijkl representa um vetor x = [xij, xkl], onde x = a, b, sao as matrizes
	__vector double a0000, a0101, a0202, a0303;
	__vector double a1010, a1111, a1212, a1313;
	__vector double a2020, a2121, a2222, a2323;
	__vector double a3030, a3131, a3232, a3333;
	__vector double b0001, b0203, b1011, b1213, b2021, b2223, b3031, b3233;

	/* acho que seria mais rapido se pudesse jogar ar1[0] direto
	 * na vec_mul, pois assim nao perderia tempo atribuindo a
	 * esse monte de vetor que criei.
	 * ou entao se eu fizesse a atribuicao usando paralelismo.
	 */
	a0000[0] = a0000[1] = ar1[0];
	a0101[0] = a0101[1] = ar1[1];
	a0202[0] = a0202[1] = ar1[2];
	a0303[0] = a0303[1] = ar1[3];

	a1010[0] = a1010[1] = ar1[4];
	a1111[0] = a1111[1] = ar1[5];
	a1212[0] = a1212[1] = ar1[6];
	a1313[0] = a1313[1] = ar1[7];

	a2020[0] = a2020[1] = ar1[8];
	a2121[0] = a2121[1] = ar1[9];
	a2222[0] = a2222[1] = ar1[10];
	a2323[0] = a2323[1] = ar1[11];

	a3030[0] = a3030[1] = ar1[12];
	a3131[0] = a3131[1] = ar1[13];
	a3232[0] = a3232[1] = ar1[14];
	a3333[0] = a3333[1] = ar1[15];

	b0001 = vec_xl(0, ar2);	
	b0203 = vec_xl(0, ar2 + 2);
	b1011 = vec_xl(0, ar2 + 4);
	b1213 = vec_xl(0, ar2 + 6);
	b2021 = vec_xl(0, ar2 + 8);
	b2223 = vec_xl(0, ar2 + 10);
	b3031 = vec_xl(0, ar2 + 12);
	b3233 = vec_xl(0, ar2 + 14);
	
	__vector double r0001, r0203, r1011, r1213, r2021, r2223, r3031, r3233;
	// r0001 = [a00b00 + a01b10 + a02b20 + a03b30, a00b01 + a01b11 + a02b21 + a03b31]
	r0001 = vec_madd(a0000, b0001, vec_madd(a0101, b1011, vec_madd(a0202, b2021, vec_mul(a0303, b3031))));
	// r2030 = [a00b02 + a01a12 + a02b22 + a03b32, a00b03 + a01b13 + a02b23 + a03b33]
	r0203 = vec_madd(a0000, b0203, vec_madd(a0101, b1213, vec_madd(a0202, b2223, vec_mul(a0303, b3233))));
	// r1011 = [a10b00 + a11b10 + a12b20 + a13b30, a20b01 + a21b11 + a22b21 + a23b31]
	r1011 = vec_madd(a1010, b0001, vec_madd(a1111, b1011, vec_madd(a1212, b2021, vec_mul(a1313, b3031))));
	// r1213 = [a10b02 + a11b12 + a12b22 + a13b32, a10b03 + a11b13 + a12b23 + a13b33]
	r1213 = vec_madd(a1010, b0203, vec_madd(a1111, b1213, vec_madd(a1212, b2223, vec_mul(a1313, b3233))));
	// r2021 = [a20b00 + a21b10 + a22b20 + a23b30, a20b01 + a21b11 + a22b21 + a23b31]
	r2021 = vec_madd(a2020, b0001, vec_madd(a2121, b1011, vec_madd(a2222, b2021, vec_mul(a2323, b3031))));
	// r2223 = [a20b02 + a21b12 + a22b22 + a23b32, a20b03 + a21b13 + a22b23 + a23b33]
	r2223 = vec_madd(a2020, b0203, vec_madd(a2121, b1213, vec_madd(a2222, b2223, vec_mul(a2323, b3233))));
	// r3031 = [a30b00 + a31b10 + a32b20 + a33b30, a30b01 + a31b11 + a32b21 + a33b31]
	r3031 = vec_madd(a3030, b0001, vec_madd(a3131, b1011, vec_madd(a3232, b2021, vec_mul(a3333, b3031))));
	// r3233 = [a30b02 + a31b12 + a32b22 + a33b32, a30b03 + a31b13 + a32b23 + a33b33]
	r3233 = vec_madd(a3030, b0203, vec_madd(a3131, b1213, vec_madd(a3232, b2223, vec_mul(a3333, b3233))));

	// print da matriz resultado
	cout << r0001[0] << " " << r0001[1] << " " << r0203[0] << " " << r0203[1] << "\n";
	cout << r1011[0] << " " << r1011[1] << " " << r1213[0] << " " << r1213[1] << "\n";
	cout << r2021[0] << " " << r2021[1] << " " << r2223[0] << " " << r2223[1] << "\n";
	cout << r3031[0] << " " << r3031[1] << " " << r3233[0] << " " << r3233[1] << "\n";

	return 0;
}
