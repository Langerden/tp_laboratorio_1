/*
 ============================================================================
 Name        : TP1_DeniseLanger.c
 Author      : Denise_Langer
 Version     :
 Copyright   : TP_Laboratorio_1
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesCalculos.h"
#include "Pedido_datos.h"

int main()
{
	setbuf(stdout, NULL);
	//declaro las variables del main
	char seguir = 'n';
	float nroA;
	float nroB;
	float rtaSuma;
	float rtaResta;
	float rtaDivision;
	float rtaMultiplicacion;
	long int factorialA = 0;
	long int factorialB = 0;
	int validarNroA = 0;
	int validarNroB = 0;
	int validarCalculos = 0;

	do
	{
		//opciones del menu

		switch (menu(validarNroA, validarNroB, nroA, nroB))
		{
		//se ingresa el primer numero
		case 1:
			nroA = inputNumero(&validarNroA, 'A');
			break;
		//se ingresa el segundo numero
		case 2:
			if(validarNroA){
				nroB = inputNumero(&validarNroB, 'B');
			}else{
				printf("Ingrese primero el valor de A\n");
			}

			break;
		//se calculan las operaciones matematicas (suma, resta, division, multiplicacion y el factorial de nroA y nroB) con los numeros ingresados por el usuario
		case 3:
			if (validarNroA == 1 && validarNroB == 1)//verificar que hayan ingresado los numeros
				{
					printf("Loading....\n");
					rtaSuma = sumar(nroA, nroB, &rtaSuma);
					rtaResta = restar(nroA, nroB, &rtaResta);
					rtaDivision = dividir(nroA, nroB, &rtaDivision);
					rtaMultiplicacion = multiplicar(nroA, nroB, &rtaMultiplicacion);
					factorialA = factorial(nroA);
					factorialB = factorial(nroB);
					validarCalculos = 1;
				}else{
					printf("Falta al menos un operando.\n");
				}
			break;
		//muestro en pantalla los resultados
		case 4:
			if (validarCalculos == 1)
			{
				printf("\n A- La suma de %.2f y %.2f es: %.2f", nroA, nroB,rtaSuma);
				printf("\n B- La resta de %.2f y %.2f es: %.2f", nroA, nroB, rtaResta);

				if (rtaDivision == -1)
				{
					//en caso de nroB = 0 imprimo que no es posible hacer el calculo
					printf("\n C- No es posible dividir por cero");
				} else {
					//imprimo el resultado de la division
					printf("\n C- La division de %.2f y %.2f es: %.2f ", nroA, nroB, rtaDivision);
				}
				printf("\n D- La multiplicacion de %.2f y %.2f es: %.2f", nroA,nroB, rtaMultiplicacion);

				if (factorialA == -1) {
					//si nroA es cero o un numero negativo muestro un mensaje de error
					printf(
							"\n E- ERROR. No se puede calcular el factorial de %.2f\n",nroA);
				} else {
					//imprimo el resultado del factorial de nroA si es != de 0 y no es negativo
					printf("\n E- El factorial de %.2f es: %ld \n", nroA,factorialA);
				}

				if (factorialB == -1) {
					//si nroB es cero o un numero negativo muestro un mensaje de error
					printf(
							"F- ERROR. No se puede calcular el factorial de %.2f\n",nroB);
				} else {
					//imprimo el resultado del factorial de nroB si es != de 0 y no es negativo
					printf(" F- El factorial de %.2f es: %ld \n", nroB,factorialB);
				}


			} else {
				printf("No se puede mostrar los resultado porque no se hicieron las operaciones\n");
			}
			break;
		case 5:
			printf("Queres salir? y/n \n");
			fflush(stdin);
			scanf("%c",&seguir);
			if(seguir=='n'){
				validarCalculos = 0;
				validarNroA = 0;
				validarNroB = 0;
			}
			break;
		default:
			printf("Opcion incorrecta.\n");
			break;
		}
		system("cls");
	} while (seguir == 'n');
	return 0;
}
