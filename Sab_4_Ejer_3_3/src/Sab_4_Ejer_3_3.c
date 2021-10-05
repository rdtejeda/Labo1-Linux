/******************************************************************************
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
Listar los números positivos de manera creciente y negativos de manera decreciente. (Como máximo 5 for)
Ejemplo:
Listado 1 : 4, 5, 6, 10, 18, 29
Listado 2 : -1,-5,-9,-12
Listar solo los números primos.
El mayor de los primos
Los números que se repiten
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Biblioteca.h"
#define TAM 10

int main()
{
   int numeros[TAM];
   int verificacionCargaArray;
   int mayorPrimo;

   verificacionCargaArray = CargarArrayEnterosExcluyente(numeros, TAM, "Ingrese un número distinto de 0", "ERROR! Ingrese un número distinto de 0", 0);
   if (verificacionCargaArray == 1)  // se puede dejar como if (verificacionCargaArray)
   {
       if (ordenarArrayEnterosExcluyentes(numeros,TAM)==0)
       {
        printf("Error en Ordernar Array");
       }
       if (MostrarArrayEnteros(numeros, TAM) == 0) {
          printf("Error en Mostrar Array");
       }
       if (mostrarPrimos(numeros,TAM)==0)
       {
           printf("No se ingresaron numeros primos");
       }
       if (MayorPrimos(numeros, TAM, &mayorPrimo)==1)
       {
           printf("\nEl mayor de los primos es igual a : %d", mayorPrimo);
       }else
		   {
			   printf("\nNo se ingresaron numeros primos.");
		   }
   }else
	   {
			printf("Error en Cargar Array");
	   }
    return EXIT_SUCCESS;
}
