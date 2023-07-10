/*
* File: Manager.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the file including all of the manager class methods and constructors  
*/
#include "..\Header\Manager.hpp"
#include "..\Header\global.hpp"
Manager::Manager(){
   this->numberOfTable = 0; 
}

/*
* Class: Manager
* Function: managerMenu
* Description: This function use for displaying the menu console
* Input:
*   none
* Output:
*   return: none
*/
void Manager::managerMenu(){
    int keyInput; 
        cout << "-----------------------------------------Manager Menu----------------------------------" << endl;
        cout << "1.Adding dish " << endl; 
        cout << "2.Edit dish " << endl; 
        cout << "3.Delete dish " << endl; 
        cout << "4.Dish list " << endl; 
        cout << "5.Set fixed number of table " << endl; 
        cout << "0.Return " << endl;
        cout << "Your choice : " << endl; 
        cin >> keyInput;
    switch ((ManagerMenuChoice)keyInput)
    {
    case ADDDISH:
        addDish();
        break;
    case EDITDISH: 
        editDish(); 
        break; 
    case DELETEDISH: 
        deleteDish(); 
        break; 
    case LISTSHOW: 
        displayDishList(); 
        break; 
    case SETTABLENUM: 
        setNumberOfTable(); 
        break; 
    case RETURN: 
        return; 
    default:
        break;
    }
}

/*
* Class: Manager
* Function: setNumberOfTable
* Description: This function use for set the number of table
* Input:
*   none
* Output:
*   return: None
*/
void Manager::setNumberOfTable(){
    int l_numberOfTable; 
    cout << "Enter the fixed restaurant's number of table :  " << endl; 
    cin >> l_numberOfTable;
    Manager::numberOfTable = l_numberOfTable;
}
/*
* Class: Manager
* Function: getDishListData
* Description: This function use for getting the list of dish
* Input:
*   none
* Output:
*   return: dishListData - list of dish 
*/
list<Dish> Manager::getDishListData(){
    return this->dishListData; 
}
/*
* Class: Manager
* Function: getNumberOfTable
* Description: This function use for getting the number of table
* Input:
*   none
* Output:
*   return: numberOfTable - the number of table 
*/
int Manager::getNumberOfTable(){
    return this->numberOfTable; 
}
/*
* Class: Manager
* Function: displayDishList
* Description: This function use for listing the dish in database 
* Input:
*   none
* Output:
*   return: none
*/
void Manager::displayDishList(){
    for(auto item : dishListData){
        cout << "ID : " << item.getDishID() << endl; 
        cout << "Dish's name : " << item.getDishName() << endl; 
        cout << "Price tag : " << item.getDishPrice() << endl; 
    }
}
/*
* Class: Manager
* Function: addDish
* Description: This function use for adding the dish to database 
* Input:
*   none
* Output:
*   return: none
*/
void Manager::addDish(){
    string l_dishName; 
    double l_dishPrice; 
    cout << "Enter the new dish's name : " << endl; 
    cin >> l_dishName; 
    cout << "Enter the new dish's price : " << endl; 
    cin >> l_dishPrice; 
    Dish newDish(l_dishName,l_dishPrice); 
    dishListData.push_back(newDish);
    cout << "Adding new dish to list successfully " << endl;
    int keyInput;   
    cout << "1.Continue to adding dish " << endl; 
    cout << "0.Return " << endl; 
    cin >> keyInput;
    switch ((MiniMenuChoice)keyInput)
    {
    case CONTINUE:
        addDish();
        break;
    case BACK: 
        managerMenu();
        break; 
    default:
        break;
    }
}
/*
* Class: Manager
* Function: editDish
* Description: This function use for editing the dish in database 
* Input:
*   none
* Output:
*   return: none
*/
void Manager::editDish(){
    int l_id; 
    int keyInput; 
    string l_dishName; 
    double l_dishPrice;
    cout << "1.Edit dish's name " << endl; 
    cout << "2.Edit dish's price " << endl; 
    cout << "0.Return " << endl; 
    cout << "Your choice : " << endl; 
    cin >> keyInput; 
    switch ((EditMenuChoice)keyInput)
    {
    case EDITNAME:
        displayDishList(); 
        cout << "Enter the id of wanted editing dish " << endl;
        cin >> l_id;
        for(auto &item : dishListData){
            if(item.getDishID() == l_id){
                cout << "Enter new name :  " << endl; 
                cin >> l_dishName; 
                item.setDishName(l_dishName);
                cout << "Editing new name succesfully ! " << endl; 
                managerMenu(); 
            } 
        }
        break;
    case EDITPRICE: 
        displayDishList(); 
        cout << "Enter the id of wanted editing dish " << endl;
        cin >> l_id;
        for(auto &item : dishListData){
            if(item.getDishID() == l_id){
                cout << "Enter new price  " << endl; 
                cin >> l_dishPrice; 
                item.setDishPrice(l_dishPrice);
                cout << "Editing new price succesfully " << endl; 
                managerMenu(); 
            } 
        }
        cout << "Id nhap vao khong ton tai" << endl; 
        return; 
        break; 
    case 0:
        return;
        break; 
    default:
        break;
    }
}
/*
* Class: Manager
* Function: deleteDish
* Description: This function use for deleting the dish in database 
* Input:
*   none
* Output:
*   return: none
*/
void Manager::deleteDish(){
    int l_id; 
    cout << "Enter the id of wanted deleting dish" << endl; 
    cin >> l_id; 
    auto position = dishListData.begin(); 
    for (auto item : dishListData){
        if (item.getDishID() == l_id){
            dishListData.erase(position); 
        }
        position++;
    }
}