/*
* File: global.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file listing enumerate of the program 
*/
#ifndef GLOBAL_HPP
#define GLOBAL_HPP

typedef enum{
    MANAGER = 1,
    EMPLOYEE, 
}SelectionChoice;

typedef enum{
    RETURN,
    ADDDISH,
    EDITDISH,
    DELETEDISH,
    LISTSHOW,
    SETTABLENUM,
}ManagerMenuChoice;

typedef enum{
    CONTINUE,
    BACK,
}MiniMenuChoice;
    
typedef enum{
    ORDER = 1,
    EDITORDER,
    DELETEORDER,
    DISHSHOW,
    PAYMENT,
}EmployeeMenuChoice; 

typedef enum{
    EDITNAME = 1,
    EDITPRICE,
}EditMenuChoice; 

#endif