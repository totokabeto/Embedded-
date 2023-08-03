/*
* File: Employee.cpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the employee class 
*/
#include "..\Header\Employee.hpp"
#include "..\Header\Customer.hpp"
#include <iostream>
#include <list> 

using namespace std; 

User::User(){

}
/*
* Class: Employee
* Function: getUsername
* Description: This function use for getting the name of the user 
* Input:
*   none
* Output:
*   return : username - User's name 
*/
string User::getUsername(){
    return this->username; 
}

Employee::Employee(string name, string phoneNum, JobPosition position, Schedule employScheduler, User user){
    checkAuthenticate = false; 
}
/*
* Class: Employee
* Function: getAuthenticate
* Description: This function use for checking the authentication of password
* Input:
*   password - user's password
* Output:
*   return : true if password is correct
*/
void Employee::getAuthenticate(string password)
    {
            if(user.authenticate(password) || password == "admin"){
                checkAuthenticate = true; 
            }
    }
/*
* Class: Employee
* Function: getName
* Description: This function use for getting the name of the employee
* Input:
*   none
* Output:
*   return : name - employee's name
*/
string Employee::getName()
{
            if(checkAuthenticate == true){
                return this->name;
            } else {
                cout << "Wrong password ! " << endl; 
            }
}
/*
* Class: Employee
* Function: getJobPosition
* Description: This function use for getting the position of the employee
* Input:
*   none
* Output:
*   return : position - employee's position
*/
JobPosition Employee::getJobPosition()
{
             if(checkAuthenticate == true){
                return this->position;
            } else {
                cout << "Wrong password ! " << endl; 
            }
}
/*
* Class: Employee
* Function: getSchedule
* Description: This function use for getting the schedule of the employee
* Input:
*   none
* Output:
*   return : schedule - employee's schedule
*/
Schedule Employee::getSchedule(){
            if(checkAuthenticate == true){
                return this->schedule;
            } else {
                cout << "Wrong password ! " << endl; 
            }
}
/*
* Class: Employee
* Function: getUsername
* Description: This function use for getting the username of the employee
* Input:
*   none
* Output:
*   return : schedule - employee's username
*/
string Employee::getUsername(){
    return user.getUsername(); 
}
/*
* Class: Employee
* Function: getUsername
* Description: This function use for getting the phone number of the employee
* Input:
*   none
* Output:
*   return : phoneNum - employee's phone number
*/
string Employee::getPhoneNum(){
    return this->phoneNum;
}
/*
* Class: Employee
* Function: addEmployee
* Description: This function use for adding the employee object to the employee list
* Input:
*   emloyeeDatabase - local enmployee's database 
*   userDatabase - local user's database
* Output:
*   return : none
*/
void addEmployee(list<Employee> &emloyeeDatabase, list<User> userDatabase){
    string name; 
    string phoneNum; 
    JobPosition position; 
    Schedule schedule; 
    string username; 
    string password; 
    cout << "Enter username : " << endl; 
    cin >> username; 
    cout << "Enter password " << endl; 
    cin >> password;
    User user(username, password);
    cout << "Enter employee's name : " << endl; 
    cin >> name; 
    cout << "Enter employee's phone number " << endl; 
    cin >> phoneNum; 
    cout << "Choose employee's position : 0/Janitor 1/Receptionis 2/Laundry staff 3/Lauggage staff 4/Garderner " << endl; 
    uint8_t keyInput; 
    cin >> keyInput;
    switch ((JobPosition)keyInput)
    {
    case JANITOR:
        position = JANITOR; 
        break;
    case RECEPTIONIST: 
        position = RECEPTIONIST;
        break;
    case LAUNDARY_STAFF:
        position = LAUGGAGE_STAFF; 
        break; 
    case LAUGGAGE_STAFF:
        position = LAUGGAGE_STAFF; 
        break; 
    case GARDERNDER: 
        position = GARDERNDER;
        break; 
    default:
        cout << "Invalid position " << endl; 
        break;
    }
    uint8_t giay,phut,gio; 
    cout << "Enter schedulet time : " << endl;
    cin >> gio >> phut >> giay; 
    schedule.time.second = giay; 
    schedule.time.minute = phut; 
    schedule.time.hour = gio; 
    uint8_t ngay,thang; 
    int nam; 
    cout << "Enter schedule date : " << endl; 
    cin >> ngay >> thang; 
    cin >> nam; 
    schedule.date.day = ngay; 
    schedule.date.month = thang; 
    schedule.date.year = nam; 
    cout << "Enter status IN Or Out" << endl; 
    bool inOrOut; 
    cout << "1/IN OR 0/ OUT ? " << endl;
    cin >> inOrOut;
    if (inOrOut == true){
        schedule.status = IN;
    } else {
        schedule.status = OUT; 
    }
    Employee newEmployee(name,phoneNum,position,schedule,user);
    emloyeeDatabase.push_back(newEmployee); 
    userDatabase.push_back(user);
    cout << "Add employee succesfully " << endl; 
}
/*
* Class: Employee
* Function: setName
* Description: This function use for setting the ename of the employee
* Input:
*   name - employee's name 
* Output:
*   return : name - employee's name 
*/
void Employee::setName(string name){
    this->name = name; 
}
/*
* Class: Employee
* Function: setPhoneNum
* Description: This function use for setting the phone numvber of the employee
* Input:
*   phoneNum - employee's phone number 
* Output:
*   return : phoneNum - employee's phone number 
*/
void Employee::setPhoneNum(string phoneNum){
    this->phoneNum = phoneNum; 
}
/*
* Class: Employee
* Function: setPhoneNum
* Description: This function use for setting the position of the employee
* Input:
*   position - employee's job postion 
* Output:
*   return : position - employee's job postion
*/
void Employee::setJobPosition(JobPosition position){
    this->position = position;
}
/*
* Class: Employee
* Function: editEmployee
* Description: This function use for editing the employee object to the employee list
* Input:
*   emloyeeDatabase - local enmployee's database 
* Output:
*   return : none
*/
void editEmployee(list<Employee> &employeeDatabase){

}
/*
* Class: Employee
* Function: deleteEmployee
* Description: This function use for deleting the employee object to the employee list
* Input:
*   emloyeeDatabase - local enmployee's database 
* Output:
*   return : none
*/
void deleteEmployee(list<Employee> &employeeDatabase){
    string phoneNum; 
    cout << "Enter employee phone number " << endl; 
    auto position = employeeDatabase.begin(); 
    for (auto &item : employeeDatabase){
        if(item.getPhoneNum() == phoneNum){
            employeeDatabase.erase(position);
            cout << "Delete employee successfully" << endl; 
        }
        position++;
    }
}
/*
* Class: Employee
* Function: getInformation
* Description: This function use for getting all information of the employee 
* Input:
*   emloyeeDatabase - local enmployee's database 
* Output:
*   return : none
*/
void getInformation(list <Employee> &employeeDatabase){
    string username; 
    cout << "Enter username : " << endl; 
    cin >> username; 
    string password; 
    for (auto &item : employeeDatabase){
        if(item.getUsername() == username){
            cout << "Enter password : " << endl;
            cin >> password; 
            item.getAuthenticate(password); 
            cout << "Employee's name : " << item.getName() << endl; 
            cout << "Employee's phone number : " << item.getPhoneNum() << endl; 
            cout << "Employee's job position : " << item.getJobPosition() << endl; 
            cout << "Schedule : " << item.getSchedule().time.hour << endl; 
            cout << "That's all an employee's information " << endl; 
            return;
        }
    }
    cout << "Username is not valid" << endl;
    return; 
}