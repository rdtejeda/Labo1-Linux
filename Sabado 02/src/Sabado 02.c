/*
 ============================================================================
 Name        : Sabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int IngrearEntero(void); //prototipo de la funcio, le aviso que esxciste, para que sepa la estructura
int IngrearEntero_1(char mensaje[]); //prototipo f, doy un mensaje recibo un numero

int main(void) { //en el main uso la f
	// uso f int IngrearEntero(void)
	setbuf(stdout,NULL);
	int numeroInresado;
	numeroInresado=IngrearEntero();
	printf("El numero ingresado es: %d\n", numeroInresado);
	__fpurge(stdin);
	//uso int IngrearEntero_1(char mensaje[])
	int legajo;
	int edad;
	legajo = IngrearEntero_1("Ingrese legajo\n");
	edad= IngrearEntero_1("Ingesa tu edad\n");
	printf("El legajo ingresado es: %d\n", legajo);
	printf("La edad ingresada es: %d\n", edad);

	return EXIT_SUCCESS;
}
/* Una F puede Recibi y Devolver, no r y d, r y no d, no r y no d(no sirve para nada)
 * una f hace algo
 * vienen desde el main o de otra f
 * */
int IngrearEntero(void) //implementacion de la f, donde la programo esta es No r y d.
{ //comienza el scope de la f
	int numeroIgresado;	//var principal a returnar
		printf("ingrese numero"); //desarrollo de la funcion
		__fpurge(stdin);
		scanf("%d",&numeroIgresado);
	return numeroIgresado;//lo que devuelve la f
}
/*Si quiero que el pedido sea generico por ejemplo un legajo
 *paso los mensajes a mostra
 * */
int IngrearEntero_1(char mensaje[]) //implementacion de la f, donde la programo, sera r y d
{ //comienza el scope de la f
	int numeroIgresado;	//var principal a returnar
	printf(mensaje); //desarrollo de la funcion
	__fpurge(stdin);
	scanf("%d",&numeroIgresado);
	return numeroIgresado;//lo que devuelve la f
}
