/*
    Comprobar si el caracter ingresado es un dígito.

    Podemos lograr esto usando la función `isdigit(c)` de la biblioteca `ctype.h`.
    Una función similar es `isalpha(c)`.
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char dig;

    printf("Ingrese un dígito: ");
    scanf("%c", &dig);

    // Si el resultado de isdigit(dig) es mayor a 0, significa que ingresaron un dígito.
    // Referencia: https://cplusplus.com/reference/cctype/isdigit/
    if (isdigit(dig) > 0) {
        printf("Es un dígito válido.\n");
    } else {
        printf("No es un dígito.\n");
    }

    return 0;
}