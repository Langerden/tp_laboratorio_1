#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funcionesCalculos.h"

float sumar (float primerNumero, float segundoNumero, float* pTotal){
    *pTotal = primerNumero + segundoNumero;
    return *pTotal;
}
float restar (float primerNumero, float segundoNumero, float* pTotal){
    *pTotal = primerNumero - segundoNumero;
    return *pTotal;
}
float dividir (float primerNumero, float segundoNumero, float* pTotal){
    if (segundoNumero != 0)
    {
        *pTotal = primerNumero / segundoNumero;
    } else {
        *pTotal = -1;
    }
    return *pTotal;
}
float multiplicar (float primerNumero, float segundoNumero, float* pTotal){
    *pTotal = primerNumero * segundoNumero;
    return *pTotal;
}

int factorial (float numeroUsuario)
{
	int resultado = -1;
    int numeroInt;
    int i;

    numeroInt = (int)numeroUsuario;

    if (numeroInt > 0)
        {
    	resultado = numeroInt;
        for (i = numeroInt-1; i >= 1; i --)
            {
        	resultado *= i;
            }
        }
    return resultado;
}
