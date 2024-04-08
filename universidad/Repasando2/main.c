#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define longitudCadena 100

typedef char cadena[longitudCadena];

typedef struct {
	cadena nombre;
	cadena apellido;
	double promedio;
} Alumno;

void leeCad(cadena, int);
void capitalizar_apellido(Alumno, cadena);
void mostrar_alumno(Alumno);
void mostrar_lista(Alumno[], int);
void cargar_lista_alumnos(Alumno[], int, int*);
int obtener_tam_lista();
Alumno cargar_alumno();

int main() {
	int listaLength, tam;
	tam = obtener_tam_lista();
	listaLength = 0;
	Alumno lista[tam];
	
	cargar_lista_alumnos(lista, tam, &listaLength);
	mostrar_lista(lista, tam);
	
	return 0;
}

void cargar_lista_alumnos(Alumno lista[], int capacidad, int * longitud) {
	Alumno aux, cur;
	int i, j;
	
	for (i = 0; i < capacidad; i++) {
		// Baraja
		aux = cargar_alumno(); // lista[0] = aux

		j = i - 1; // longitud ACTUAL del vector
		cur = lista[j];
		while (j >= 0 && strcmp(aux.apellido, cur.apellido) < 0) {
			lista[j+1] = lista[j];
			j--;
		}
		
		lista[j+1] = aux;
		longitud++;
		// Baraja end
	}
}

void mostrar_alumno(Alumno alumno) {
	cadena cap_aux;
	capitalizar_apellido(alumno, cap_aux);
	
	printf("%s, %s | Promedio: %f\n", cap_aux, alumno.nombre, alumno.promedio);
}

void mostrar_lista(Alumno lista[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		mostrar_alumno(lista[i]);
	}
}

int obtener_tam_lista() {
	int tam;
	
	do {
		printf("Por favor, ingrese una longitud para la lista de alumnos a ingresar > ");
		scanf("%d", &tam);
		printf("\n");
		
		if (tam <= 0) {
			printf("Longitud no valida para una lista.\n");
		}
	} while(tam <= 0);
	
	return tam;
}

void capitalizar_apellido(Alumno alumno, cadena destino) {
	strcpy(destino, alumno.apellido);
	strupr(destino);
}
	
Alumno cargar_alumno() {
	Alumno res;
	printf("\n");
	
	printf("Ingrese un nombre > ");
	leeCad(res.nombre, longitudCadena);
	printf("\n");
	
	printf("Ingrese un apellido > ");
	leeCad(res.apellido, longitudCadena);
	printf("\n");
	
	printf("Ingrese un promedio numerico > ");
	scanf("%lf", &res.promedio);
	printf("\n");
	
	return res;
}

void leeCad(cadena lista, int tam) {
	int j, m;
	j = 0;
	
	fflush(stdin);
	while(j < (tam-1) && (m = getchar()) != EOF && m != '\n') {
		lista[j] = m;
		j++;
	}
	
	lista[j] = '\0';
	
	// limpiando buffer supuestamente
	if (m != EOF && m != '\n')
		while((m = getchar()) != EOF && m != '\n');
}
