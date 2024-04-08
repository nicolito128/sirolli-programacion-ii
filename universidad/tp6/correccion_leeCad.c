#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char list[100];

void leeCad(list, int);

int main() {
	list micad;
	
	// Leyendo cadena y limpiando buffer
	leeCad(micad, 100);
	
	// Mostrando
	printf("\nMi Cadena: %s", micad);
	
	return 0;
}

void leeCad(list cadena, int tam){
	int j, m;
	j = 0;
	fflush(stdin);
	while(j<tam-1 && (m=getchar())!=EOF && m != '\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	/*limpia el buffer*/
	if(m != EOF && m != '\n')
		while((m=getchar())!=EOF && m!='\n');
}
