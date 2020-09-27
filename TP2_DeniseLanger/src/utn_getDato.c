
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_getDato.h"
#include "ArrayEmployees.h"

int utn_myGets (char* cadena, int largo)
{
	int retorno = -1;
	char bufferString [4096];
	if(cadena != NULL && largo > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			 if (strnlen(bufferString,sizeof(bufferString)) <= largo)
			{
				strncpy(cadena,bufferString, largo);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int IsFloat (char* cadena, int largo)
{
	int retorno = 0;
	int countPoint = 0;

	if(cadena != NULL && strlen (cadena) > 0)
	{
		for(int i = 0; i < largo && cadena[i] != '\0'; i++)
		{
			if (cadena [0] == '-' || cadena [0] == '+')
				continue;
			else if (cadena [i] == '.')
			{
				countPoint++;
			}
			if(cadena[i] > '9' || cadena [i] < '0' || countPoint != 1)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int isNumber (char* cadena, int largo)
{
	int retorno = 0;

	for(int i = 0; i < largo && cadena[i] != '\0'; i++)
	{
		if (i == 0 && (cadena [i] == '-' || cadena [i] == '+'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena [i] < '0')
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int getInt (int* bufferInt)
{
	int retorno = -1;
	char bufferString [50];
	if (bufferInt != NULL && utn_myGets(bufferString,sizeof(bufferString) == 0) && isNumber (bufferString, sizeof(bufferString) == 0))
	{
		*bufferInt = atoi(bufferString);
		retorno = 0;
	}
	return retorno;
}

int getFloat (float* bufferFloat)
{
	int retorno = -1;
	char bufferString [50];
	if (bufferFloat != NULL && utn_myGets(bufferString,sizeof(bufferString) == 1) && isNumber (bufferString, sizeof(bufferString)))
	{
		*bufferFloat = atof(bufferString);
		retorno = 0;
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
			if(getFloat(&numUsuario) == 0 && numUsuario >= min && numUsuario <= max)
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

int utn_getInt(int* pResultado,char* mensaje,char* msjError,int min, int max, int reintentos)
{
	int retorno = -1;
	int numUsuario;
	if(pResultado != NULL && mensaje != NULL && msjError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			if(getInt(&numUsuario) == 0 && numUsuario >= min && numUsuario <= max)
			{
				*pResultado = numUsuario;
				retorno = 0;
				break;
			}
			printf("%s",msjError);
			reintentos--;
		}while (reintentos >= 0);
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

int isName (char* cadena,int largo)
{
	int retorno = 0;

	if(cadena != NULL && largo > 0)
	{
		for(int i = 0 ; cadena[i] != '\0' && i < largo; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

void formatName(char* string)
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

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
		{
			do
			{
				printf("%s", mensaje);
				if(utn_myGets(bufferString, sizeof(bufferString)) && isName(bufferString, sizeof(bufferString)))
				{
					strncpy(pResultado, bufferString, longitud);
					retorno = 0;
					break;
				}
				printf("%s",mensajeError);
				reintentos--;
			}while (reintentos > 0);
		}
	formatName(pResultado);
	return retorno;
}

int menu(){
	int opcion;

		printf("1 - Alta del Empleado\n");
		printf("2 - Modificar datos del Empleado\n");
		printf("3 - Borrar datos del Empelado\n");
		printf("4 - Informar lista de Empleados \n");
		printf("5 - Salir \n");
		//scanf("%d", &opcion);
		utn_getInt(&opcion, "Opcion: ", "Opcion incorrecta, elija entre 1-5", 1, 5,5);

		return opcion;
}
