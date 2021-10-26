#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE_ARRAY 10

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

void setGlobalConfig( );

void printMenuAndGetOpt( char *menu, char *opt );

void processInventario( );

void processVentas( );

void processReportes( );

void printError( char *err );


int main( ) {
	setGlobalConfig( );

	char opt = 0;

	do {
		printMenuAndGetOpt( "Bienvenido a REFRIAPP (Proyecto final de programación 1)\n"
		                    "-- Presione el numero indicado al inicio de cada opción --\n"
		                    "-- 1) Ir a Inventario\n"
		                    "-- 2) Ir a Ventas\n"
		                    "-- 3) Ir a Reportes\n"
		                    "-- S) Salir del programa\n", &opt );

		switch ( opt ) {
			case '1':
				processInventario( );
				break;
			case '2':
				processVentas( );
				break;
			case '3':
				processReportes( );
				break;

			default:
				opt = ( char ) tolower( opt );
				if ( opt != 's' )
					printError( "ERROR: La opción es invalida favor de probar otra ves" );
				break;
		}

	} while ( opt != 's' );

	return 0;
}

void setGlobalConfig( ) {
	setlocale( LC_ALL, ".UTF8" );
}

void printMenuAndGetOpt( char *menu, char *opt ) {
	printf( "%s", menu );
	scanf( " %c", opt );
}

void processInventario( ) {
	char opt;
	do {
		printMenuAndGetOpt( "\nMenu de Inventario\n"
		                    "-- 1) Alta de articulo\n"
		                    "-- 2) Baja de articulo\n"
		                    "-- 3) Cambio de articulo\n"
		                    "-- 4) Disponibilidad de articulo\n"
		                    "-- S) Regresar al menu principal\n", &opt );

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
				opt = ( char ) tolower( opt );
				if ( opt != 's' )
					printError( "ERROR: La opción es invalida favor de probar otra ves" );
				break;
		}

	} while ( opt != 's' );
}

void processVentas( ) {
	char opt;
	do {
		printMenuAndGetOpt( "\nMenu de Ventas\n"
		                    "-- 1) Alta de clientes\n"
		                    "-- 2) Baja de clientes\n"
		                    "-- 3) Buscar un cliente\n"
		                    "-- 4) Generar ticket de venta\n"
		                    "-- S) Regresar al menu principal\n", &opt );

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
				opt = ( char ) tolower( opt );
				if ( opt != 's' )
					printError( "ERROR: La opción es invalida favor de probar otra ves" );
				break;
		}

	} while ( opt != 's' );
}

void processReportes( ) { }

void printError( char *err ) {
	printf( "\n*===* %s *===*\n", err );
}