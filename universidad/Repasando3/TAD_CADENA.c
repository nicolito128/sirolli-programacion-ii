#include <stdio.h>
#include <stdlib.h>
#include "TAD_CADENA.h"

void leeCad(cadena cad, int tam) {
	int j,m;
	j = 0;
	
	fflush(stdin);
	while(j < (tam - 1) && (m = getchar()) != EOF && m != '\n') {
		cad[j] = m;
		j++;
	}
	cad[j] = '\0';
	
	// limpiando buffer
	if (m != EOF && m != '\n')
		while((m = getchar()) != EOF && m != '\n');
}
