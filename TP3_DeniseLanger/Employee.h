#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/**
 * @brief  Pide memoria con malloc
 * @return Puntero a Employee
 */
Employee* employee_new();

/**
 * @brief Carga los campos de un Employee (Setters) pasados por parametro
 * @param idStr: ID del employee (String)
 * @param nombreStr: Nombre del employee
 * @param horasTrabajadasStr: Horas trabajadas del employee (string)
 * @param sueldoStr: Sueldo del employee (string)
 * @return Puntero a Employee
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @brief Elimina los datos de un Employee
 * @param this: puntero a Employee
 */
void employee_delete(Employee* this);

/**
 * @brief : Busca un Employee por ID
 * @param this: Linkedlist
 * @param idEmployee: Id a buscar en la lista
 * @return: retorna el index del Employee en caso de existir
 */
int employee_SearchByID(LinkedList* this, int idEmployee);

/**
 * @brief Imprime los datos de un Employee
 * @param this: Puntero a Employee
 */
void employee_listEmployee(Employee* this);

/**
 * @brief Ordena Employees segun criterio (Campos del Employee) y orden (ASC / DESC)
 * @param pArrayListEmployee: Linkedlist
 * @return: -1 en caso de error. 0 en caso de exito y 1 en caso de exit
 */
int employee_sortEmployee(LinkedList *pArrayListEmployee);

/**
 * @brief Compara los ID de dos Employee
 * @param firstEmployee: Puntero al primer empleado
 * @param secondEmployee: Puntero al segundo empleado
 * @return 1 si el ID del 1°Employee > 2°Employee, -1 si es < y 0 si son =
 */
int employee_sortById(void* firstEmployee, void* secondEmployee);

/**
 * @brief Compara los Nombres de dos Employee (strcmp)
 * @param firstEmployee: Puntero al primer empleado
 * @param secondEmployee: Puntero al segundo empleado
 * @return 1 si el nombre del 1°Employee esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int employee_sortByName(void* firstEmployee, void* secondEmployee);

/**
 * @brief Compara las Horas de dos Employee
 * @param firstEmployee: Puntero al primer empleado
 * @param secondEmployee: Puntero al segundo empleado
 * @return: 1 si las Horas Trabajadas del 1°Employee > 2°Employee, -1 si es < y 0 si son =
 */
int employee_sortByHours(void* firstEmployee, void* secondEmployee);

/**
 * @brief Compara los Salarios de dos Employee
 * @param firstEmployee: Puntero al primer empleado
 * @param secondEmployee: Puntero al segundo empleado
 * @return 1 si el Salario del 1°Employee > 2°Employee, -1 si es < y 0 si son =
 */
int employee_sortBySalary(void* firstEmployee, void* secondEmployee);

/**
 * @brief Carga el ID del Employee en el puntero que se pasa por parametro
 * @param this: Puntero a Employee
 * @param id: ID que se quiere cargar
 * @return -1 en caso de error. 0 en caso de exito
 */
int employee_setId(Employee* this,int id);

/**
 * @brief Obtiene el ID del Employee (pasado por parametro)
 * @param this: Puntero a Employee
 * @param id: puntero a un int donde se carga el ID
 * \return -1 en caso de error. 0 en caso de exito
 */
int employee_getId(Employee* this,int* id);

/**
 * @brief Recorre el Linkedlist y retorna el ultimo ID registrado
 * @param pArrayListEmployee: Linkedlist
 * @return -1 en caso de error. Sino retorna el valor del ultimo ID
 */
int employee_lastId(LinkedList* pArrayListEmployee);

/**
 * @brief Carga el Nombre del Employee en el puntero que se pasa por parametro
 * @param this: Puntero a Employee
 * @param nombre: Nombre a cargar
 * @return -1 en caso de error. 0 en caso de exito
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @brief Obtiene el Nombre del Employee (pasado por parametro)
 * @param this: Puntero a Employee
 * @param nombre: puntero a char donde se carga el Nombre
 * \return -1 en caso de error. 0 en caso de exito
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @brief Carga las Horas Trabajadas del Employee en el puntero que se pasa por parametro
 * @param this: Puntero a Employee
 * @param horasTrabajadas: Horas Trabajadas que se quiere cargar
 * @return -1 en caso de error. 0 en caso de exito
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @brief Obtiene las Horas Trabajadas del Employee (pasado por parametro)
 * @param this: Puntero a Employee
 * @param horasTrabajadas: puntero a un int donde se cargan las Horas Trabajadas
 * \return -1 en caso de error. 0 en caso de exito
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief Carga el Sueldo del Employee en el puntero que se pasa por parametro
 * @param this: Puntero a Employee
 * @param sueldo: Sueldo que se quiere cargar
 * @return -1 en caso de error. 0 en caso de exito
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @brief Obtiene el Sueldo del Employee (pasado por parametro)
 * @param this: Puntero a Employee
 * @param sueldo: puntero a un int donde se carga el Sueldo
 * @return -1 en caso de error. 0 en caso de exito
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
