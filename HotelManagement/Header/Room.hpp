/*
* File: Room.hpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class room 
*/
#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <vector> 

using namespace std; 
/*
 * Function: class room
 * Description: Used to create room list include id, booking and cleaning condition
 * Property:
 * - roomId  : id of room  
 * - isBooked : booking condition 
 * Contructor:
 * - Room(uint8_t roomID): This function is used to add a room object including roomID
 * Method:
 * - getRoomNumber(): This function is used to output the number id of the room  
 * - isAvailable(): This function is used to check the availability of the room
 * - bookRoom() : This function is used to book the room
 * - checkIn() : This function is used for check in 
 * - checkOut() : This function is used for check out  
 * */
class Room{
    private: 
    uint8_t roomId; 
    bool isBooked; 
    bool isCleaning; 
    public: 
    Room(uint8_t roomID); 
    bool isAvailable();
    uint8_t getRoomNumber();
    void bookRoom(); 
    void checkIn();
    void checkOut();
};
/*
    Declaration of function prototypes using in class Room 
*/
void addRoom(vector<Room> &roomData);
void showRoomList(vector<Room> &roomData);
void bookRoom(vector<Room> &roomData);
void isAvailable(vector<Room> &roomData);
void checkIn(vector<Room> &roomData);
void checkOut(vector<Room> &roomData);
#endif