#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 30

typedef char list[tam];

typedef struct {
	long int id;
	list nombre;
	list domicilio;
	float saldo;
} Cliente;

typedef Cliente ListCliente[tam];

void leeCad(list, int);
void pedirCliente();
void cargarCliente(ListCliente, int, Cliente);
int buscarCliente(long int);

int main() {
	Cliente cl = pedirCliente();
	
	return 0;
}

void pedirCliente() {
	float aux;
	Cliente result;
	
	do {
		printf("\nIngrese un numero de cuenta: ");
		scanf("%f", &aux);
		fflush(stdin);
	} while(aux < 0 || aux != (int)aux);
	result.id = (int)aux;
	
	do {
		printf("\nIngrese el nombre del titular: ");
		scanf("%s", &result.nombre);
		fflush(stdin);
	} while(strlen(result.nombre) <= 1 || strlen(result.nombre) > tam);
	
	do {
		printf("\nIngrese el domicilio del titular: ");
		scanf("%s", &result.domicilio);
		fflush(stdin);
	} while(strlen(result.nombre) <= 1 || strlen(result.nombre) > tam);
	
	do {
		printf("\nDigite el saldo inicial de la cuenta: ");
		scanf("%f", &aux);
		fflush(stdin);
	} while(aux < 0 || aux != (int)aux);
	result.saldo = (int)aux;
	
	return result;
}
