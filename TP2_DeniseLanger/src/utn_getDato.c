
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getDato.h"
#include "ArrayEmployees.h"

int utn_myGets(char* cadena, int largo)
{
	int retorno =-1;
	char bufferString[4096];

	if(cadena != NULL && largo > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= largo)
			{
				strncpy(cadena,bufferString,largo);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//Funciones Floats

static int isFloat(char* cadena)
{
	int retorno = -1;
	int countPoints = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(int i = 0 ; cadena[i] != '\0'; i++)
		{
			if(i ==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && countPoints == 0)
				{
					countPoints++;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[64];

    if(pResultado != NULL)
    {
    	if(utn_myGets(bufferString,sizeof(bufferString))== 0 && isFloat(bufferString))
    	{
			*pResultado = atof(bufferString);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* msjError,	float min, float max, int reintentos)
{
	float numUsuario;
	int retorno = -1;

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&numUsuario) == 0)
		{
			if(numUsuario >= min && numUsuario <= max)
			{
				*pResultado = numUsuario;
				retorno = 0;
				break;
			}
		}
		printf("%s",msjError);
	}
	return retorno;
}

//Funciones Int

static int isNumber(char* cadena, int largo)
{
	int retorno = -1;

	for(int i = 0; i < largo && cadena[i] != '\0';i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(	pResultado != NULL && utn_myGets(bufferString,sizeof(bufferString)) == 0 && isNumber(bufferString,sizeof(bufferString) == 0))
    {
		*pResultado = atoi(bufferString);
		retorno=0;

	}
    return retorno;
}

int utn_getInt(int* pResultado, char* mensaje, char* msjError,int min, int max, int reintentos)
{
	int retorno = -1;
	int numUsuario;

	do{
		printf("%s",mensaje);
		if(getInt(&numUsuario) == 0 && numUsuario >= min && numUsuario <= max)
		{
			*pResultado = numUsuario;
			retorno = 0;
			break;
		}
		printf("%s",msjError);
		reintentos--;
	} while(reintentos >= 0);
	return retorno;
}

//Funcion Strings


//Funcion para Poner el primer Char en Mayuscula y el resto del String en Minuscula
static void formatName(char* string)
{
	int largoArray;

	largoArray = strlen(string);

	for(int i = 0; i < largoArray; i++)
	{
		if(i == 0)
		{
			string[i] = toupper(string[i]);
		} else {
			string[i] = tolower(string[i]);
		}
	}
}

static int isName(char* cadena,int largo)
{
	int retorno = 1;

	if(cadena != NULL && largo > 0)
	{
		for(int i = 0 ; cadena[i] != '\0' && i < largo; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&	(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getName(char* pResultado, int largo)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL)
    {
    	if(utn_myGets(bufferString,sizeof(bufferString)) == 0 && isName(bufferString,sizeof(bufferString)) && strnlen(bufferString,sizeof(bufferString)) < largo)
    	{
    		strncpy(pResultado,bufferString,largo);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getName(char* pResultado, int largo ,char* mensaje, char* msjError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	while(reintentos >= 0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getName(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < largo )
		{
			strncpy(pResultado,bufferString,largo);
			formatName(pResultado);
			retorno = 0;
			break;
		}
		printf("%s",msjError);
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
			fflush(stdin);
			scanf("%c", &charUser);
			if(charUser >= min && charUser <= max)
			{
				*pResultado = charUser;
				retorno = 0;
				break;
			} else {
				printf("%s",msjError);
				fflush(stdin);
				reintentos--;
			}
		}while (reintentos > 0);
	}
	return retorno;
}

int menu()
{
	int opcion;

	printf("1 - Alta del Empleado\n");
	printf("2 - Modificar datos del Empleado\n");
	printf("3 - Borrar datos del Empelado\n");
	printf("4 - Informar lista de Empleados \n");
	printf("5 - Salir \n");
	fflush(stdin);
	utn_getInt(&opcion, "Opcion: ", "Opcion incorrecta, elija entre 1-5\n", 1, 5,5);
	return opcion;
}
