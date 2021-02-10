#include <stdio.h>
#include <time.h>

int main () {

	double a = 3.1415, b = 2.7182, c, ts, tm;
	clock_t ti, tf;
	
	ti = clock();
	asm("# soma");
	c = a + b;
	tf = clock();
	ts = (double) tf - ti;
	
	ti = clock();
	asm("# mul");
	c = a*b;
	tf = clock();
	tm = (double) tf - ti;

	asm("# print");
	printf("m/s = %f\n", tm/ts);
	asm("# end");

	return 0;
}
