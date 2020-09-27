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

int initEmployees(Employee* list, int len);
int findIsEmpty(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int chargeDataEmployee(Employee *list,int len, int *nextID);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
void printOneEmployee (Employee list);
void printEmployees(Employee* list, int length);
int calculateAverAndTotalSalary (Employee* list, int len, float* pPromedio, int* pTotal);
int countMaxAvarangeSalary (Employee* list, int len, float* pPromedio);
int modifyEmployee(Employee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
