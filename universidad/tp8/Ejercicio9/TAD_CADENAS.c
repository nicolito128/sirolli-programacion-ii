#include "TAD_CADENAS.h"
#include <stdlib.h>
#include <stdio.h>

void leeCad(cadena cad, int tam) {
	int j, m;
	j = 0;
	
	fflush(stdin);
	while(j < tam-1 && (m=getchar()) != EOF && m != '\n') {
		cad[j] = m;
		j++;
	}
	cad[j] = '\0';
	
	
	if(m != EOF && m != '\n')
		while((m=getchar()) != EOF && m != '\n');
}
