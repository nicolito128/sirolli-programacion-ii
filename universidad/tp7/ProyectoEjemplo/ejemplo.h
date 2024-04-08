#ifndef EJEMPLO_H
#define EJEMPLO_H
#define tam 100

// Alias
typedef char string[tam];

// Structs
typedef struct {
	string firstname;
	string lastname;
} Person;

// Prototies
Person newPerson();
void showPerson(Person);

#endif
