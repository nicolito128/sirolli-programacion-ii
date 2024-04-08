#include <stdio.h>
#include <math.h>

int main(void) {
	int k,i;
	printf("Ingrese un numero natural de dos cifras:\n");
	scanf("%d", &k);
	
	if (k < 10 || k > 99) {
		printf("El numero ingresado no es de dos cifras. Programa cerrado.");
		return 0;
	}
	
	for (i = 2; i < k; i++) {
		int pd = 2;
		while (pd <= sqrt(i) && (i % pd) != 0) {
			pd += 1;
		}
		
		if (pd > sqrt(i) && i != 1) {
			printf("Primo: %d\n", i);
		}
	}
	
	return 0;
}

