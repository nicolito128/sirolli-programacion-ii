#include <stdio.h>
#include <stdlib.h>
#include "TAD_TEST.h"

int main() {
	int a, b;
	a = 5;
	b = 10;
	
	printf("%d + %d = %d\n", a, b, sum(a, b));
	return 0;
}
