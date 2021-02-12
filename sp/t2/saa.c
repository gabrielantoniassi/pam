#include <stdio.h>
#include <time.h>
#include <altivec.h>
#include <sys/platform/ppc.h>

int main () {

	double r, x, y, z, s, m, t1, t2;
	int i, ITMAX = 500000000;
	clock_t ti, tf;	

	r = 3.63;
	z = 0.22;
	y = 0;

	asm("# primeiro loop");
	ti = __ppc_get_timebase();
	for (i = 0; i < ITMAX; i++) {
		z = r*z*(1 - z);
		y += z;
	}
	tf = __ppc_get_timebase();
	t1 = (double) tf - ti;

	x = 0.15;
	x = (x + z)/2;

	asm("# segundo loop");
	ti = __ppc_get_timebase();
	for (i = 0; i < ITMAX; i++)
		x = r*x*(1 - x);
	tf = __ppc_get_timebase();
	t2 = (double) tf - ti;

	s = t1 - t2;
	m = t2 - t1/2;

	asm("# printando");
	printf("m/s = %f\n", m/s);
	printf("soh pro compilador nao tirar: %f %f %f\n", z, y, x);
	asm("# final");

	return 0;
}
