#ifndef TLISTA_H
#define TLISTA_H
#include "TAD_MIEMBRO.h"

typedef struct Nodo {
	Miembro dato;
	struct Nodo * sig;
} TNodo;

typedef TNodo * TLista;

void existe_miembro(TLista);
void eliminar_miembro(TLista*);
void agregar_miembro(TLista*);
void mostrar_lista_estados(TLista);
void mostrar_lista(TLista);

#endif
