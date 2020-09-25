
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_getDato.h"

int utn_getInt(int* pResultado,char* mensaje,char* msjError,int min, int max, int reintentos)
{
	int retorno = -1;
	int numUsuario;
	if(pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			//scanf("%d", &numUsuario);
			if(getInt(numUsuario) && numUsuario >= min && numUsuario <= max)
			{
				*pResultado = numUsuario;
				retorno = 1;
				break;
			} else {
				printf("%s",msjError);
				reintentos--;
			}
		}while (reintentos > 0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado,char* mensaje,char* msjError,float min, float max, int reintentos)
{
	int retorno = -1;
	float numUsuario;
	if(pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &numUsuario);
			if(numUsuario >= min && numUsuario <= max)
			{
				*pResultado = numUsuario;
				retorno = 0;
				break;
			} else {
				printf("%s",msjError);
				reintentos--;
			}
		}while (reintentos > 0);
	}
	return retorno;
}

int utn_getChar(char* pResultado,char* mensaje,char* msjError,char min, char max, int reintentos)
{
	int retorno = -1;
	char charUser;
	if(pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%c", &charUser);
			if(charUser >= min && charUser <= max)
			{
				*pResultado = charUser;
				retorno = 0;
				break;
			} else {
				printf("%s",msjError);
				reintentos--;
			}
		}while (reintentos > 0);
	}
	return retorno;
}

//int utn_getString(char* arrayString, char* mensaje, char* msjError, int largoArray)

int utn_myGets (char* cadena, int largo)
{
	int retorno = -1;
	char bufferString [4096];
	if(cadena != NULL && largo > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			else if (strlen(bufferString) <= largo)
			{
				strncpy(cadena,bufferString, largo);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int getInt (char* cadena)
{
	int retorno = -1;
	char bufferString [50];
	if (cadena != NULL && myGets(bufferString,sizeof(bufferString) == 1) && isNumber (bufferString))
	{
		retorno = 1;
		bufferString = atoi(bufferString);
	}

}

int isNumber ()
{

}

int menu(){
	int opcion;
		printf("1 - Alta del Empleado\n");
		printf("2 - Modificar datos del Empleado\n");
		printf("3 - Borrar datos del Empelado\n");
		printf("4 - Informar lista de Empleados \n");
		printf("5 - Salir \n");

	utn_getInt(&opcion, "Opcion: ", "Opcion incorrecta, elija entre 1-5", 1, 5,5);

	return opcion;
}
