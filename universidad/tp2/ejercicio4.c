#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scanDate(int*, int*, int*);
int getMonthDays(int);
int existDayInMonth(int, int);
int randomizer(int, int);
int getDaysDifferent(int, int, int, int, int, int);

int main() {
	int day, month, year, randY, randM, randD, diff;
	srand(time(NULL));
	
	// Obteniendo fecha
	scanDate(&day, &month, &year);
	printf("Fecha: %d/%d/%d", day, month, year);
	
	// Generando fecha aleatoria
	// Intervalo: [year+1, year+150]
	randY = randomizer(year+1, year + 150);
	// Un mes aleatorio en el intervalo [1, 12]
	randM = randomizer(1, 12);
	// Un dia aleatorio generado a partir de la cantidad de dias del mes
	randD = randomizer(1, getMonthDays(randM));
	
	printf("\nFecha aleatoria: %d/%d/%d", randD, randM, randY);
	
	diff = getDaysDifferent(day, randD, month, randM, year, randY);
	printf("\nDias transcurridos entre las dos fechas: %d", diff);
	return 0;
}

// scanDate obtiene y registra los valores de una fecha.
void scanDate(int* day, int* month, int* year) {
	printf("\nIngrese un anio: ");
	scanf("%d", year);
	
	while(*year < 0) {
		printf("\nEl anio que intenta ingresar es invalido.\nIngrese un anio valido: ");
		scanf("%d", year);
	}
	
	printf("\nIngrese un mes: ");
	scanf("%d", month);
	while(*month > 12 || *month < 1) {
		printf("\nEl mes que intenta ingresar es invalido.\nIngrese un mes valido: ");
		scanf("%d", month);
	}
	
	printf("\nIngrese un dia: ");
	scanf("%d", day);
	while(existDayInMonth(*day, *month) == 0) {
		printf("\nEl dia que intenta ingresar es invalido.\nIngrese un dia valido: ");
		scanf("%d", day);
	}
}

// getMonthDays obtiene la cantidad de dias en un mes en especifico.
// Si el mes no es valido retorna 0.
int getMonthDays(int month) {
	if (month < 1 || month > 12) return 0;
		
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
		
	case 2:
		return 28;
		break;
		
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	}
	
	return 0;
}

// isDayInMonth verifica si el dia dado puede existir en el mes especificado.
// En caso de no ser valido retorna 0.
int existDayInMonth(int day, int month) {
	int monthDays = getMonthDays(month);
	if (monthDays == 0) return 0; 
	if (day < 1 || day > monthDays) return 0;
	
	return 1;
}

// randomizer obtiene un valor aleatorio en el intervalo [a, b].
int randomizer(int a, int b) {
	int rb;
	rb = rand() % (b - a + 1) + a;
	return rb;
}

// getDaysDifferent obtiene la cantidad de dias entre dos fechas.
int getDaysDifferent(int day1, int day2, int month1, int month2, int year1, int year2) {
	int years, days, months, i, m;
	
	years = year2 - year1;
	days = day2 - day1;
	months = 0;
	
	if (month2 < month1) years--;
	
	if (month2 > month1) {
		i = month1;
		m = month2;
	} else {
		i = month2;
		m = month1;
	}
	
	while(i <= m) {
		months += getMonthDays(i);
		i++;
	}
	
	return (years * 365) + months + days;
}
