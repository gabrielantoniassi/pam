#include <stdio.h>
#include <time.h>

int main () {

	double a = 3.1415, b = 2.7182, c, ts, tm;
	clock_t ti, tf;
	
	asm("# soma");
	c = a + b;
	
	asm("# mul");
	c = a*b;

	asm("# print");
//	printf("m/s = %f\n", tm/ts);
	asm("# end");

	return 0;
}
