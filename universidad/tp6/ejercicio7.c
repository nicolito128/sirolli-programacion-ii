#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tamPatente 7

typedef char patenteTipo[tamPatente];

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
	patenteTipo patente;
	enum Vehiculo tipo;
	Fecha fechaIngreso;
	Hora horaIngreso;
	Hora horaSalida;
	int monto;
} Ticket;

typedef Ticket VTicket[100];

void menu();
enum Vehiculo charAVehiculo(char);
Ticket obtenerTicket();
void agregarTicket(VTicket, int*, Ticket);
void agregarTicketDeSalida(VTicket, int*, VTicket, int*, int);
void eliminarTicket(VTicket, int*, int);
void eliminarTicketsPorTipo(VTicket, int*, enum Vehiculo, int*);
void mostrarTickets(VTicket, int);
int obtenerDiasDelMes(int);
int calcularCostes(Ticket);
int buscarTicket(VTicket, int, patenteTipo);

int main() {
	menu();
	return 0;
}

void menu() {
	VTicket ingreso_vehiculos, salida_vehiculos;
	int ingreso_len, salida_len, aux;
	Ticket recibo;
	float option;
	char cAux;
	patenteTipo p;
	
	ingreso_len = 0;
	salida_len = 0;
	
	do {
		printf("* Programa para Calcular Coste de Estacionamiento *\n");
		printf("Digite la accion a realizar:\n");
		printf("0. Salir\n1. Cargar nuevo ingreso de vehiculo.\n2. Procesar salida de vehiculo\n3. Mostrar vehiculos en la lista de ingreso\n4. Mostrar vehiculos en la lista de salida.\n5. Eliminar vehiculos de un mismo tipo en la lista de salida.");
		printf("\n> ");
		scanf("%f", &option);
		
		switch((int)option) {
		case 1:
			recibo = obtenerTicket();
			agregarTicket(ingreso_vehiculos, &ingreso_len, recibo);
			printf("\nTicket cargado satisfactoriamente.\n");
			break;
			
		case 2:
			printf("\nIngrese una patente para procesar.");
			mostrarTickets(ingreso_vehiculos, ingreso_len);
			do {
				fflush(stdin);
				printf("\n> ");
				scanf(" %s", &p);
			} while(strlen(p) < 7);
			strcpy(p, strupr(p));
			
			aux = buscarTicket(ingreso_vehiculos, ingreso_len, p);
			if (aux != 0) {
				agregarTicketDeSalida(ingreso_vehiculos, &ingreso_len, salida_vehiculos, &salida_len, aux);
				printf("\nSalida del vehiculo registrada satisfactoriamente.");
			} else {
				printf("\nNo se encontro ningun ticket emitido para algun vehiculo con esa patente.");
			}
			
			break;
		
		case 3:
			mostrarTickets(ingreso_vehiculos, ingreso_len);
			break;
			
		case 4:
			mostrarTickets(salida_vehiculos, salida_len);
			break;
			
		case 5:
			do {
				fflush(stdin);
				printf("\nIngrese el tipo de Vehiculo a eliminar (M: moto, A: Auto, C: Camioneta): ");
				scanf(" %c", &cAux);
				cAux = toupper(cAux);
			} while(cAux != 'C' && cAux != 'A' && cAux != 'M');	
			
			eliminarTicketsPorTipo(salida_vehiculos, &salida_len, charAVehiculo(cAux), &aux);
			if (aux == 1) {
				printf("\nElementos eliminados satisfactoriamente.\n");
			} else {
				printf("\nNo se encontraron vehiculos de ese tipo a eliminar.\n");
			}
			
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
		strcpy(recibo.patente, strupr(recibo.patente));
	} while(strlen(recibo.patente) < 7);
	
	do {
		printf("\nIngrese el tipo de Vehiculo (M: moto, A: Auto, C: Camioneta): ");
		scanf(" %c", &cAux);
		cAux = toupper(cAux);
		fflush(stdin);
	} while(cAux != 'C' && cAux != 'A' && cAux != 'M');
	recibo.tipo = charAVehiculo(cAux);
	
	do {
		printf("\nIngrese el anio de ingreso: ");
		scanf("%f", &fAux);
		fflush(stdin);
	} while(fAux != (int)fAux || fAux <= 0);
	recibo.fechaIngreso.anio = (int)fAux;
	
	do {
		printf("\nIngrese el mes de ingreso: ");
		scanf("%f", &fAux);
		fflush(stdin);
	} while(fAux != (int)fAux || fAux <= 0 || fAux > 12);
	recibo.fechaIngreso.mes = (int)fAux;
	
	do {
		printf("\nIngrese el dia de ingreso (desde 1 hasta %d): ", obtenerDiasDelMes(recibo.fechaIngreso.mes));
		scanf("%f", &fAux);
		fflush(stdin);
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
		fflush(stdin);
	} while((int)fAux != fAux || fAux < 0 || fAux > 59);
	recibo.horaIngreso.minutos = (int)fAux;
	
	recibo.horaSalida.horas = 0;
	recibo.horaSalida.minutos = 0;
	recibo.monto = 0;
	
	return recibo;
}

int calcularCostes(Ticket recibo) {
	int total;
	
	total = ((int)(recibo.horaSalida.horas - recibo.horaIngreso.horas) + ((int)(recibo.horaSalida.minutos + recibo.horaIngreso.minutos)/60)) * recibo.tipo;
	if ((recibo.horaSalida.minutos) >= (15)) {
		total += recibo.tipo;
	}
	
	return total;
}

void agregarTicket(VTicket arr, int* length, Ticket recibo) {
	*length = *length + 1;
	arr[*length] = recibo;
}

int buscarTicket(VTicket arr, int length, patenteTipo p) {
	int i = 1;
	
	while(i <= length && strcmp(arr[i].patente, p) != 0) {
		i++;
	}
	
	if (i <= length) {
		return i;
	}
	
	return 0;
}

void eliminarTicket(VTicket arr, int* length, int pos) {
	int i;
	if (pos > 0 && pos <= *length) {
		for(i = pos; i <= (*length); i++) {
			arr[i] = arr[i + 1];
		}
		*length = *length - 1;
		
	}
}

void eliminarTicketsPorTipo(VTicket arr, int* length, enum Vehiculo tipo, int* result) {
	int i;
	i = 1;
	
	while(i <= *length && *length > 0) {
		*result = 0;
		
		if (arr[i].tipo == tipo) {
			eliminarTicket(arr, length, i);
			*result = 1;
		}
		
		if (*result == 0) {
			i++;
		}
	}
}

void agregarTicketDeSalida(VTicket ingreso, int* ingreso_len, VTicket salida, int* salida_len, int pos) {
	float fAux;
	
	do {
		printf("\nDigite la hora de salida del vehiculo: ");
		scanf("%f", &fAux);
	} while((int)fAux != fAux || fAux < 0 || fAux >= 24 || ingreso[pos].horaIngreso.horas > (int)fAux);
	ingreso[pos].horaSalida.horas = (int)fAux;
	
	do {
		printf("\nDigite los minutos de salida del vehiculo: ");
		scanf("%f", &fAux);
		fflush(stdin);
	} while((int)fAux != fAux || fAux < 0 || fAux > 59);
	ingreso[pos].horaSalida.minutos = (int)fAux;
	
	ingreso[pos].monto = calcularCostes(ingreso[pos]);
	
	agregarTicket(salida, salida_len, ingreso[pos]);
	eliminarTicket(ingreso, ingreso_len, pos);
}

void mostrarTickets(VTicket arr, int length) {
	int i;
	for (i = 1; i <= length; i++) {
		printf("\n%d) Patente: %s - Fecha: %d/%d/%d", i, arr[i].patente, arr[i].fechaIngreso.dia, arr[i].fechaIngreso.mes, arr[i].fechaIngreso.anio);
		printf(" - Hora de Ingreso: %d:%d", arr[i].horaIngreso.horas, arr[i].horaIngreso.minutos);
		
		if (arr[i].horaSalida.horas >= arr[i].horaIngreso.horas) {
			printf(" - Hora de Salida: %d:%d", arr[i].horaSalida.horas, arr[i].horaSalida.minutos);
		}
		
		if (arr[i].monto > 0) {
			printf(" - Total: $%d", arr[i].monto);
		}
		
		printf("\n");
	}
	
	if (length == 0) {
		printf("\nNo se encontraron elementos para mostrar.\n");
	}
}
