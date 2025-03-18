#include <stdio.h>
#define LONGITUD 15

int main() {
    char appelido[LONGITUD] = {'L', 'o', 'p', 'e', 'z', '\0'};
    char nombre[LONGITUD] = "Juan";

    printf("%s, %s\n", appelido, nombre);
    return 0;
}