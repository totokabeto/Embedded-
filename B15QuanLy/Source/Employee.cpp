/*
* File: Employee.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file including all of the employee class methods and constructors  
*/
#include "..\Header\Employee.hpp"
#include "..\Header\global.hpp"

Employee::Employee(){}

void Employee::displayTableOrderInfo(tableInformation &ttableIndex){
    cout << "Information of table's index : " << ttableIndex.getTableIndex() << endl; 
    for (auto item : tableOrderList){
        if (item.getTableIndex() == ttableIndex.getTableIndex()){
            cout << " Ordered dish's name : " << item.getDishName() << endl; 
            cout << " Number of ration : " << item.getNumberOfRation() << endl; 
        }
    }
}
/*
* Class: Employee
* Function: Payment
* Description: This function use for charging one single table
* Input:
*   ttableIndex - the table index
* Output:
*   return : none  
*/
void Employee::Payment(tableInformation &ttableIndex){
    cout << "Conducting payment of table's index : " << ttableIndex.getTableIndex() << endl; 
    double l_sumOfCharge = 0; 
    for(auto item : tableOrderList){
        if (item.getTableIndex() == ttableIndex.getTableIndex()){
            l_sumOfCharge += item.getNumberOfRation() * item.getDishPrice();
        }
    }
    cout << "The total amount to pay : " << l_sumOfCharge << " $ " << endl; 
}
/*
* Class: Employee
* Function: getTableOrdered
* Description: This function use for getting the dishes all table ordered so far. 
* Input:
*   none 
* Output:
*   return : none  
*/
void Employee::getTableOrdered(){
    if(tableOrderList.size() == 0){
        cout << "There has been ordered from any table" <<endl; 
    } else{
    for(auto item : tableOrderList){
        cout << "Dish's name : " << item.getDishName() << endl; 
        cout << "Number of ration : " << item.getNumberOfRation() << endl; 
    }
    }
}
/*
* Class: Employee
* Function: deleteDish
* Description: This function use for deleting a dish from a table. 
* Input:
*   none 
* Output:
*   return : none  
*/
void Employee::deleteDish(){
    int l_id; 
    cout << "Enter the id of wanted deleting dish : " << endl; 
    cin >> l_id; 
    auto position = tableOrderList.begin(); 
    for (auto &item : tableOrderList){
        if (item.getDishID() == l_id){
             tableOrderList.erase(position); 
             cout << "The dish has been deledted from table's order successfully ! " << endl; 
             return; 
        }
        position++; 
    }
    cout  << "The id is not valid. Try again. " << endl; 
    return; 
}
/*
* Class: Employee
* Function: addDish
* Description: This function use for ordering a dish from a table. 
* Input:
*   dishListData - list of restaurant dishes 
*   ttableIndex - the index of table
* Output:
*   return : none  
*/
void Employee::addDish(list<Dish> dishListData, tableInformation &ttableIndex){
    L: 
    int l_id; 
    int l_numberOfRation;
    cout << "Enter the id of wanted adding dish: " << endl; 
    cin >> l_id; 
    for (auto item : dishListData){
        if(item.getDishID() == l_id){
            cout << "ID is valid ! " << endl; 
            cout << "Enter the number of ration : " << endl; 
            cin >> l_numberOfRation; 
            tableInformation newDishAtTable(ttableIndex.getTableIndex(),true,item,l_numberOfRation);
            tableOrderList.push_back(newDishAtTable);
            ttableIndex.setTableStatus();
            cout << "The dish has been ordered successfully ! " << endl;
        //     for (auto &item : DATABASE_MON_AN_TAI_BAN){
        //     if (item.getSoBan() == a.getSoBan()){
        //         item.setTrangThai();
        //       }
        //  }
            int keyInput; 
            cout << "1.Continue to add " << endl; 
            cout << "0.Return " << endl; 
            cin >> keyInput; 
            switch ((MiniMenuChoice)keyInput)
            {
            case CONTINUE:
                goto L; 
                break;
            case BACK: 
                employeeMenu(dishListData,tableNumberStatus.size()); 
                break; 
            default:
                break;
            }
        }
    }
    cout << "The id is not valid. Try again. " << endl;
    return;
}
/*
* Class: Employee
* Function: editDish
* Description: This function use for edting a dish from a table. 
* Input:
*   none
* Output:
*   return : none  
*/
void Employee::editDish(){
    int l_id; 
    int l_numberOfRation; 
    cout << "Enter the id of wanted editing dish: " << endl;
    cin >> l_id; 
    for (auto &item : tableOrderList){
        if(item.getDishID() == l_id){
            cout << "Enter the number of ration you want to change : " << endl; 
            cin >> l_numberOfRation; 
            item.setNumberOfRation(l_numberOfRation);
            cout << "The dish has been deledted from table's order successfully ! " << endl; 
            return; 
        } 
    } 
    cout << "The id is not valid. Try again. " <<endl; 
    return; 
}
/*
* Class: Employee
* Function: employeeMenu
* Description: This function use for displaying the employee menu selection. 
* Input:
*   dishListData - the list of restaurant dishes
*   iNumberOfTable - the number of fixed table 
* Output:
*   return : none  
*/
void Employee::employeeMenu(list<Dish> dishListData, int iNumberOfTable){
    if(iNumberOfTable != 0 && dishListData.size() != 0) {
        if(dishListData.size() == 0){
            for (int i = 1; i <= iNumberOfTable; i++){   
                tableInformation newTable{i,false}; 
                tableNumberStatus.push_back(newTable);
        }
        dishListData.assign(dishListData.begin(),dishListData.end());
    } 
    cout << "-------------------------------NUMBER OF TABLE AND CURRENT STATUS------------------------" << endl; 
    for (auto item : tableNumberStatus){ 
        cout << "So ban : " << item.getTableIndex() << endl;
        cout << "Trang thai:  " << item.getTableStatus() << endl;
    }
    /*cout << "Tinh trang------------------------------" << endl; 
    for (auto item : tableOrderList){
         cout << "So ban : " << item.getTableIndex() << endl;
        cout << "Trang thai:  " << item.getTableStatus() << endl;
    }*/
    while(1)
    {
    int l_orderTableIndex; 
    cout << "Enter the index of table " << endl; 
    cin >> l_orderTableIndex; 
    for (auto &item : tableNumberStatus){
        if (item.getTableIndex() == l_orderTableIndex){
            cout << "Enter your choice with table : " << item.getTableIndex() << endl;
            int tableSelection; 
            cout << "----------------------------------------Employee Menu----------------------------------------" << endl; 
            cout << "1.Add Dish " << endl; 
            cout << "2.Edit Dish " <<endl; 
            cout << "3.Delete Dish " << endl; 
            cout << "4.Table Dish List " << endl; 
            cout << "5.Payment " << endl; 
            cout << "0.Return " << endl;
            cout << "Your choice : " << endl; 
            cin >> tableSelection; 
            switch ((EmployeeMenuChoice)tableSelection)
            {
            case ORDER:
                for (auto d_item : dishListData){
                    d_item.getDishList(); 
                }
                addDish(dishListData, item); 
                break;
            case EDITORDER: 
                displayTableOrderInfo(item);
                editDish();
                break;
            case DELETEORDER: 
                displayTableOrderInfo(item);
                deleteDish();
                break;
            case DISHSHOW: 
                displayTableOrderInfo(item); 
                break; 
            case PAYMENT: 
                Payment(item); 
                break; 
            case 0: 
                break; 
            default:
                break;
            }
        } 
        }
        cout << "The table index is not valid. Try again.  " << endl; 
        return; 
    }    
    }
        else {   
            cout << "Plese set up the number of table and dish list databse before getting access to Employee" << endl; 
            return; 
        }
}