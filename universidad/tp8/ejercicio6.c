#include <stdio.h>

int fibo(int);

int main() {
	printf("Fibonacci de 4: %d\n", fibo(4));
	printf("Fibonacci de 7: %d\n", fibo(7));
	return 0;
}

int fibo(int n) {
	if (n <= 2) return 1;
	return fibo(n-1) + fibo(n-2);
}
