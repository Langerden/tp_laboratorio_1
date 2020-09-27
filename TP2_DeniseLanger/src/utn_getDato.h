#ifndef UTN_GETDATO_H_
#define UTN_GETDATO_H_

/**
 * @brief Lee de stdin hasta que encuentra un \n o hasta que haya copiado en cadena un
 * 		  maximo de 'largo -1' caracteres
 * @param cadena
 * @param largo
 * @return
 */

int utn_myGets (char* cadena, int largo);

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
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el numero devuelve 1
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
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el float devuelve 1
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
 * @return Devuelve -1 si no hay mas reintentos. Si ingresa bien el char devuelve 1
 */

int utn_getChar(char* pResultado,char* mensaje,char* msjError,char min, char max, int reintentos);

int menu();


int IsFloat (char* cadena, int largo);

int getInt (int* bufferInt);

int isNumber (char* cadena, int largo);
int getFloat (float* bufferFloat);
int isName (char* cadena,int largo);
void formatName(char* string);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);








#endif /* UTN_GETDATO_H_ */
