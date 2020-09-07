#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Pedido_datos.h"

int menu(int flag1, int flag2, float num1, float num2){
	int opcion = 0;

	if(flag1 && !flag2){
		printf("1 - Ingresar 1er operando (A=%.2f)\n",num1);
		printf("2 - Ingresar 2do operando (B=y)\n");
		printf("3 - Calcular todas las operaciones.\n");
		printf("	a) Calcular la suma (%.2f+B)\n",num1);
		printf("	b) Calcular la resta (%.2f-B)\n",num1);
		printf("	c) Calcular la division (%.2f/B)\n",num1);
		printf("	d) Calcular la multiplicacion (%.2f*B)\n",num1);
		printf("	e) Calcular el factorial (%.2f!)\n",num1);
		printf("	f) Calcular el factorial (B!)\n");
		printf("4 - Informar resultados \n");
		printf("5 - Salir \n");

	}else if (flag2){
		printf("1 - Ingresar 1er operando (A=%.2f)\n",num1);
		printf("2 - Ingresar 2do operando (B=%.2f)\n",num2);
		printf("3 - Calcular todas las operaciones.\n");
		printf("	a) Calcular la suma (%.2f+%.2f)\n",num1,num2);
		printf("	b) Calcular la resta (%.2f-%.2f)\n",num1,num2);
		printf("	c) Calcular la division (%.2f/%.2f)\n",num1,num2);
		printf("	d) Calcular la multiplicacion (%.2f*%.2f)\n",num1,num2);
		printf("	e) Calcular el factorial (%.2f!)\n",num1);
		printf("	f) Calcular el factorial (%.2f!)\n",num2);
		printf("4 - Informar resultados \n");
		printf("5 - Salir \n");
	}else{
		printf("1 - Ingresar 1er operando (A=x)\n");
		printf("2 - Ingresar 2do operando (B=y)\n");
		printf("3 - Calcular todas las operaciones.\n");
		printf("	a) Calcular la suma (A+B)\n");
		printf("	b) Calcular la resta (A-B)\n");
		printf("	c) Calcular la division (A/B)\n");
		printf("	d) Calcular la multiplicacion (A*B)\n");
		printf("	e) Calcular el factorial (A!)\n");
		printf("	f) Calcular el factorial (B!)\n");
		printf("4 - Informar resultados \n");
		printf("5 - Salir \n");
	}
	printf("Opcion: ");
	scanf("%d",&opcion);

	return opcion;
}

float inputNumero(int *flag, char charNumber){
	float numero;

	printf("Ingrese el valor de %c: ",charNumber);
	scanf("%f", &numero);
	*flag = 1;

	return numero;
}
