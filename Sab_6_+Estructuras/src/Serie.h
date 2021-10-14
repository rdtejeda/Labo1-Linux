/*
 * Serie.h
 *
 *  Created on: 2 oct. 2021
 *      Author: usuario
 */

#ifndef SERIE_H_
#define SERIE_H_

typedef	struct
		{
		int idGenero; //variable de ineraccion de datos
		char descripcion[50];
		}eGenero;

typedef	struct
		{
		int idSerie;
		char descripcion[50];
		int cantidadTemp;
		int idGenero; //variable de ineraccion de datos
		//eGenero genero; REDUNDANCIA
		}eSerie;

void MostrarSeries(eSerie listaSeries[], int len);
void MostrarSeriesGenero(eSerie listaSeries[], int lenSerie,eGenero listaGeneros[], int lenGenero);
void MostrarListadoGenero(eSerie listaSeries[], int lenSerie, eGenero listaGeneros[], int lenGenero);



#endif /* SERIE_H_ */
