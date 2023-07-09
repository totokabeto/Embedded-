/*
* File: Manager.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file create the class manager 
*/
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <list> 
#include "Dish.hpp"

using namespace std;
/**********************************Class Manager*********************************/
class Manager{
    private: 
     /* data */
    int numberOfTable;
    void addDish();
    void editDish();
    void deleteDish(); 
    void displayDishList();

    void setNumberOfTable();
    public:
    Manager();
    list<Dish> dishListData;
    void managerMenu();

    list<Dish> getDishListData();
    int getNumberOfTable(); 
}; 

#endif