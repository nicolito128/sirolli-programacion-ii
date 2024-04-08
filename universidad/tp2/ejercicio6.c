#include <stdio.h>
#include <math.h>

int scanNumber();
int cantDivs(int);
int isPrime(int);
int convert(int, int);

int main() {
	int num, cant;
	
	num = scanNumber();
	cant = cantDivs(num);
	
	printf("\nCantidad de divisores de %d: %d", num, cant);
	if (isPrime(cant) == 1) {
		printf("\nLa cantidad de divisores es prima.");
		printf("\nNumero expresado en base 2: %d", convert(num, 2));
	} else {
		printf("\nLa cantidad de divisores NO es prima.");
		printf("\nNumero expresado en base 9: %d", convert(num, 9));
	}
	
	return 0;
}

int scanNumber() {
	int value;
	printf("\nIngrese un numero natural: ");
	scanf("%d", &value);
	
	while(value <= 0) {
		printf("\nNumero no valido. Ingresa otro valor que sea natural: ");
		scanf("%d", &value);
	}
	
	return value;
}

int cantDivs(int number) {
	int i;
	if (number == 1) return 1;
	
	int cant = 2;
	for (i = 2; i <= number/2; i++) {
		if ((number % i) == 0) cant++;
	}
	
	return cant;
}

int isPrime(int number) {
	if (number == 1) return 0;
	
	int pd = 2;
	while(pd <= sqrt((double)number) && (number % pd) != 0) {
		pd++;
	}
	
	if (pd > sqrt((double)number)) {
		return 1;
	}
	
	return 0;
}

int convert(int number, int base) {
	int value, p;
	value = 0;
	p = 1;
	
	while(number > 0){
		value += (number % base) * p;
		number /= base;
		p *= 10;
	}
	
	return value;
}
