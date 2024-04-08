#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tamAgenda 100

typedef char cadena[tamAgenda];

typedef struct {
	cadena apellido;
	cadena nombre;
	cadena domicilio;
	cadena telefono;
} Contacto;

typedef struct {
	cadena str;
	int tam;
} TipoNombreCompleto;

typedef Contacto Agenda[tamAgenda];

void leerCadena(cadena, int);
void menu();
TipoNombreCompleto obtenerNombreCompleto(Contacto);
int compararContactos(Contacto, Contacto);
int esCadenaNumerica(cadena);
Contacto obtenerContacto();
void insertarContacto(Agenda, int*, Contacto);
void mostrarContactos(Agenda, int);

int main() {
	menu();
	return 0;
}

void menu() {
	Agenda agenda;
	int longitud;
	char option;
	Contacto con;
	
	do {
		printf("/*/ Menu de la Agenda Telefonica /*/\n");
		printf("Seleccione una:\n");
		printf("\n0. Salir\n1. Agregar nuevo contacto");
		printf("\n>");
		fflush(stdin);
		scanf(" %c", &option);
		
		switch(option) {
		case '1':
			con = obtenerContacto();
			insertarContacto(agenda, &longitud, con);
			mostrarContactos(agenda, longitud);
			break;
		}
		
		system("pause");
		system("cls");
	} while(option != '0');
}

void leerCadena(cadena cad, int tam) {
	int j, m;
	j = 0;
	fflush(stdin);
	while((j < tam-1) && ((m = getchar()) != EOF) && m != '\n') {
		cad[j] = m;
		j++;
	}
	cad[j] = '\0';
	// limpiar buffer
	if(m != EOF && m != '\n')
		while((m=getchar()) != EOF && m != '\n');
}

TipoNombreCompleto obtenerNombreCompleto(Contacto c) {
	TipoNombreCompleto resultado;
	strcpy(resultado.str, strcat(c.apellido, " "));
	strcpy(resultado.str, strcat(resultado.str, c.nombre));
	resultado.tam = strlen(resultado.str);
		
	return resultado;
}

int compararContactos(Contacto c1, Contacto c2) {
	TipoNombreCompleto completo1, completo2;
	completo1 = obtenerNombreCompleto(c1);
	completo2 = obtenerNombreCompleto(c2);
	
	return strcmp(completo1.str, completo2.str);
}

int esCadenaNumerica(cadena cad) {
	int i, b;
	i = 0;
	b = 1;
	
	while(i < strlen(cad) && b == 1) {
		if (cad[i] != '0' && cad[i] != '1' && cad[i] != '2' && cad[i] != '3' && cad[i] != '4' && cad[i] != '5' && cad[i] != '6' && cad[i] != '7' && cad[i] != '8' && cad[i] != '9') {
			b = 0;
		}
		i++;
	}
	
	return b;
}

Contacto obtenerContacto() {
	Contacto resultado;
	
	printf("\nIngrese un apellido para el contacto: ");
	leerCadena(resultado.apellido, tamAgenda);
	
	printf("\nIngrese un nombre para el contacto: ");
	leerCadena(resultado.nombre, tamAgenda);
	
	printf("\nIngres un domicilio para el contacto: ");
	leerCadena(resultado.domicilio, tamAgenda);
	
	do {
		printf("\nIngrese un numero telefonico para el contacto: ");
		leerCadena(resultado.telefono, 10);
	} while(esCadenaNumerica(resultado.telefono) != 1);
	
	return resultado;
}

void insertarContacto(Agenda vec, int* longitud, Contacto con) {
	int j;
	vec[0] = con;
	j = *longitud;
	while(compararContactos(con, vec[j]) == -1) {
		vec[j+1] = vec[j];
		j -= 1;
	}
	vec[j+1] = con;
	*longitud += 1;
}

void mostrarContactos(Agenda vec, int longitud) {
	for(int i = 1; i <= longitud; i++) {
		printf("Nombre: %s - Apellido: %s - Domicilio: %s - Telefono: %s\n", vec[i].nombre, vec[i].apellido, vec[i].domicilio, vec[i].telefono);
	}
}
