#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA_MIEMBRO.h"

void opciones();
void menu();
void menu_rec(TLista*, char);

int main() {
	menu();
	return 0;
}

void opciones() {
	printf("*** Menu de Aplicacion ***\n");
	printf("0. Salir.\n");
	printf("1. Verificar si existe por DNI.\n");
	printf("2. Agregar miembro.\n");
	printf("4. Mostrar miembros.\n");
}

void menu() {
	TLista lista = NULL;
	char op;
	
	do {
		opciones();
		printf("> ");
		fflush(stdin);
		scanf("%c", &op);
		printf("\n");
		
		switch(op) {
		case '1':
			existe_miembro(lista);
			break;
			
		case '2':
			agregar_miembro(&lista);
			break;
			
		case '4':
			mostrar_lista(lista);
			break;
		}
		
		system("pause");
		system("cls");
	} while(op != '0');
}

void menu_rec(TLista * lista, char last_op) {
	char op;
	
	if (last_op != '0') {
		opciones();
		printf("> ");
		scanf("%c", &op);
		printf("\n");
		
		switch(op) {
		case '1':
			existe_miembro(lista);
			break;
			
		case '2':
			agregar_miembro(&lista);
			break;
		}
		
		system("pause");
		system("cls");
		
		menu_rec(lista, op);
	}
}

