#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#define LARGO_CHAR 150

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int retorno = -1;
	char id[LARGO_CHAR];
	char nombre[LARGO_CHAR];
	char horasTrabajadas[LARGO_CHAR];
	char sueldo[LARGO_CHAR];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
			{

				auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(auxEmployee != NULL)
				{
					ll_add(pArrayListEmployee, auxEmployee);
					retorno = 0;
				}
			}
		} while(feof(pFile) == 0);
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int retorno = -1;

	if(pFile != NULL)
	{
		do
		{
			auxEmployee = employee_new();
			if(fread(auxEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, auxEmployee);
				retorno = 0;
			}
		}while(!feof(pFile));
	}
    return retorno;
}
