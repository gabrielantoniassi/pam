#include <stdio.h>
#include <time.h>
#include <altivec.h>
#include <sys/platform/ppc.h>

int main () {

	double ts, tm;
	clock_t ti, tf;

	double e[2], pi[2], res1[2], res2[2];
	e[0] = 1.2;
	e[1] = 1.4;
	pi[0] = 1.5;
	pi[1] = 1.7;

	__vector double ev, piv;
	ev = vec_xl(0, e);
	piv = vec_xl(0, pi);

	asm("# soma");
	ti = __ppc_get_timebase();
	vec_xst(vec_add(ev, piv), 0, res1);
	tf = __ppc_get_timebase();
	ts = (double) tf - ti;
	printf("ts = %f\n", ts);
	
	asm("# mul");
	ti = __ppc_get_timebase();
	vec_xst(vec_mul(ev, piv), 0, res2);
	tf = __ppc_get_timebase();
	tm = (double) tf - ti;
	printf("tm = %f\n", tm);

	asm("# printando");
	printf("m/s = %f\n", tm/ts);
	printf("soh pro compilador nao remover: %f %f %f %f\n", res1[0], res1[1], res2[0], res2[1]);
	asm("# final");

	return 0;
}
