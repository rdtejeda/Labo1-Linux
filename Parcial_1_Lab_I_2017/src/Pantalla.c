/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#include "Pantalla.h"
#include "Pedir.h"
#include "Contrataciones.h"


#define DISPLAY_NUM 10
#define INTENTOS 3
#define OCUPADO 0 //flag busy
#define LIBRE -1 //flag emty

static int dameUnIdNuevo(void);

//=============================================================================
/* La estructura Display
 type; //0 LCD 1 LED
 price;
 id;
 name[128];
 address[128];
 flagEmpty; //0 ocupada 1 vacia
 */
//==============================================================================


/**
* \brief Imprime menu de opciones
* \param
* \return
*/
void imprimirMenu()
{
	puts("1- TIPO DE DIPLAY");
	puts("2- PRECIO DE LA PUBLICACION");
	puts("3- NOMBRE DE LA PUBLICACION");
	puts("4- DIRECCION DE LA PANTALLA");
	puts("5- SALIR");
}

/**
* \brief da de alta un display en el array de Display
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
//=============================================================================
int altaDisplay(Display pDisplay[],int len)
{
	int retorno=-1;
	int libre;
	if(pDisplay!=NULL && len>0)
	{
		libre=buscarLugarLibreDisplay(pDisplay, DISPLAY_NUM);
		if(buscarLugarLibreDisplay(pDisplay, DISPLAY_NUM)>=0)
			{
				printf("\nEl primer lugar libre es %d\n",libre);
				if(disp_loadDisplay(&pDisplay[libre], DISPLAY_NUM)==0)
				{
					puts("Se ha completado la carga");
				}else
				{
					puts("No se ha completado la carga");
				}
			}else
				{
					puts("No hay espacio libre en el array");
				}
	}
	retorno=0;
return retorno;
}
//=============================================================================
/**
* \brief Ordena el array de Display por orden alfabetico ascendente de nombre y precio
* \param recibe un array de estructura, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
//=============================================================================
int ordenaDisplayPorDireccioYPrecio(Display pDisplay[], int len)
{
	int banderaSwapp=-1;
	Display auxiliar;
	int limite=len;
	int estadostrcmp;
	if(pDisplay!=NULL && len>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				estadostrcmp=strcmp(pDisplay[i].name, pDisplay[i+1].name);
				if(estadostrcmp>0)
				{
					banderaSwapp=1;
					auxiliar=pDisplay[i];
					pDisplay[i]=pDisplay[i+1];
					pDisplay[i+1]=auxiliar;
				}
				if (estadostrcmp==0)
				{
					if(pDisplay[i].price>pDisplay[i+1].price)
						{
							banderaSwapp=1;
							auxiliar=pDisplay[i];
							pDisplay[i]=pDisplay[i+1];
							pDisplay[i+1]=auxiliar;
						}
				}
			}
		}while(banderaSwapp==1);
	}
	return banderaSwapp;
}
//=============================================================================
/**
* \brief Modifica un ID emty
* \param recibe un estructura por puntero, el largo
* \return Retorna -1 todo mal 0 todo bien
*/
 int modificarUnDisplay(Display *pDisplay, int len)
 {
	 int retorno=-1;
	 int idamodificar;
	 int posicion;
	 int bufferType;
	 char bufferAddres[128];
	 char bufferName[128];
	 float bufferPrice;
	 int opcion;
	 Display auxiliar; //= {1,100,99,"Name","Siempre 11 viva",0}; //MODIFICACION Harcodeada
	 if(pDisplay!=NULL && len>0)
		 {
		 imprimirDisplayCargado(pDisplay, len);  // IMPRIMIR LISTA EMTY - MOSTRA LISTADO de posibles Display a modificar
		 pedirInt(&idamodificar, "Ingrese Id a modificar", "Error", 0, len, INTENTOS);// Seleccionar id a modificar
		 posicion=buscarUnId(pDisplay, len, idamodificar); // Buscar la posicion en el array del id selecionado
		 if (posicion>=0)// Modificar la pantalla
			 {
			 do
				 {
					 puts("INGRESE OPCION A MOFIFICAR");
					 imprimirMenu();
					 pedirInt(&opcion, "INGRESE OPCION A MOFIFICAR", "Ingrese entre 1 y 5", 1,5,INTENTOS);
					 switch (opcion)
					 {
						case 1:
							pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS);
							pDisplay->type=bufferType;
							break;
						case 2:
							pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS);
							pDisplay->price=bufferPrice;
							break;
						case 3:
							pedirText(bufferName, sizeof(auxiliar.name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS);
							strncpy(pDisplay->name, bufferName, sizeof(pDisplay->name));
							break;
						case 4:
							pedirText(bufferAddres, sizeof(auxiliar.address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS);
							strncpy(pDisplay->address, bufferAddres, sizeof(pDisplay->address));
							break;
						default:
							break;
					 }
				 }while(opcion<5);
			 }else
				 puts("Id no hallado");
		 }
	 return retorno;
 }
 //=========================================================================
 /**
 * \brief Da de baja en forma logica un ID = Emty
 * \param recibe un estructura por puntero, el largo y el id a dar de baja
 * \return Retorna -1 salio mal 0 todo bien
 */
 int bajaLogicaUnDisplay(Display *pDisplay, int len, int idabajar)
 {
	 int retorno=-1;
	 int posicion;
	 posicion=buscarUnId(pDisplay, len, idabajar);
	 if(pDisplay!=NULL && posicion>=0 && len>0)
	 {
		 pDisplay[posicion].flagEmpty=LIBRE; // podemos hacer un estados de baja para llevar un control
		 retorno=0;
	 }
	 return retorno;
 }
//==============================================================================
/**
* \brief busca la posiscion de un ID
* \param recibe un estructura por puntero, el largo y el idbuscado
* \return Retorna posicion en el array del id buscado o -1 si no lo alla
*/
int buscarUnId(Display *pDisplay, int len, int idbuscado)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pDisplay[i].id==idbuscado && pDisplay[i].flagEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
//=============================================================================
/**
* \brief busca el primer index del array con flag emty
* \param recibe un estructura por puntero y el largo
* \return Retorna lugar el primer lugar libre de la lista o -1 si no encuentra ninguno libre
*/
int buscarLugarLibreDisplay(Display *pDisplay, int len)
{
	int retorno=-1;
	if(pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;++i)
		{
			if(pDisplay[i].flagEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
//=============================================================================
/**
* \brief Imprime todo el arraay del Display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplay(Display pDisplay[], int len)
{
	int estado=-1;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i=0;i<len;i++)
		{
			printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
			pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
		}
	}
	estado=0;
	return estado;
}
//=============================================================================
/**
* \brief busca e Imprime el array Display cargado con datos flag busy
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int imprimirDisplayCargado(Display pDisplay[], int len)
{
	int estado=-1;
	int contadordeCargados=0;
	printf("\nFlagEmpt\t Id\t Type\t Price\t Name\t Address\t\n");
	if (pDisplay!=NULL && len>0)
	{
		for (int i= 0;  i< len; i++)
		{
			if(pDisplay[i].flagEmpty==OCUPADO)
			{
				printf("\n\t%d \t%d \t%d \t%.2f \t%s \t%s\n",
				pDisplay[i].flagEmpty,pDisplay[i].id,pDisplay[i].type, pDisplay[i].price,pDisplay[i].name,pDisplay[i].address);
				contadordeCargados++;
			}
		}
		if(contadordeCargados==0)
			{
				puts("NO HAY DIPLAYS CARGADOS");
			}
	}
	estado=0;
	return estado;
}
//=============================================================================
/**
* \brief Dar de alta un display
* \param recibe un estructura por puntero y el largo
* \return Retorna 0 si se logor carga  y -1  si no
*/
int disp_loadDisplay(Display *pDisplay, int len)
{
	int estado=-1;
	int bufferType;
	char bufferAddres[128];
	char bufferName[128];
	float bufferPrice;
	   if(pDisplay!=NULL && len>0)
	   {
		   if(pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS)==0)
		   {
			     if(pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS)==0)
			     {
			    	 if(pedirText(bufferAddres, sizeof(pDisplay->address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS)==0)
			    	 {
			    		 if(pedirText(bufferName, sizeof(pDisplay->name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS)==0)
			    		 {

			    			 pDisplay->type=bufferType;
			    			 pDisplay->price=bufferPrice;
			    			 strncpy(pDisplay->address, bufferAddres,sizeof(pDisplay->address));
			    			 strncpy(pDisplay->name, bufferName,sizeof(pDisplay->name));
			    			 pDisplay->id=dameUnIdNuevo();
			    			 pDisplay->flagEmpty=OCUPADO;
			    			 estado=OCUPADO;
			    		 }
			    	 }
			     }
		   }
	   }
	   return estado;
}
//=============================================================================
/**
  * \brief me da un id consecutivo y no repetido memorizando el ultimolvalor
  * \param void
  * \return Retorna 0 si todo bien  y -1 si no numero de id
  */
static int dameUnIdNuevo(void)
{
	static int contador=0; //varable Global y solo de esta funcio y no olvida el valor mientra corre
	contador++;
	return contador;
}
//==============================================================================
/**
  * \brief inicializa la var flag en Empty
  * \param un estructura pDisplay Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param el tamañoo
  * \return Retorna 0 si todo bien  y -1 si no
  */
int cargaFlagDisplay(Display *pDiplay, int len)
{
   int estado=-1;
   if (pDiplay!=NULL && len>0)
   {

	  for (int j = 0;  j<len; j++)
	   {
			pDiplay[j].flagEmpty=LIBRE;
			//pDiplay[j].id=dameUnIdNuevo();
			//pDiplay[j].type=-1;
			//strncpy(pDiplay[j].name,"Sin datos",128);
			//strncpy(pDiplay[j].address,"Sin datos",128);
			estado=0;
	   }
   }
   return estado;
}
 //=====================================================================================================
/*
int modificarUnDisplay(Display *pDisplay, int len)
{
	 int retorno=-1;
	 int idamodificar;
	 int posicion;
	 int bufferType;
	 char bufferAddres[128];
	 char bufferName[128];
	 float bufferPrice;
	 int opcion;
	 Display auxiliar; //= {1,100,99,"Name","Siempre 11 viva",0}; //MODIFICACION Harcodeada
	 if(pDisplay!=NULL && len>0)
		 {
		 imprimirDisplayCargado(pDisplay, len);  // IMPRIMIR LISTA EMTY - MOSTRA LISTADO de posibles Display a modificar
		 pedirInt(&idamodificar, "Ingrese Id a modificar", "Error", 0, len, INTENTOS);// Seleccionar id a modificar
		 posicion=buscarUnId(pDisplay, len, idamodificar); // Buscar la posicion en el array del id selecionado
		 if (posicion>=0)// Modificar la pantalla
			 {
			 if(pedirInt(&bufferType, "Ingrese tipo 0 para LCD y 1 LED", "Ingrese tipo valido", 0, 1, INTENTOS)==0)
						 		   {
						 			     if(pedirFloat(&bufferPrice, "Valor de la publicación", "Ingrese un numero correcto", 0, 100000, INTENTOS)==0)
						 			     {
						 			    	 if(pedirText(bufferAddres, sizeof(auxiliar.address), "Ingrese la dirrecion de la pantalla", "Direccion no valida", INTENTOS)==0)
						 			    	 {
						 			    		 if(pedirText(bufferName, sizeof(auxiliar.name), "ingrese el nombre de la pantala", "Nombre invalido",INTENTOS)==0)
						 			    		 {
						 			    			 auxiliar.type=bufferType;
						 			    			 auxiliar.price=bufferPrice;
						 			    			 strncpy(auxiliar.address, bufferAddres,sizeof(auxiliar.address));
						 			    			 strncpy(auxiliar.name, bufferName,sizeof(auxiliar.name));
						 			    			 auxiliar.id=idamodificar;
						 			    			 auxiliar.flagEmpty=OCUPADO;
						 			    			 pDisplay[posicion]=auxiliar;
						 			    			 retorno=0;
						 			    		 }else
						 				 			   puts("Datos ingresados no validos, no se ha modificado el ID");
						 			    	 }else
									 			   puts("Datos ingresados no validos, no se ha modificado el ID");
						 			     }else
								 			   puts("Datos ingresados no validos, no se ha modificado el ID");
						 		   }else
						 			   puts("Datos ingresados no validos, no se ha modificado el ID");
			 }else
				 puts("Id no hallado");
		 }
	 return retorno;
}
*/
