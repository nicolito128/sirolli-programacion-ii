#ifndef TAD_CONJUNTO_H
#define TAD_CONJUNTO_H
#define CAP_CONJUNTO 70

typedef struct {
	char elems[CAP_CONJUNTO];
	int cant;
} Conjunto;

// Inicializa un conjunto con `n` elementos asignando caracteres al azar.
Conjunto inicializar(int n);
// Agrega un elemento al conjunto `c` y retorna el nuevo conjunto.
Conjunto agregar(Conjunto c, char ch);
// Toma los conjuntos `c1` y `c2`, para realizar la union y retornar el nuevo conjunto.
Conjunto union_conjuntos(Conjunto c1, Conjunto c2);

// Determina si un caracter `ch` pertenece al conjunto `c`.
// Devuelve 1 para el caso verdadero y 0 para falso.
int pertenece(Conjunto c, char ch);

// Muestra los elementos del conjunto `c` por la salida estandar (consola).
void mostrar(Conjunto c);
#endif
