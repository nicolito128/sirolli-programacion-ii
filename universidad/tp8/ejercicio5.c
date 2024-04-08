#include <stdio.h>

int resto(int, int);

int main() {
	int a, b;
	
	a = 22;
	b = 5;
	printf("Resto entre %d y %d: %d", a, b, resto(a, b));
	
	return 0;
}

int resto(int x, int y) {
	if (x < y) return x;
	return resto(x-y, y);
}

