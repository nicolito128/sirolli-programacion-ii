#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tamPatente 7

enum Vehiculo {
	Moto = 50,
	Auto = 100,
	Camioneta = 150
};

typedef struct {
	int anio;
	int mes;
	int dia;
} Fecha;

typedef struct {
	int horas;
	int minutos;
} Hora;

typedef struct {
	char patente[tamPatente];
	enum Vehiculo tipo;
	Fecha fechaIngreso;
	Hora horaIngreso;
	Hora horaSalida;
} Ticket;

typedef struct {
	char nombre[100];
	char dni[100];
} Alumno;

void menu();
void leerStr();
enum Vehiculo charAVehiculo(char);
Ticket obtenerTicket();
int calcularCostes(Ticket);

int main() {
	menu();
	return 0;
}

void menu() {
	float option;
	Ticket recibo;
	int total;
	
	do {
		printf("* Programa para Calcular Coste de Estacionamiento *\n");
		printf("Digite la accion a realizar:\n");
		printf("0. Salir\n1. Calcular importe de ticket\n");
		printf("> ");
		scanf("%f", &option);
		
		switch((int)option) {
		case 1:
			recibo = obtenerTicket();
			total = calcularCostes(recibo);
			printf("\nEl vehiculo %s de coste $%d por hora debe pagar: $%d\n", recibo.patente, recibo.tipo, total);
			break;
		}
		
		system("pause");
		system("cls");
	} while(option != 0);
}

void leerStr(char cadena[], int tam){
	int j, m;
	
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n') {
		cadena[j]=m;
		j++;
	}
	
	cadena[j]='\0';
	if(m != EOF && m != '\n') /*limpia el buffer*/
		while((m=getchar())!=EOF && m!='\n');
}
	
enum Vehiculo charAVehiculo(char c) {
	switch(c) {
	case 'M':
		return 50; 
		break;
	case 'A':
		return 100;
		break;
	case 'C':
		return 150;
		break;
	}
	
	return 100;
}

Ticket obtenerTicket() {
	Ticket recibo;
	float fAux;
	char cAux;
	
	printf("\nIngrese una patente (debe contener 7 digitos): ");
	gets(recibo.patente);
	fflush(stdin);
	
	do {
		printf("\nIngrese el tipo de Vehiculo (M: moto, A: Auto, C: Camioneta): ");
		scanf(" %c", &cAux);
		cAux = toupper(cAux);
	} while(cAux != 'C' && cAux != 'A' && cAux != 'M');
	recibo.tipo = charAVehiculo(cAux);
	
	do {
		printf("\nIngrese el dia de ingreso: ");
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0 || fAux > 31);
	recibo.fechaIngreso.dia = (int)fAux;
	
	do {
		printf("\nIngrese el mes de ingreso: ");
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0 || fAux > 12);
	recibo.fechaIngreso.mes = (int)fAux;
	
	do {
		printf("\nIngrese el anio de ingreso: ");
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0);
	recibo.fechaIngreso.anio = (int)fAux;
	
	do {
		printf("\nDigite la hora de ingreso del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux > 24);
	recibo.horaIngreso.horas = (int)fAux;
	
	do {
		printf("\nDigite los minutos de ingreso del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux > 59);
	recibo.horaIngreso.minutos = (int)fAux;
	
	do {
		printf("\nDigite la hora de salida del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux > 24);
	recibo.horaSalida.horas = (int)fAux;
	
	do {
		printf("\nDigite los minutos de salida del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux > 59);
	recibo.horaSalida.minutos = (int)fAux;
	
	return recibo;
}

int calcularCostes(Ticket recibo) {
	return 100;
}

