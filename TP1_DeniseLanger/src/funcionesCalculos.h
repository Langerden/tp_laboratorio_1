#ifndef FUNCIONESCALCULOS_H_INCLUDED
#define FUNCIONESCALCULOS_H_INCLUDED


/** \brief Pide dos numeros decimales y realiza la suma entre ellos.
 *
 * \param float primerNumero: Es el parametro para el primer numero que ingresa el usuario
 * \param float segundoNumero: Es el parametro para el segundo numero que ingresa el usuario
 * \param float* pTotal: Es el parametro de la direccion de memoria que recibe de una variable tipo float
 *
 * \return El valor decimal de la suma entre el primerNumero y el segundoNumero, asignado a la direccion de memoria de pTotal
 */
float sumar (float primerNumero, float segundoNumero, float* pTotal);

/** \brief Pide dos numeros decimales y realiza la resta entre ellos.
 *
 * \param float primerNumero Es el parametro para el primer numero que ingresa el usuario
 * \param float segundoNumero Es el parametro para el segundo numero que ingresa el usuario
 * \param float* pTotal Es el parametro de la direccion de memoria que recibe de una variable tipo float
 *
 * \return El valor decimal de la resta entre el primerNumero y el segundoNumero, asignado a la direccion de memoria de pTotal
 */
float restar (float primerNumero, float segundoNumero, float* pTotal);


/** \brief Pide dos numeros decimales y realiza la division entre ellos siempre que segundoNumero sea diferente de cero.
 *
 * \param float primerNumero Es el parametro para el primer numero que ingresa el usuario
 * \param float segundoNumero Es el parametro para el segundo numero que ingresa el usuario
 * \param float* pTotal Es el parametro de la direccion de memoria que recibe de una variable tipo float
 *
 * \return El valor decimal de la division entre primerNumero y segundoNumero, asignado a la direccion de memoria de pTotal. En caso de segundoNumero = 0, devuelve -1
 */
float dividir (float primerNumero, float segundoNumero, float* pTotal);


/** \brief Pide dos numeros decimales y realiza la multiplicacion entre ellos.
 *
 * \param float primerNumero Es el parametro para el primer numero que ingresa el usuario.
 * \param float segundoNumero Es el parametro para el segundo numero que ingresa el usuario.
 * \param float* pTotal Es el parametro de la direccion de memoria que recibe de una variable tipo float
 *
 * \return El valor decimal de la multiplicacion entre primerNumero y segundoNumero, asignado a la direccion de memoria de pTotal.
 */
float multiplicar (float primerNumero, float segundoNumero, float* pTotal);

/** \brief Calcula el factorial de un numero float, devolviendolo en int.
 *
 * \param float numeroUsuario Es el parametro del numero que ingresa el usuario.
 *
 * \return Si el numeroUsuario es negativo o vale cero, devuelve -1. En caso de numeroUsuario ser un numero positivo me retorna el valor entero del factorial de numeroUsuario.
 */

int factorial (float numeroUsuario);

#endif // FUNCIONESCALCULOS_H_INCLUDED
