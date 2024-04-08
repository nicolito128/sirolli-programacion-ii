#include "lista_repuestos.h"
#include <stdio.h>
#include <stdlib.h>

ListaRepuestos inicializador();
void menu(ListaRepuestos*);

int main() {
	ListaRepuestos lista;
	lista = inicializador();
	
	system("cls");
	menu(&lista);
	return 0;
}

ListaRepuestos inicializador() {
	ListaRepuestos lista;
	int n;
	
	lista.tam = 0;
	
	printf("Ingrese la cantidad de repuestos a cargar inicialmente: ");
	scanf("%d", &n);
	
	cargarLista(&lista, n);
	return lista;
}

void menu(ListaRepuestos* lista) {
	int option;
	
	do {
		printf("Aplicacion de Repuestos - Menu");
		printf("\n0. Salir\n1. Agregar un nuevo repuesto\n2. Mostrar lista de repuestos\n3. Buscar y mostrar repuesto por codigo.\n4. Modificar el precio de un repuesto.\n5. Mostrar repuestos sin stock.");
		printf("\n>");
		scanf("%d", &option);
		
		switch(option) {
		case 1:
			cargarLista(lista, 1);
			break;
			
		case 2:
			mostrarListaRepuestos(*lista);
			break;
			
		case 3:
			mostrarRepuestoPorCodigo(*lista);
			break;
		case 4:
			omodificarPrecioListaRepuesto(lista);
			break;
		case 5:
			mostrarRepuestosSinStock(*lista);
			break;
		}
		
		system("pause");
		system("cls");
	} while(option != 0);
}
