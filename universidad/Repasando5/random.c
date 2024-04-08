#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_rand(int, int);
void get_data(int*, int*);

int main() {
    int a, b, result;

    srand(time(NULL));

    get_data(&a, &b);

    result = get_rand(a, b);
    printf("Valor aleatorio obtenido en el intervalo [%d, %d] = %d", a, b, result);

    return 0;
}

void get_data(int * a, int * b) {
    printf("\nIngrese un valor para A > ");
    scanf("%d", a);

    printf("\nIngrese un valor para B > ");
    scanf("%d", b);
}

int get_rand(int a, int b) {
    return rand() % (b - a + 1) + a;
}