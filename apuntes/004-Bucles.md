# Bucles

## `for`

Bucle tradicional usado para iterar sobre un rango conocido de valores. Por ejemplo, un bucle que muestre los primeros 10 números naturales:

```c
#include <stdio.h>

int main() {
    int limite = 10;
    for (int indice = 1; indice <= limite; indice += 1) {
        printf("%d\n", indice);
    }

    return 0;
}
```

Observamos que su estructura es la siguiente:

```c
    for (VARIABLES ; CONDICIÓN ; MODIFICADOR DE LA VARIABLE) {
        // ...
    }
```

## `while`

El bucle `while` se ejecutará siempre que la condición que evalúa sea verdadera. Por ejemplo, vamos a invertir los dígitos de un número entero:

```c
#include <stdio.h>

int main() {
    int num = 128;
    int invertido = 0;
    int digito;

    printf("Original: %d\n", num);
    while (num != 0) {
        digito = num%10;
        num = num/10;
        invertido = invertido*10 + digito;
    }
    printf("Invertido: %d\n", invertido);

    return 0;
}
```

Observamos que su estructura es la siguiente:

```c
    while (CONDICIÓN) {
        // ...
    }
```

## `do...while`

Los bucles `do...while` evalúan la condición al final de la ejecución del bloque de código, por lo tanto siempre se ejecutarán por lo menos una vez. Por ejemplo, ingresaremos una lista no conocida de valor enteros hasta encontrar algún impar:

```c
#include <stdio.h>

int main() {
    int numero;

    do {
        printf("Ingrese el número: ");
        scanf("%d", &numero);

        if (numero%2 != 0) {
            printf("¡El número ingresado es impar! Saliendo del bucle...\n");
        }
    } while (numero%2 == 0);


    return 0;
}
```

Observamos que su estructura es la siguiente:

```c
    do {
        // ...
    } while (CONDICIÓN);
```