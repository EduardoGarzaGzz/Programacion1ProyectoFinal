#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE_ARRAY 100

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

struct Proveedor {
	char nombreMarca[255];
	char nombre[255];
	char telefono[10];
	char direccion[500];
	char correo[255];
};

int countRefrigeradores = 0;
struct Refrigerador {
	char code[5];
	int inventario;
	float precio;
	char nombre[255];
	char descripcion[500];
	struct Proveedor Proveedor;
} refrigeradores[MAX_SIZE_ARRAY];

struct Cliente {
	char nombre[255];
	char correo[255];
	struct Refrigerador refrigeradoresList[MAX_SIZE_ARRAY];
};

void setGlobalConfig();

void processInventario();

void processVentas();

void processReportes();

void processClientes();

void printError(const char *err);

void agregarRefrigerador();

int lenArrChar(char *c);

int main() {
	char opt = 0;
	setGlobalConfig();

	do {
		printf("Bienvenido a REFRIAPP (Proyecto final de programación 1)");
		printf("\n-- Presione el numero indicado al inicio de cada opción -- \n");
		printf("-- 1) Ir a Inventario\n");
		printf("-- 2) Ir a Ventas\n");
		printf("-- 3) Ir a Reportes\n");
		printf("-- 4) Ir a Clientes\n");
		printf("-- S) Salir del programa\n");
		scanf(" %c", &opt);

		switch ( opt ) {
			case '1':
				processInventario();
				break;
			case '2':
				processVentas();
				break;
			case '3':
				processReportes();
				break;
			case '4':
				processClientes();
				break;

			default:
				opt = ( char ) tolower(opt);
				if (opt != 's')
					printError("ERROR: La opción es invalida favor de probar otra ves");
				break;
		}

	} while ( opt != 's' );

	return 0;
}

void setGlobalConfig() {
	setlocale(LC_ALL, "");
}

void processInventario() {
	char opt;
	do {
		printf("\nMenu de Inventario\n");
		printf("-- 1) Alta de articulo\n");
		printf("-- 2) Baja de articulo\n");
		printf("-- 3) Cambio de articulo\n");
		printf("-- 4) Disponibilidad de articulo\n");
		printf("-- S) Regresar al menu principal\n");
		scanf(" %c", &opt);

		switch ( opt ) {
			case '1':
				agregarRefrigerador();
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			default:
				opt = ( char ) tolower(opt);
				if (opt != 's')
					printError("ERROR: La opción es invalida favor de probar otra ves");
				break;
		}

	} while ( opt != 's' );
}

void processVentas() {
	char opt;
	do {
		printf("\nMenu de Ventas\n");
		printf("-- 1) Alta de clientes\n");
		printf("-- 2) Baja de clientes\n");
		printf("-- 3) Cambio de clientes\n");
		printf("-- 4) Generar ticket de venta\n");
		printf("-- S) Regresar al menu principal\n");
		scanf(" %c", &opt);

		switch ( opt ) {
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			default:
				opt = ( char ) tolower(opt);
				if (opt != 's')
					printError("ERROR: La opción es invalida favor de probar otra ves");
				break;
		}

	} while ( opt != 's' );
}

void processReportes() {
	char opt;
	do {
		printf("\nMenu de Reportes\n");
		printf("-- 1) Reporte de orden de compra\n");
		printf("-- 2) Reporte de venta del dia\n");
		printf("-- 3) Reporte generar saldos\n");
		printf("-- 4) Generar ticket de venta\n");
		printf("-- S) Regresar al menu principal\n");
		scanf(" %c", &opt);

		switch ( opt ) {
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			default:
				opt = ( char ) tolower(opt);
				if (opt != 's')
					printError("ERROR: La opción es invalida favor de probar otra ves");
				break;
		}

	} while ( opt != 's' );
}

void processClientes() {
	printf("\nMenu de de clientes no implementado \n");
}

void printError(const char *err) {
	printf("\n*===* %s *===*\n", err);
}

char *getCodigoRefrigerador();

void agregarRefrigerador() {

}

char *getCodigoRefrigerador() {
	short isCodeValid = 0;
	char code[5];
//	while (isCodeValid != 1) {
//		strcpy(" %s", code);
//		if ()
//	}
	return code;
}

int lenArrChar(char *c) {
	int longitud = sizeof(*c) / sizeof(char);
	return 0;
}