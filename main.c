#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesCalculos.h"

int main()
{
	setbuf(stdin, NULL);
//declaro variables del main
    char seguir='y';
    int opcion = 0;
    float nroA;
    float nroB;
    float rtaSuma;
    float rtaResta;
    float rtaDivision;
    float rtaMultiplicacion;
    long int factorialA = 0;
    long int factorialB = 0;

    do
    {
        //opciones del menu
        printf("1- Ingresar el primer numero (A) \n");
        printf("2- Ingresar el segundo numero (B)\n");
        printf("3- Calcular las operaciones \n");
        printf("4- Informar resultados \n");
        printf("5- Salir \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            //se ingresa el primer numero
            case 1:
                printf("Ingrese el valor de A: ");
                scanf("%f", &nroA);
                break;

            //se ingresa el segundo numero
            case 2:
                printf("Ingrese el valor de B: ");
                scanf("%f", &nroB);
                break;

            //se calculan las operaciones matematicas (suma, resta, division, multiplicacion y el factorial de nroA y nroB) con los numeros ingresados por el usuario
            case 3:
                rtaSuma = sumar(nroA, nroB, &rtaSuma);
                rtaResta = restar(nroA, nroB, &rtaResta);
                rtaDivision = dividir(nroA, nroB, &rtaDivision);
                rtaMultiplicacion = multiplicar (nroA, nroB, &rtaMultiplicacion);
                factorialA = factorial(nroA);
                factorialB = factorial(nroB);
                break;

            //muestro en pantalla los resultados
            case 4:
                printf("\n A- La suma de A y B es: %.2f", rtaSuma);
                printf("\n B- La resta de A y B es: %.2f", rtaResta);

                if(rtaDivision == -1) {
                    //en caso de nroB = 0 imprimo que no es posible hacer el calculo
                    printf("\n C- No es posible dividir por cero");
                    } else {
                    //imprimo el resultado de la division
                    printf("\n C- La division de A y B es: %.2f ", rtaDivision);
                    }

                printf("\n D- La multiplicacion de A y B es: %.2f", rtaMultiplicacion);


                if (factorialA == 0) {
                    //si nroA es cero o un numero negativo muestro un mensaje de error
                    printf("\n E- ERROR. No se puede calcular el factorial\n");
                    } else {
                    //imprimo el resultado del factorial de nroA si es != de 0 y no es negativo
                    printf("\n E- El factorial de A es: %ld \n", factorialA);
                    }


                if (factorialB == 0) {
                    //si nroB es cero o un numero negativo muestro un mensaje de error
                    printf("F- ERROR. No se puede calcular el factorial\n");
                    } else {
                    //imprimo el resultado del factorial de nroB si es != de 0 y no es negativo
                    printf(" F- El factorial de B es: %ld \n", factorialB);
                    }

                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("No se ingreso una opcion del menu valida \n");
        }
    } while(seguir == 'y');

return 0;
}


