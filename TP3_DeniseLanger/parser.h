#ifndef PARSER_H_
#define PARSER_H_

/**
 * \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*: Ruta del archivo a cargar
 * \param pArrayListEmployee: LinkedList
 * \return int -1 en caso de error. 0 en caso de exito
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/**
 * \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*: Ruta del archivo a cargar
 * \param pArrayListEmployee:LinkedList
 * \return int -1 en caso de error. 0 en caso de exito
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
