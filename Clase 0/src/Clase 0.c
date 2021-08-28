/*
 ============================================================================
 Name        : Apoyo 0
 Author      : Tejeda Roberto
 Version     :
 Ingresar numeros enteros hasta que el usuario quiera
 calcular promedio y suma
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
	//pedir numeros hasta que el usuario quiera y promediar
int main(void) {

	//setbuf(stdout,NULL) //limpiar buffer solo para eclipse

	//Declaramos variables

	int numeroIngresado; // pedir numero entero
	int contadorDenumeros=0; //contador
	int contadorDepositivos=0;
	int acumuladorDenumeros=0;
	float promedio;
	char sigue='s';//caracter

	//Pedido al usuario hasta que quiera
	while (sigue == 's')
	{
		printf("\nIngrese el numero: \n");//pido el entero
		scanf("%d",&numeroIngresado);//cargo valor a la variable

		acumuladorDenumeros = acumuladorDenumeros +numeroIngresado;
		contadorDenumeros++;

		if(numeroIngresado>0)
		{
		contadorDepositivos++;
		}

		printf("\n¿desea conntinuar?s-n\n");
		//fpurge (stdin); //LIMPIAR BUFER ENTREDA fpurge(stdin)-linux fflush-win
		scanf("%s",&sigue);

	}
	//castear acumulador convertir en tipo numerico solo en esta linea
	promedio=(float)acumuladorDenumeros/contadorDenumeros; //calculo promedio
	//Mostramos el resultado
	printf("\nLa suma del numero es %d", acumuladorDenumeros);
	printf("\nEl promedio es %.2f", promedio);
	return EXIT_SUCCESS;
}

/*
#include <stdio.h>
#include <stdlib.h>
	//pedir numeros hasta que el usuario quiera y promediar
int main(void) {
	//Declaramos variables

	int numeroUno;
	float promedio;
	int suma = 0;
	float contador=0;
	char sigue;
	//Pedido al usuario hasta que quiera
	do{
		printf("\nIngrese el numero: \n");
		scanf("%d",&numeroUno);
		suma = suma +numeroUno;
		printf("\n¿desea conntinuar?s-n\n");
		scanf("%s",&sigue);
		contador++;
	}
	while (sigue == 's');
	promedio=suma/contador; //calculo promedio
	//Mostramos el resultado
	printf("\nLa suma del numero es %d", suma);
	printf("\nEl promedio es %f", promedio);
	return EXIT_SUCCESS;
}
*/
/*#include <stdio.h>
#include <stdlib.h>

#define CLIENTES 3


int main(void) {
	setbuf(stdout,NULL);

	//Declaramos variables
	int numeroUno;

	int suma = 0;
	int i;

	//Pedido al usuario
	for(i=0;i<CLIENTES;i++)
	{
		printf("\nIngrese el numero: \n");
		scanf("%d",&numeroUno);
		suma = suma +numeroUno;
	}

	if(CLIENTES == 3){
		printf("es igual a 3");
	}

	//Mostramos el resultado
	printf("\nLa suma del numero es %d", suma);

	return EXIT_SUCCESS;
}
*/
/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	printf("Esta es la primer clase");

	//declarar variables
	int numeroUno;
	int numeroDos;
	int suma;

	//pedir al usuario
	printf("\nIngrese el numero Uno : \n");
	scanf("%d",&numeroUno);
	printf("\nIngrese el numero Dos: \n");
	scanf("%d",&numeroDos);

	//calcular
	suma = numeroUno - numeroDos;

	//mostrar resultado
	printf("\nLa resta es %d", suma);

	return EXIT_SUCCESS;
}
*/
