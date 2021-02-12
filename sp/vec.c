#include <stdio.h>
#include <time.h>
#include <altivec.h>
#include <sys/platform/ppc.h>

int main () {

	int i, max = 1000000000;
	double a = 3.1415, b = 2.7182, ts, tm, tl;
	clock_t ti, tf;

	double e[2], pi[2], res1[2], res2[2], res3[2];
	e[0] = 2.7182;
	e[1] = 2.7182;
	pi[0] = 3.1415;
	pi[1] = 3.1415;

	__vector double ev, piv;
	ev = vec_xl(0, e);
	piv = vec_xl(0, pi);


	//ti = clock();
	//
	ti = __ppc_get_timebase();
	asm("# soma");
	vec_xst(vec_add(ev, piv), 0, res1);
	tf = __ppc_get_timebase();
	ts = (double) tf - ti;
	printf("ts = %f\n", ts);

	ti = __ppc_get_timebase();
	asm("# mul");
	vec_xst(vec_mul(ev, piv), 0, res2);
	tf = __ppc_get_timebase();
	tm = (double) tf - ti;
	printf("tm = %f\n", tm);

	asm("# printando");
	printf("m/s = %f\n", tm/ts);
	asm("# final");

	return 0;
}
