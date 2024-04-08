#include "ejemplo.h"
#include <stdio.h>

Person newPerson() {
	Person result;
	
	printf("\nIngrese un nombre: ");
	scanf(" %s", &result.firstname);
	
	printf("\nIngrese un apellido: ");
	scanf(" %s", &result.lastname);
	
	return result;
}

void showPerson(Person p) {
	printf("\nNombre de la persona: %s", p.firstname);
	printf("\nApellido de la persona: %s", p.lastname);
}
