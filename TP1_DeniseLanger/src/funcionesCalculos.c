#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funcionesCalculos.h"

float sumar(float primerNumero, float segundoNumero, float *pTotal) {
	*pTotal = primerNumero + segundoNumero;
	return *pTotal;
}
float restar(float primerNumero, float segundoNumero, float *pTotal) {
	*pTotal = primerNumero - segundoNumero;
	return *pTotal;
}
float dividir(float primerNumero, float segundoNumero, float *pTotal) {
	if (segundoNumero != 0) {
		*pTotal = primerNumero / segundoNumero;
	} else {
		*pTotal = -1;
	}
	return *pTotal;
}
float multiplicar(float primerNumero, float segundoNumero, float *pTotal) {
	*pTotal = primerNumero * segundoNumero;
	return *pTotal;
}

long int factorial(float numeroUsuario)
{
	long int resultado;
	if(numeroUsuario <= 1 || numeroUsuario>12){
		resultado = -1;
	}
	else{
		resultado = numeroUsuario;
				for (int i = numeroUsuario - 1; i >= 1; i--)
				{
					resultado *= i;
				}
	}

	return resultado;
}

