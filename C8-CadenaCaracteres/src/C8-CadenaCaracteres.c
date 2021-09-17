/*
 ============================================================================
 Name        : C8-CadenaCaracteres.c
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

int myStrLen(char* myStr);
int main(void)
{

	char cadena2[50]="Buenas";
	char cadena1[50]= {'h','o','l','a', '\0'};
	int bylen;
	int bymy;
	bylen=strlen(cadena2);
	printf("puts dice %d\n", bylen);
	bymy=myStrLen(cadena2);
	printf("myStrLen dice %d\n", bymy);
	puts(cadena1);

return EXIT_SUCCESS;
}

int myStrLen(char* cadena)//o char cadena[]
{
	int index=0;
	while(cadena[index]!='\0')
		{
			index++;
		}
	return index;
}
	// index coincide con la cant de letras
	/*
	int index=0;
	if(cadena!=NULL)
	{
		while(cadena[index]!='\0')
		{
			index++;
		}
	}
	return index;
	*/
/*
void muyPuts
{

}

void myStrCpy
{

}
*/
