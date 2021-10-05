/*
 ============================================================================
 Name        : Sab_6_+Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Serie.h"


void MostrarSeries(eSerie listaSeries[], int len);
void MostrarSeriesGenero(eSerie listaSeries[], int lenSerie,eGenero listaGeneros[], int lenGenero);
void MostrarListadoGenero(eSerie listaSeries[], int lenSerie, eGenero listaGeneros[], int lenGenero);

int main(void)
{
	eSerie series[5]=
	{
			{100,"la cas de papel",23,1},
			{101,"el juego",8,2},
			{102,"wanda",4,3},
			{103,"evan",1,3},
			{104,"hamnn",3,2}
	};
	eGenero generos[3]=
	{
			{1,"Accion"},
			{2,"terror"},
			{3,"Ficcion"}
	};
	MostrarSeries(series, 5);
	printf("\n\n");
	MostrarSeriesGenero(series, 5, generos, 3);
	printf("\n\n");
	MostrarListadoGenero(series, 5, generos, 3);

	puts("!!!Que hay de nuevo viejo!!!");
	return EXIT_SUCCESS;
}

void MostrarSeries(eSerie listaSeries[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d %-30s %d %4d\n",listaSeries[i].idSerie,listaSeries[i].descripcion,
									listaSeries[i].cantidadTemp,listaSeries[i].idGenero);
	}
}
void MostrarSeriesGenero(eSerie listaSeries[], int lenSerie,eGenero listaGeneros[], int lenGenero)
{
	for (int i = 0; i < lenSerie; i++)
	{
		for (int j = 0; j < lenGenero; ++j)
		{
			if(listaSeries[i].idGenero==listaGeneros[j].idGenero)
			{
				printf("%d %-30s %d %4s\n",listaSeries[i].idSerie,listaSeries[i].descripcion,
										listaSeries[i].cantidadTemp,listaGeneros[j].descripcion);
			}
		}
	}
}

void MostrarListadoGenero(eSerie listaSeries[], int lenSerie, eGenero listaGeneros[], int lenGenero)
{
	for (int i = 0; i< lenGenero ; ++i)
	{
		printf("%s: \n",listaGeneros[i].descripcion);
		for (int j = 0; j < lenSerie; ++j)
		{
			if (listaSeries[j].idGenero==listaGeneros[i].idGenero)
			{
				printf("%d %-30s %d\n",listaSeries[j].idSerie,listaSeries[j].descripcion,
										listaSeries[j].cantidadTemp);
			}
		}
	}
}









