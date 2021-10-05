/*
 * Matriz.h
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

int esAlfaumerica(char* cadena);
int esAlfaumerica(char* cadena);
int eseMail(char* cadena);

int OrdenarArrayIntElegir(int pArray[], int ext, int mayorUnomenorCero);
int OrdenarArrayInt(int pArray[], int ext);
int cargarArrayIntUnDato(int pArray[],int ext);
int imprimirArrayInt(int pArray[],int ext);
void inicializarArrayInt(int pArray[],int ext,int valorInicial);
void inicializarArrayFloat(float pArray[],int ext,float valorInicial);
void imprimirArrayFloat(float pArray[],int ext);
int cargarArrayFloatUnDato(float pArray[],int ext);
void cargarArrayInt(int pArray[],int ext);
int sumaPares(int pArray[],int ext);
int sumaImpares(int pArray[],int ext);
int cantidadPares(int pArray[],int ext);
int cantidadImpares(int pArray[],int ext);
int cambiarPares(int pArray[],int ext, int valor);
int cambiarImpares(int pArray[],int ext, int valor);

//int esNumericaFloat1(char* cadena);
//int esNumericaInt(char* cadena);

#endif /* MATRIZ_H_ */
