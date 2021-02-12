#include <stdio.h>
#include <time.h>
#include <altivec.h>

int main () {

	int i, max = 1000000000;
	double a = 3.1415, b = 2.7182, ts, tm, tl;
	clock_t ti, tf;

	double e[2], pi[2], res[2];
	e[0] = 2.7182;
	e[1] = 2.7182;
	pi[0] = 3.1415;
	pi[1] = 3.1415;

	__vector double ev, piv;
	ev = vec_xl(0, e);
	piv = vec_xl(0, pi);

	ti = clock();
	asm("# soma");
	for (i = 0; i < max; i++)
		vec_xst(vec_add(ev, vec_add(ev, piv)), 0, res);
	tf = clock();
	ts = (double) tf - ti;
	printf("ts = %f\n", ts);

	ti = clock();
	asm("# mul");
	for (i = 0; i < max; i++)
		vec_xst(vec_mul(ev, piv), 0, res);
	tf = clock();
	tm = (double) tf - ti;
	printf("tm = %f\n", tm);

	ti = clock();
	asm("# loop vazio");
	for (i = 0; i < max; i++)
		vec_xst(ev, 0, res);
	tf = clock();
	tl = (double) tf - ti;
	printf("tl = %f\n", tl);

	asm("# printando");
	printf("m/s = %f\n", (tm - tl)/(ts - tl));
	asm("# final");

	return 0;
}
