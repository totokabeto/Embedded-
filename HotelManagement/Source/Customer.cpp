/*
* File: Customer.cpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file including all of the customer class methods and constructors  
*/
#include "..\Header\Customer.hpp"
#include "..\Header\Room.hpp"

#include <list> 

using namespace std; 

Customer::Customer(string name, string phoneNum, string address, uint8_t idRoom){
    this->name = name; 
    this->phoneNum = phoneNum; 
    this->address = address; 
    this->idRoom = idRoom; 
}
/*
* Class: Customer
* Function: getPhoneNum
* Description: This function use for getting the phone number of a customer
* Input:
*   none
* Output:
*   return : phoneNum - the customer's phone number 
*/
string Customer::getPhoneNum(){
    return this->phoneNum; 
}
/*
* Class: Customer
* Function: setIDRoom
* Description: This function use for setting the id of the customer's room
* Input:
*   idRoom - room's id
* Output:
*   return : none
*/
void Customer::setIDRoom(uint8_t idRoom){
    this->idRoom = idRoom; 
}
/*
* Class: Customer
* Function: setIDRoom
* Description: This function use for setting the name of the customer
* Input:
*   name - customer name
* Output:
*   return : none
*/
void Customer::setName(string name){
    this->name = name; 
}
/*
* Class: Customer
* Function: setAddress
* Description: This function use for setting the address of the customer
* Input:
*   address - customer's address
* Output:
*   return : none
*/
void Customer::setAddress(string address){
    this->address = address; 
}
/*
* Class: Customer
* Function: setPhoneNum
* Description: This function use for setting the phone number of the customer
* Input:
*   phoneNum - customer's phone number
* Output:
*   return : none
*/
void Customer::setPhoneNum(string phoneNum){
    this->phoneNum = phoneNum; 
}
/*
* Class: Customer
* Function: addBookingHistory
* Description: This function use for adding the booking history of the customer
* Input:
*   bookingDetail - customer's booking history details
* Output:
*   return : none
*/
void Customer::addBookingHistory(bookingHistory bookingDetail){
    uint8_t second, minute , hour; 
    cout << "Enter hour , minute , second : " << endl;
    cin >> hour >> minute >> second; 
    bookingDetail.time.second = second;
    bookingDetail.time.minute = minute;
    bookingDetail.time.hour = hour; 
    uint8_t ngay, thang; 
    int nam; 
    cout << "Enter date, month , year : " << endl; 
    cin >> ngay >> thang; 
    cin >> nam; 
    bookingDetail.date.day = ngay;
    bookingDetail.date.month = thang; 
    bookingDetail.date.year = nam; 
    bool inOrOut; 
    cout << "1/IN OR 0/ OUT ? " << endl;
    cin >> inOrOut;
    if (inOrOut == true){
        bookingDetail.status = IN;
    } else {
        bookingDetail.status = OUT; 
    }
    bookingHistorys.push_back(bookingDetail); 
    cout << "Add booking history succeeded " << endl; 
}
/*
* Class: Customer
* Function: displayBookingHistory
* Description: This function use for displaying the booking history of the customer
* Input:
*   none
* Output:
*   return : none
*/
void Customer::displayBookingHistory(){
    for (auto &item : bookingHistorys){
        cout << item.time.second << endl; 
        cout << item.time.minute << endl; 
        cout << item.time.hour << endl; 
        cout << item.status << endl; 
    }
}
/*
* Class: Customer
* Function: checkIDRoom
* Description: This function use for checking the room id according to hotel's room list
* Input:
*   roomID - customer's room id
*   roomDatabase - hotel's room database
* Output:
*   return : true if the room id is correct 
*   return : false if the room id is incorrect 
*/
bool checkIDRoom (uint8_t roomID ,vector <Room> &roomDatabase){
    for (auto &item : roomDatabase){
        if(item.getRoomNumber() == roomID){
            return true; 
        } 
    }
    return false; 
}
/*
* Class: Customer
* Function: addCustomer
* Description: This function use for adding the customer object to the customer list
* Input:
*   roomDatabase - hotel's room list
*   customerDatabase - local customer database
* Output:
*   return : none
*/
void addCustomer(list<Customer> &customerDatabase , vector <Room> roomDatabase){
    uint8_t idRoom; 
    string name; 
    string phoneNum; 
    string address; 
    cout << "Enter the customer room id : " << endl; 
    cin >> idRoom; 
    if(checkIDRoom(idRoom,roomDatabase)){
        cout << "ID room valid " << endl; 
         cout << "Enter the customer's name : " << endl; 
        cin >> name; 
        cout << "Enter the custoemr's phone number : " << endl; 
        cin >> phoneNum; 
        cout << "Enter customer's address : " << endl; 
        cin >> address;
        Customer newCustomer(name,phoneNum,address,idRoom); 
        customerDatabase.push_back(newCustomer); 
    cout << "Adding new customer successfully " << endl;
    } else {
        cout << "ID room not valid " << endl; 
    }  
}
/*
* Class: Customer
* Function: editCustomer
* Description: This function use for edit the customer object to the customer list
* Input:
*   roomDatabase - hotel's room list
*   customerDatabase - local customer database
* Output:
*   return : none
*/
void editCustomer(list<Customer> &customerDatabase , vector <Room> roomDatabase){
    string phoneNum; 
    cout << "Enter the customer phone to delete : " << endl;
    cin >> phoneNum; 
    for (auto &item : customerDatabase){
        if(item.getPhoneNum() == phoneNum){
            int keyInput; 
            cout << "1.Edit room id" << endl; 
            cout << "2.Edit name " << endl; 
            cout << "3.Edit phone numner " << endl; 
            cout << "4.Edit address " << endl; 
            cout << "0.Return " << endl; 
            cout << "Your choice : " << endl; 
            cin >> keyInput; 
            switch (keyInput)
            {
            case 1:
                uint8_t idRoom; 
                cout << "Enter the edit room id : " << endl; 
                cin >> idRoom;
                if(checkIDRoom(idRoom,roomDatabase)){
                     item.setIDRoom(idRoom); 
                     cout << "ID room is valid " << endl; 
                } else {
                    cout << "ID room is not valid " << endl; 
                }
           
                break;
            case 2: 
                {
                string name; 
                cout << "Enter the edit name : " << endl; 
                cin >> name; 
                item.setName(name); 
                break;
                } 
            case 3: 
                {
                string phoneNumber;
                cout << "Enter the edit phone number : " << endl; 
                cin >> phoneNumber;
                item.setPhoneNum(phoneNumber); 
                break;
                } 
            case 4: 
                {
                string address; 
                cout << "Enter the edit address : " << endl; 
                cin >> address;
                item.setAddress(address); 
                break;
                } 
            case 0 : 
                return; 
                break; 
            default:
                break;
            }
        }
    }
}
/*
* Class: Customer
* Function: deleteCustomer
* Description: This function use for deleting the customer object to the customer list
* Input:
*   customerDatabase - local customer database
* Output:
*   return : none
*/
void deleteCustomer(list<Customer> &customerDatabase){
    string phoneNum; 
    cout << "Enter the customer phone to delete : " << endl;
    cin >> phoneNum; 
    auto position = customerDatabase.begin(); 
    for (auto &item : customerDatabase){
        if(item.getPhoneNum() == phoneNum){
            customerDatabase.erase(position); 
            return; 
        }
        position++; 
    }
    cout << "Invalid phone number " << endl; 
    return; 
}
/*
* Class: Customer
* Function: deleteCustomer
* Description: This function use for running the method addBookingHistory of customer class
* Input:
*   customerDatabase - local customer database
* Output:
*   return : none
*/
void addBookingHistory(list<Customer> &customerDatabase){
    string phoneNum; 
    cout << "Enter the customer phone to delete : " << endl;
    cin >> phoneNum; 
    bookingHistory bookDetail; 
    auto position = customerDatabase.begin(); 
    for (auto &item : customerDatabase){
        if(item.getPhoneNum() == phoneNum){
            item.addBookingHistory(bookDetail); 
            return; 
        }
        position++; 
    }
    cout << "Invalid phone number " << endl; 
    return; 
}
/*
* Class: Customer
* Function: deleteCustomer
* Description: This function use for running the method showBookingHistory of customer class
* Input:
*   customerDatabase - local customer database
* Output:
*   return : none
*/
void showBookingHistory(list<Customer> &customerDatabase){
    string phoneNum; 
    cout << "Enter the customer phone to delete : " << endl;
    cin >> phoneNum; 
    auto position = customerDatabase.begin(); 
    for (auto &item : customerDatabase){
        if(item.getPhoneNum() == phoneNum){
            item.displayBookingHistory(); 
            return; 
        }
        position++; 
    }
    cout << "Invalid phone number " << endl; 
    return; 
}