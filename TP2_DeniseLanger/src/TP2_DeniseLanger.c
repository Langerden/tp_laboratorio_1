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
#define FACTORY_LEN 5

int main(void)
{
	setbuf(stdout, NULL);
	int flagMenu = 0;
	int primerIDEmpelado = 2000;
	int idLibre = primerIDEmpelado;
	int subMenu;
	int idUser;
	float promedioSalario = 0;
	int empleadosArribaPromedio;
	int totalSalario;
	char salir = 'n';
	Employee factory[FACTORY_LEN];

	initEmployees(factory, FACTORY_LEN); //Inicializo Array en 1

	do
	{
		switch( menu())
		{
		case 1: //Ingresar un empleado
			if(!chargeDataEmployee(factory, FACTORY_LEN, &idLibre)){
				flagMenu++;
			}
			break;
		case 2: //Ingresar ID y modificar Nombre, Apellido, Salario o Sector
			if(flagMenu)
			{
				modifyEmployee(factory, FACTORY_LEN);

			}else{
				printf("Aun no cargaste ningun empleado.\n");
			}
			break;
		case 3: // Ingresar ID y eliminar empleado
			if(flagMenu){
				printEmployees(factory, FACTORY_LEN);
				utn_getInt(&idUser, "Escriba el ID del empleado a eliminar: ", "ERROR. ID inexistente.\n",primerIDEmpelado , (idLibre-1), 7);
				if(!removeEmployee(factory, FACTORY_LEN, idUser)){
					flagMenu--;
				}
			}else{
				printf("Aun no cargaste ningun empleado.\n");
			}
			break;
		case 4: // Informar empleados por Apellido / Nombre + Total y Promedio de salarios + Cant empleados salario > Promedio
			if(flagMenu)
			{
				utn_getInt(&subMenu, "Elija el orden a Informar (Desc = 2 / Ascen = 1)", "ERROR. Opcion invalida.\n", 1, 2, 5);
				sortEmployees(factory, FACTORY_LEN, subMenu);
				printEmployees(factory, FACTORY_LEN);
				calculateAverAndTotalSalary(factory, FACTORY_LEN, &promedioSalario, &totalSalario);
				empleadosArribaPromedio = countMaxAvarangeSalary(factory, FACTORY_LEN, &promedioSalario);
				printf("\nEl total de Salarios registados es: %d", totalSalario);
				printf("\nEl promedio de los salarios es de %.2f: ", promedioSalario);
				printf("\nLa cantidad de Empleados que supera el promedio es de %d\n",empleadosArribaPromedio);
			}else{
				printf("Aun no cargaste ningun empleado.\n");
			}
			break;
		case 5: // Salir
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
		system("pause");
		system("cls");
	}while (salir == 'n');
	return EXIT_SUCCESS;
}
