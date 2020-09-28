/*
 * ArrayEmployees.h
 *
 *  Created on: 23 sep. 2020
 *      Author: User
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define LONG_ARRAY 51

typedef struct{
	int id;
	char name[LONG_ARRAY];
	char lastName[LONG_ARRAY];
	float salary;
	int sector;
	int isEmpty;
} Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Employee*: Pointer to array of employees
 * \param len int Array: length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len);

/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array length
 * \param id int: ID of employee
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee *list, int len, int id);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*: Pointer to array of employees
 * \param len int: Array lenght
 * \param id int: ID of the employee
 * \param name[] char: Array with employee name
 * \param lastName[] char: Array with employee lastname
 * \param salary float: Array with employee salary
 * \param sector int: Array with employee sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/**
 * @brief ask the usert to put the array data
 * @param list: Pointer to array of employees
 * @param len: Array lenght
 * @param nextID: Pointer to the Next ID
 * @return Return -1 if Error [No free space or error with addEmployee]. Returns 0 if OK
 */
int chargeDataEmployee(Employee *list,int len, int *nextID);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array lenght
 * \param id int: ID of employee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee*: Pointer to array of employees
 * \param len int: Array lenght
 * \param order int [1] indicate DESC - [2] indicate ASC
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @brief: Print one employee info
 * @param list: Pointer to array of employee
 */
void printOneEmployee (Employee list);

/** \brief print the content of employees array
 * \param list Employee*: Pointer to array of employee
 * \param length int: Array lenght
 * \return Return (-1) if Error [No print] - (0) if Ok
 */
int printEmployees(Employee* list, int length);

/**
 * @brief: Returns the total of salarys and the avarange
 * @param list: Pointer to array of employee
 * @param len: Array lenght
 * @param pPromedio: Pointer to Averange of salarys
 * @param pTotal: Pointer to total of salarys
 * @return
 */
int calculateAverAndTotalSalary (Employee* list, int len, float* pPromedio, int* pTotal);

/**
 * @brief: Count the total of employees up to the Averange of salary
 * @param list: Pointer to array of employee
 * @param len: Array lenght
 * @param pPromedio: Pointer to Averange of salarys
 * @return: Returns the total of employees upper of tha Averange of salary
 */
int countMaxAvarangeSalary (Employee* list, int len, float* pPromedio);

/**
 * @brief: Modify the employee info
 * @param list: Pointer to array of employee
 * @param len: Array lenght
 * @return: Exit_success
 */
int modifyEmployee(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
