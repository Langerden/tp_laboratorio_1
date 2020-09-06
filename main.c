#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesCalculos.h"

int main()
{
	setbuf(stdout, NULL);
	//declaro variables del main
	char seguir = 'y';
	int opcion = 0;
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
		printf("1- Ingresar el primer numero (A) \n");
		printf("2- Ingresar el segundo numero (B)\n");
		printf("3- Calcular las operaciones \n");
		printf("4- Informar resultados \n");
		printf("5- Salir \n");
		scanf("%d", &opcion);

		while(opcion == 0 || opcion > 5){
			printf("ERROR. Opcion del menu invalida, reingrese\n 1-Ingresar 1° numero\n 2-Ingresar 2° numero\n 3-Calcular operaciones matematicas\n 4-Mostrar resultados\n 5-Salir\n");
			scanf("%d", &opcion);
		}

		switch (opcion)
		{
		//se ingresa el primer numero
		case 1:
			printf("Ingrese el valor de A: ");
			scanf("%f", &nroA);
			validarNroA = 1;
			break;
		//se ingresa el segundo numero
		case 2:
			printf("Ingrese el valor de B: ");
			scanf("%f", &nroB);
			validarNroB = 1;
			break;
		//se calculan las operaciones matematicas (suma, resta, division, multiplicacion y el factorial de nroA y nroB) con los numeros ingresados por el usuario
		case 3:
			if (validarNroA == 1 && validarNroB == 1)//verificar que hayan ingresado los numeros
				{
					rtaSuma = sumar(nroA, nroB, &rtaSuma);
					rtaResta = restar(nroA, nroB, &rtaResta);
					rtaDivision = dividir(nroA, nroB, &rtaDivision);
					rtaMultiplicacion = multiplicar(nroA, nroB, &rtaMultiplicacion);
					factorialA = factorial(nroA);
					factorialB = factorial(nroB);
					validarCalculos = 1;
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

				if (factorialA == 1) {
					//si nroA es cero o un numero negativo muestro un mensaje de error
					printf(
							"\n E- ERROR. No se puede calcular el factorial de %.2f\n",nroA);
				} else {
					//imprimo el resultado del factorial de nroA si es != de 0 y no es negativo
					printf("\n E- El factorial de %.2f es: %ld \n", nroA,factorialA);
				}

				if (factorialB == 1) {
					//si nroB es cero o un numero negativo muestro un mensaje de error
					printf(
							"F- ERROR. No se puede calcular el factorial de %.2f\n",nroB);
				} else {
					//imprimo el resultado del factorial de nroB si es != de 0 y no es negativo
					printf(" F- El factorial de %.2f es: %ld \n", nroB,factorialB);
				}

				system("pause");
				system("cls");
			} else {
				printf("No se ingresaron los valores de A y B. REINTENTE\n");
			}
			break;
		case 5:
			seguir = 'n';
			break;
		}
	} while (seguir == 'y');
	return 0;
}


