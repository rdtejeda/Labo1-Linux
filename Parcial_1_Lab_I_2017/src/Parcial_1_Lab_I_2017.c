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

#include "Pantalla.h"
#include "Pedir.h"


#define DISPLAY_NUM 10
#define INTENTOS 3
#define OCUPADO 0 //flag
#define LIBRE -1 //flag

int main(void)
{
	Display displays[DISPLAY_NUM];
	char seguir;
	int libre;
	//int buscado;
	//int baja;
	//int retorno;
	cargaFlagDisplay(displays, DISPLAY_NUM);
	do
	{
	if(buscarLugarLibreDisplay(displays, DISPLAY_NUM)>=0)
		{
			libre=buscarLugarLibreDisplay(displays, DISPLAY_NUM);
			printf("\nEl primer lugar libre es %d\n",libre);
			disp_loadDisplay(&displays[libre], DISPLAY_NUM);
		}else
		{
			puts("No hay espacio libre en el array");
		}

	/// el & termina mandando la direccion
	///de memoria de la posicion[libre] del array diplay
	pedirCharAUsuario(&seguir, 3, "Para seguir ingrese 'S'", "txtError");

	}while(seguir=='S');

	puts("LOS DIPLAY CARGADOS SON");
	imprimirDisplayCargado(displays, DISPLAY_NUM);


	//buscado=buscarUnId(displays, DISPLAY_NUM, 1);
	//printf("El id 1 esta en la posicion  %d\n", buscado);

	//imprimirDisplay(displays, DISPLAY_NUM);
	//modificarUnDisplay(displays, DISPLAY_NUM);

	//pedirInt(&baja, "Ingrese el Id a dar de baja", "mensajeError", 0, DISPLAY_NUM,INTENTOS);
	//retorno=bajaLogicaUnDisplay(displays, DISPLAY_NUM, baja);
	//printf("\nEl RETORNO DE LA BAJA LOGICA DICE %d\n",retorno);
	ordenaDisplayPorDireccioYPrecio(displays, DISPLAY_NUM);

	imprimirDisplayCargado(displays, DISPLAY_NUM);

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
 */



	// ALTA
	// 1) busco lugar libre : HACER leeestooo
	// 2) llamo a funcion de load : LISTOOO

	// MODIFICAR
	// 1) pedirle auser que ingrese un ID
	// 2) buscar por id : HACER
	// 3) llamar a funcionar que modifica: HACER
