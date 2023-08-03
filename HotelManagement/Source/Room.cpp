/*
* File: Room.cpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class customer 
*/
#include "..\Header\Room.hpp"
#include <vector> 

using namespace std; 

Room::Room(uint8_t roomID){
    this->roomId = roomID;
    this->isBooked = false; 
    this->isCleaning = false; 
}
uint8_t Room::getRoomNumber(){
    return this->roomId;
}
/*
* Class: Room
* Function: isAvailable
* Description: This function use for checking the available of the room
* Input:
*   none
* Output:
*   return : true if the room is not booked and being cleaning 
*/
bool Room::isAvailable(){
    return isBooked && isCleaning; 
}
/*
* Class: Room
* Function: bookRoom
* Description: This function use for booking the room
* Input:
*   none
* Output:
*   return : none
*/
void Room::bookRoom(){
    isBooked = true; 
}
/*
* Class: Room
* Function: checkIn
* Description: This function use for checking in the room
* Input:
*   none
* Output:
*   return : none
*/
void Room::checkIn(){
    isCleaning = false; 
    isBooked = true; 
}
/*
* Class: Room
* Function: checkOut
* Description: This function use for check out  the room
* Input:
*   none
* Output:
*   return : none
*/
void Room::checkOut(){
    isCleaning = true; 
    isBooked = false; 
}
/*
* Class: Room
* Function: addRoom
* Description: This function use for adding the room object the the room list
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void addRoom(vector<Room> &roomData){
    uint8_t roomID; 
    cout << "Enter room's ID : " << endl; 
    cin >> roomID; 
    Room newRoom(roomID); 
    roomData.push_back(newRoom);
    cout << "Adding room succeeded !" << endl; 
}
/*
* Class: Room
* Function: showRoomList
* Description: This function use for showing the room list
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void showRoomList(vector<Room> &roomData){
    cout << "Hotel Room List " << endl; 
    for (auto &item : roomData){
        cout <<"Room id : " << item.getRoomNumber() << endl; 
    }
}
/*
* Class: Room
* Function: bookRoom
* Description: This function use for ruuning the method bookRoom of Room class
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void bookRoom(vector<Room> &roomData){
    uint8_t idRoom; 
    cout << "Enter room id you want to book : " << endl; 
    cin >> idRoom; 
    for (auto &item : roomData){
        if (item.getRoomNumber() == idRoom){
            item.bookRoom(); 
            return;
        }
    }
    cout << "Id is not valid " << endl; 
    return; 
}
/*
* Class: Room
* Function: isAvailable
* Description: This function use for ruuning the method isAvailable of Room class
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void isAvailable(vector<Room> &roomData){
    uint8_t idRoom; 
    cout << "Enter room id you want to check its status : " << endl; 
    cin >> idRoom; 
    for (auto &item : roomData){
        if (item.getRoomNumber() == idRoom){
            item.isAvailable(); 
            return;
        }
    }
    cout << "Id is not valid " << endl; 
    return; 
}
/*
* Class: Room
* Function: checkIn
* Description: This function use for ruuning the method checkIn of Room class
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void checkIn(vector<Room> &roomData){
    uint8_t idRoom; 
    cout << "Enter room id you want to check in : " << endl; 
    cin >> idRoom; 
    for (auto &item : roomData){
        if (item.getRoomNumber() == idRoom){
            item.checkIn(); 
            return;
        }
    }
    cout << "Id is not valid " << endl; 
    return; 
}
/*
* Class: Room
* Function: checkIn
* Description: This function use for ruuning the method checkOut of Room class
* Input:
*   roomData - local room database 
* Output:
*   return : none
*/
void checkOut(vector<Room> &roomData){
    uint8_t idRoom; 
    cout << "Enter room id you want to check in : " << endl; 
    cin >> idRoom; 
    for (auto &item : roomData){
        if (item.getRoomNumber() == idRoom){
            item.checkOut(); 
            return;
        }
    }
    cout << "Id is not valid " << endl; 
    return; 
}