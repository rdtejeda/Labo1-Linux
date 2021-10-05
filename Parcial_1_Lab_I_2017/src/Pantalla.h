/*
 * Pantalla.h
 *
 *  Created on: 30 sep. 2021
 *      Author: usuario
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_


typedef struct{
	int type; //0 LCD 1 LED
	float price;
	int id;
	char name[128];
	char address[128];
	int flagEmpty; //0 ocupada 1 vacia
}Display;
int buscarUnId(Display *pDisplay, int len, int idbuscado);
int imprimirDisplayCargado(Display pDisplay[], int len);
int buscarLugarLibre(Display *pDisplay, int len);
int cargaFlagDisplays(Display *pDiplay, int len);
int disp_loadDisplay(Display *pDiplay, int len);
int imprimirDisplay(Display pDisplay[], int len);
int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int esNumericaInt(char* cadena);
int myGets(char pResultado[], int len);
int esNumericaFloat(char* cadena);
int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
int pedirText(char* pResultado, int len, char* mensaje, char* mensajeError, int intentos);

#endif /* PANTALLA_H_ */
