/*
 * Pedir.h
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */

#ifndef PEDIR_H_
#define PEDIR_H_

int myGets(char pResultado[], int len);
int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int pedirText(char* pResultado, int len, char* mensaje, char* mensajeError, int intentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int esNumericaInt(char* cadena);
int esNumericaFloat(char* cadena);
int pedirCharAUsuario(char* pResultado, int reintentos, char* variableTexto, char* textoError);

#endif /* PEDIR_H_ */
