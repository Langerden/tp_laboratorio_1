#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_getDato.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee) == 0 )
	{
		printf("Archivo de texto cargado con exito\n");
		retorno = 0;
	} else
	{
		printf("Error al cargar el archivo\n");
	}
	fclose(pFile);
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			printf("Archivo de texto cargado con exito\n");
			retorno = 0;
		} else
		{
			printf("Error al cargar el archivo\n");
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_listEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int largo;
	Employee* auxEmployee;

	largo = ll_len(pArrayListEmployee);
	if (largo > 0)
	{
		for (int i = 0; i < largo; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(auxEmployee != NULL)
			{
				employee_listEmployee(auxEmployee);
			}
		}
		retorno = 0;
	}
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = employee_new();
	char auxNombre [128];
	int auxID;
	int auxHoras;
	int auxSueldo;
	int retorno = -1;

	if (pArrayListEmployee != NULL && auxEmployee != NULL)
	{
		auxID = employee_lastId(pArrayListEmployee) + 1;
		utn_getName(auxNombre, 128, "Ingrese el Nombre del empleado: \n", "ERROR: DATO NO VALIDO\n", 10);
		utn_getInt(&auxHoras, "Ingrese la cantidad de Horas Trabajadas del empleado (60 a 500): \n", "ERROR: DATO NO VALIDO\n", 60, 500, 10);
		utn_getInt(&auxSueldo, "Ingrese el Sueldo del empleado (20000 a 100000): \n", "ERROR: DATO NO VALIDO\n", 20000, 100000, 10);

		employee_setId(auxEmployee, auxID);
		employee_setNombre(auxEmployee, auxNombre);
		employee_setHorasTrabajadas(auxEmployee, auxHoras);
		employee_setSueldo(auxEmployee, auxSueldo);
		ll_add(pArrayListEmployee, auxEmployee);
		printf("Alta exitosa!\n");
		retorno = 0;
	}
	return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int retorno = -1;
	int auxID;
	int auxSueldo;
	int auxHoras;
	int index;
	int maxIndex;
	int opcionEdit;
	char auxName [128];
	char salir = 'N';

	if(pArrayListEmployee != NULL)
	{
		controller_listEmployee(pArrayListEmployee);
		maxIndex = employee_lastId(pArrayListEmployee);
		utn_getInt(&auxID, "Ingrese el ID a Modificar: \n", "ERROR. DATO NO VALIDO\n", 1, maxIndex, 10);
		index = employee_SearchByID(pArrayListEmployee, auxID);
		if (index == -1)
		{
			printf("No hay un Empleado con el ID %d",auxID);
		} else {
			auxEmployee = ll_get(pArrayListEmployee, index);
			employee_listEmployee(auxEmployee);
			do{
				printf("\n1)Editar Nombre\n2)Editar Sueldo\n3)Editar Horas Trabajadas\n4)Salir\n");
				utn_getInt(&opcionEdit, "Opcion: \n", "ERROR. OPCION NO VALIDA\n", 1, 4, 10);
				switch (opcionEdit)
				{
					case 1:
						utn_getName(auxName, 128, "Ingrese el nuevo Nombre: ", "ERROR: NOMBRE INVALIDO\n", 10);
						employee_setNombre(auxEmployee, auxName);
						printf("¡Se guardaron los cambios!\n");
						retorno = 0;
						break;
					case 2:
						utn_getInt(&auxSueldo, "Ingrese el nuevo Sueldo (20000 a 100000): ", "ERROR: SUELDO NO VALIDO\n", 20000, 100000, 10);
						employee_setSueldo(auxEmployee, auxSueldo);
						printf("¡Se guardaron los cambios!");
						retorno = 0;
						break;
					case 3:
						utn_getInt(&auxHoras, "Ingrese las nuevas Horas Trabajadas (60 a 500): ", "ERROR: HORAS TRABAJADAS INVALIDAS\n", 60, 500, 10);
						employee_setHorasTrabajadas(auxEmployee, auxHoras);
						printf("¡Se guardaron los cambios!");
						retorno = 0;
						break;
					case 4:
						utn_getChar(&salir,"¿Confirma Salir (Y/N)?: ", "ERROR: OPCION NO VALIDA\n", 'N', 'Y', 10);
						break;
				}
			} while (salir == 'N');
			if(retorno != 0)
			{
				printf("Se cancelo la operacion\n");
			}
		}
	}
	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int auxIDUser;
	int auxIDLL;
	int index;
	int maxIndex;
	int retorno = -1;
	char confirms = 'Y';

	if(pArrayListEmployee != NULL)
	{
		controller_listEmployee(pArrayListEmployee);
		maxIndex = employee_lastId(pArrayListEmployee);
		utn_getInt(&auxIDUser, "Ingrese el ID que desea eliminar: \n", "ERROR: ID NO VALIDO\n", 1, maxIndex, 10);
		index = employee_SearchByID(pArrayListEmployee, auxIDUser);
		auxEmployee = ll_get(pArrayListEmployee, index);
		employee_getId(auxEmployee, &auxIDLL);

		if(auxIDUser == auxIDLL)
		{
			utn_getChar(&confirms, "¿Confirma eliminar al Empleado (Y/N): \n", "ERROR: OPCION NO VALIDA\n", 'N', 'Y', 10);
			if(confirms == 'Y')
			{
				ll_remove(pArrayListEmployee, index);
				employee_delete(auxEmployee);
				printf("Empleado removido con exito\n");
				retorno = 0;
			} else {
				printf("Se cancelo la operacion\n");
			}
		}
	}
	return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int returnSort;

	if(pArrayListEmployee != NULL)
	{
		returnSort = employee_sortEmployee(pArrayListEmployee);

		if(returnSort == 0)
		{
			retorno = 0;
		} else if(returnSort) {
			retorno = 1;
		}
	}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

		FILE* pFile;
		int auxId;
		char auxName[200];
		int auxHours;
		int auxSalary;
		int flagHeader = 1;
		Employee* pEmployee;

		if(pArrayListEmployee != NULL && path != NULL)
		{
			pFile = fopen(path, "w");
			if(pFile != NULL)
			{
				retorno = 0;
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					pEmployee = ll_get(pArrayListEmployee, i);
					if(!employee_getId(pEmployee, &auxId) &&
					   !employee_getNombre(pEmployee, auxName) &&
					   !employee_getHorasTrabajadas(pEmployee, &auxHours) &&
					   !employee_getSueldo(pEmployee, &auxSalary))
					{
						if(flagHeader){
							fprintf(pFile,"%s,%s,%s,%s\n","ID","NOMBRE","HORAS","SUELDO");
							flagHeader = 0;
						}
						fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
					}
				}
				fclose(pFile);
				printf("Archivo guardado!\n");
			}
		}
	    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee, sizeof(Employee), 1, pFile);
		}
		printf("Archivo guardado!\n");
		fclose(pFile);


		retorno = 0;
	}
	return retorno;
}

