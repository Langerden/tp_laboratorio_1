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

int findIsEmpty(Employee *list, int len) //retornar la posicion de espacio vacio
 {
	int index = -1;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty)
		{
			index = i;
			break;
		}
	}
	return index;
}


int findEmployeeById(Employee *list, int len, int id) //retornar la posicion
 {
	int index = -1;

	for (int i = 0; i < len; i++)
	{
		if (id == list[i].id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int index;
	Employee auxiliar;

	if(list != NULL && len > 0){
	index = findIsEmpty(list, len);
	auxiliar.id = id;
	strncpy (auxiliar.name, name, sizeof(auxiliar.name));
	strncpy (auxiliar.lastName, lastName, sizeof(auxiliar.lastName));
	auxiliar.salary = salary;
	auxiliar.sector = sector;
	auxiliar.isEmpty = 0;
	list[index] = auxiliar;
	retorno = 0;
	}
	return retorno;
}

int chargeDataEmployee(Employee *list,int len, int *nextID){
	int success = -1;
	Employee auxiliar;

	auxiliar.id = *nextID;
	utn_getNombre(auxiliar.name, 51, "Ingrese el Nombre del Empleado\n", "ERROR. Nombre mal ingreasdo, reintente: \n", 5);
	utn_getNombre(auxiliar.lastName, 51, "Ingrese el Apellido del Empleado\n", "ERROR. Apellido mal ingresado, reintente\n", 5);
	utn_getFloat(&auxiliar.salary, "Ingrese un salario entre 15.000 y 150.000: ", "ERROR. Sueldo incorrecto, ingrese un valor entre 15.000 y 150.000: ", 15000, 150000, 5);
	utn_getInt(&auxiliar.sector, "Ingrese un sector\n1) Informatica.\n2) Administracion.\n3) Ventas.\n4) Cobranzas.\nOpcion: ", "Error, elija entre 1-4.", 1, 4, 5);

	if(!addEmployee(list, len, auxiliar.id,auxiliar.name,auxiliar.lastName,auxiliar.salary,auxiliar.sector))
	{
		(*nextID)++;
		success = 0;
	}
	return success;
}

int removeEmployee(Employee* list, int len, int id)
{
	int auxID;
	int retorno = -1;

	auxID = findEmployeeById(list, len, id);
	if (auxID != -1)
	{
		list[auxID].isEmpty = 1;
		retorno = 0;
	}
return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int auxOrden = order;
	int retorno = -1;
	int swapLastName;
	int limit;
	Employee auxEmployee;

	if (list != NULL && len > 0)
	{
			limit = len-1;
			swapLastName = 0;
	do {
		if (auxOrden == 1) //ASC Menor a Mayor
		{
				for (int i = 0; i < limit; i++)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) < 0)
					{
						auxEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
						swapLastName = 1;
					} else if (!swapLastName && list[i].sector > list[i+1].sector)
					{
						auxEmployee = list[i+1];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
					}
				}
				limit--;
				retorno = 0;
		} else if (auxOrden == 0) // DESC MAX a min
		{
				for (int i = 0; i < limit; i++)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
						{
						auxEmployee = list[i];
							list[i] = list[i+1];
							list[i+1] = auxEmployee;
							swapLastName = 1;
						} else if (!swapLastName && list[i].sector < list[i+1].sector)
						{
							auxEmployee = list[i+1];
							list[i] = list[i+1];
							list[i+1] = auxEmployee;
						}
					}
				limit--;
				retorno = 0;
			}
	} while (swapLastName);
}
return retorno;
}

void printOneEmployee (Employee list)
{
	printf("ID:%d        Nombre:%s        Apellido:%s        Salario:%.2f        Sector:%d",list.id,list.name,list.lastName,list.salary,list.sector);
}

void printEmployees(Employee* list, int length)
{
	for (int i = 0;i<length;i++){
		if (list[i].isEmpty==0)
		{
			printOneEmployee(list[i]);
		}
	}
}

int calculateAverAndTotalSalary (Employee* list, int len, float* pPromedio, int* pTotal)
{
	int totalEmployee = 0;
	float acumuladorSalarios = 0;
	int retorno = -1;

	for (int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			acumuladorSalarios += list[i].salary;
			totalEmployee++;
		}
	}
	*pTotal = totalEmployee;
	if(totalEmployee != 0)
	{
	*pPromedio = (float) acumuladorSalarios / totalEmployee;
	retorno = 0;
	}
	return retorno;
}

int countMaxAvarangeSalary (Employee* list, int len, float* pPromedio)
{
	int contadorEmpoyee = 0;

	for (int i = 0; i < len; i++)
	{
		if(list[i].salary > *pPromedio && list[i].isEmpty == 0)
		{
			contadorEmpoyee++;
		}
	}
	return contadorEmpoyee;
}

int modifyEmployee(Employee* list, int len)
{
	int id;
	int index;
	char opcionMenu;
	char seguir = 's';
	Employee auxiliarEmployee;

	utn_getInt(&id,"Ingrese el N° de ID (1 a 1000) a Editar: ","ERROR. ID incorrecto, ingrese entre 1 a 1000: ", 1, 1000, 5);

	index = findEmployeeById(list, len, id); //devuelve la posicion donde esta el empleado, o -1

	if(index != -1)
	{
		printf("Datos del empleado actuales:");
		printOneEmployee(list[index]);
		do
		{
		utn_getChar(&opcionMenu,"Elija la opcion a modificar:\nA) Nombre \nB) Apellido \nC) Salario \nD) Sector \nE) Salir", "ERROR. Opcion no valida: \nA) Nombre: \nB) Apellido: \nC) Salario: \nD) Sector: \nE) Salir:", 'A', 'E', 5);
			switch(opcionMenu)
			{
			case 'A': // change Name
				fflush(stdin);
				if (utn_getNombre(auxiliarEmployee.name, 51, "\nEscriba el nuevo nombre: ", "\nERROR. Nombre mal registrado, reintente: ", 5) == 1)
				{
					strncpy(list[index].name, auxiliarEmployee.name,51);
					printf("\nSe guardo el cambio!");
				}
					break;
			case 'B': // change Last Name
				fflush(stdin);
				if (utn_getNombre(auxiliarEmployee.lastName, 51, "\nEscriba el nuevo Apellido: ", "\nERROR. Apellido mal registrado, reintente: ", 5) == 1)
					{
						strncpy(list[index].lastName,auxiliarEmployee.lastName,51);
						printf("\nSe guardo el cambio!");
				}
						break;
			case 'C': // Salary
				if(utn_getFloat(&auxiliarEmployee.salary, "\nIngrese el valor del salario actual (15.000 a 150.000): ","\nERROR. Valor no valido, reingrese un sueldo entre 15.000 y 150.000", 15000, 150000, 5) == 1)
				{
					list[index].salary = auxiliarEmployee.salary;
					printf("\nSe guardo el cambio!");
				}
				break;
			case 'D': // Sector
				if(utn_getInt(&auxiliarEmployee.sector, "Ingrese el sector\n1) Informatica.\n2) Administracion.\n3) Ventas.\n4) Cobranzas.\nOpcion: ", "Error, elija entre 1-4.", 1, 4, 5) == 1)
				{
				list[index].sector = auxiliarEmployee.sector;
				printf("\nSe guardo el cambio!");
				}
				break;
			case 'E':
				printf("\n¿Quiere modificar otro dato? s/n: ");
				scanf("%c", &seguir);
				break;
			default:
				printf("\nOpcion no valida, ingrese otra");
				break;
			}
			system("cls");
		}while(seguir =='s');
	}
	return 0;
}
