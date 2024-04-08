/**********************
 * Serna, Nicolas Abel *
**********************/
#include <stdio.h>
#include <stdlib.h>
#define listSize 100

// Uso de enum sugerido por el profe.
enum civilState {
	C = 0, 	// Casado
	S = 1, 	// Soltero
	V = 2, 	// Viudo
	W = 3 	// Separado
};

typedef long int list[listSize];
typedef enum civilState civilList[listSize];

// Auxiliares
enum civilState charToCivilState(char);
char civilStateToChar(enum civilState);
// Ingreso de datos
void scanMembersData(int*, list, list, civilList, list);
// Funciones y procesos para la presentacion de informacion al usuario
void menu(int*, list, list, civilList, list);
void printMember(int, list dni, list phones, civilList civil, list ages, int position);
void showMembersByCivilState(int, list, list, civilList, list, int);
void showMembers(int, list, list, civilList, list);
// Funciones y procesos para el manejo del vector
int findMember(int, list, long int);
void addMember(int*, list, list, civilList, list);
void deleteMember(int*, list, list, civilList, list, long int, int*);

int main() {
	int membersLength = 0;
	list dni, phones, ages;
	civilList civil;
	
	scanMembersData(&membersLength, dni, phones, civil, ages);
	menu(&membersLength, dni, phones, civil, ages);
	return 0;
}

void menu(int* length, list dni, list phones, civilList civil, list ages) {
	float option;
	long int member;
	int aux;
	
	do {
		system("cls");
		printf("/*/ Menu para la Gestion de Miembros - Institucion Deportiva SRL /*/");
		printf("\n- Digite por teclado alguna de las siguientes opciones: ");
		printf("\n0. Salir\n1. Buscar por DNI\n2. Agregar un nuevo miembro");
		printf("\n3. Eliminar un miembro por DNI\n4. Mostrar miembros segun su estado civil\n5. Mostrar todos los miembros\n\n");
		printf("> ");
		scanf("%f", &option);
		
		switch((int)option) {
		case 1:
			printf("\nIngrese un DNI para buscar al miembro: ");
			scanf("%ld", &member);
			aux = findMember(*length, dni, member);
			
			// Verificando que se encontro un miembro.
			if (aux != 0) {
				printMember(*length, dni, phones, civil, ages, aux);
				printf("\n");
			} else {
				printf("\nNo se encontro ningun DNI que coincida con los miembros registrados.\n");
			}
			
			system("pause");
			break;
			
		case 2:
			addMember(length, dni, phones, civil, ages);
			printf("\nNuevo miembro agregado correctamente.\n");
			
			system("pause");
			break;
			
		case 3:
			printf("\nIngrese un DNI para eliminar al miembro: ");
			scanf("%ld", &member);
	
			deleteMember(length, dni, phones, civil, ages, member, &aux);
			// Verificando que se pudo eliminar el miembro.
			if (aux == 1) {
				printf("\nEl miembro se elimino satisfactoriamente.\n");
			} else {
				printf("\nNo se encontro ningun miembro registrado con ese DNI para eliminarlo.\n");
			}
			
			system("pause");
			break;
			
		case 4:
			showMembersByCivilState(*length, dni, phones, civil, ages, 0);
			system("pause");
			break;
			
		case 5:
			showMembers(*length, dni, phones, civil, ages);
			system("pause");
			break;
		}
	} while(option != 0);
}

// charToCivilState evalua un caracter y devuelve equivalente entero. 
// En caso de no coincidir con ninguno retorna por defecto 1.
enum civilState charToCivilState(char character) {
	switch(character) {
	case 'C':
		return 0;
		break;
		
	case 'S':
		return 1;
		break;
		
	case 'V':
		return 2;
		break;
		
	case 'W':
		return 3;
		break;
	}
	
	return 1;
}

// civilStateToChar evalua un estado civil y devuelve equivalente en forma de caracter. 
char civilStateToChar(enum civilState civil) {
	switch(civil) {
	case 0:
		return 'C';
		break;
		
	case 1:
		return 'S';
		break;
		
	case 2:
		return 'V';
		break;
		
	case 3:
		return 'W';
		break;
	}
	
	return 'S';
}

// addMember solicita al usuario los datos para un nuevo miembro y lo agrega a las listas de manera ordenada segun DNI.
void addMember(int* length, list dni, list phones, civilList civil, list ages) {
	long int document, phone, age;
	enum civilState state;
	char status;
	double aux;
	int j, check;
	
	// Pidiendo y validando los datos del miembro
	do {
		printf("Ingrese el DNI de la persona: ");
		scanf("%lf", &aux);
	} while(aux < 0 || aux != (int)aux);
	document = (long int)aux;
	
	do {
		printf("Ingrese el Telefono Celular de la persona: ");
		scanf("%lf", &aux);
	} while(aux < 0 || aux != (int)aux);
	phone = (long int)aux;
	
	do {
		printf("Ingrese el Estado Civil de la persona (C: casado, S: soltero, V: viudo, W: separado): ");
		scanf(" %c", &status);
		fflush(stdin);
	} while(status != 'C' && status != 'S' && status != 'V' && status != 'W');
	state = charToCivilState(status);
	
	do {
		printf("Ingrese la Edad de la persona: ");
		scanf("%lf", &aux);
	} while(aux < 0 || aux != (int)aux);
	age = (long int)aux;
	
	check = findMember(*length, dni, document);	
	if (check == 0) {
		// Metodo de ordenamiento por insercion.
		dni[0] = document;
		j = *length;
		while(document < dni[j]) {
			dni[j+1] = dni[j];
			phones[j+1] = phones[j];
			civil[j+1] = civil[j];
			ages[j+1] = ages[j];
			j -= 1;
		}
		
		dni[j+1] = document;
		phones[j+1] = phone;
		civil[j+1] = state;
		ages[j+1] = age;
		*length = *length + 1;
	} else {
		dni[check] = document;
		phones[check] = phone;
		civil[check] = state;
		ages[check] = age;
	}
}

// scanMembersData lee la consola y lleva a cabo el ingreso de los M miembros especificados por el usuario.
void scanMembersData(int* length, list dni, list phones, civilList civil, list ages) {
	int i, limit;
	float len;
	
	do {
		printf("Defina la cantidad de personas a ingresar: ");
		scanf("%f", &len);
	} while(len < 0 || len != (int)len);
	limit = (int)len;
	
	for(i = 1; i <= limit; i++) {
		printf("\nDatos de la persona %d\n", i);
		addMember(length, dni, phones, civil, ages);
	}
}

// printMember muestra por consola los datos de un miembro en una posicion dada.
void printMember(int length, list dni, list phones, civilList civil, list ages, int position) {
	if (position <= 0 || position > length) {
		printf("\nMiembro no valido.");
	} else {
		printf("\n%d) DNI: %ld - Telefono: %ld - Civil: %c - Edad: %ld", position, dni[position], phones[position], civilStateToChar(civil[position]), ages[position]);
	}
}

// showMembersByCivilState muestra en pantalla una lista con los datos de todos los miembros que cumplan con el estado civil ingresado por teclado.
// Si el parametro 'all' es pasado como 1 entonces mostrara el dato de todos los miembros.
void showMembersByCivilState(int length, list dni, list phones, civilList civil, list ages, int all) {
	int i, e, state = -1;
	char aux;
	// Bandera para verificar que se mostro algun miembro.
	e = 0;
	
	if (all != 1) {
		do {
			printf("Ingrese el Estado Civil a buscar (C: casado, S: soltero, V: viudo, W: separado): ");
			scanf(" %c", &aux);
			fflush(stdin);
		} while(aux != 'C' && aux != 'S' && aux != 'V' && aux != 'W');
		state = charToCivilState(aux);
	}
	
	printf("\nDatos de los Miembros: ");
	for (i = 1; i <= length; i++) {
		if (state != -1) {
			if (civil[i] == state) {
				printMember(length, dni, phones, civil, ages, i);
				e = 1;
			}
		} else {
			printMember(length, dni, phones, civil, ages, i);
			e = 1;
		}
	}
	
	if (e == 0) {
		printf("\nNo se encontro ningun miembro a mostrar.");
	}
	printf("\n");
}

// showMembers muestra en pantalla la informacion de todos los miembros registrados.
// Es equivalente a llamar showMembersByCivilState() con su parametro 'all' en 1.
void showMembers(int length, list dni, list phones, civilList civil, list ages) {
	showMembersByCivilState(length, dni, phones, civil, ages, 1);
}

// findMember busca en la lista la posicion del DNI pasado como parametro y retorna la posicion. 
// En caso de no existir devuelve 0.
int findMember(int length, list dni, long int doc) {
	int start = 1, end = length, mid = (end + start)/2;
	while(start <= end && dni[mid] != doc) {
		if (dni[mid] > doc) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
		
		mid = (end + start) / 2;
	}
	
	if (dni[mid] == doc) {
		return mid;
	}
	
	return 0;
}

// deleteMember elimina un miembro de las listas en base al DNI pasado como parametro.
// Si se logra eliminar retorna 1, caso contrario retorna 0.
void deleteMember(int* length, list dni, list phones, civilList civil, list ages, long int member, int* success) {
	int i, pos = findMember(*length, dni, member);
	// En caso de no existir devolvemos 0.
	if (pos != 0) {
		*success = 1;
		
		// Algoritmo de eliminacion.
		for(i = pos; i <= (*length); i++) {
			dni[i] = dni[i + 1];
			phones[i] = phones[i + 1];
			civil[i] = civil[i + 1];
			ages[i] = ages[i + 1];
		}
		*length = *length - 1;
	} else {
		*success = 0;
	}
}
