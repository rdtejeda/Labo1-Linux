/*
 ============================================================================
 Name        : Parcial_1_Lab_I_2017.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "Pantalla.h"
#include "Pedir.h"
#include "Contrataciones.h"

#define DISPLAY_NUM 10
#define INTENTOS 3
#define OCUPADO 0 //flag
#define LIBRE -1 //flag

int main(void)
{
	Display displays[DISPLAY_NUM];
	Contatraciones contrataciones[DISPLAY_NUM];
	int menuPrincipal;
	int retornoModif;
	int idBAja;
	cargaFlagDisplay(displays, DISPLAY_NUM);
	cargaFlagDisplay(contrataciones, DISPLAY_NUM);

	do
	{
		imprimirMenuInicial();
		pedirInt(&menuPrincipal, "Ingrese opcion deseada", "Entre 1 y 11", 1, 11, INTENTOS);
		switch (menuPrincipal)
		{
			case 1:
				altaDisplay(displays, DISPLAY_NUM);
				break;
			case 2:
				modificarUnDisplay(displays, DISPLAY_NUM);
				break;
			case 3:
				imprimirDisplayCargado(displays, DISPLAY_NUM);
				pedirInt(&idBAja, "Ingrese BAja", "Id no valido", 1, DISPLAY_NUM, INTENTOS);
				bajaLogicaUnDisplay(displays, DISPLAY_NUM, idBAja);
							break;
			case 4:
				altaDisplay(contrataciones, DISPLAY_NUM);
							break;

			case 5:
				puts("LOS DIPLAY CARGADOS SON");

				retornoModif=modificarUnDisplay(displays, DISPLAY_NUM);
				break;

			case 6:

				break;
			case 7:

							break;
			case 8:

							break;



			case 9:
				ordenaDisplayPorDireccioYPrecio(displays, DISPLAY_NUM);
				imprimirDisplayCargado(displays, DISPLAY_NUM);
				break;

			case 10:

				imprimirMenuInformes();

				break;

			default:
				break;
		}





	/// el & termina mandando la direccion
	///de memoria de la posicion[libre] del array diplay
		//((pedirCharAUsuario(&seguir, 3, "Para seguir ingrese 'S'", "txtError");

	}while(menuPrincipal!=11);




	//buscado=buscarUnId(displays, DISPLAY_NUM, 1);
	//printf("El id 1 esta en la posicion  %d\n", buscado);

	//imprimirDisplay(displays, DISPLAY_NUM);

	//printf("\nEl RETORNO DE modificar DICE %d\n",retorno);


	//pedirInt(&baja, "Ingrese el Id a dar de baja", "mensajeError", 0, DISPLAY_NUM,INTENTOS);
	//retorno=bajaLogicaUnDisplay(displays, DISPLAY_NUM, baja);





	puts("!!!Que hay de nuevo viejo!!!");


	return EXIT_SUCCESS;
}
/*
 * typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;
typedef struct{
	int cuit; //0 LCD 1 LED
	int cantidadDias;
	int idContratacion;
	char nombreArchivo[128];
	int id;
	int flagEmptyC; //0 ocupada 1 vacia
}Contrataciones;
 */
