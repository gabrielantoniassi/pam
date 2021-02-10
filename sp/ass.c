#include <stdio.h>

int main () {
	asm("# double a;");
	double a;
	asm("# a = 1;");
	a = 1;
	asm("# doubel b;");
	double b;
	asm("# b = a");
	b = a;
	asm("# double c;");
	double c;
	asm("# comeca o asm:");
	asm("stfd %1, %0"
	    : "=r" (c)
	    : "r" (a));
	asm("# fim");
/*
	asm ("mov %1, %0\n\t"
	    "add $1, %0"
	    : "=r" (dst) 
	    : "r" (src));

	printf("%d\n", dst);
*/
	return 0;
}
