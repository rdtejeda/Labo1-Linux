/*
 ============================================================================
 Name        : C02-E001.c
 Author      : Tejeda
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio:
 -Realizar un programa que solicite cinco números e imprima por pantalla el
*    promedio, el máximo y el mínimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un número tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los máximos y mínimos
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    int maximo;
    int minimo;
    int acumulador;
    int auxiliarInt;
    int i;
    // Solicito el primer número el cual por ser el primero sera tanto el
    // maximo como el minimo y el primer numero a ser acumulado
    printf("Ingrese un numero: ");
    scanf("%d",&auxiliarInt);
    maximo = auxiliarInt;
    minimo = auxiliarInt;
    acumulador = auxiliarInt;
    // Solicito el resto de los numeros
    for(i=0;i<4;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&auxiliarInt);
        acumulador = acumulador + auxiliarInt;

        if(auxiliarInt > maximo)
        {
            maximo = auxiliarInt;
        }

        if(auxiliarInt < minimo)
        {
            minimo = auxiliarInt;
        }
    }
    printf("El maximo es: %d\n",maximo);
    printf("El minimo es: %d\n",minimo);
    printf("El promedio es: %f\n", ((float)acumulador) / 5);
    return 0;
}
