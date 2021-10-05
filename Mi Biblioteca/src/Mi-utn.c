/*
 *  Mi-utn.c
 *
 *  Created on: 11 sep. 2021
 *  Author: Tejeda Roberto
 */
//Como Documentar cada funcióm
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Mi-utn.h"
#include "Operar.h"
#include "Matriz.h"
#include "Pedir.h"
#include "Txt.h"
//=========================================================================
/**
* \brief imprime un entero
* \param recibe un char y un int
* \return
*/
void imprimirNumeroInt(char txt[],int x)
{
	printf("\n%s %d\n",txt,x);
	__fpurge(stdin);
}
//==========================================================================
/**
* \brief imprime un numero float con 4 decimales
* \param recibe un char y un int
* \return
*/
void imprimirNumeroFloat(char txt[],float x)
{
	printf("\n%s %.4f\n",txt,x);
	__fpurge(stdin);
}

//========================================================================
/* Funcion usada para verificar el ingreso de caracteres.Chequea para que
 solo sean admitidas las letras S o N.
 Se ingresa void y devuelve un entero sin signo
 0 si se ingreso la N
 1 si se ingreso la S
*/
/*
unsigned int verificaSyN(void)
{
	char letra;
	printf("\nIngrese opcion...S/N?");
	letra=toupper(getche());
	while(!((letra=='S')||(letra=='N')))
		{
		printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
		letra=toupper(getche());
		}
	return (letra=='S');
}*/
//==================================================================
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no

int pedirNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
				{
				*pResultado = bufferInt;
				retorno = 0;
				break;
				}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
*/
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
			{
			*pResultado = atoi(buffer);
			retorno = 0;
			}
	}
	return retorno;
}
*/
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*

static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
			{
			cadena[strlen(cadena)-1] = '\0';
			}
		return 0;
	}
	return -1;
}
*/


/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es

static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if(cadena[i] < '0' || cadena[i] > '9' )
					{
					retorno = 0;
					break;
					}
				i++;
			}
	}
	return retorno;
}
*/

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no

int pedirNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			*pResultado = bufferFloat;
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
*/

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && (esNumericaFloat(buffer))==0)
			{
			*pResultado = atof(buffer);
			retorno = 0;
			}
	}
	return retorno;
}
*/

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*

static int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
			{
			cadena[strlen(cadena)-1] = '\0';
			}
		return 0;
	}
	return -1;
}
*/

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es

static int esNumericaFloat(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if(cadena[i] < 48 || cadena[i] > 57)
					{
					if(cadena[i]==46)
						{

						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
	}
	return retorno;
}
*/
