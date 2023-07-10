/*
* File: quanLy.cpp
* Author: Khanh Pham
* Date: 09/07/2023
* Description: This is the program used to manage a restaurant
*/

#include <iostream> 
#include <list> 

using namespace std; 

typedef enum{
    EXIT,
    MANAGER ,
    EMPLOYEE,
    
}SelectionChoice;

typedef enum{
    RETURN,
    ADDDISH,
    EDITDISH,
    DELETEDISH,
    LISTSHOW,
    SETTABLENUM,
}ManagerMenuChoice;

typedef enum{
    CONTINUE,
    BACK,
}MiniMenuChoice;
    
typedef enum{
    ORDER = 1,
    EDITORDER,
    DELETEORDER,
    DISHSHOW,
    PAYMENT,
}EmployeeMenuChoice; 

typedef enum{
    EDITNAME = 1,
    EDITPRICE,
}EditMenuChoice; 


/**********************************Class Dish*********************************/

class Dish{
    /* data */
    private: 
    uint8_t id; 
    string dishName;
    double dishPrice;
    public: 
    Dish(string strDishName, double dDishPrice); 
    Dish(); 
    void setDishName(string strDishName); 
    void setDishPrice(double dDishPrice); 

    int getDishID(); 
    string getDishName(); 
    double getDishPrice(); 
    void getDishList();
   
}; 
Dish::Dish(){}

void Dish::getDishList(){
    cout << "ID: " << (unsigned short)Dish::id << endl; 
    cout << "Dish name : " << Dish::dishName << endl; 
    cout << "Price tag : "<< Dish::dishPrice << " $ " << endl; 
}
Dish::Dish(string strDishName, double dDishPrice){
    static int id = 100; 
    this->id = id; 
    id++; 
    this->dishName = strDishName; 
    this->dishPrice = dDishPrice; 
}
/*
* Class: Dish
* Function: setDishName
* Description: This function use for set name of a dish
* Input:
*   strDishName - name of a dish
* Output:
*   return : none
*/
void Dish::setDishName(string strDishName){
    Dish::dishName = strDishName; 
}
/*
* Class: Dish
* Function: setDishPrice
* Description: This function use for set price of a dish
* Input:
*   strDishName - price of a dish
* Output:
*   return : none
*/
void Dish::setDishPrice(double dDishPrice){
    Dish::dishPrice = dDishPrice; 
}
/*
* Class: Dish
* Function: getDishID
* Description: This function use for get ID of a dish
* Input:
*   none
* Output:
*   return: id - id of a dish
*/
int Dish::getDishID(){
    return this->id;
}
/*
* Class: Dish
* Function: getDishName
* Description: This function use for get name of a dish
* Input:
*   none
* Output:
*   return: dishName - name of a dish
*/
string Dish::getDishName(){
    return Dish::dishName; 
}
/*
* Class: Dish
* Function: getDishPrice
* Description: This function use for get price of a dish
* Input:
*   none
* Output:
*   return: dishPrice - price of a dish
*/
double Dish::getDishPrice(){
    return Dish::dishPrice; 
}
/**********************************Class Manager*********************************/
class Manager{
    private: 
     /* data */
    int numberOfTable;
    void addDish();
    void editDish();
    void deleteDish(); 
    void displayDishList();

    void setNumberOfTable();
    public:
    Manager();
    list<Dish> dishListData;
    void managerMenu();

    list<Dish> getDishListData();
    int getNumberOfTable(); 
}; 

Manager::Manager(){
   this->numberOfTable = 0; 
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
/**********************************Class tableInformation*********************************/
class tableInformation{
private:  
    /* data */
    int tableIndex;
    bool tableStatus;
    Dish dish; 
    int numberOfRation; 
public:
    tableInformation(int tableIndex, bool tableStatus , Dish dish, int numberOfRation); 
    tableInformation(int tableIndex, bool tableStatus);
    void setNumberOfRation(int numberOfRation);
    void setTableStatus();

    int getDishID();
    int getTableIndex(); 
    bool getTableStatus();
    int getNumberOfRation();  
    string getDishName(); 
    double getDishPrice(); 
    int getNumberOfTable(); 

}; 
tableInformation::tableInformation(int tableIndex, bool tableStatus){
    this->tableIndex = tableIndex;
    this->tableStatus = tableStatus;
}

tableInformation::tableInformation(int tableIndex, bool tableStatus, Dish dish, int numberOfRation){
    tableInformation::tableIndex = tableIndex;
    tableInformation::tableStatus = tableStatus;
    tableInformation::dish = dish; 
    tableInformation::numberOfRation = numberOfRation;
}
/*
* Class: tableInformation
* Function: setNumberOfRation
* Description: This function use for setting the number of ration
* Input:
*   numberOfRation - number of ration
* Output:
*   return: none
*/
void tableInformation::setNumberOfRation(int numberOfRation){
    tableInformation::numberOfRation = numberOfRation;
}
/*
* Class: tableInformation
* Function: getNumberOfRation
* Description: This function use for getting the number of ration
* Input:
*   none
* Output:
*   return: numberOfRation - number of ration
*/
int tableInformation::getNumberOfRation(){
    return tableInformation::numberOfRation;
}
/*
* Class: tableInformation
* Function: getDishID
* Description: This function use for getting the ID of dish
* Input:
*   none
* Output:
*   return: dish ID
*/
int tableInformation::getDishID(){
    return dish.getDishID();
}
/*
* Class: tableInformation
* Function: getDishName
* Description: This function use for getting the name of dish
* Input:
*   none
* Output:
*   return: dish name
*/
string tableInformation::getDishName(){
    return dish.getDishName(); 
}
/*
* Class: tableInformation
* Function: getDishPrice
* Description: This function use for getting the price of dish
* Input:
*   none
* Output:
*   return: dish price
*/
double tableInformation::getDishPrice(){
    return dish.getDishPrice(); 
}
/*
* Class: tableInformation
* Function: getTableIndex
* Description: This function use for getting the index of table
* Input:
*   none
* Output:
*   return: table index
*/
int tableInformation::getTableIndex(){
    return tableInformation::tableIndex; 
}
/*
* Class: tableInformation
* Function: setTableStatus
* Description: This function use for setting the status of table
* Input:
*   none
* Output:
*   none
*/
void tableInformation::setTableStatus(){
    this->tableStatus = !this->tableStatus; 
}
/*
* Class: tableInformation
* Function: getTableStatus
* Description: This function use for getting the status of table
* Input:
*   none
* Output:
*   return : ableStatus - the status of table  
*/
bool tableInformation::getTableStatus(){
    return tableInformation::tableStatus; 
}
/**********************************Class Employee*********************************/
class Employee{
    /* data */
    private: 
    list<Dish> dishListData;
    list<tableInformation> tableNumberStatus;
    list<tableInformation> tableOrderList; 
    void addDish(list<Dish> dishListData , tableInformation &ttableIndex);
    void editDish();
    void deleteDish();
    void Payment(tableInformation &ttableIndex); 
    public: 
    Employee();
    void employeeMenu(list<Dish> dishListData, int iNumberOfTable);
    void displayTableOrderInfo(tableInformation &ttableIndex);

    void getTableOrdered();
}; 
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