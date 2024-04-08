#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long int dni;
} Alumno;

int main() {
	
	return 0;
}

void merge_sort(int lista[], int ini, int fin) {
	int m;
	if (ini < fin) {
		m = (ini + fin) / 2;
		merge_sort(lista, ini, m);
		merge_sort(lista, m+1, fin);
		merge(lista, ini, m, fin);
	}
}

void merge(int lista[], int ini, int mid, int fin) {
	int aux[50], i, j, k, t;
	i = ini;
	j = fin;
	k = 0;
	
	while(i <= m && j <= fin) {
		k++;
		
		if (lista[i] < lista[j]) {
			aux[k] = lista[i];
			i++;
		} else {
			aux[k] = lista[j];
			j++;
		}
	}
	
	for (t = i; t <= m; t++) { // Se ejecuta este o el otro
		k++;
		aux[k] = lista[t];
	}
	
	for (t = j; t <= fin; t++) {
		k++;
		aux[k] = lista[t];
	}
	
	for (t = 1; t <= k; t++) {
		lista[ini+t-1] = aux[t];
	}
}

void quick_sort(int lista[], int ini, int fin) {
	int izq, der, piv;
	
	if (ini < fin) {
		izq = ini;
		der = fin;
		piv = lista[ini];
		
		while(izq < der) {
			while(izq < der && lista[der] > piv)
				der--;
			
			if (izq < der) {
				lista[izq] = lista[der];
				izq++;
			}
			
			while(izq < der && lista[izq] < piv)
				izq++;
			
			if (izq < der) {
				lista[der] = lista[izq];
				der--;
			}
			
		}
		
		lista[der] = piv;
		quick_sort(lista, ini, der - 1);
		quick_sort(lista, der+1, fin);
	}
}

void mostrarvec( int a[], int tam){
	if (tam!=1)
		mostrarvec( a, tam-1);
	
	printf("%d ", a[tam]);
}

void do_ptr() {
	Alumno maxi = {11222333};
	
	Alumno * alu_ptr = &maxi;
	Alumno ** ptr_ptr = &alu_ptr;
	
	printf("DNI de Maxi: %ld\n", (*(*ptr_ptr)).dni);
}
