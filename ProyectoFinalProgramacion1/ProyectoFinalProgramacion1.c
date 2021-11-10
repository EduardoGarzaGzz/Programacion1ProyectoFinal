#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE_ARRAY 100

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

const char pathFiles[] = "C:\\ProyectoProgramacion1EUGG";

int countProveedores = 0;
struct Proveedor {
	char nombreMarca[255];
	char nombre[255];
	char telefono[10];
	char direccion[500];
	char correo[255];
} proveedores[MAX_SIZE_ARRAY];

int countRefrigeradores = 0;
struct Refrigerador {
	char code[6];
	int inventario;
	float precio;
	char nombre[255];
	char descripcion[500];
	struct Proveedor proveedor;
} refrigeradores[MAX_SIZE_ARRAY];

int countClientes = 0;
struct Cliente {
	int countRefrigeradoresList;
	char nombre[255];
	char correo[255];
	struct Refrigerador refrigeradoresList[MAX_SIZE_ARRAY];
} clientes[MAX_SIZE_ARRAY];

void saveProveedores();

void saveClientes();

void saveRefrigeradores();

void setGlobalConfig();

void readProveedores();

void readClientes();

void readRefrigeradores();

void processInventario();

void processVentas();

void processReportes();

void printError(const char *err);

void agregarRefrigerador();

long lengthOfArray(const char *c);

char *getCodigoRefrigerador(char *);

char *getText();

int main() {
	char opt = 0;
	setGlobalConfig();
	readProveedores();
	readRefrigeradores();
	readClientes();

	do {
		printf("Bienvenido a REFRIAPP (Proyecto final de programación 1)");
		printf("\n-- Presione el numero indicado al inicio de cada opción -- \n");
		printf("-- 1) Ir a Inventario\n");
		printf("-- 2) Ir a Ventas\n");
		printf("-- 3) Ir a Reportes\n");
		printf("-- S) Salir del programa\n");
		scanf(" %c", &opt);

		switch ( opt ) {
			case '1':
				system("cls");
				processInventario();
				break;
			case '2':
				system("cls");
				processVentas();
				break;
			case '3':
				system("cls");
				processReportes();
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
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
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
				printf("Cual es el refrigerador que deseas dar de baja\n");
				for ( int i = 0; i < countRefrigeradores; i++ )
					printf("#%d %s\n", i + 1, refrigeradores[i].nombre);

				do {
					int iOpt;
					scanf(" %d", &iOpt);
					iOpt--;

					if (iOpt > countRefrigeradores || iOpt < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					for ( int i = 0; i < countRefrigeradores; i++ )
						if (iOpt == i) {
							refrigeradores[i] = refrigeradores[i + 1];
							iOpt++;
						}

					countRefrigeradores--;
					saveRefrigeradores();
					break;
				} while ( 1 );
				break;
			case '3': {
				int iOpt;

				printf("Cual es el refrigerador que deseas cambiar\n");
				for ( int i = 0; i < countRefrigeradores; i++ )
					printf("#%d %s\n", i + 1, refrigeradores[i].nombre);

				do {
					scanf(" %d", &iOpt);
					iOpt--;

					if (iOpt > countRefrigeradores || iOpt < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					break;
				} while ( 1 );

				printf("Código del refrigerador:");
				getCodigoRefrigerador(refrigeradores[iOpt].code);

				printf("Inventario inicial:");
				scanf(" %d", &refrigeradores[iOpt].inventario);

				printf("Precio unitario:");
				scanf(" %f", &refrigeradores[iOpt].precio);

				printf("Nombre:");
				scanf(" %s", refrigeradores[iOpt].nombre);

				printf("Descripcion:");
				scanf(" %s", refrigeradores[iOpt].descripcion);

				for ( int i = 0; i < countProveedores; i++ )
					printf("#%d - %s\n", i + 1, proveedores[i].nombreMarca);

				int opt = 0;
				do {
					scanf(" %d", &opt);

					if (opt <= countProveedores) {
						refrigeradores[iOpt].proveedor = proveedores[opt];
						break;
					} else
						printError("ERROR: proveedor invalido.");

				} while ( 1 );

				saveRefrigeradores();
				printf("\n");
			}
				break;
			case '4': {
				int rCount = 0;
				char textBusqueda[500];
				struct Refrigerador r[MAX_SIZE_ARRAY];
				printf("Buscar por código o nombre");
				scanf(" %s", textBusqueda);

				for ( int i = 0; i < countProveedores; i++ )
					if (strcmp(refrigeradores[i].code, textBusqueda) == 0 ||
					    strcmp(refrigeradores[i].nombre, textBusqueda) == 0) {
						r[rCount] = refrigeradores[i];
						rCount++;
					}

				if (rCount == 0)
					printf("No hay resultados para la busqueda");
				else
					for ( int i = 0; i < rCount; i++ )
						printf("#%d - %s Inventario: %d\n", i + 1, r[i].nombre, r[i].inventario);
			}
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
			case '1': {
				printf("Agregar un nuevo cliente\n");
				printf("Nombre: ");
				scanf(" %s", clientes[countClientes].nombre);

				printf("Correo: ");
				scanf(" %s", clientes[countClientes].correo);

				saveClientes();
				countClientes++;
			}
				break;
			case '2': {
				printf("Cual es el cliente que deseas dar de baja\n");
				for ( int i = 0; i < countClientes; i++ )
					printf("#%d %s\n", i + 1, clientes[i].nombre);

				do {
					int iOpt;
					scanf(" %d", &iOpt);
					iOpt--;

					if (iOpt > countClientes || iOpt < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					for ( int i = 0; i < countClientes; i++ )
						if (iOpt == i) {
							clientes[i] = clientes[i + 1];
							iOpt++;
						}

					countClientes--;
					saveClientes();
					break;
				} while ( 1 );
			}
				break;
			case '3': {
				int iOpt;

				printf("Cual es el cliente que deseas modificar\n");
				for ( int i = 0; i < countClientes; i++ )
					printf("#%d %s\n", i + 1, clientes[i].nombre);

				do {
					scanf(" %d", &iOpt);
					iOpt--;

					if (iOpt > countClientes || iOpt < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					break;
				} while ( 1 );

				printf("\nNombre: ");
				scanf(" %s", clientes[iOpt].nombre);

				printf("Correo: ");
				scanf(" %s", clientes[iOpt].correo);

				saveClientes();
				printf("\n");
			}
				break;
			case '4': {
				int iClienteSelected;
				printf("Seleccione un cliente\n");
				for ( int i = 0; i < countClientes; i++ )
					printf("#%d %s\n", i + 1, clientes[i].nombre);

				do {
					scanf(" %d", &iClienteSelected);
					iClienteSelected--;

					if (iClienteSelected > countClientes || iClienteSelected < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					break;
				} while ( 1 );

				clientes[iClienteSelected].countRefrigeradoresList = 0;
				do {
					int iRefri;
					printf("Seleccione un item a agregar al ticket o para salir presione (0)\n");
					for ( int i = 0; i < countRefrigeradores; i++ )
						printf("#%d %s Precio: %.2f, Inventario: %d\n", i + 1, refrigeradores[i].nombre,
						       refrigeradores[i].precio, refrigeradores[i].inventario);
					scanf(" %d", &iRefri);
					iRefri--;

					if (iRefri == -1)
						break;

					if (iRefri > countRefrigeradores || iRefri < 0) {
						printError("ERROR: Opción no valida");
						continue;
					}

					if (refrigeradores[iRefri].inventario == 0)
						printf("Lo sentimos no hay elementos disponibles de %s", refrigeradores[iRefri].nombre);
					else {
						int idx = clientes[iClienteSelected].countRefrigeradoresList;
						clientes[iClienteSelected].refrigeradoresList[idx] = refrigeradores[iRefri];
						clientes[iClienteSelected].countRefrigeradoresList++;
						refrigeradores[iRefri].inventario--;
					}

				} while ( 1 );

				float totalCosto = 0;
				system("cls");
				printf("========Ticket========\n");
				for(int i = 0; i < clientes[iClienteSelected].countRefrigeradoresList; i++) {
					struct Refrigerador r = clientes[iClienteSelected].refrigeradoresList[i];
					printf("#%d %s === $%.2f\n", i + 1, r.nombre, r.precio);
					totalCosto += r.precio;
				}
				printf("Total:   $%.2f\n", totalCosto);

				saveRefrigeradores();
				saveClientes();
			}
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

void printError(const char *err) {
	printf("\n*===* %s *===*\n", err);
}

void agregarRefrigerador() {
	system("cls");
	printf("\nAgregar un nuevo refrigerador\n");
	printf("Código del refrigerador:");
	getCodigoRefrigerador(refrigeradores[countRefrigeradores].code);

	printf("Inventario inicial:");
	scanf(" %d", &refrigeradores[countRefrigeradores].inventario);

	printf("Precio unitario:");
	scanf(" %f", &refrigeradores[countRefrigeradores].precio);

	printf("Nombre:");
	scanf(" %s", refrigeradores[countRefrigeradores].nombre);

	printf("Descripcion:");
	scanf(" %s", refrigeradores[countRefrigeradores].descripcion);

	for ( int i = 0; i < countProveedores; i++ )
		printf("#%d - %s\n", i + 1, proveedores[i].nombreMarca);

	int opt = 0;
	do {
		scanf(" %d", &opt);

		if (opt <= countProveedores) {
			refrigeradores[countRefrigeradores].proveedor = proveedores[opt];
			break;
		} else
			printError("ERROR: proveedor invalido.");

	} while ( 1 );

	saveRefrigeradores();
	printf("\n");
}

char *getCodigoRefrigerador(char *code) {
	short isCodeValid = 0;
	while ( isCodeValid == 0 ) {
		scanf(" %s", code);

		if (lengthOfArray(code) == 5)
			if (isdigit(code[0]) && isdigit(code[1]) && isalpha(code[2]) && isalpha(code[3]) && isalpha(code[4]))
				isCodeValid = 1;
			else
				printError("Error: El código es invalido debe de ser 2 numero y 3 caracteres");
		else
			printError("Error: El código tiene que ser de 5 caracteres");
	}
	return code;
}

long lengthOfArray(const char *arr) {
	long size = 0;

	while ( *arr ) {
		size += 1;
		arr += 1;
	}

	return size;
}

void readProveedores() {
	char finalPath[255] = { 0 };
	FILE *fProveedor;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\proveedores.txt");

	fProveedor = fopen(finalPath, "r");
	if (fProveedor == NULL) {
		printError("ERROR: No se puede recuperar la información de proveedores");
		exit(1);
	}

	while ( fread(&proveedores[countProveedores], sizeof(struct Proveedor), 1, fProveedor) )
		countProveedores++;

	fclose(fProveedor);
}

void readRefrigeradores() {
	char finalPath[255] = { 0 };
	FILE *fRefrigerador;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\refrigeradores.txt");

	fRefrigerador = fopen(finalPath, "r");
	if (fRefrigerador == NULL) {
		printError("ERROR: No se puede recuperar la información de refrigeradores");
		exit(1);
	}

	while ( fread(&refrigeradores[countRefrigeradores], sizeof(struct Refrigerador), 1, fRefrigerador) )
		countRefrigeradores++;

	fclose(fRefrigerador);
}

char *getText() {
	char *line = malloc(100), *linep = line;
	size_t lenmax = 100, len = lenmax;
	int c;

	if (line == NULL)
		return NULL;

	for ( ;; ) {
		c = fgetc(stdin);
		if (c == EOF)
			break;

		if (--len == 0) {
			len = lenmax;
			char *linen = realloc(linep, lenmax *= 2);

			if (linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if ((*line++ = c) == '\n')
			break;
	}
	*line = '\0';
	return linep;
}

void saveProveedores() {
	char finalPath[255] = { 0 };
	FILE *fProveedor;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\proveedores.txt");

	fProveedor = fopen(finalPath, "w");

	for ( int i = 0; i < countProveedores; i++ )
		fwrite(&proveedores[i], sizeof(struct Proveedor), 1, fProveedor);

	if (fwrite != 0)
		printf("Se guardo correctamente la información de proveedores\n");
	else
		printf("Error: No se guardo el archivo de proveedores\n");

	fclose(fProveedor);
}

void saveRefrigeradores() {
	char finalPath[255] = { 0 };
	FILE *fRefrigerador;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\refrigeradores.txt");

	fRefrigerador = fopen(finalPath, "w");

	for ( int i = 0; i < countRefrigeradores; i++ )
		fwrite(&refrigeradores[i], sizeof(struct Refrigerador), 1, fRefrigerador);

	if (fwrite != 0)
		printf("Se guardo correctamente la información de refrigeradores\n");
	else
		printf("Error: No se guardo el archivo de refrigeradores\n");

	fclose(fRefrigerador);
}

void saveClientes() {
	char finalPath[255] = { 0 };
	FILE *fCliente;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\clientes.txt");

	fCliente = fopen(finalPath, "w");

	for ( int i = 0; i < countRefrigeradores; i++ )
		fwrite(&clientes[i], sizeof(struct Cliente), 1, fCliente);

	if (fwrite != 0)
		printf("Se guardo correctamente la información de clientes\n");
	else
		printf("Error: No se guardo el archivo de clientes\n");

	fclose(fCliente);
}

void readClientes() {
	char finalPath[255] = { 0 };
	FILE *fCliente;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\clientes.txt");

	fCliente = fopen(finalPath, "r");
	if (fCliente == NULL) {
		printError("ERROR: No se puede recuperar la información de clientes");
		exit(1);
	}

	while ( fread(&clientes[countClientes], sizeof(struct Cliente), 1, fCliente) )
		countClientes++;

	fclose(fCliente);
}