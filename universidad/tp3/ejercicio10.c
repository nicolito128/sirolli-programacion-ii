#include <stdio.h>

int getMenuOption();
long getCode();
long encode(long);
long decode(long);

int main() {
	int op;
	long code;
	
	do {
		op = getMenuOption();
		
		switch(op) {
		case 1:
			code = getCode();
			printf("\nCodigo: %ld", code);
			break;
		}
	} while(op != 0);
	
	printf("\nFinalizando programa.");
	return 0;
}

int getMenuOption() {
	float option;
	
	do {
		printf("\n<-- Menu de la Agencia de Comunicacion -->\n");
		printf("Especifique el numero de la accion a realizar o 0 (cero) para salir.");
		printf("\n0. Salir\n1. Codificar\n2. Decodificar");
		printf("\n> ");
		scanf("%f", &option);
	} while(option != 0 && option != 1 && option != 2 && option != (int)option);
	
	return (int)option;
}

long getCode() {
	long code, rcode;
	int b;
	
	do {
		b = 0;
		printf("\nIngrese un valor a codificar: ");
		scanf("%ld", &code);
		
		while(rcode > 0 && b != 1) {
			printf("\n- %ld -\n", rcode%10);
			if ((rcode%10) != 0 && (rcode%10) != 1) {
				b = 1;
			}
			
			rcode /= 10;
		}
	} while(b == 1);
	
	return code;
}
