#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/**
 * \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*: path al archivo a cargar
 * \param pArrayListEmployee LinkedList*: likedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path char*: path al archivo a cargar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Baja de empleado
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Listar empleados
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_listEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito y 1 en caso de salir del submenu
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*: path al archivo a guardar
 * \param pArrayListEmployee LinkedList*: linkedlist
 * \return int: -1 en caso de error. 0 en caso de exito
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
