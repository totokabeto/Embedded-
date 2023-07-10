/*
* File: main.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file including the main function to run the program
*/

#include "..\Header\Manager.hpp"
#include "..\Header\Employee.hpp"
#include "..\Header\global.hpp"
#include "Dish.cpp"
#include "Employee.cpp"
#include "Manager.cpp"
#include "TableInformation.cpp"

/*
* Function: programRun
* Description: This function use for initializing the first main menu. 
* Input:
*   none 
* Output:
*   return : none  
*/
void programRun(){
    Manager l_newManager;
    Employee l_newEmployee;
    while(1){
    int keyInput = 0;
    cout << "--------------------------Restaurant Managerment Program--------------------------- " << endl; 
    cout << "1.Manager " << endl; 
    cout << "2.Employee " << endl;
    cout << "0.Exit" << endl; 
    cout << "Your choice : " << endl; 
    cin >> keyInput; 
    switch ((SelectionChoice)keyInput)
    {
    case MANAGER:
    {
        l_newManager.managerMenu();
        break;
    } 
    case EMPLOYEE:{
        l_newEmployee.employeeMenu(l_newManager.getDishListData(),l_newManager.getNumberOfTable());
        break;
    }
    case EXIT:
        cout << "EXITING......." << endl; 
        exit(0);
    default: 
        break;
    }
    }
}
int main(int argc, char const *argv[])
{   programRun();
    return 0;
}
