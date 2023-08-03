/*
* File: Employee.hpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class employee and class user  
*/
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP 
#include "main.hpp"
#include <list> 

using namespace std;
/*
 * Function: class user
 * Description: Used to create user list include user name and password 
 * Property:
 * - username  : username of user  
 * - password : password of user 
 * Contructor:
 * - User(string username, string password): This function is used to add a user object including username and password 
 * Method:
 * - getUsername(): This function is used to output the username of the user  
 * - authenticate(string inputPassword): This function is used to check the authentication of password 
 * */
class User{
    private:
        string username; 
        string password; 
    public: 
        User(); 
        User(string username, string password){
            this->username = username; 
            this->password = password;
        }; 
        string getUsername(); 
        bool authenticate(string inputPassword){
            return inputPassword == password; 
        }
};
/*
 * Function: class employee
 * Description: Used to create employee list include  name , phone number ,address , position and schedule 
 * Property:
 * - name : name of the employee
 * - phoneNum: phone number of the employee 
 * - position: employee's position
 * - schedule : employee's schedule  
 * - user : employee's user 
 * - checkAuthenticate : authentication of the user 
 * Contructor:
 * - Employee(string name, string phoneNum, JobPosition position, Schedule employScheduler, User user): This function is used to add a customer object including all properties 
 * Method:
 * - setName(string name): This function is used to edit the name of employee 
 * - setJobPosition(JobPosition position): This function is used to edit the position of employee 
 * - setPhoneNum(string phoneNum): This function is used to edit the phone number of employee
 * - getName(): This function is used to output the name of the employee 
 * - getJobPosition(): This function is used to output the position of the employee 
 * - getSchedule(): This function is used to output the schedule of the employee 
 * - getUsername(): This function is used to output the username of the employee 
 * - getPhoneNum(): This function is used to output the phone number of the employee 
 * - getAuthenticate(string password): This function is used to output the authentication of the password 
 * */
class Employee{
    private:
        string name; 
        string phoneNum; 
        JobPosition position; 
        Schedule schedule;  
        User user; 
        bool checkAuthenticate;
    public: 
        Employee(string name, string phoneNum, JobPosition position, Schedule employScheduler, User user);
        void getAuthenticate(string password);
        string getName();
        JobPosition getJobPosition();
        Schedule getSchedule();
        string getUsername();
        string getPhoneNum();
        void setName(string name);
        void setPhoneNum(string phoneNum);
        void setJobPosition(JobPosition position); 
};
/*
    Declaration of function prototypes using in employee class 
*/
void addEmployee(list<Employee> &emloyeeDatabase, list<User> userDatabase);
void editEmployee(list<Employee> &employeeDatabase);
void deleteEmployee(list<Employee> &employeeDatabase);
void getInformation(list <Employee> &employeeDatabase);

#endif