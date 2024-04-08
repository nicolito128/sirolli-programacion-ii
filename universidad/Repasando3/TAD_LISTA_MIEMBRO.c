#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA_MIEMBRO.h"
#include "TAD_MIEMBRO.h"

TLista crear_nodo(Miembro);
int buscar_miembro_dni(TLista, long int);
long int pedir_dni();
char pedir_estado_civil();

long int pedir_dni() {
	long int dni;
	
	printf("Ingrese un DNI para buscar > ");
	scanf("%ld", &dni);
	printf("\n");
	
	return dni;
}

char pedir_estado_civil() {
	char estado;
	
	do {
		printf("Ingrese un Estado Civil para buscar > ");
		scanf("%c", &estado);
		printf("\n");
	} while(estado != 'C' && estado != 'S' && estado != 'V' && estado != 'W');
	
	return estado;
}

TLista crear_nodo(Miembro m) {
	TLista nodo;
	nodo = (TLista)malloc(sizeof(TNodo));
	nodo->dato = m;
	nodo->sig = NULL;
	
	return nodo;
}

int buscar_miembro_dni(TLista lista, long int dni) {
	int resultado;
	
	if (lista == NULL) {
		resultado = 0;
	} else {
		TLista aux = lista;
		while(aux->sig != NULL && aux->dato.dni != dni) {
			aux = aux->sig;
		}
		
		if (aux->dato.dni == dni) {
			resultado = 1;
		} else {
			resultado = 0;
		}
	}
	
	return resultado;
}

void existe_miembro(TLista lista) {
	long int dni;
	int aux;
	
	dni = pedir_dni();
	aux = buscar_miembro_dni(lista, dni);
	if (aux == 1) {
		printf("El miembro si existe.\n");
	} else {
		printf("El miembro NO existe.\n");
	}
	
}

void agregar_miembro(TLista * lista) {
	TLista aux, ant, temp;
	Miembro m = crear_miembro();
	
	if (*lista != NULL) {
		aux = *lista;
		ant = NULL;
		while (aux->sig != NULL && aux->dato.dni < m.dni) {
			ant = aux;
			aux = aux->sig;
		}
		
		temp = crear_nodo(m);
		if (ant == NULL) {
			if (aux->dato.dni >= m.dni) {
				temp->sig = aux;
				ant->sig = temp;
			} else {
				aux->sig = temp;
			}
		} else {
			if (aux != NULL) {
				if (aux->dato.dni >= m.dni) {
					
				}
			}
		}
	} else {
		*lista = crear_nodo(m);
	}
}

void eliminar_miembro(TLista * lista) {
	long int dni;
	
	if (*lista != NULL) {
		dni = pedir_dni();
		
		TLista aux, ant;
		ant = NULL;
		aux = *lista;
		
		while(aux->sig != NULL && comparar_dni(aux->dato, dni) == 0) {
			ant = aux;
			aux = aux->sig;
		}
		
		if (ant == NULL) {
			if (comparar_dni(aux->dato, dni) == 1) {
				*lista = aux->sig;
				free(aux);
				aux = NULL;
			}
		} else {
			if (aux != NULL) {
				if (comparar_dni(aux->dato, dni) == 1) {
					ant->sig = aux->sig;
					free(aux);
					aux = NULL;
				}
			}
		}
	}
}

void mostrar_lista(TLista lista) {
	TLista aux = lista;
	if (lista != NULL) {
		while(aux != NULL) {
			mostrar_miembro(aux->dato);
			aux = aux->sig;
		}
	} else {
		printf("No hay miembros para mostrar.\n");
	}
}
