/*
 ============================================================================
 Name        : Clase1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h> //bibliotecas del lenguja
#include <stdlib.h>
#include <stdio_ext.h>

#define EDAD_ADULTO 18 //es una macro que busca y reempaza la palabar por eso

//se define una funcion con void
int main(void) {
	//windows mo uses buffer
	// setbuf(stdout,NULL);
	//Linux no hace falta

	//TIPO NOMBRE; como declaro la variable
	//Tipo variable estatico o fijo y no la puedo cambiar

	int a=0; //numeros enteros
	/* otros tipos de variables
	double
	long
	*/
	// para ingresar un numero
	printf("Ingresa tu edad :\n");//primero pregunto y genero una direccion
	__fpurge(stdin);//limpiar el bufer antes de leer siempre antes scanf
	scanf("%d",&a);//despues asigno pasando la direccion con el & y avisando %d

	if (a>=EDAD_ADULTO)
	{
		printf("Es mayor.\n ");
	}

	printf("Ingresaste la edad: %d\n",a); //imprimo la variable
	__fpurge(stdin);

	// bucles son equivalentes con cualquiera
	//while (no se numeros de iteraciones)
	//for (secuantas veces itero)
	//do while (primero itero i despues pregunto)

	char respuesta;
	do
	{
		printf("Ingresa tu edad :\n");//primero pregunto y genero una direccion
		__fpurge(stdin);//limpiar el bufer antes de leer siempre antes scanf
		scanf("%d",&a);//despues asigno pasando la direccion con el & y avisando %d

		printf("Continuar? s-n");
		__fpurge(stdin);
		scanf("%c",&respuesta);
	}
	while(respuesta == 's');

	return EXIT_SUCCESS;
}
