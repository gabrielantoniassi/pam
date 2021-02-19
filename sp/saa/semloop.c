#include <stdio.h>
#include <time.h>

int main () {

	double r, x, y, z, s, m, t1, t2;
	int i;
	clock_t ti, tf;

	r = 3.63;
	z = 0.22;
	y = 0;

	asm("# primeiro loop");
	ti = clock();
	z = r*z*(1 - z);
	y += z;	// talvez o compilador otimize esse comando pra virar uma multiplicação
	tf = clock();
	t1 = (double) tf - ti;

	x = 0.15;
	x = (x + z)/2;

	asm("# segundo loop");
	ti = clock();
	x = r*x*(1 - x);
	tf = clock();
	t2 = (double) tf - ti;

	s = t1 - t2;
	m = t2 - t1/2;

	printf("m/s = %f\n", m/s);
	printf("soh pro compilador nao tirar: %f %f %f\n", z, y, x);

	return 0;
}
