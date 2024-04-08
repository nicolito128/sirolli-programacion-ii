#include <stdio.h>
#define tamDatos 100

typedef int vector[tamDatos];

void cargar_rec(vector, int*, int);
void mostrar_rec(vector, int);
void eliminar_rec(vector, int*, int);
void quicksort(vector, int, int);
void mergesort(vector, int, int);
void merge(vector, int, int, int);
int busqueda_sec_rec(vector, int, int);
int busqueda_binaria_rec(vector, int, int, int);

int main() {
	vector vec = {0, 1, 4, 5, 3, 7, 8, 2, 6};
	int longitud = 8; 
	mostrar_rec(vec, longitud);
	
	/*cargar_rec(vec, &longitud, 1);
	mostrar_rec(vec, longitud);
	
	printf("\n");
	eliminar_rec(vec, &longitud, 2);
	eliminar_rec(vec, &longitud, 3);
	mostrar_rec(vec, longitud);
	
	printf("\nContiene 0: %d", busqueda_sec_rec(vec, longitud, 0));
	printf("\nContiene 4: %d", busqueda_sec_rec(vec, longitud, 4));
	printf("\nContiene 8: %d", busqueda_sec_rec(vec, longitud, 8));
	printf("\nContiene 6: %d", busqueda_sec_rec(vec, longitud, 6));*/
	
	/*printf("\nOrdenando por mergesort\n");
	mergesort(vec, 1, longitud);
	mostrar_rec(vec, longitud);*/
	
	printf("\nOrdenando por quick sort\n");
	vector vec2 = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int longitud2 = 9;
	quicksort(vec2, 1, longitud2);
	mostrar_rec(vec2, longitud2);
	
	printf("\nBusqueda binaria");
	printf("\nContiene 2: %d", busqueda_binaria_rec(vec2, 1, longitud2, 2));
	printf("\nContiene 13: %d", busqueda_binaria_rec(vec2, 1, longitud2, 13));
	
	return 0;
}

void cargar_rec(vector vec, int* tam, int N) {
	if (N == 0) return;
	int nuevo;
	printf("\nIngrese nuevo dato a cargar: ");
	scanf("%d", &nuevo);
	
	(*tam) = (*tam) + 1;
	vec[*tam] = nuevo;
	cargar_rec(vec, tam, N-1);
}

void mostrar_rec(vector vec, int tam) {
	if (tam == 0) return;
	mostrar_rec(vec, tam-1);
	printf("%d\n", vec[tam]);
}

void eliminar_rec(vector vec, int* tam, int pos) {
	if (pos == (*tam)) {
		*tam -= 1;
		return;
	}
	
	vec[pos] = vec[pos+1];
	eliminar_rec(vec, tam, pos+1);
}

void eliminar_fabri(vector vec, int tam, int pos){
	if (pos<tam){
		vec[pos]=vec[pos+1];
		eliminar_fabri(vec, tam, pos+1);
	}
	else
		printf ("\n se esfumo alv"); 
}




int busqueda_sec_rec(vector vec, int tam, int buscado) {
	if (tam == 0) return 0;
	if (vec[tam] == buscado) return tam;
	busqueda_sec_rec(vec, tam - 1, buscado);
}

int busqueda_binaria_rec(vector vec, int ini, int fin, int buscado) {
	int mid = (ini + fin) / 2;
	
	if (ini <= fin) {
		if (vec[mid] == buscado) {
			return mid;
		} else {
			if(vec[mid] > buscado) {
				busqueda_binaria_rec(vec, ini, mid - 1, buscado);
			} else {
				busqueda_binaria_rec(vec, mid + 1, fin, buscado);
			}
		}
	} else return 0;
}

// M-sort
void mergesort(vector vec, int ini, int fin) {
	int mid;
	if (ini < fin) {
		mid = (ini + fin) / 2;
		
		mergesort(vec, ini, mid);
		mergesort(vec, mid+1, fin);
		merge(vec, ini, mid, fin);
	}
}

void merge(vector vec, int ini, int mid, int fin) {
	vector aux;
	int j, i, k, t;
	
	k = 0;
	j = mid+1;
	i = ini;
	
	while(i <= mid && j <= fin) {
		k++;
		if (vec[i] < vec[j]) {
			aux[k] = vec[i];
			i++;
		} else {
			aux[k] = vec[j];
			j++;
		}
	}
	
	for(t = i; t <= mid; t++) {
		k++;
		aux[k] = vec[t];
	}
	
	for(t = j; t <= fin; t++) {
		k++;
		aux[k] = vec[t];
	}
	
	for(t = 1; t <= k; t++) {
		vec[ini+t-1] = aux[t];
	}
}

void quicksort(vector vec, int ini, int fin) {
	int piv, izq, der, mid;
	
	if (ini < fin) {
		piv = vec[ini];
		izq = ini;
		der = fin;
		
		while(izq < der) {
			while(der > izq && vec[der] > piv)
				der--;
			
			if (der > izq) {
				vec[izq] = vec[der];
				izq++;
			}
			
			while(izq < der && piv > vec[izq])
				izq++;
			
			if (izq < der) {
				vec[der] = vec[izq];
				der--;
			}
		}
		
		vec[der] = piv;
		mid = der;
		quicksort(vec, ini, mid-1);
		quicksort(vec, mid+1, fin);
		
	}
}
