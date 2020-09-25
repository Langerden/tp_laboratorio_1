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
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/

int initEmployees(Employee* list, int len);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee *list, int len, int id);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

#endif /* ARRAYEMPLOYEES_H_ */
