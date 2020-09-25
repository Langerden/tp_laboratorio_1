/*
 * ArrayEmployees.c
 *
 *  Created on: 23 sep. 2020
 *      Author: User
 */
#include "ArrayEmployees.h"
#include "utn_getDato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*
*Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
*/
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	for (int i = 0; i < len; i++)
	{
		list[i].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int findEmployeeById(Employee *list, int len, int id) //retornar la posicion
 {
	int index = -1;

	for (int i = 0; i < len; i++)
	{
		//if (id == list[i]) {
			index = i;
			break;
		//}
	}
	return index;
}


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{


	return -1;
}



int chargeData(Employee *list,int len, int *nextID){
	int success = -1;

	//int idAux = *nextID;
	Employee auxiliar;


	auxiliar.id = *nextID;
	utn_getFloat(&auxiliar.salary, "Ingrese un salario entre 12k y 45k: ", "Sueldo incorrecto, ingrese entre 12k y 45k.", 12000, 45000, 5);
	utn_getInt(&auxiliar.sector, "Ingrese un sector\n1) Informatica.\n2) Administracion.\n3) Ventas.\n4) Cobranzas.\nOpcion: ", "Error, elija entre 1-4.", 1, 4, 5);

	if(!addEmployee(list, len, auxiliar.id,auxiliar.name,auxiliar.lastName,auxiliar.salary,auxiliar.sector)){
		(*nextID)++;
		success = 0;
	}


	return success;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
return 0;
}

