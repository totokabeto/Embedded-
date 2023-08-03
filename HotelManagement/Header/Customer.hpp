/*
* File: Customer.hpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class customer 
*/
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "main.hpp"
#include "Room.hpp"
#include <iostream>
#include <list> 
#include <vector> 

using namespace std; 
/*
 * Function: class customer
 * Description: Used to create customer list include id, name , phone number and address 
 * Property:
 * - idRoom : ID of room 
 * - NAME: Name of customer 
 * - phoneNum: phone number of customer 
 * - address : address of customer 
 * Contructor:
 * - Customer(string name, string phoneNum, string address, uint8_t idRoom): This function is used to add a customer object including all properties 
 * Method:
 * - setName(string newName): This function is used to edit the name of customer 
 * - setIDRoom(uint8_t idRoom): This function is used to edit the id of the customer room
 * - setPhoneNum(string phoneNum) : This function is used to edit the customer phone number
 * - setAddress(string address) : This function is used to edit the customer's address 
 * - getPhoneNum(): This function is used to output the phone number of the customer 
 * - addBookingHistory(bookingHistory bookingDetails): This function is used to adding the booking history of the customer 
 * - displayBookingHistory(): This function is used to output the booking history of the customer 
 */
class Customer {
    private: 
    uint8_t idRoom; 
    string name; 
    string phoneNum; 
    string address; 
    vector <bookingHistory> bookingHistorys;  
    public: 
    Customer(string name, string phoneNum, string address, uint8_t idRoom); 
    void addBookingHistory(bookingHistory bookingDetails); 
    void displayBookingHistory();
    string getPhoneNum();
    void setIDRoom(uint8_t idRoom); 
    void setName(string name); 
    void setPhoneNum(string phoneNum); 
    void setAddress(string address); 
}; 
/*
    Declaration of function prototypes using in customer class 
*/
void addCustomer(list<Customer> &customerDatabase , vector <Room> roomDatabase);
void editCustomer(list<Customer> &customerDatabase , vector <Room> roomDatabase);
void deleteCustomer(list<Customer> &customerDatabase);
void addBookingHistory(list<Customer> &customerDatabase);
void showBookingHistory(list<Customer> &customerDatabase);

#endif