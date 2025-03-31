# Punteros

Cuando hablamos sobre [variables y tipos de datos](./001-Variables-y-Tipos.md) hicimos referencia a que toda variable posee un identificador único llamado *dirección de memoria*, con el uso de **punteros** podemos acceder a una dirección de memoria y modificar el valor subyacente de una variable.

Los punteros en C resultan un concepto **fundamental** que todo programador debe interiorizar. Dada la naturaleza de bajo nivel del lenguaje, los punteros ocupan un lugar privilegiado: tienen su propía sintaxis y aritmética especial llamada _"aritmética de punteros"_ (que no está presente en muchos lenguajes).

## ¿Qué es un puntero?

Los punteros son valores numéricos, numeros como cualquier otro que conocemos. Suelen escribirse en _base 16_, también conocida como _hexadecimal_.

El puntero más simple que podemos escribir en C es el siguiente:

```c
    0x0
```

La primera mitad del número es `0x` que simboliza que estamos por escribir un valor hexadecimal, la otra parte es `0` que es el número propiamente dicho. Por lo tanto, sólo hemos escrito el número 0 en hexadecimal.

De hecho, C tiene una constante especial que representa justamente esto. Recibe el nombre de `NULL` y está incluída en `stdlib.h`.

Algunos ejemplos de direcciones de memoria reales pueden ser:

```c
    0x7fff5feed190
    0xc000010070
    0x7ffe5f009ae
    0xc000102048
```

Sin embargo, el valor real de una dirección de memoria suele resultar poco útil. Hay que tener en cuenta que cambian cada vez que ejecutamos un programa.

## Sintaxis: ¿A dónde _apunta_?

Podemos declarar punteros de la siguiente manera:

```c
    <tipo de dato> *<nombre de la variable>;
```

Si está atento habrá notado el sutil esterisco (**\***) que se coloca entre el tipo de dato y el nombre de nuestra variable. Por ejemplo:

```c
    int *entero_ptr;
    float *real_ptr;
    char *caracter_ptr;
    unsigned int *ui_ptr;
```

Los anteriores casos pueden leerse de la siguiente manera: "_declara una variable TIPO puntero con nombre NOMBRE DE LA VARIABLE_".

Tradicionalmente se recomienda colocar el asterisco pegado al nombre de la variable, pero tenga en cuenta que también son válidas las siguientes formas:

```c
    unsigned int * i1ptr;
    signed int* i2ptr;
    double* d1ptr;
    double * d2ptr;
```

Como ya se mencionó, un puntero es _sólo_ una dirección de memoria que **_apunta a una variable pero no la contiene_**.

Además, podemos mostrar el valor de un puntero por consola usando `%p`:

```c
    int *int_ptr;
    printf("%p", int_ptr);
```

Y, como toda variable tiene su propia dirección de memoria, podemos acceder a un puntero con el operador `&` seguido por el nombre de la variable:

```c
    int mi_variable;
    int *mi_ptr = &mi_variable;
    printf("&mi_variable = %p\n", &mi_variable);
    printf("mi_ptr = %p", mi_ptr);
```

Si ya ha utilizado la función `scanf`, notará que todo este tiempo estuvo haciendo uso de los punteros.

## Accediendo y modificando el valor de un puntero

Los punteros son sólo una dirección de memoria, pero podemos hacer uso de la operación de `desreferencia` para acceder al valor de la variable a la que apunta. Es necesario colocar un asterisco (\*) antes del nombre de aquel puntero al que queremos acceder a su valor. Veamos un ejemplo:

```c
#include <stdio.h>

int main() {
    int mi_valor = 68;
    int *ptr = &mi_valor;

    printf("ptr = %p, *ptr = %d", ptr, *ptr);

    return 0;
}
```

La variable `ptr` es un puntero que apunta a `mi_valor`. La desreferencia de `ptr` sucede cuando utilizamos `*ptr` y tratamos de mostrar su valor formateado como un entero (denotado por `%d`). Si ejecutamos ese mismo código, obtendremos como resultado `ptr = 0x..., *ptr = 68`; es decir, `ptr` apunta al entero `68`.

Así como podemos conocer el valor al que apunta, es posible modificarlo con la misma operación de desreferencia:

```c
#include <stdio.h>

int main() {
    int mi_valor = 68;
    int *ptr = &mi_valor;

    // Modificando el valor al que apunta `ptr`.
    // Lo dividiremos entre 2.
    *ptr = (*ptr) / 2;

    printf("ptr = %p, *ptr = %d\n", ptr, *ptr);
    printf("&mi_valor = %p, mi_valor = %d", &mi_valor, mi_valor);

    return 0;
}
```

No es casualidad que consultemos el puntero y valor de `mi_valor`. **Cuando modifiquemos `ptr` también alteraremos el valor de `mi_valor`** que pasará a ser `34`. Esa es toda la magia de los punteros.