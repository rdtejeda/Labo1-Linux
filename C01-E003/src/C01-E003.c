/*
 ============================================================================
 Name        : C01-E003.c
 Author      : Tejeda
 Version     :
 Copyright   : Your copyright notice
 Description :Agregar al programa adjunto la funcionalidad resaltada con un (*)

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	int a;
	int b;
	int resultado;
	printf("\nIngrese numero1: \n");
	__fpurge(stdin);
	scanf("%d",&a);
	printf("\nIngrese numero2: \n");
	__fpurge(stdin);
	scanf("%d",&b);
	resultado=a-b;
	printf("\nEl resultado es: %d \n",resultado);
	__fpurge(stdin);
		if(resultado>0)
		{
	        printf("\nResultado positivo \n");
	        __fpurge(stdin);
		}
		if(resultado<0)
		 	 {
	        printf("\nResultado negativo \n");
	        __fpurge(stdin);
		 	 }
	return EXIT_SUCCESS;
}
