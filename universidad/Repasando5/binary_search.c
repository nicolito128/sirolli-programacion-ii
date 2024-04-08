#include <stdlib.h>
#include <stdio.h>
#define TAM 100

typedef int Vector[TAM];

int binary_search_rec(Vector, int, int, int);
void show_vec(Vector, int);
void get_vec(Vector, int);

// RECORDAR: binary search solo sirve si ya está ordenado.
int main() {
    Vector vec;
    int size = 5;
    int search;

    get_vec(vec, size);

    search = 3;
    printf("\nElement %d at position %d by binary_search_rec\n", search, binary_search_rec(vec, 0, size, search));
    printf("\nElement %d at position %d by binary_search\n", search, binary_search(vec, size, search));

    search = 1;
    printf("\nElement %d at position %d by binary_search_rec\n", search, binary_search_rec(vec, 0, size, search));
    printf("\nElement %d at position %d by binary_search\n", search, binary_search(vec, size, search));

    printf("\n");
    show_vec(vec, size);

    return 0;
}

int binary_search_rec(Vector vec, int start, int end, int search) {
    int mid = (start + end) / 2;
    if (start <= end) {
        if (vec[mid] == search) {
            return mid;
        }

        if (search < vec[mid])
            return binary_search_rec(vec, start, mid-1, search);
        else
            return binary_search_rec(vec, mid+1, end, search);
    }

    return -1;
}

int binary_search(Vector vec, int size, int search) {
    int mid, start, end;
    start = 0;
    end = size;
    mid = (start + end) / 2;
    
    while (start <= end && vec[mid] != search) {
        if (search < vec[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    if (start <= end) {
        return mid;
    }

    return -1;
}

void show_vec(Vector vec, int size) {
    int pos = size - 1;
    if (size > 1)
        show_vec(vec, pos);
    
    printf("Elem %d: %d\n", pos, vec[pos]);
}

void get_vec(Vector vec, int size) {
    if (size > 1)
        get_vec(vec, size - 1);

    printf("Ingrese un nuevo valor > ");
    scanf("%d", &vec[size - 1]);
}