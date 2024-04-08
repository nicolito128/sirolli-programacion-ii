#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int A, B, Z;
	
	srand(time(NULL));
	
	printf("Ingrese un valor natural A: ");
	scanf("%d", &A);
	
	printf("\nIngrese un valor natural B: ");
	scanf("%d", &B);
	
	Z = rand();
	
	printf("\nValor de Z: %d", Z);
	
	if ((Z % 2) == 0) {
		printf("\nZ es PAR.");
		printf("\n\nA + B = %d\n", (A+ B));
	} else {
		printf("\nZ es IMPAR");
		printf("\n\nA * B = %d\n", (A*B));
	}
	
	return 0;
}

