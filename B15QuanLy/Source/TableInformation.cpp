/*
* File: TableInformation.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file including all of the table information class methods and constructors  
*/
#include "..\Header\TableInformation.hpp"
#include "..\Header\global.hpp"

tableInformation::tableInformation(int tableIndex, bool tableStatus){
    this->tableIndex = tableIndex;
    this->tableStatus = tableStatus;
}

tableInformation::tableInformation(int tableIndex, bool tableStatus, Dish dish, int numberOfRation){
    tableInformation::tableIndex = tableIndex;
    tableInformation::tableStatus = tableStatus;
    tableInformation::dish = dish; 
    tableInformation::numberOfRation = numberOfRation;
}
/*
* Class: tableInformation
* Function: setNumberOfRation
* Description: This function use for setting the number of ration
* Input:
*   numberOfRation - number of ration
* Output:
*   return: none
*/
void tableInformation::setNumberOfRation(int numberOfRation){
    tableInformation::numberOfRation = numberOfRation;
}
/*
* Class: tableInformation
* Function: getNumberOfRation
* Description: This function use for getting the number of ration
* Input:
*   none
* Output:
*   return: numberOfRation - number of ration
*/
int tableInformation::getNumberOfRation(){
    return tableInformation::numberOfRation;
}
/*
* Class: tableInformation
* Function: getDishID
* Description: This function use for getting the ID of dish
* Input:
*   none
* Output:
*   return: dish ID
*/
int tableInformation::getDishID(){
    return dish.getDishID();
}
/*
* Class: tableInformation
* Function: getDishName
* Description: This function use for getting the name of dish
* Input:
*   none
* Output:
*   return: dish name
*/
string tableInformation::getDishName(){
    return dish.getDishName(); 
}
/*
* Class: tableInformation
* Function: getDishPrice
* Description: This function use for getting the price of dish
* Input:
*   none
* Output:
*   return: dish price
*/
double tableInformation::getDishPrice(){
    return dish.getDishPrice(); 
}
/*
* Class: tableInformation
* Function: getTableIndex
* Description: This function use for getting the index of table
* Input:
*   none
* Output:
*   return: table index
*/
int tableInformation::getTableIndex(){
    return tableInformation::tableIndex; 
}
/*
* Class: tableInformation
* Function: setTableStatus
* Description: This function use for setting the status of table
* Input:
*   none
* Output:
*   none
*/
void tableInformation::setTableStatus(){
    this->tableStatus = !this->tableStatus; 
}
/*
* Class: tableInformation
* Function: getTableStatus
* Description: This function use for getting the status of table
* Input:
*   none
* Output:
*   return : ableStatus - the status of table  
*/
bool tableInformation::getTableStatus(){
    return tableInformation::tableStatus; 
}
