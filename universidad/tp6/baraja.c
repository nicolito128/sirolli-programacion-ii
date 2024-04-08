/* Algoritmo de baraja invertida */
#include <stdio.h>
#define tamLista 100

typedef int lista[tamLista];

void baraja(lista, int*, int);
void mostrarVector(lista, int);

int main() {
	lista vector;
	int longitud, aux;
	
	longitud = 0;
	
	printf("Ingrese numeros uno a uno para ordenar.\n");
	while(1 == 1) {
		scanf("%d", &aux);
		baraja(vector, &longitud, aux);
		mostrarVector(vector, longitud);
	}
	
	return 0;
}

void baraja(lista vec, int* longitud, int elemento) {
	int j;
	// Centinela del vector
	vec[0] = elemento;
	
	// 'j' es la longitud de ese momento del vector en un instante determinado
	j = *longitud;
	while(elemento > vec[j]) {
		vec[j+1] = vec[j];
		j--;
	}
	
	vec[j+1] = elemento;
	(*longitud)++;
}

void mostrarVector(lista vec, int longitud) {
	int i;
	printf("[");
	for(i = 1; i <= longitud; i++) {
		printf(" %d ", vec[i]);
	}
	printf("]\n");
}
