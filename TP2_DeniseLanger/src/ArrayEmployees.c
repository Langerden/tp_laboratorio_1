
#include "ArrayEmployees.h"
#include "utn_getDato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int initEmployees(Employee *list, int len)
{
	int retorno = -1;

	for (int i = 0; i < len; i++)
	{
		list[i].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

static int findIsEmpty(Employee *list, int len)
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

int findEmployeeById(Employee *list, int len, int id)
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

int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;
	int index;
	Employee auxiliar;

	if (list != NULL && len > 0)
	{
		index = findIsEmpty(list, len);

		auxiliar.id = id;
		strncpy(auxiliar.name, name, sizeof(auxiliar.name));
		strncpy(auxiliar.lastName, lastName, sizeof(auxiliar.lastName));
		auxiliar.salary = salary;
		auxiliar.sector = sector;
		auxiliar.isEmpty = 0;
		list[index] = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int chargeDataEmployee(Employee *list, int len, int *nextID)
{
	int retorno = -1;
	int index;
	Employee auxiliar;

	index = findIsEmpty(list, len);
	if (index < 0)
	{
		printf("No hay mas lugar para cargar.\n");
	} else {
		auxiliar.id = *nextID;
		utn_getName(auxiliar.name, 51, "Ingrese el Nombre del Empleado: ",  "ERROR. Nombre mal ingreasdo\n", 5);
		utn_getName(auxiliar.lastName, 51, "Ingrese el Apellido del Empleado: ","ERROR. Apellido mal ingresado\n", 5);
		utn_getFloat(&auxiliar.salary, "Ingrese un salario entre 15.000 y 150.000: ","ERROR. Sueldo incorrecto\n", 15000, 150000, 5);
		utn_getInt(&auxiliar.sector,"Ingrese un sector\n1) Informatica.\n2) Administracion.\n3) Ventas.\n4) Cobranzas.\nOpcion: ","ERROR. Sector incorrecto:\n", 1, 4, 5);

		if (!addEmployee(list, len, auxiliar.id, auxiliar.name, auxiliar.lastName, auxiliar.salary, auxiliar.sector))
		{
			(*nextID)++;
			retorno = 0;
			printf("Empleado cargado con exito.\n");
		}
	}
	return retorno;
}

int removeEmployee(Employee *list, int len, int id)
{
	int auxID;
	int retorno = -1;
	char confirmar = 's';

	auxID = findEmployeeById(list, len, id);

	if (auxID != -1)
	{
		do
		{
			printf("¿Seguro que quiere remover el empleado con ID %d (s/n:) ",id);
			utn_myGets(&confirmar, sizeof(confirmar));
			confirmar = tolower(confirmar);
		} while(confirmar!='s' && confirmar!='n');

		if(confirmar=='s')
		{
			list[auxID].isEmpty = 1;
			retorno = 0;
			printf("Empleado removido con exito.\n");
		} else {
			printf("Accion cancelada.");
		}
	}
	return retorno;
}

int sortEmployees(Employee *list, int len, int order)
{
	int auxOrden = order;
	int retorno = -1;
	int limit;
	Employee auxEmployee;

	if (list != NULL && len > 0)
	{
		limit = len - 1;
		if (auxOrden == 1) //DESC
		{
			do {
				for (int i = 0; i < limit; i++)
				{
					if (strcmp(list[i+1].lastName, list[i].lastName) < 0)
					{
						auxEmployee = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmployee;
					} else if (!strcmp(list[i+1].lastName, list[i].lastName) && list[i].sector > list[i + 1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmployee;
					}
				}
				limit--;
			} while (limit > 0);
			retorno = 0;
		} else if (auxOrden == 2) // ASC
			{
			do {
				for (int i = 0; i < limit; i++)
				{
					if (strcmp(list[i+1].lastName, list[i].lastName) > 0)
					{
						auxEmployee = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmployee;
					} else if (!strcmp(list[i+1].lastName, list[i].lastName) && list[i].sector < list[i + 1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmployee;
					}
				}
				limit--;
			} while (limit > 0);
			retorno = 0;
		}
	}
	return retorno;
}

void printOneEmployee(Employee list)
{
	printf("ID:%d  Nombre:%s  Apellido:%s Salario:%.2f Sector:%d\n", list.id, list.name, list.lastName, list.salary, list.sector);
}

int printEmployees(Employee *list, int length)
{
	int retorno = -1;

	for (int i = 0; i < length; i++)
	{
		if (list[i].isEmpty == 0)
		{
			printOneEmployee(list[i]);
			retorno = 0;
		}
	}
	return retorno;
}

int calculateAverAndTotalSalary(Employee *list, int len, float *pPromedio, int *pTotal)
{
	int totalEmployee = 0;
	float acumuladorSalarios = 0;
	int retorno = -1;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 0)
		{
			acumuladorSalarios += list[i].salary;
			totalEmployee++;
		}
	}
	*pTotal = totalEmployee;
	if (totalEmployee != 0)
	{
		*pPromedio = (float) acumuladorSalarios / totalEmployee;
		retorno = 0;
	}
	return retorno;
}

int countMaxAvarangeSalary(Employee *list, int len, float *pPromedio)
{
	int contadorEmpoyee = 0;

	for (int i = 0; i < len; i++)
	{
		if (list[i].salary > *pPromedio && list[i].isEmpty == 0)
		{
			contadorEmpoyee++;
		}
	}
	return contadorEmpoyee;
}

int modifyEmployee(Employee *list, int len)
{
	int id;
	int index;
	char opcionMenu;
	char seguir = 's';
	Employee auxiliarEmployee;

	printEmployees(list, len);
	utn_getInt(&id, "Ingrese el Numero de ID (2000 a 2100) a Editar: ", "ERROR. ID incorrecto.\n", 2000,2100, 5);
	index = findEmployeeById(list, len, id);

	if (index != -1)
	{
		do {
			printf("Datos del empleado actuales\n");
			printOneEmployee(list[index]);
			utn_getChar(&opcionMenu,"Elija la opcion a modificar:\nA) Nombre \nB) Apellido \nC) Salario \nD) Sector \nE) Salir\n opcion: ","ERROR. Opcion no valida.\n", 'A', 'E', 5);

			switch (opcionMenu)
			{
			case 'A': // Edit Name
				if (utn_getName(auxiliarEmployee.name, 51, "\nEscriba el nuevo nombre: ", "\nERROR. Nombre mal registrado.\n", 5) == 0)
				{
					strncpy(list[index].name, auxiliarEmployee.name, 51);
					printf("\nSe guardo el cambio!\n");
				}
				break;
			case 'B': // Edit LastName
				if (utn_getName(auxiliarEmployee.lastName, 51, "\nEscriba el nuevo Apellido: ","\nERROR. Apellido mal registrado.\n", 5) == 0)
				{
					strncpy(list[index].lastName, auxiliarEmployee.lastName, 51);
					printf("\nSe guardo el cambio!\n");
				}
				break;
			case 'C': // Edit Salary
				if (utn_getFloat(&auxiliarEmployee.salary, "\nIngrese el valor del salario actual (15.000 a 150.000): ","\nERROR. Valor no valido\n", 15000, 150000, 5) == 0)
				{
					list[index].salary = auxiliarEmployee.salary;
					printf("\nSe guardo el cambio!\n");
				}
				break;
			case 'D': // Edit Sector
				if (!utn_getInt(&auxiliarEmployee.sector,"Ingrese el sector\n1) Informatica.\n2) Administracion.\n3) Ventas.\n4) Cobranzas.\nOpcion: ","ERROR. Sector incorrecto:\n", 1,4, 5))
				{
					list[index].sector = auxiliarEmployee.sector;
					printf("\nSe guardo el cambio!\n");
				}
				break;
			case 'E': //Edit Exit
				do{
					printf("Quiere modificar otro dato (s/n): ");
					utn_myGets(&seguir, sizeof(seguir));
					seguir = tolower(seguir);
				} while(seguir!='s' && seguir!='n');
				break;
			default:
				printf("\nOpcion no valida, ingrese otra\n");
				break;
			}
			system("pause");
			system("cls");
		} while (seguir == 's');
	} else {
		printf("El ID ingresado no coincide con los datos registrados.\n");
	}
	return 0;
}
