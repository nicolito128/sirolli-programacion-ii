#include <stdio.h>
#include <stdlib.h>

void ingresar_lista(int[], int);
void determinar_par_impar(int[], int);
void ordenar_secuencial(int[], int);
void eliminar(int[], int*, int);
void mostrar(int[], int);
int getTam();

int main() {
	int tam = getTam();
	int lista[100];
	
	ingresar_lista(lista, tam);
	mostrar(lista, tam);
	
	ordenar_secuencial(lista, tam);
	mostrar(lista, tam);
	
	eliminar(lista, &tam, 1);
	mostrar(lista, tam);
	
	determinar_par_impar(lista, tam);
	
	return 0;
}

int getTam() {
	int tam;
	do {
		printf("\nIngrese el tamanio: ");
		scanf("%d", &tam);
	} while(tam <= 0);
	
	return tam;
}

void ingresar_lista(int lista[], int tam) {
	int i;
	for (i = 1; i <= tam; i++) {
		printf("\nIngrese el numero en la posicion %d: ", i);
		scanf("%d", &lista[i - 1]);
	}
}

void determinar_par_impar(int lista[], int tam) {
	int i;
	
	printf("\n");
	for (i = 0; i < tam; i++) {
		if ((lista[i] % 2) == 0) {
			printf("%d es par!\n", lista[i]);
		} else {
			printf("%d es impar!\n", lista[i]);
		}
	}
}

void ordenar_secuencial(int lista[], int tam) {
	int i, j, aux;
	for (i = 0; i < tam - 1; i++) {
		for (j = i + 1; j < tam; j++) {
			if (lista[i] > lista[j]) {
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	} 
}

void mostrar(int lista[], int tam) {
	int i;
	
	printf("\nTam: %d", tam);
	printf("\n[");
	for (i = 0; i < tam; i++) {
		printf(" %d", lista[i]);
	}
	printf("]\n");
}

void eliminar(int lista[], int* tam, int pos) {
	int i;
	for (i = pos; i < ((*tam) - 1); i++) {
		lista[i] = lista[i+1];
	}
	
	(*tam)--;
}
