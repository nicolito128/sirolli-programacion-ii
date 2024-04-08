#include <stdlib.h>
#include <stdio.h>
#define TAM 100

typedef int Vector[TAM];

void quick_sort(Vector, int, int);
void show_vec(Vector, int);
void get_vec(Vector, int);

int main() {
    Vector vec;
    int size = 5;

    get_vec(vec, size);

    quick_sort(vec, 0, size);

    show_vec(vec, size);

    return 0;
}

void quick_sort(Vector vec, int start, int end) {
    int pivot, left, right, mid;

    if (start < end) {
        pivot = vec[start];
        left = start;
        right = end;

        while (left < right) {
            while (right > left && vec[right] > pivot)
                right--;

            if (right > left) {
                vec[left] = vec[right];
                left++;
            }

            while (left < right && vec[left] < pivot)
                left++;
            
            if (left < right) {
                vec[right] = vec[left];
                right--;
            }
        }

        mid = right;
        vec[mid] = pivot;
        quick_sort(vec, start, mid-1);
        quick_sort(vec, mid+1, end);
    }
}

void show_vec(Vector vec, int size) {
    int pos = size - 1;
    if (size > 1)
        show_vec(vec, size - 1);

    printf("Element %d: %d\n", pos, vec[pos]);
}

void get_vec(Vector vec, int size) {
    int i, aux;

    for (i = 0; i < size; i++) {
        printf("Ingrese un nuevo valor > ");
        scanf("%d", &aux);

        vec[i] = aux;
    }

    printf("\n");
}