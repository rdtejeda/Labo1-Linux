/*
 * Contrataciones.h
 *
 *  Created on: 12 oct. 2021
 *      Author: usuario
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_

typedef struct{
	int cuit; //0 LCD 1 LED
	int cantidadDias;
	int idContratacion;
	char nombreArchivo[128];
	int id;
	int flagEmptyC; //0 ocupada 1 vacia
}Contrataciones;

int altaContrataciones(Display pContrato[],int len);
int buscarLugarLibreContrato(Contrataciones *pContrato, int len);

#endif /* CONTRATACIONES_H_ */
