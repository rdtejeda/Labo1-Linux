/*
 * Bibioteca.h
 *
 *  Created on: 18 sep. 2021
 *      Author: usuario
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente);
int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente);
int MostrarArrayEnteros(int lista[], int tam);
int clasificarNumero(int numeroAClasficiar);
int ordenarArrayEnterosExcluyentes(int lista[], int tam);
int mostrarPrimos(int lista[], int tam);
void mostrarEntero(int entero);
int clasificarPrimos(int numero);
int MayorPrimos(int lista[], int tam, int* refMayorPrimo);

#endif /* BIBLIOTECA_H_ */
