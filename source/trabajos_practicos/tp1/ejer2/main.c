#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad_conjunto.h"

// Cabeceras del menu y sus opciones
void menu();
void opcion_mostrar_conjunto(Conjunto c, const char *titulo);
void opcion_mostrar_union(Conjunto a, Conjunto b);
void opcion_determinar_pertenencia(Conjunto a, Conjunto b);
Conjunto opcion_agregar(Conjunto c);

// Cabeceras auxiliares
char ingresar_caracter();
Conjunto generar_conjunto();
void mostrar_codes(Conjunto c);

int main() {
	// Asignamos una "seed" para obtener numeros pseudo-aleatorios.
	srand(time(NULL));
	
	menu();
	return 0;
}

// No pertenece al ejercicio, pero es util mientras se está desarrollando.
// Muestra el conjunto por consola, pero en lugar del caracter muestra el codigo numerico que lo identifica.
void mostrar_codes(Conjunto c) {
	printf("\n{ ");
	for (int i = 0; i < c.cant; i++) {
		printf("%d ", c.elems[i]);
	}
	printf("}");
}

void menu() {
	int opcion;
	Conjunto a;
	Conjunto b;
	
	printf("\n-- Generando el Conjunto A --");
	a = generar_conjunto();
	
	printf("\n-- Generando el Conjunto B --");
	b = generar_conjunto();
	
	do {
		printf("\n--- Menu para el Ejercicio 2: Conjuntos ---");
		printf("\n[ 0 ] Salir.");
		printf("\n[ 1 ] Agregar elemento al conjunto A.");
		printf("\n[ 2 ] Agregar elemento al conjunto B.");
		printf("\n[ 3 ] Mostrar conjunto A.");
		printf("\n[ 4 ] Mostrar conjunto B.");
		printf("\n[ 5 ] Mostrar la unión de A y B.");
		printf("\n[ 6 ] Determinar pertenencia a los conjuntos.\n");
		
		printf("\nSeleccione una de las opciones > ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			a = opcion_agregar(a);
			break;
		case 2:
			b = opcion_agregar(b);
			break;
		case 3:
			opcion_mostrar_conjunto(a, "A");
			break;
		case 4:
			opcion_mostrar_conjunto(b, "B");
			break;
		case 5:
			opcion_mostrar_union(a, b);
			break;
		case 6:
			opcion_determinar_pertenencia(a, b);
			break;
		}
	} while(opcion != 0);
	printf("\nFinalizando el programa. Ciao!\n");
}

char ingresar_caracter() {
	char ch;
	printf("\nIngrese un caracter > ");
	// El espacio en blanco en " %c" es intencional.
	// Resulta que es una forma especial de no leer el caracter de salto de 
	// linea (\n) cuando damos enter.
	scanf(" %c", &ch);
	return ch;
}

Conjunto generar_conjunto() {
	Conjunto gen;
	int tam;
	
	printf("\nIngrese el tamaño inicial del conjunto a generar > ");
	scanf("%d", &tam);
	
	if (tam < 0) {
		printf("\nEl tamaño del conjunto debe ser un numero positivo.");
		gen.cant = 0; // Conjunto vacío en caso de error
		return gen;
	}
	
	gen = inicializar(tam);
	return gen;
}

Conjunto opcion_agregar(Conjunto c) {
	char ch = ingresar_caracter();
	return agregar(c, ch);
}

void opcion_mostrar_conjunto(Conjunto c, const char *titulo) {
	printf("\n- %s:", titulo);
	mostrar(c);
	mostrar_codes(c);
	printf("\n");
}

void opcion_mostrar_union(Conjunto a, Conjunto b) {
	Conjunto union_ab = union_conjuntos(a, b);
	opcion_mostrar_conjunto(union_ab, "A union B");
}

void opcion_determinar_pertenencia(Conjunto a, Conjunto b) {
	int pertenece_a, pertenece_b;
	char ch = ingresar_caracter();
	
	pertenece_a = pertenece(a, ch);
	pertenece_b = pertenece(b, ch);
	
	if (pertenece_a == 1 && pertenece_b == 1) {
		printf("- ¡Pertenece a ambos conjuntos!\n");
	} else if (pertenece_a == 1) {
		printf("- Pertenece al conjunto A.\n");
	} else if (pertenece_b == 1) {
		printf("- Pertenece al conjunto B.\n");
	} else {
		printf("- El caracter NO está en A ni en B.\n");
	}
}
