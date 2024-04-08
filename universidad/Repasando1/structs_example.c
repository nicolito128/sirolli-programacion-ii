#include <stdio.h>

typedef struct {
	char firstname[100];
	char lastname[100];
	long int dni;
} Person;

int main() {
	int i, length = 3;
	// Declarando una estructura Person
	Person nico = {"Nicolas", "Serna", 45432055};
	// Declarando un vector de personas
	Person people[3] = {
		{"Maximiliano", "Fernandez", 36789010},
		{"Mauricio", "Arispe", 44543009},
		nico
	};
	
	// Recorremos los elementos del vector personas
	for(i = 0; i < length; i++) {
		// Accedemos a los elementos de cada dato Person con Person.<PROPERTY>
	    printf("Datos de mi persona: %s %s - DNI: %ld\n", people[i].firstname, people[i].lastname, people[i].dni);
	}
	
	return 0;
}

