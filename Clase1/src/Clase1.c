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

#define EDAD_ADULTO 18 //es una macro que busca y reempaza la palabar por eso

//se define una funcion con void
int main(void) {
	//windows mo uses buffer
	// setbuf(stdout,NULL);
	//Linux no hace falta

	//TIPO NOMBRE; como declaro la variable
	//Tipo variable estatico o fijo y no la puedo cambiar

	int a=0; //numeros enteros
	float f; //numero decimales
	char c; //1 caracter, 1 letra, 1 simbolo
	/* otros tipos de variables
	double
	long
	*/
	// para ingresar un numero
	printf("Ingresa tu edad :");//primero pregunto y genero una direccion
	fflush(stdin); //limpiar el bufer antes de leer siempre antes scanf
	scanf("%d",&a);//despues asigno pasando la direccion con el & y avisando %d

	if (a>=EDAD_ADULTO)
	{
		printf("Es mayor. ");
	}

	printf("Ingresaste la edad: %d ",a); //imprimo la variable

	// bucles son equivalentes con cualquiera
	//while (no se numeros de iteraciones)
	//for (secuantas veces itero)
	//do while (primero itero i despues pregunto)

	char respuesta;
	do
	{
		printf("Continuar? s-n");
		scanf("%c",&respuesta);
	}
	while(respuesta == 's');

	return EXIT_SUCCESS;
}