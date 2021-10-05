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

int main(void)
{
	Display displays[DISPLAY_NUM];
	char seguir;
	int libre;
	int buscado;
	cargaFlagDisplays(displays, DISPLAY_NUM);
	do
	{
	libre=buscarLugarLibre(displays, DISPLAY_NUM);
	printf("\nEl primer lugar libre es %d\n",libre);
	disp_loadDisplay(&displays[libre], DISPLAY_NUM);
	pedirCharAUsuario(&seguir, 3, "Para seguir ingrese 'S'", "txtError");

	}while(seguir=='S');
	imprimirDisplayCargado(displays, DISPLAY_NUM);

	buscado=buscarUnId(displays, DISPLAY_NUM, 2);
	printf("El id buscado esta en la posicion  %d\n", buscado);

	//imprimirDisplay(displays, DISPLAY_NUM);
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
