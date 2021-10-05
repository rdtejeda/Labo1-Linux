/*
 * Input.c
 *
 *  Created on: 27 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Input.h"
#include "Empleado.h"

float IngresarFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}
void getString(char cadena[],char mensaje[],int tam)
{
    char auxiliar[tam];
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", auxiliar);
    strcpy(cadena, auxiliar);
}

int IngresarEntero(char mensaje[])
{
    int numero;

    printf("%s",mensaje);
	scanf("%d",&numero );

	return numero;
}

