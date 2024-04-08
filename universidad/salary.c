#include <stdio.h>

int main() {
	const int DAYS = 30;
	float workHs, perHs, salary;
	
	printf("Calcule los ingresos del mes\n");
	
	printf("Ingrese cuantas horas trabaja en un dia:\n");
	scanf("%f", &workHs);
	
	printf("Ingrese cuanto gana por hora:\n");
	scanf("%f", &perHs);
	
	salary = workHs * perHs * (float)DAYS;
	printf("Usted tiene un salario de $%.2f al mes.", salary);
		
	return 0;
}
