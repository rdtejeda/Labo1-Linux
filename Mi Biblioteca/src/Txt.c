/*
 * Txt.c
 *
 *  Created on: 17 sep. 2021
 *      Author: usuario
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


/**
* \brief cuenta caratres en mayuscula en una  cadena
* \param cadena
* \return numer de caracteres en mayuscula
*/
int myStrlenMayusculas(char* cadena)
{
	int contMayus=0;
	int index=0;
	while(cadena[index]!='\0')
	{
		if(cadena[index]>='A' && cadena[index]<='Z')
		{
			contMayus++;
		}
		index++;
	}
	return contMayus;
}
/**
* \brief cuenta caratres en una  cadena
* \param cadena
* \return numer de caracteres
*/
int myStrLen(char* cadena)//o char cadena[]
{
	int index=0;
	while(cadena[index]!='\0')
		{
			index++;
		}
	return index;
}
/**
* \brief imprimen una  cadena
* \param cadena
* \return
*/
void myPuts(char* cadena)
{
int index=0;
	while(cadena[index]!='\0')
		{
			printf("%C",cadena[index]);
			index++;
		}
	printf("\n");
}
/**
* \brief copia carateres de una cadena a otra
* \param cadena2 (destino) cadena1 (destino)
* \return
*/
void myStrCpy(char* cadena2, char*cadena1)
{
	int index=0;
		while(cadena1[index]!='\0')
			{
				cadena2[index]=cadena1[index];
				index++;
			}
		cadena2[index]=0;
}
