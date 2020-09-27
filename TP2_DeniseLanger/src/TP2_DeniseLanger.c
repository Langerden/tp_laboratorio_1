/*
 ============================================================================
 Name        : TP2_DeniseLanger.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn_getDato.h"
#include "ArrayEmployees.h"
#define FACTORY_LEN 10

int main(void)
{
	setbuf(stdout, NULL);
	int flagMenu;
	int idLibre = 2000;
	int subMenu;
	int opcionMenu;
	int idUser;
	float promedioSalario;
	int empleadosArribaPromedio;
	int totalSalario;
	char salir = 'y';
	Employee factory[FACTORY_LEN];

	initEmployees(factory, FACTORY_LEN); //Inicializo Array en 1
	do
	{
		//fflush(stdin);
		opcionMenu = menu();
		switch(opcionMenu)
		{
		case 1: //Ingresar un empleado
			flagMenu = chargeDataEmployee(factory, FACTORY_LEN, &idLibre);
			break;
		case 2: //Ingresar ID y modificar Nombre, Apellido, Salario o Sector
			if(!flagMenu)
			{
				modifyEmployee(factory, FACTORY_LEN);
			}
			printf("Aun no cargaste ningun empleado.");
			break;
		case 3: // Ingresar ID y eliminar empleado
			if(!flagMenu){
				utn_getInt(&idUser, "Ingrese el ID a eliminar", "ERROR. Numero invalido, reingrese (Entre XXX y XXX)", 0, 5000, 5);
				removeEmployee(factory, FACTORY_LEN, idUser);
			}
			printf("Aun no cargaste ningun empleado.");
			break;
		case 4: // Informar empleados por Apellido / Nombre + Total y Promedio de salarios + Cant empleados salario > Promedio
			if(!flagMenu)
			{
			utn_getInt(&subMenu, "Elija el orden a Informar (ASC = 1 / DESC = 0)", "ERROR. Opcion invalida, reingrese el orden (ASC = 1 / DESC = 0)", 0, 1, 5);
			sortEmployees(factory, FACTORY_LEN, subMenu);
			calculateAverAndTotalSalary(factory, FACTORY_LEN, &promedioSalario, &totalSalario);
			}
			if (promedioSalario > 0)
			{
				empleadosArribaPromedio = countMaxAvarangeSalary(factory, FACTORY_LEN, &promedioSalario);
				printEmployees(factory, FACTORY_LEN);
				printf("\nEl total de Salarios registados es: %d", totalSalario);
				printf("\nEl promedio de los salarios es de %.2f: ", promedioSalario);
				printf("\nLa cantidad de Empleados que supera el promedio es de %d",empleadosArribaPromedio);
			}
			printf("Aun no cargaste ningun empleado.");
			break;
		case 5:
			printf("\n¿Desea salir? Y/N:");
			fflush(stdin);
			scanf("%c",&salir);
			if(salir == 'n')
			{
				flagMenu = 1;
			}
			break;
		default:
			printf("Opcion incorrecta.\n");
		break;
		}
		//system("pause");
	}while (salir == 'n');
	return EXIT_SUCCESS;
}
