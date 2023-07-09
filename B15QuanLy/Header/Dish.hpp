/*
* File: Dish.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file create the class dish 
*/
#ifndef DISH_HPP
#define DISH_HPP

#include <iostream>
#include <list> 

using namespace std; 
/**********************************Class Dish*********************************/
class Dish{
    /* data */
    private: 
    uint8_t id; 
    string dishName;
    double dishPrice;
    public: 
    Dish(string strDishName, double dDishPrice); 
    Dish(); 
    void setDishName(string strDishName); 
    void setDishPrice(double dDishPrice); 

    int getDishID(); 
    string getDishName(); 
    double getDishPrice(); 
    void getDishList();
   
}; 
#endif