#include <stdlib.h>
#include <stdio.h>
#define TAM 100

typedef int Vector[TAM];

typedef struct {
    int size;
    Vector vec;
} Lista;

void merge_sort(Vector, int, int);
void merge(Vector, int, int, int);
void mostrar_vec(Lista);
void carga_vec(Lista*);

int main() {
    Lista l;
    l.size = 5;

    carga_vec(&l);
    merge_sort(l.vec, 0, l.size);

    mostrar_vec(l);

    return 0;
}

void merge_sort(Vector vec, int start, int end) {
    int mid;

    if (start < end) {
        mid = (start + end) / 2;

        // Divide el problema
        merge_sort(vec, start, mid);
        merge_sort(vec, mid+1, end);

        // el merge se encargará a su vez de conquistar y unir
        merge(vec, start, mid, end);
    }
}

void merge(Vector vec, int start, int mid, int end) {
    int aux[20];
    int i, j, k, t;
    k = 0;
    i = start;
    j = mid+1;

    while (i <= mid && j <= end) {
        k++;

        if (vec[i] < vec[j]) {
            aux[k] = vec[i];
            i++;
        } else {
            aux[k] = vec[j];
            j++;
        }
    }
    
    /** Se ejecutará uno pero no los dos */
    // se encargan de colocar lo que quedó en ambos lados
    for (t=i; t <= mid; t++)
        aux[++k] = vec[t];
    
    for (t=j; t <= end; t++)
        aux[++k] = vec[t];
    /** Bucles ends */

    for (t=1; t <= k; t++)
        vec[start+t-1]=aux[t];
}

void mostrar_vec(Lista l) {
    int i;
    for (i = 0; i < l.size; i++) {
        printf("Element %d: %d\n", i, l.vec[i]);
    }
}

void carga_vec(Lista * l) {
    int i, aux;

    for (i = 0; i < l->size; i++) {
        printf("Ingrese un nuevo valor > ");
        scanf("%d", &aux);

        l->vec[i] = aux;
    }

    printf("\n");
}