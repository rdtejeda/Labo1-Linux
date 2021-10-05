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
#include "Pantalla.h"
#include "Pedir.h"
#define DISPLAY_NUM 10
#define LCD 0
#define LED 1
#define INTENTOS 3
static int dameUnIdNuevo(void);



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
			if(pDisplay[i].id==idbuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
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
			if(pDisplay[i].flagEmpty==-1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


/*
 type; //0 LCD 1 LED
 price;
 id;
 name[128];
 address[128];
 flagEmpty; //0 ocupada 1 vacia
 */

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
			    			 estado=0;
			    		 }
			    	 }
			     }
		   }
	   }
	   return estado;
}

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
			pDiplay[j].flagEmpty=-1;
			//pDiplay[j].id=dameUnIdNuevo();
			//pDiplay[j].type=-1;
			//strncpy(pDiplay[j].name,"Sin datos",128);
			//strncpy(pDiplay[j].address,"Sin datos",128);
			estado=0;
	   }
   }
   return estado;
}
//================================================================================================================================================
/**
* \brief pide un texto al ususario
* \param puntero cahr, reintentos y textos de pedido y error , intentos
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirText(char* pResultado, int len, char* mensaje, char* mensajeError, int intentos)
{
	int retorno = -1;
	int i;
	char bufferCadenaAux[128];//esto
	for(i=0; i<=intentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
		{

			printf("\n%s\n", mensaje);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				strncpy(pResultado, bufferCadenaAux,len);
				if (esAlfaumerica(pResultado)==0)
				{
					retorno = 0;
				break;
				}
			}else
				{
					printf("%s", mensajeError);
				}
		}
	}
	return retorno;
}
 //==================================================================================================
 /**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
 int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
 {
 	int retorno = -1;
 	int bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("\n%s\n", mensaje);
 			__fpurge(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaInt(bufferCadenaAux)==0)
 					{
 					bufferInt = atoi(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}
 	return retorno;
 }
 //=====================================================================================================
 /**
  * \brief Verifica si la cadena ingresada es numerica
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \return Retorna 0 (EXITO) si se obtiene un numero  y -1 (ERROR) si no
 */
 int esNumericaInt(char* cadena)
 {
 	int i=0;
 	int retorno=-1;
 	if(cadena!=NULL && strlen(cadena)> 0)
 	{
 		retorno=0;
 		while(cadena[i]!='\0')
 			{
 				if(cadena[i]<'0'||cadena[i]> '9')
 					{
 					retorno=-1;
 					break;
 					}
 				i++;
 			}
 	}
 	return retorno;
 }
 //=====================================================================================================
 /**
  * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
  * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
  * \param len Define el tamaño de cadena
  * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
 int myGets(char pResultado[], int len)
 {
 	int retorno=-1;
 	int indexFinal;
 	//__fpurge(stdin);
 	if(fgets(pResultado,len,stdin)!=NULL)
 	{
 		__fpurge(stdin);
 		indexFinal = strlen(pResultado)-1;
 		if(pResultado[indexFinal] == '\n')
 			{
 			pResultado[indexFinal] = '\0';
 			}
 		retorno = 0;
 	}
 	return retorno;
 }
 //==================================================================================================
 /**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
 int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
 {
 	int retorno = -1;
 	float bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("\n%s\n", mensaje);
 			__fpurge(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaFloat(bufferCadenaAux)==0)
 					{
 					bufferInt = atof(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}
 	return retorno;
 }
 //=========================================================================================================
 /**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
 */
 int esNumericaFloat(char* cadena)
 {
 	int i=0;
 	int retorno = -1;
 	int contNeg=0;
 	int contPuntos=0;
 	if(cadena != NULL && strlen(cadena) > 0)
 	{
 		retorno=0;
 		while(cadena[i] != '\0')
 			{
 				if(cadena[i] < '0' || cadena[i] > '9')
 					{
 					if(cadena[i]=='-' || cadena[i]=='.')
 						{
 							if(cadena[i]=='-')
 							{
 								contNeg++;
 								if(i!=0)
 								{
 									retorno = -1;
 									break;
 								}
 							}
 							if(cadena[i]=='.')
 							{
 								contPuntos++;
 							}
 						}else
 						{
 							retorno = -1;
 							break;
 						}
 					}
 				i++;
 			}
 		if(contNeg>1 ||contPuntos>1)
 		{
 			retorno=-1;
 		}
 	}
 	return retorno;
 }
 //=====================================================================================================
