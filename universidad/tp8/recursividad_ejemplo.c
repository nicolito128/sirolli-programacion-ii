#include <stdio.h>

int factorial(int);
int contarDigitos(int);

int main() {
	printf("Factorial de 2: %d\n", factorial(2));
	printf("Factorial de 3: %d\n", factorial(3));
	printf("Factorial de 4: %d\n", factorial(4));
	printf("Factorial de 5: %d\n", factorial(5));

	printf("Contando digitos de 99: %d\n", contarDigitos(99));
	printf("Contando digitos de 123: %d\n", contarDigitos(123));
	
	return 0;
}

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

int contarDigitos(int num) {
	if (num == 0) return 0;
	return 1 + contarDigitos(num/10);
}
