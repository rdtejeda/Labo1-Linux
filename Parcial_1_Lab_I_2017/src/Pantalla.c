/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: usuario
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

static int dameUnIdNuevo(void);

//=============================================================================
/**
* \brief busca por por ID
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna lugar libre
*/
int buscarUnId(Display *pDisplay, int len, int idbuscado)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i = 0; i < len; ++i)
		{
			if(pDisplay[i].id==idbuscado && pDisplay[i].flagEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
//=============================================================================
/**
* \brief busca un index flag emtyy
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar libre
*/
int buscarLugarLibre(Display *pDisplay, int len)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i = 0; i < len; ++i)
		{
			if(pDisplay[i].flagEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
//=============================================================================
/*
 type; //0 LCD 1 LED
 price;
 id;
 name[128];
 address[128];
 flagEmpty; //0 ocupada 1 vacia
 */
//=============================================================================
/**
* \brief Imprime  todo el Display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplay(Display pDisplay[], int len)
{
	int estado=-1;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
			pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
		}
	}

	estado=0;
	return estado;
}
//=============================================================================
/**
* \brief Imprime  el Display cargado con datos
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplayCargado(Display pDisplay[], int len)
{
	int estado=-1;
	int contadordeCargados=0;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pDisplay[i].flagEmpty==0)
			{
				printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
				pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
				contadordeCargados++;
			}
			if(contadordeCargados==0)
			{
				puts("NO HAY DIPLAYS CARGADOS");
			}
		}
	}
	estado=0;
	return estado;
}
//=============================================================================
/**
* \brief Dar de alta un display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int disp_loadDisplay(Display *pDiplay, int len)
{
	int estado=-1;
	int bufferType;
	char bufferAddres[128];
	char bufferName[128];
	float bufferPrice;
	   if(pDiplay!=NULL && len>0)
	   {
		   if(pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS)==0)
		   {
			     if(pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS)==0)
			     {
			    	 if(pedirText(bufferAddres, sizeof(pDiplay->address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferName, sizeof(pDiplay->name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS)==0)
			    		 {

			    			 pDiplay->type=bufferType;
			    			 pDiplay->price=bufferPrice;
			    			 strncpy(pDiplay->address, bufferAddres,sizeof(pDiplay->address));
			    			 strncpy(pDiplay->name, bufferName,sizeof(pDiplay->name));
			    			 pDiplay->id=dameUnIdNuevo();
			    			 pDiplay->flagEmpty=0;
			    			 estado=OCUPADO;
			    		 }
			    	 }
			     }
		   }
	   }
	   return estado;
}
//=============================================================================
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * \param void
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
static int dameUnIdNuevo(void)
{
	static int contador=0; //varable Global y solo de esta funcio
	contador++;
	return contador;
}
//==============================================================================
/**
  * \brief inicializa la var flag en -1
  * \param un estructura pDisplay Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param el tamañoo
  * \return Retorna 0 si todo bien  y -1 si no
  */
int cargaFlagDisplays(Display *pDiplay, int len)
{
   int estado=-1;
   if (pDiplay!=NULL && len>0)
   {

	  for (int j = 0;  j<len; j++)
	   {
			pDiplay[j].flagEmpty=LIBRE;
			//pDiplay[j].id=dameUnIdNuevo();
			//pDiplay[j].type=-1;
			//strncpy(pDiplay[j].name,"Sin datos",128);
			//strncpy(pDiplay[j].address,"Sin datos",128);
			estado=0;
	   }
   }
   return estado;
}
 //=====================================================================================================
 /*
 int buscarLibre (Display *unDisplay, int len)
 {
	 int retorno=-1;
	 if(unDisplay!=NULL && len>0)
	 {
		 for (int i = 0;  i< len; ++i)
		 {
			if(unDisplay[i].flagEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		 }
	 }
	 return retorno;
 }

 int modificarDisplay(Display *unDisplay, int len)
 {
	 int retorno=-1;
	 int idamodificar;
	 int posicion;

	 imprimirDisplayCargado(unDisplay, len); //IMPRIMIR LISTA
	 pedirInt(&idamodificar, "Ingrese Id a modificar", "Error", 0, len, INTENTOS);
	 posicion=buscarUnId(unDisplay, len, idamodificar);

	 if (posicion>=0)
	 {
		 Display auxiliar={1,100,99,"Name","Siempre viva",0}; //MODIFICACION

		 unDisplay[posicion]=auxiliar;

		 unDisplay[posicion].flagEmpty=LIBRE; ///baja logica
		 	 	 	 	 	 	 	 	 	  // estados de baja para llevar un control
		 retorno=0;
	 }
	 return retorno;
 }
 // MOSTRA LISTADO a modificar
 // Seleccionar id a modificar
 // Buscar el id
 // Modificar la pantalla
 */















