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

#include "Operar.h"
#include "Matriz.h"
#include "Pedir.h"
#include "Txt.h"

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







