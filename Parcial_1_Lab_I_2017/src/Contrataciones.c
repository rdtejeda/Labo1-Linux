/*
 * Contrataciones.c
 *
 *  Created on: 12 oct. 2021
 *      Author: usuario
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



/**
* \brief da de alta un Contrato en el array de Contrato
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
//=============================================================================
int altaContrataciones(Contrataciones pContrato[],int len)
{
	int retorno=-1;
	int libre;
	if(pContrato!=NULL && len>0)
	{
		libre=buscarLugarLibreContrato(pContrato, DISPLAY_NUM);
		if(buscarLugarLibreContrato(pContrato, DISPLAY_NUM)>=0)
			{
				printf("\nEl primer lugar libre es %d\n",libre);
				if(disp_loadContrato(&pContrato[libre], DISPLAY_NUM)==0)
				{
					puts("Se ha completado la carga");
				}else
				{
					puts("No se ha completado la carga");
				}
			}else
				{
					puts("No hay espacio libre en el array");
				}
	}
	retorno=0;
return retorno;
}
//=============================================================================
/**
* \brief busca el primer index del array con flag emty
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreContrato(Contrataciones *pContrato, int len)
{
	int retorno=-1;
	if(pContrato!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pContrato[i].flagEmptyC==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/**
* \brief Dar de alta un display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
//============================================
int disp_loadContrato(Contrataciones *pContrato, int len)
{
	int estado=-1;
	int bufferType;
	char bufferAddres[128];
	char bufferName[128];
	float bufferPrice;
	   if(pContrato!=NULL && len>0)
	   {
		   if(pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS)==0)
		   {
			     if(pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS)==0)
			     {
			    	 if(pedirText(bufferAddres, sizeof(pContrato->address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferName, sizeof(pContrato->name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS)==0)
			    		 {

			    			 pContrato->type=bufferType;
			    			 pContrato->price=bufferPrice;
			    			 strncpy(pContrato->address, bufferAddres,sizeof(pContrato->address));
			    			 strncpy(pContrato->name, bufferName,sizeof(pContrato->name));
			    			 pContrato->id=dameUnIdNuevo();
			    			 pContrato->flagEmpty=OCUPADO;
			    			 estado=OCUPADO;
			    		 }
			    	 }
			     }
		   }
	   }
	   return estado;
}
//==================================================
