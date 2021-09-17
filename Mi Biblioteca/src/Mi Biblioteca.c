/*
 ============================================================================
 Name        : Mi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

//#define INTENTOS 3

int main(void)
{

	puts("¡Que hay de nuevo viejo!");

return EXIT_SUCCESS;
}
//__fpurge(stdin);
/*
		char cadena2[50]="BuEnAs PaRa ToDoS";
		char cadena1[50]= "Hi";//{'h','o','l','a','\0'};
		int bylen;
		int bymy;
		int may;
		bylen=strlen(cadena2);
		printf("puts dice %d\n", bylen);
		bymy=myStrLen(cadena2);
		printf("myStrLen dice %d\n", bymy);
		puts(cadena2);
		myPuts(cadena2);
		//myStrCpy(cadena2, cadena1);
		//myPuts(cadena2);
		may=myStrlenMayusculas(cadena2);
		printf("Hay %d mayuscula",may);
*/

/*
	int un;
	int dos;
	char cadena1[5];
	char cadena2[10]="Buenasasdf";

	puts(cadena1);
	puts(cadena2);
	puts(" ");

	//strcpy(cadena1, cadena2);

    puts(cadena1);
    puts (cadena2);
    puts(" ");
	//strcpy(cadena1, "Hi");

	strncpy(cadena1, cadena2, sizeof(cadena1)-1);
	cadena1[sizeof(cadena1)-1]= '\0';

	puts(cadena1);
	puts(cadena2);



	//printf("%s\n", cadena1);
	//un=strlen(cadena1);
	//printf("strlen%d\n",un);
    //dos=sizeof(un);
    //printf("sizeof%d", dos);
*/

/*

	int arraydesordenado [5]={8, 20, 134, 23, 50};

	imprimirArrayInt(arraydesordenado, 5);
	OrdenarArrayIntElegir(arraydesordenado, 5, 0);
	imprimirArrayInt(arraydesordenado, 5);
	cambiarPares(arraydesordenado, 5,418);
	cambiarImpares(arraydesordenado, 5, 1564879);
	imprimirArrayInt(arraydesordenado, 5);
*/

/*
	imprimirNumeroInt("la suma de los partes es ", sumaPares(arraydesordenado, 5));
	imprimirNumeroInt("La cantidad de pares es ", cantidadPares(arraydesordenado, 5));
	imprimirNumeroInt("La suma de los impares es ", sumaImpares(arraydesordenado, 5));
	imprimirNumeroInt("La cantidad de impares es ", cantidadImpares(arraydesordenado, 5));

	imprimirArrayInt(arraydesordenado, 5);
	inicializarArrayInt(arraydesordenado, 5, 34);
	imprimirArrayInt(arraydesordenado, 5);
	cargarArrayIntUnDato(arraydesordenado, 5);
	imprimirArrayInt(arraydesordenado, 5);
	cargarArrayInt(arraydesordenado, 5);
	imprimirArrayInt(arraydesordenado, 5);
*/

/*
		int s;
		int paridad;
		s=4;
		paridad=VerificarParidad(s);
		imprimirNumeroInt("dio", paridad);
		s=3;
		paridad=VerificarParidad(s);
		imprimirNumeroInt("dio", paridad);
*/

/*
	float numeroUno;
	float numeroDos;
	int resultadoentradafloat1;
	int resultadoentradafloat2;
	int resultadoDivision;
	float resultadoOperacion;
	int resulChar;
	char texto;
	int estado;

	estado=pedirNumeroInt(&resulChar, INTENTOS, "Ingrese numero", "ERROR - Ingrese un numero Entero valido");
	estado=factorial(&resultadoDivision, resulChar);
*/

/*
	int valor, result;
		printf("\nIngrese numero:");
		scanf("%d",&valor);
	if (valor<0)
	{
		printf("Error: Valor fuera de rango");
	}else
	{
		if(valor==1 || valor==0)
		{
		result = 1;
		printf("El factorial es %d",result);
		}else
		{
			result=valor*(valor-1);
			while(valor>2)
			{
				valor--;
				result=result*(valor-1);
			}
		printf("El factorial es %d",result);
		}
	}
*/

/*
	numeroUno=pedirNumeroFloat(&numeroUno, INTENTOS, "Ing. Numero uno", "Fuera de rango");
	printf("%.4f\n", &numeroUno);
	numeroDos=pedirNumeroFloat(&numeroDos, INTENTOS, "Ing. Numero dos", "Fuera de rango");
	printf("%.4f\n", &numeroDos);
	resultadoOperacion=numeroUno+numeroDos;
	//resultadoOperacion=sumaFloat(numeroDos, numeroDos);
	printf("%.4f\n",resultadoOperacion);


	int valor,result;
	printf("\nIngrese numero:");
	scanf("%d",&valor);
	if (valor<0)
	{
		printf("Error - Valor fuera de rango");
	}else
		{
		result=factorial(valor);
		printf("\nEl factorial de %d es %d",valor,result);
		}

	//int pedirCharAUsuario(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
	resulChar= pedirCharAUsuario(&texto, INTENTOS, "ingrese char", "no es char");
	printf("\nEl cahr ingresado es %c\n", texto);

	//printf("Ingrese el valor de la primera compra: \n");
	//scanf("%d",&numeroUno); //numeroUno = 8
	resultadoentradafloat1 = pedirNumeroFloat(&numeroUno, INTENTOS, "Ingrese numerador", "Numerador fuera de rango");
	//imprimirNumeroInt("El numerador es ", numeroUno);
	imprimirNumeroFloat("El numerador es \n", numeroUno);
	//printf("Cargar float devuelve %d\n", resultadoentradafloat1);
	//printf("Ingrese el valor de la segunda compra: \n");
	//scanf("%d",&numeroDos); //numeroDos = 5
	resultadoentradafloat2 = pedirNumeroFloat(&numeroDos, INTENTOS, "Ingrese Divisor", "Divisosr fuera de ragos");
	//imprimirNumeroInt("El divisor es ", numeroDos);
	//usando dividir
	imprimirNumeroFloat("El Divisor es \n", numeroDos);
	//printf("Cargar float devuelve%d\n", resultadoentradafloat2);
	estado = sumaFloat(&resultadoOperacion, numeroUno, numeroDos);
	printf("%.4f", resultadoOperacion);

	if(resultadoDivision==-1)
	{
		printf("Salio todo mal");
	}
	else
	{
		imprimirNumeroFloat("El resultado de la division es", resultadoOperacion);

		//printf("El resultado dela division es %f",resultadoOperacion);
	}
*/
