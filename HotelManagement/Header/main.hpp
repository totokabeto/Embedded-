/*
* File: Main.hpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the main 
*/
#ifndef MAIN_HPP
#define MAIN_HPP
/*
    Declaration of struct and enum using in the program 
*/
typedef struct{
    uint8_t second;
    uint8_t minute; 
    uint8_t hour;
}typeTime; 

typedef struct{
    uint8_t day;
    uint8_t month; 
    int year;
} typeDate; 

typedef enum {
    IN,
    OUT
}TypeStatus; 

typedef struct{
    uint8_t second;
    uint8_t minute; 
    uint8_t hour;
}TypeTime; 

typedef struct{
    uint8_t day;
    uint8_t month; 
    int year;
} TypeDate; 

typedef struct {
    TypeTime time; 
    TypeDate date;
    TypeStatus status; 
}bookingHistory; 

typedef struct{
    typeTime time; 
    typeDate date; 
    TypeStatus status;
}Schedule;

typedef enum{
    JANITOR,
    RECEPTIONIST, 
    LAUNDARY_STAFF,
    LAUGGAGE_STAFF,
    GARDERNDER
}JobPosition;

typedef enum{
    RESTAURANT, 
    BAR, 
    POOL,
    GYM, 
    PARKING_LOT
}TypeService; 
/*
    Declaration of function prototypes using in main program 
*/
void run();
#endif                                                             

