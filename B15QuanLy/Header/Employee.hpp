/*
* File: Employee.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file create the class employee 
*/
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream> 
#include "Dish.hpp"
#include "TableInformation.hpp"

using namespace std; 
/**********************************Class Employee*********************************/
class Employee{
    /* data */
    private: 
    list<Dish> dishListData;
    list<tableInformation> tableNumberStatus;
    list<tableInformation> tableOrderList; 
    void addDish(list<Dish> dishListData , tableInformation &ttableIndex);
    void editDish();
    void deleteDish();
    void Payment(tableInformation &ttableIndex); 
    public: 
    Employee();
    void employeeMenu(list<Dish> dishListData, int iNumberOfTable);
    void displayTableOrderInfo(tableInformation &ttableIndex);

    void getTableOrdered();
}; 

#endif