#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_getDato.h"

int main()
{
    int option;
    int flagTxt = 0;
    int flagBin = 0;
    char salir = 'N';

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    option = menu();
        switch(option)
        {
            case 1: //Cargar los datos desde data.csv (modo texto).
            	if(flagBin != 1 && flagTxt == 0)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados) == 0)
            		{
            			flagTxt = 1;
            		}
            	} else {
            		printf("El archivo ya fue cargado\n");
            	}
				break;
            case 2: //Cargar los datos desde data.bin (modo binario).
            	if(flagTxt != 1 && flagBin == 0)
            	{
            		if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
            		{
            			flagBin = 1;
            		}
            	} else {
            		printf("El archivo ya fue cargado\n");
            	}
            	break;
            case 3: //Alta de empleado
            	if(flagBin || flagTxt)
            	{
            		controller_addEmployee(listaEmpleados);
            	} else {
            		printf("Aun no se cargo ningun archivo\n");
            	}
            	break;
            case 4: //Modificar datos de empleado
            	if(flagBin || flagTxt)
				{
					controller_editEmployee(listaEmpleados);
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 5: //Baja de empleado
            	if(flagBin || flagTxt)
				{
            		controller_removeEmployee(listaEmpleados);
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 6: //Listar empleados
            	if(flagBin || flagTxt)
				{
            		controller_listEmployee(listaEmpleados);
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 7: //Ordenar empleados
            	if(flagBin || flagTxt)
				{
            		if(controller_sortEmployee(listaEmpleados) == 0)
            		{
            			controller_listEmployee(listaEmpleados);
            		}
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 8: //Guardar los datos en el archivo data.csv (modo texto).
            	if(flagBin || flagTxt)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 9: //Guardar los datos en el archivo data.bin (modo binario).
            	if(flagBin || flagTxt)
				{
					controller_saveAsBinary("data.bin", listaEmpleados);
				} else {
					printf("Aun no se cargo ningun archivo\n");
				}
				break;
            case 10: //Salir
            	utn_getChar(&salir,"¿Confirma Salir? (Y/N): " , "ERROR: OPCION NO VALIDA\n", 'N', 'Y', 10);
            	if(salir == 'Y')
            	{
            		ll_deleteLinkedList(listaEmpleados);
            	}
            	break;
        }
		system("pause");
		system("cls");
    }while(salir == 'N');
    return 0;
}

