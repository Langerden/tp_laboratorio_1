#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_getDato.h"

Employee* employee_new()
	{
	Employee* auxEmployee;
	auxEmployee = (Employee*) malloc(sizeof(Employee));
	return auxEmployee;
}

void employee_listEmployee(Employee* this)
{
	int auxID;
	char auxNombre [128];
	int auxHoras;
	int auxSalario;

	if(this != NULL)
	{
		employee_getId(this, &auxID);
		employee_getNombre(this, auxNombre);
		employee_getHorasTrabajadas(this, &auxHoras);
		employee_getSueldo(this, &auxSalario);

		printf("ID:%d     Nombre:%s     Hs Trabajadas:%d      Sueldo:%d\n",auxID,auxNombre,auxHoras,auxSalario);
	}
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* auxEmployee;
	int auxID;
	int auxHoras;
	int auxSueldo;

	auxEmployee = employee_new();
	if(auxEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		auxID = atoi(idStr);
		auxHoras = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldoStr);
		employee_setId(auxEmployee, auxID);
		employee_setNombre(auxEmployee, nombreStr);
		employee_setHorasTrabajadas(auxEmployee, auxHoras);
		employee_setSueldo(auxEmployee, auxSueldo);
	}
	return auxEmployee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_SearchByID(LinkedList* this, int idEmployee)
{
	int retorno = -1;
	int idAux;
	Employee* auxEmplo = NULL;

	if(this != NULL)
	{
		for (int index = 0; index < ll_len(this); index++)
		{
			auxEmplo = ll_get(this, index);
			if(!employee_getId(auxEmplo, &idAux) && idAux==idEmployee)
			{
				retorno = index;
				break;
			}
		}
	}
	return retorno;
}

int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int orden;
	int opcionSort;

	if(pArrayListEmployee != NULL)
	{
		utn_getInt(&opcionSort, "Ingrese el criterio de orden\n 1- ID\n 2- Nombre\n 3- Horas Trabajadas\n 4- Sueldo\n 5- Salir\n Opcion: ", "ERROR: OPCION NO VALIDA\n", 1, 5, 10);
		switch(opcionSort)
		{
			case 1:
				//Id
				utn_getInt(&orden, "Ingrese el orden (1:ASC / 0:DESC) \n", "ERROR: OPCION NO VALIDA\n", 0, 1,10);
				printf("Ordenando, aguarde unos minutos :D \n");
				ll_sort(pArrayListEmployee, employee_sortById, orden);
				retorno = 0;
				break;
			case 2:
				//Nombre
				utn_getInt(&orden, "Ingrese el orden (1:ASC / 0:DESC) \n", "ERROR: OPCION NO VALIDA\n", 0, 1,10);
				printf("Ordenando, aguarde unos minutos :D \n");
				ll_sort(pArrayListEmployee, employee_sortByName, orden);
				retorno = 0;
				break;
			case 3:
				//Horas
				utn_getInt(&orden, "Ingrese el orden (1:ASC / 0:DESC) \n", "ERROR: OPCION NO VALIDA\n", 0, 1,10);
				printf("Ordenando, aguarde unos minutos :D \n");
				ll_sort(pArrayListEmployee, employee_sortByHours, orden);
				retorno = 0;
				break;
			case 4:
				//Sueldo
				utn_getInt(&orden, "Ingrese el orden (1:ASC / 0:DESC) \n", "ERROR: OPCION NO VALIDA\n", 0, 1,10);
				printf("Ordenando, aguarde unos minutos :D \n");
				ll_sort(pArrayListEmployee, employee_sortBySalary, orden);
				retorno = 1;
				break;
			case 5:
				printf("Ordenamiento Cancelado con exito\n");
				break;
		}
	}
	return retorno;
}

int employee_sortById(void* firstEmployee, void* secondEmployee)
{
	int retorno = 0;
	int firstId;
	int secondId;

	employee_getId(firstEmployee, &firstId);
	employee_getId(secondEmployee, &secondId);

	if(firstId > secondId)
	{
		retorno = 1;
	}
	else if(firstId < secondId)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_sortByName(void* firstEmployee, void* secondEmployee)
{
	int retorno = 0;
	char firstName[200];
	char secondName[200];

	employee_getNombre(firstEmployee, firstName);
	employee_getNombre(secondEmployee, secondName);

	if(strcmp(firstName, secondName) > 0)
	{
		retorno = 1;
	}
	else if(strcmp(firstName, secondName) < 0)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_sortByHours(void* firstEmployee, void* secondEmployee)
{
	int retorno = 0;
	int firstHours;
	int secondHours;

	employee_getHorasTrabajadas(firstEmployee, &firstHours);
	employee_getHorasTrabajadas(secondEmployee, &secondHours);

	if(firstHours > secondHours)
	{
		retorno = 1;
	}
	else if(firstHours < secondHours)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_sortBySalary(void* firstEmployee, void* secondEmployee)
{
	int retorno = 0;
	int firstSalary;
	int secondSalary;

	employee_getSueldo(firstEmployee, &firstSalary);
	employee_getSueldo(secondEmployee, &secondSalary);

	if(firstSalary > secondSalary)
	{
		retorno = 1;
	}
	else if(firstSalary < secondSalary)
	{
		retorno = -1;
	}

	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_lastId(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int largo;
	int auxId;
	int lastId = -1;
	int flag = 0;

	largo = ll_len(pArrayListEmployee);
	if (pArrayListEmployee != NULL)
	{
		for(int i = 0; i < largo; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &auxId);

			if(auxId > lastId || flag == 0)
			{
				lastId = auxId;
				flag = 1;
			}
		}
	}
	return lastId;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && (strlen(nombre) > 0))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
		{
			strcpy(nombre,this->nombre);
			retorno = 0;
		}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
