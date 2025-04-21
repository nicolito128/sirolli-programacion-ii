#ifndef TAD_COMPLEJO_H
#define TAD_COMPLEJO_H
/*
Un numero complejo es de la forma (a + bi).
En otra notacion que podemos usar es (a, b);
es decir, como un par ordenado.

Definiremos el tipo "complejo". Sera un
vector de dos elementos de tipo float.
*/
typedef float complejo[2];

void sumar(complejo elem1, complejo elem2, complejo resultado);

void restar(complejo elem1, complejo elem2, complejo resultado);

void multiplicar(complejo elem1, complejo elem2, complejo resultado);

void dividir(complejo elem1, complejo elem2, complejo resultado);

void mostrar(complejo elem);
#endif
