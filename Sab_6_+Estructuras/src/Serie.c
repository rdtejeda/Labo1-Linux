/*
 * Serie.c
 *
 *  Created on: 2 oct. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "Serie.h"

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
