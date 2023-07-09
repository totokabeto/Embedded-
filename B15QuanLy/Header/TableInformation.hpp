/*
* File: TableInformation.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file create the class table information 
*/
#ifndef TABLEINFORMATION_HPP
#define TABLEINFORMATION_HPP

#include <iostream> 
#include "Dish.hpp"
using namespace std; 


/**********************************Class tableInformation*********************************/
class tableInformation{
private:  
    /* data */
    int tableIndex;
    bool tableStatus;
    Dish dish; 
    int numberOfRation; 
public:
    tableInformation(int tableIndex, bool tableStatus , Dish dish, int numberOfRation); 
    tableInformation(int tableIndex, bool tableStatus);
    void setNumberOfRation(int numberOfRation);
    void setTableStatus();

    int getDishID();
    int getTableIndex(); 
    bool getTableStatus();
    int getNumberOfRation();  
    string getDishName(); 
    double getDishPrice(); 
    int getNumberOfTable(); 

}; 

#endif