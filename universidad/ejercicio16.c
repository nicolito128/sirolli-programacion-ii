#include <stdio.h>

int main(void) {
	int x;
	int cantCap = 0;
	int cantCapImp = 0;
	
	printf("Verificador de capicuas\n\n");
	printf("Ingrese algun numero negativo para terminar el programa.\n");
	printf("Ingrese un numero natural:\n");
	scanf("%d", &x);
	
	while(x > 0) {
		int digs = 0;
		int impDigs = 0;
		int cap = 0;
		int pos = 1;
		int rx = x;
		
		while(rx != 0) {
			int dig = rx % 10;
			cap = cap * 10 + dig;
			
			if ((dig % 2) != 0) {
				impDigs++;
			}
			
			rx = rx / 10;
			digs++;
		}
				
		if (cap == x) {
			cantCap++;
			
			if (digs == impDigs) {
				cantCapImp++;
			}
		}
		
		printf("Ingrese otro numero natural:\n");
		scanf("%d", &x);
	}
	
	printf("\nCantidad de numeros capicua ingresados: %d\n", cantCap);
	printf("Cantidad de numeros copicua con todos sus digitos impares: %d", cantCapImp);
	
	return 0;
}

