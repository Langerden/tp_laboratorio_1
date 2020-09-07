/*
 * Pedido_datos.h
 *
 *  Created on: 7 sep. 2020
 *      Author: Usuario
 */

#ifndef PEDIDO_DATOS_H_
#define PEDIDO_DATOS_H_

/**
 * @brief	Muestra el menu de opciones al usuario.
 * @param flag1 Validacion del primer numero.
 * @param flag2 Validacion del segundo numero.
 * @param num1 Primer operando ingresado por el usuario.
 * @param num2 Segundo operando ingresado por el usuario.
 * @return Retorna la opcion elegida por el usuario.
 */
int menu(int flag1, int flag2, float num1, float num2);

/**
 * @brief Pide un numero al usuario y Valida el ingreso
 * @param flag Retorna 1 si se ingreso el dato
 * @param charNumber Letra de referencia
 * @return Retorna el numero ingresado del usuario
 */
float inputNumero(int *flag, char charNumber);

#endif /* PEDIDO_DATOS_H_ */
