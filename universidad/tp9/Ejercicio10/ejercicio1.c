#include <stdio.h>
#include <stdlib.h>
#define tamCadena 50

typedef char TCadena[tamCadena];

typedef struct {
	long int dni;
	int edad;
	TCadena nombre;
} Persona;

typedef Persona People[3];

void leeCad(TCadena, int);
Persona crearPersona();
void mostrarMayor(People, int);

int main() {
	People* lista = NULL;
	int tamLista = 0, i;
	
	lista = (People*)malloc(sizeof(People)*3);
	for (i = 1; i <= 3; i++) {
		tamLista++;
		(*lista)[i] = crearPersona();
	}
	
	mostrarMayor(*lista, tamLista);
	free(*lista);
	return 0;
}

void leeCad(TCadena cad, int tam){
	int j; 	char c;
	j=0;
	c=getchar();
	while (c!=EOF && c!='\n' && j<tam-1)
	{ cad[j]=c;
	j++;
	c=getchar(); 	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}

Persona crearPersona() {
	Persona aux;
	
	printf("\nIngresando\n");
	printf("Ingrese DNI: ");
	scanf("%ld", &aux.dni);
	
	printf("Ingrese la edad: ");
	fflush(stdin);
	scanf("%d", &aux.edad);
	
	printf("Ingrese el nombre: ");
	fflush(stdin);
	leeCad(aux.nombre, tamCadena);
	
	return aux;
}

void mostrarMayor(People lista, int tam) {
	int i = 1, mayor = 1;
	for(i = 2; i <= tam; i++) {
		if (lista[mayor].edad < lista[i].edad) {
			mayor = i;
		}
	}
	
	printf("\nMostrando...");
	printf("\nDNI: %ld", lista[mayor].dni);
	printf("\nNombre: %s", lista[mayor].nombre);
	printf("\nEdad: %d", lista[mayor].edad);
}
