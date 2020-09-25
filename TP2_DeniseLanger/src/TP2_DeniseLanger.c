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
#include "utn_getDato.h"
#include "ArrayEmployees.h"
#define FACTORY_LEN 10



int main(void) {
	setbuf(stdout, NULL);
	int flagMenu = 1;
	char salir = 'n';
	//int proximoLegajo = 1;

	//Employee factory[FACTORY_LEN];

	do
	{
		switch(menu())
		{
		case 1: //Ingresar un empleado
			// funcion para dar de alta
			//chargeData(factory, FACTORY_LEN, proximoLegajo);
			flagMenu = 0;
			break;
		case 2: //Ingresar ID y modificar Nombre, Apellido, Salario o Sector
			if(!flagMenu){
				//modificar
			}else{
				printf("Aun no cargaste ningun empleado.");
			}
			break;
		case 3: // Ingresar ID y eliminar empleado
			if(!flagMenu){
				//eliminar
			}else{
				printf("Aun no cargaste ningun empleado.");
			}
			break;
		case 4: // Informar empleados por Apellido / Nombre + Total y Promedio de salarios + Cant empleados salario > Promedio
			if(!flagMenu){
				//informar
			}else{
				printf("Aun no cargaste ningun empleado.");
			}
			break;
		case 5:
			printf("¿Desea salir? Y/N: \n");
			fflush(stdin);
			scanf("%c",&salir);
			break;
		default:
		printf("Opcion incorrecta.\n");
		break;
		}
		flagMenu = 1;
		system("cls");
	}while (salir == 'n');
	return EXIT_SUCCESS;
}
