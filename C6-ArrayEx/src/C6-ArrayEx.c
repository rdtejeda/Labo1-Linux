/*
 ============================================================================
 Name        : C6-ArrayEx.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 Ejercicio 1:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Mi-utn.h"

int main(void)
{
	float tempDiaMes[31];
	int menu;
	inicializarArrayFloat(tempDiaMes, 31, 0.0);
		do
		{
			printf("\nIngreso 1 para imprimir array\n");
			printf("\nIngreso 2 para cargar Array\n");
			printf("\nIngreso 3 para salir\n");
			scanf("%d",&menu);

			switch (menu) {
				case 1:
					imprimirArrayFloat(tempDiaMes, 31);
					break;
				case 2:
					cargarArrayFloat(tempDiaMes, 31);
					break;
				default:

					break;
			}
		}while(menu != 3);
	return EXIT_SUCCESS;
}
