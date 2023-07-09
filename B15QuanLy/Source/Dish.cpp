/*
* File: Dish.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file including all of the dish class methods and constructors  
*/
#include "..\Header\Dish.hpp"

Dish::Dish(){}

void Dish::getDishList(){
    cout << "ID: " << (unsigned short)Dish::id << endl; 
    cout << "Dish name : " << Dish::dishName << endl; 
    cout << "Price tag : "<< Dish::dishPrice << " $ " << endl; 
}
Dish::Dish(string strDishName, double dDishPrice){
    static int id = 100; 
    this->id = id; 
    id++; 
    this->dishName = strDishName; 
    this->dishPrice = dDishPrice; 
}
/*
* Class: Dish
* Function: setDishName
* Description: This function use for set name of a dish
* Input:
*   strDishName - name of a dish
* Output:
*   return : none
*/
void Dish::setDishName(string strDishName){
    Dish::dishName = strDishName; 
}
/*
* Class: Dish
* Function: setDishPrice
* Description: This function use for set price of a dish
* Input:
*   strDishName - price of a dish
* Output:
*   return : none
*/
void Dish::setDishPrice(double dDishPrice){
    Dish::dishPrice = dDishPrice; 
}
/*
* Class: Dish
* Function: getDishID
* Description: This function use for get ID of a dish
* Input:
*   none
* Output:
*   return: id - id of a dish
*/
int Dish::getDishID(){
    return this->id;
}
/*
* Class: Dish
* Function: getDishName
* Description: This function use for get name of a dish
* Input:
*   none
* Output:
*   return: dishName - name of a dish
*/
string Dish::getDishName(){
    return Dish::dishName; 
}
/*
* Class: Dish
* Function: getDishPrice
* Description: This function use for get price of a dish
* Input:
*   none
* Output:
*   return: dishPrice - price of a dish
*/
double Dish::getDishPrice(){
    return Dish::dishPrice; 
}
