#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamCad 100

typedef char cadena[tamCad];

typedef struct {
	cadena apellido, nombre, fecha_nacimiento, curso;
	long int dni;
} Alumno;

typedef struct Nodo {
	Alumno dato; // <- CORRECTO
	// MAL:
	// cadena apellido, nombre, fecha_nacimiento, curso;
	// long int dni;
	struct Nodo* sig;
} TNodoAlumno;

typedef TNodoAlumno* TLista;

// Prototipos
void menu(TLista*);
void leeCad(cadena, int);
TLista crearNodo(Alumno);
Alumno crearAlumno();
void mostrarAlumno(Alumno);
void modificarAlumnoFecha(Alumno*);
void cargarAlumnoOrdenado(TLista*, Alumno);
void cargarAlumnos(TLista*);
void mostrarAlumnosCurso(TLista);
void eliminarAlumno(TLista*);
void eliminarAlumnoPorDNI(TLista*, long int);
int buscarAlumno(TLista, long int);

int main() {
	TLista lista = NULL;
	cargarAlumnos(&lista);
	menu(&lista);
	return 0;
}

void menu(TLista* lista) {
	int option;
	TLista aux = *lista;
	
	do {
		printf("\nIngrese una opcion: ");
		printf("\n0. Salir");
		printf("\n1. Eliminar un alumno por dni");
		printf("\n3. Mostrar alumnos por curso\n4. Mostrar todos");
		printf("\n> ");
		scanf("%d", &option);
		
		switch(option) {
		case 1:
			eliminarAlumno(lista);
			break;
		case 3:
			mostrarAlumnosCurso(*lista);
			break;
		case 4:
			while(aux != NULL) {
				printf("\n");
				mostrarAlumno(aux->dato);
				aux = aux->sig;
			}
			
			aux = *lista;
			break;
		}
		
		system("pause");
		system("cls");
	} while(option != 0);
}

void leeCad(cadena cad, int tam) {
	int j, m;
	j = 0;
	
	fflush(stdin);
	while(j < tam-1 && (m=getchar()) != EOF && m != '\n') {
		cad[j] = m;
		j++;
	}
	cad[j] = '\0';
	
	if (m != EOF && m != '\n')
		while((m=getchar()) != EOF && m != '\n');
}

Alumno crearAlumno() {
	Alumno aux;
	
	printf("\nCargando alumno\n");
	printf("\nIngrese un Apellido: ");
	leeCad(aux.apellido, 100);
	
	printf("\nIngrese el nombre: ");
	leeCad(aux.nombre, 100);
	
	printf("\nIngrese el DNI: ");
	scanf("%ld", &aux.dni);
	
	printf("\nIngrese la fecha de nacimiento (AAAAMMDD): ");
	leeCad(aux.fecha_nacimiento, 8);
	
	printf("\nIngrese el curso: ");
	leeCad(aux.curso, 100);
	
	return aux;
}

void mostrarAlumno(Alumno alum) {
	printf("\nApellido: %s", alum.apellido);
	printf("\nNombre: %s", alum.nombre);
	printf("\nDNI: %ld", alum.dni);
	printf("\nFecha de nacimiento: %s", alum.fecha_nacimiento);
	printf("\nCurso: %s", alum.curso);
}

void modificarAlumnoFecha(Alumno* alum) {
	printf("\nIngrese una nueva fecha de nacimiento: ");
	leeCad(alum->fecha_nacimiento, 8);
}

TLista crearNodo(Alumno alum) {
	TLista nodo = (TLista)malloc(sizeof(TNodoAlumno));
	nodo->dato = alum;
	nodo->sig = NULL;
	return nodo;
}

int buscarAlumno(TLista lista, long int dni) {
	if (lista == NULL) return 0;
	
	TLista aux = lista;
	while(aux->sig != NULL && aux->dato.dni != dni) {
		aux = aux->sig;
	}
	
	if (aux->dato.dni == dni) return 1;
	return 0;
}

void cargarAlumnoOrdenado(TLista* lista, Alumno alum) {
	if (*lista == NULL) {
		*lista = crearNodo(alum);
		return;
	}
	
	TLista aux = *lista, ant = NULL, nodo = NULL;
	while(aux != NULL && aux->dato.dni < alum.dni) {
		ant = aux;
		aux = aux->sig;
	}
	
	nodo = crearNodo(alum);
	if (aux == NULL) {
		ant->sig = nodo;
	} else {
		if (ant != NULL) {
			nodo->sig = aux;
			ant->sig = nodo;
		} else {
			nodo->sig = aux;
			*lista = nodo;
		}
	}
}

void cargarAlumnos(TLista* lista) {
	int cantAlum, i;
	Alumno auxAlum;
	
	printf("\nIngrese una cantidad de alumnos a cargar: ");
	scanf("%d", &cantAlum);
	
	for(i = 1; i <= cantAlum; i++) {
		do {
			auxAlum = crearAlumno();
		} while(buscarAlumno(*lista, auxAlum.dni) == 1);
		cargarAlumnoOrdenado(lista, auxAlum);
		printf("\nSe cargo satisfacotiramente al nuevo alumno.\n");
	}
	
	system("pause");
	system("cls");
}

void mostrarAlumnosCurso(TLista lista) {
	TLista aux = lista;
	cadena auxCurso;
	int b = 0;

	if (lista != NULL) {
		printf("\nIngrese un curso a mostrar: ");
		leeCad(auxCurso, 100);
		
		while(aux != NULL) {
			if (strcmp(aux->dato.curso, auxCurso) == 0) {
				b = 1;
				mostrarAlumno(aux->dato);
			}
			
			aux = aux->sig;
		}
	} else {
		printf("\nNo hay alumnos a mostrar.");
	}
	
	if (b == 0) {
		printf("\nNo se pudo mostrar ningun alumno con el curso seleccionado.");
	}
}

void eliminarAlumnoPorDNI(TLista* lista, long int dni) {
	if (*lista != NULL) {
		TLista aux = *lista, ant = NULL;
		
		while(aux != NULL && aux->dato.dni != dni) {
			ant = aux;
			aux = aux->sig;
		}
		
		if (aux != NULL) {
			if (ant != NULL) {
				ant->sig = aux->sig;
			} else {
				*lista = aux->sig;
			}
			
			free(aux);
		}
	}
}

void eliminarAlumno(TLista* lista) {
	long int dni;
	
	printf("\nIngrese un DNI para eliminar al alumno: ");
	scanf("%ld", &dni);
	
	if (buscarAlumno(*lista, dni) == 1) {
		eliminarAlumnoPorDNI(lista, dni);
	} else {
		printf("\nEl alumno no existe.");
	}
}
