#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE_ARRAY 100

#include <locale.h>
#include <stdio.h>
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
	char code[5];
	int inventario;
	float precio;
	char nombre[255];
	char descripcion[500];
	struct Proveedor proveedor;
} refrigeradores[MAX_SIZE_ARRAY];

void addRefrigerador(
		const char *code,
		int inventario,
		float precio,
		const char *nombre,
		const char *descripcion,
		struct Proveedor proveedor
);

void addProveedor(
		const char nombreMarca[255],
		const char nombre[255],
		const char telefono[10],
		const char direccion[500],
		const char correo[255]
);

int mkdir(const char *pathname);

void saveProveedores();

void saveRefrigeradores();

void saveClientes();

void addRefrigerador(const char* code, int inventario, float precio, const char* nombre,
	const char* descripcion, struct Proveedor proveedor);

void addProveedor(const char nombreMarca[255], const char nombre[255], const char telefono[10],
	const char direccion[500], const char correo[255]);

int main() {
	setlocale(LC_ALL, ".UTF-8");

	addProveedor("LG", "LG", "1234567890", "LG Fabrica", "ventas@lg.com");
	addProveedor("Samsung", "Samsung", "1234567890", "Samsung Fabrica", "ventas@samsung.com");
	addProveedor("Whirlpool", "Whirlpool", "1234567890", "Whirlpool Fabrica", "ventas@whirlpool.com");
	addProveedor("Maytag", "Maytag", "1234567890", "Maytag Fabrica", "ventas@maytag.com");
	addProveedor("Insignia", "Insignia", "1234567890", "Insignia Fabrica", "ventas@insignia.com");

	saveProveedores();

	//  Whirlpool 25.2-Cubic-Foot French Door WRF535SMH Refrigerator
	addRefrigerador("262FX", 20, 2649.0f, "26.2-Cubic-Foot Smart French Door LFXS26973 Refrigerator",
	                "LG is a global electronics company based in South Korea. It offers a range of products including TVs, kitchen appliances, washers and dryers, computers, and mobile devices. LG was established in 1958 and the company has pioneered technologies like the world???s first 84-inch Ultra HD TV and the first internet-connected refrigerator. LG currently offers a full line-up of French door, side-by-side, top-freezer, and bottom-freezer refrigerators.",
	                proveedores[0]);
	addRefrigerador("551RF", 10, 3799.0f, "27.7-Cubic-Foot Four-Door RF28R7551 Refrigerator",
	                "The Samsung French Door RF28R7551 has several standout features including a touch screen with speakers and Wi-Fi connectivity, known as the Family Hub. The Family Hub allows you to see what???s inside the fridge without opening it using three built-in cameras. It can also create shopping lists based on what???s inside and keep track of expiration dates.",
	                proveedores[1]);
	addRefrigerador("535SMH", 10, 1721.0f, "Whirlpool 25.2-Cubic-Foot French Door WRF535SMH Refrigerator",
	                "The Whirlpool French Door WRF535SMH scores 4.0 out of 5 which ties it at No. 3 for both Best Refrigerators of 2021 and Best French Door Refrigerators. The popular French door layout is noted by experts as convenient and offering ample space at eye level to browse fresh foods.",
	                proveedores[2]);

	addRefrigerador("01AAA", 0, 100.0f, "TEST1", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("02AAA", 0, 100.0f, "TEST2", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("03AAA", 0, 100.0f, "TEST3", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("04AAA", 0, 100.0f, "TEST4", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("05AAA", 0, 100.0f, "TEST5", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("06AAA", 0, 100.0f, "TEST6", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("07AAA", 0, 100.0f, "TEST7", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("08AAA", 0, 100.0f, "TEST8", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("09AAA", 0, 100.0f, "TEST9", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("10AAA", 0, 100.0f, "TEST10", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("11AAA", 0, 100.0f, "TEST11", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("12AAA", 0, 100.0f, "TEST12", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("13AAA", 0, 100.0f, "TEST13", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("14AAA", 0, 100.0f, "TEST14", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("15AAA", 0, 100.0f, "TEST15", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("16AAA", 0, 100.0f, "TEST16", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("17AAA", 0, 100.0f, "TEST17", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("18AAA", 0, 100.0f, "TEST18", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("19AAA", 0, 100.0f, "TEST19", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);
	addRefrigerador("20AAA", 0, 100.0f, "TEST20", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book", proveedores[0]);


	saveRefrigeradores();
	saveClientes();
}

void addRefrigerador(const char *code, int inventario, float precio, const char *nombre,
                     const char *descripcion, struct Proveedor proveedor) {
	strcpy(refrigeradores[countRefrigeradores].code, code);
	refrigeradores[countRefrigeradores].inventario = inventario;
	refrigeradores[countRefrigeradores].precio = precio;
	strcpy(refrigeradores[countRefrigeradores].nombre, nombre);
	strcpy(refrigeradores[countRefrigeradores].descripcion, descripcion);
	refrigeradores[countRefrigeradores].proveedor = proveedor;
	countRefrigeradores++;
}

void addProveedor(const char nombreMarca[255], const char nombre[255], const char telefono[10],
                  const char direccion[500], const char correo[255]) {
	strcpy(proveedores[countProveedores].nombreMarca, nombreMarca);
	strcpy(proveedores[countProveedores].nombre, nombre);
	strcpy(proveedores[countProveedores].telefono, telefono);
	strcpy(proveedores[countProveedores].direccion, direccion);
	strcpy(proveedores[countProveedores].correo, correo);
	countProveedores++;
}

void saveProveedores() {
	char finalPath[255] = { 0 };
	FILE *fProveedor;

	strcpy(finalPath, pathFiles);
	strcat(finalPath, "\\proveedores.txt");

	fProveedor = fopen(finalPath, "w");

	if (fProveedor == NULL)
		if (mkdir(pathFiles))
			printf("Se creo el directorio %s", pathFiles);
		else
			printf("ERROR: No se pudo crear el directorio");

	for ( int i = 0; i < countProveedores; i++ )
		fwrite(&proveedores[i], sizeof(struct Proveedor), 1, fProveedor);

	if (fwrite != 0)
		printf("Se guardo correctamente la informaci??n de proveedores\n");
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

	if (fRefrigerador == NULL)
		if (mkdir(pathFiles))
			printf("Se creo el directorio %s", pathFiles);
		else
			printf("ERROR: No se pudo crear el directorio");

	for ( int i = 0; i < countRefrigeradores; i++ )
		fwrite(&refrigeradores[i], sizeof(struct Refrigerador), 1, fRefrigerador);

	if (fwrite != 0)
		printf("Se guardo correctamente la informaci??n de refrigeradores\n");
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

	if (fCliente == NULL)
		if (mkdir(pathFiles))
			printf("Se creo el directorio %s", pathFiles);
		else
			printf("ERROR: No se pudo crear el directorio");


	fclose(fCliente);
}