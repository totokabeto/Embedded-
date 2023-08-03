/*
* File: main.cpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file containing the main function  
*/
#include "..\Header\Room.hpp"
#include "..\Header\Employee.hpp"
#include "..\Header\Customer.hpp"
#include "..\Header\Service.hpp"
#include "..\Header\main.hpp"
#include "Room.cpp"
#include "Customer.cpp"
#include "Service.cpp"
#include "Employee.cpp"
/*
* Function: run
* Description: This function use for running the program
* Input:
*   none  
* Output:
*   return : none
*/
void run(){
    vector<Room> roomDatabase;
    list<Employee> emloyeeDatabase; 
    list<User> userDatabase; 
    list<Customer> customerDatabase; 
    ServiceAndEnter se1; 
    while(1){
    A:
    int keyInput; 
    cout << "1. Room Management" << endl; 
    cout << "2. Customer Mananagement" << endl; 
    cout << "3. Employee Management" << endl; 
    cout << "4. Service and Entertainment Management" << endl; 
    cout << "5. Customer's Feedback" << endl; 
    cout << "0. Exit " << endl; 
    cout << "Your choice " << endl; 
    cin >> keyInput;
    switch (keyInput)
    {
    case 1:
        int key; 
        cout << "1. Add room" << endl; 
        cout << "2. Show room list" << endl;
        cout << "0. Return " << endl; 
        cin >> key; 
        switch (key)
        {
        case 1:
        B:  
            addRoom(roomDatabase); 
            int keyMini;
            cout << "1. Continue to add " << endl;
            cout << "0. Return " << endl; 
            cout << "Your choice : " << endl; 
            cin >> keyMini;
            switch (keyMini)
            {
             case 1:
                goto B; 
                break;
             case 0:
                goto A; 
                break; 
             default:
                break;
            }
            break;
        case 2: 
            int roomSelect; 
            showRoomList(roomDatabase);
            cout << "1. Check room " << endl; 
            cout << "2. Book room " << endl; 
            cout << "3. Check in" << endl; 
            cout << "4. Check out" << endl;
            cout << "0. Return " << endl; 
            cin >> roomSelect;
            switch (roomSelect)
            {
            case 1:
                isAvailable(roomDatabase);
                break;
            case 2: 
                bookRoom(roomDatabase);
                break; 
            case 3: 
                checkIn(roomDatabase);
                break; 
            case 4: 
                checkOut(roomDatabase);
                break;
            case 0: 
                break;  
            default:
                break;
            }
            break; 
        case 0: 
            goto A;  
            break;
        default:
            break;
        }
        break;
    case 2: 
        int key2; 
        cout << "1. Add Customer " << endl; 
        cout << "2. Edit Customer " << endl;
        cout << "3. Delete Customer " << endl;
        cout << "4. Show customer information " << endl; 
        cout << "5. Add customer booking history" << endl; 
        cout << "6. Display customer booking history " << endl; 
        cin >> key2; 
        switch (key2)
        {
        case 1:
            addCustomer(customerDatabase,roomDatabase); 
            break;
        case 2: 
            editCustomer(customerDatabase,roomDatabase); 
            break;
        case 3 : 
            deleteCustomer(customerDatabase); 
            break; 
        case 0: 
            break;  
        default:
            break;
        }
        break; 
    case 3: 
        int employKey; 
        cout << "1. Add Employee " << endl; 
        cout << "2. Edit Employee " << endl;
        cout << "3. Delete Employee " << endl;
        cout << "4. Show employee information " << endl; 
        cout << "0. Return " << endl; 
        cout << "Your choice : " << endl; 
        cin >> employKey; 
        switch (employKey)
        {
        case 1:
            addEmployee(emloyeeDatabase,userDatabase);
            break;
        case 2: 
            editEmployee(emloyeeDatabase);
            break; 
        case 3: 
            deleteEmployee(emloyeeDatabase); 
            break; 
        case 4: 
            getInformation(emloyeeDatabase);
            break; 
        default:
            break;
        }
        break; 
    case 4 : 

        break; 
    case 0: 
        cout << "Exiting the program... " << endl;
        exit(0); 
        break; 
    default:
        break;
    }
    }
}

int main(int argc, char const *argv[])
{
    run();
}
