/*
 ============================================================================
 Name        : C01-E002.c
 Author      : Tejeda Roberto
 Version     :
 Copyright   : Your copyright notice
 Description :
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int resultado;
	printf("ingrese el valor del numero 1: \n");
	__fpurge(stdin);
	scanf("%d",&numeroUno);
	printf("ingrese el valor del numero 2: \n");
	__fpurge(stdin);
	scanf("%d",&numeroDos);

	resultado=numeroUno-numeroDos;

	printf("El resultado de la resta edl numero 1 menos el numero 2 es:  %d\n", resultado);
	__fpurge(stdin);
	return EXIT_SUCCESS;
}
