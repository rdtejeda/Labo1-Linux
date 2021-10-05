/*
 * Pedir.c
 *
 *  Created on: 5 oct. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "Pantalla.h"

/**
* \brief Verifica si la cadena ingresada es alfanumerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
int esAlfaumerica(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<48||cadena[i]>57)&&(cadena[i]< 65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122))//0-9 48-57 A-Z 65-90 a-z 97-122
					{
						if (cadena[i]==32)
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
//==============================================================================
/**
  * \brief te da un entero consecutivo y lo recuerda
  * \param VOID
  * \return Retorna un entero desde 1 y lo recuerda
  */
//=====================================================================================================
/**
* \brief pide un char al ususario
* \param puntero cahr, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirCharAUsuario(char* pChar, int reintentos, char* txt, char* txtError)
{

	int retorno=-1;
	int i;
	char bufferCadenaAux[32];
	if(pChar != NULL && reintentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("\n%s\n", txt);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
				//if(es loque necesite)
				strncpy(pChar, bufferCadenaAux,1);
					retorno = 0;
					break;
				}else
				{
						printf("%s", txtError);

				}
		}
	}
	return retorno;
}


