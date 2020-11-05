#ifndef UTN_GETDATO_H_
#define UTN_GETDATO_H_

/**
 * @brief: Lee stdin hasta que encuentra un '\n' o hasta que haya copiado una cadena
 * 			un maximo de largo - 1 caracteres
 * @param cadena: Cadena donde se copia el dato ingresado
 * @param largo: Tamaño de la cadena
 * @return: Devuelve -1 si hubo error. Si se ingresa correctamente devuelve un 0
 */

int utn_myGets(char* cadena, int largo);

/**
 * @brief Pide un numero al usuario por mensaje.
 * Valida si el numero ingresado esta dentro de los rangos de min y max.
 * Despues de un numero de intentos, muestra un error por mensaje
 *
 * @param pResultado: Puntero que retorna el numero del usuario si esta ok
 * @param mensaje: mensaje que el usuario ve por pantalla
 * @param msjError: mensaje de error en caso de ingresar mal el numero despues de x intentos
 * @param min: Numero minimo que el usuario puede ingresar
 * @param max: Numero Maximo que el usuario puede ingresar
 * @param reintentos: Cantidad de veces que el usuario puede ingresar el numero
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el numero devuelve 0
 */

int utn_getInt(int* pResultado,char* mensaje,char* msjError,int min, int max, int reintentos);

/**
 * @brief Pide un decimal al usuario por mensaje.
 * Valida si el decimal ingresado esta dentro de los rangos de min y max.
 * Despues de un numero de intentos, muestra un error por mensaje
 *
 * @param pResultado: Puntero que retorna el float del usuario si esta ok
 * @param mensaje: mensaje que el usuario ve por pantalla
 * @param msjError: mensaje de error en caso de ingresar mal el decimal despues de x intentos
 * @param min: Decimal minimo que el usuario puede ingresar
 * @param max: Decimal Maximo que el usuario puede ingresar
 * @param reintentos: Cantidad de veces que el usuario puede ingresar el numero
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el float devuelve 0
 */

int utn_getFloat(float* pResultado,char* mensaje,char* msjError,float min, float max, int reintentos);
/**
 * @brief Pide un caracter al usuario por mensaje.
 * Valida si el char ingresado esta dentro de los rangos de min y max.
 * Despues de un numero de intentos, muestra un error por mensaje
 *
 * @param pResultado: Puntero que retorna el char del usuario si esta ok
 * @param mensaje: mensaje que el usuario ve por pantalla
 * @param msjError: mensaje de error en caso de ingresar mal el dato despues de x intentos
 * @param min: Char minimo que el usuario puede ingresar
 * @param max: Char Maximo que el usuario puede ingresar
 * @param reintentos: Cantidad de veces que el usuario puede ingresar el caracter
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el char devuelve 0
 */

int utn_getChar(char* pResultado,char* mensaje,char* msjError,char min, char max, int reintentos);

/**
 * @brief Pide un nombre al usuario y lo pone en formato Mayus y Minus
 * Verifica que este dentro de los paramentos correctos
 * Despues de un numero de intetos, muestra un error por mensaje
 *
 * @param pResultado: Puntero que retorna el nombre del usuario si esta ok
 * @param largo: El largo del array resultado
 * @param mensaje: Mensaje que el usuario ve por pantalla
 * @param msjError: Mensaje de error en caso de ingresar mal los datos
 * @param reintentos: Cantidad de veces que puede ingresar el nombre
 * @return Devuelve -1 si no hay mas intentos. Si se obtuvo el nombre, devuelve 0
 */

int utn_getName(char* pResultado, int largo ,char* mensaje, char* msjError, int reintentos);

/**
 * @brief: Imprime el Menu de opciones
 * @return: Retorna el numero que el usuario elije del menu
 */
int menu();

#endif /* UTN_GETDATO_H_ */
