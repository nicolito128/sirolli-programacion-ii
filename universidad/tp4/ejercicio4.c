/*** Serna, Nicolas Abel ***/

#include <stdio.h>
#include <stdlib.h>
#define tam 100

typedef int list[tam];

void entradaIncondicionada(list, int*);
void entradaCondicionada(list, int*);
void entradaComoPila(list, int*);
void reemplazarMayoresPorDiff(list, int, int);
int calcularPromedio(list, int);

int main() {
	list vecA;
	int i, op, promedio, longitudA = 0;
	float aux;
	
	do {
		system("cls");
		printf("Seleccione un tipo de entrada:");
		printf("\n1. Condicionada\n2. Incondicionada\n3. Como pila/stack\n");
		scanf("%f", &aux);
	} while((int)aux != 1 && (int)aux != 2 && (int)aux != 3);
	op = (int)aux;
	
	switch(op) {
	case 1:
		entradaCondicionada(vecA, &longitudA);
		break;
		
	case 2:
		entradaIncondicionada(vecA, &longitudA);
		break;
		
	case 3:
		entradaComoPila(vecA, &longitudA);
		break;
	}
	
	promedio = calcularPromedio(vecA, longitudA);
	printf("\nPromedio: %d\n", promedio);
	reemplazarMayoresPorDiff(vecA, longitudA, promedio);
		
	printf("Vector resultante: [ ");
	for(i = 1; i <= longitudA; i++) {
		printf("%d ", vecA[i]);
	}
	printf("]");
	
	return 0;
}

void entradaIncondicionada(list vec, int* longitud) {
	int i;
	float aux;
	
	do {
		printf("Digite la longitud del vector a ingresar: ");
		scanf("%f", &aux);
	} while(aux <= 0 || aux != (int)aux);
	*longitud = (int)aux;
	
	for(i = 1; i <= *longitud; i++) {
		do {
			printf("\nIngrese el entero N*%d: ", i);
			scanf("%f", &aux);
		} while(aux != (int)aux);
		vec[i] = (int)aux;
	}
}

void entradaComoPila(list vec, int* longitud) {
	int i;
	float aux;
	
	printf("Ingrese un valor entero: ");
	scanf("%f", &aux);
	
	while(aux == (int)aux) {
		(*longitud)++;
		
		for(i = *longitud; i >= 1; i--) {
			vec[i + 1] = vec[i];
		}
		vec[1] = (int)aux;
		
		printf("\nIngrese un valor entero o finalice con un No-Entero: ");
		scanf("%f", &aux);
	}
}

void entradaCondicionada(list vec, int* longitud) {
	float aux;
	
	printf("\nIngrese un valor entero: ");
	scanf("%f", &aux);
	
	while(aux == (int)aux) {
		(*longitud)++;
		vec[*longitud] = (int)aux;
		printf("\nIngrese un valor entero o finalice con un No-Entero: ");
		scanf("%f", &aux);
	}
}

int calcularPromedio(list vec, int longitud) {
	int i, sum;
	sum = 0;
	
	for (i = 1; i <= longitud; i++) {
		sum += vec[i];
	}
	
	return (sum/longitud);
}

void reemplazarMayoresPorDiff(list vec, int longitud, int promedio) {
	int i;
	
	for(i = 1; i <= longitud; i++) {
		if (vec[i] > promedio) {
			vec[i] = vec[i] - promedio;
		}
	}
}
