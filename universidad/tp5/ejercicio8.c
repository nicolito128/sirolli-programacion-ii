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
int obtenerDiasDelMes(int);
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

// obtenerDiasDelMes obtiene la cantidad de dias en un mes en especifico.
// Si el mes no es valido retorna 0.
int obtenerDiasDelMes(int mes) {
	if (mes < 1 ||  mes > 12) return 0;
	
	switch(mes){
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
	
	do {
		printf("\nIngrese una patente (debe contener 7 digitos): ");
		scanf(" %s", &recibo.patente);
		fflush(stdin);
	} while(strlen(recibo.patente) < 7);
	
	do {
		printf("\nIngrese el tipo de Vehiculo (M: moto, A: Auto, C: Camioneta): ");
		scanf(" %c", &cAux);
		cAux = toupper(cAux);
	} while(cAux != 'C' && cAux != 'A' && cAux != 'M');
	recibo.tipo = charAVehiculo(cAux);
	
	do {
		printf("\nIngrese el anio de ingreso: ");
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0);
	recibo.fechaIngreso.anio = (int)fAux;
	
	do {
		printf("\nIngrese el mes de ingreso: ");
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0 || fAux > 12);
	recibo.fechaIngreso.mes = (int)fAux;
	
	do {
		printf("\nIngrese el dia de ingreso (desde 1 hasta %d): ", obtenerDiasDelMes(recibo.fechaIngreso.mes));
		scanf("%f", &fAux);
	} while(fAux != (int)fAux || fAux <= 0 || fAux > obtenerDiasDelMes(recibo.fechaIngreso.mes));
	recibo.fechaIngreso.dia = (int)fAux;
	
	do {
		printf("\nDigite la hora de ingreso del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux >= 24);
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
	float auxIn, auxOut;
	int total;
	auxIn = recibo.horaIngreso.horas + (recibo.horaIngreso.minutos / 60);
	auxOut = recibo.horaSalida.horas + (recibo.horaSalida.minutos / 60);
	
	total = (int)(auxOut - auxIn) + 1;
	return (total * recibo.tipo);
}
