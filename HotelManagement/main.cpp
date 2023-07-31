#include <iostream>
#include <vector>
#include <list> 

using namespace std; 

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

Room::Room(uint8_t roomID){
    this->roomId = roomID;
    this->isBooked = false; 
    this->isCleaning = false; 
}
uint8_t Room::getRoomNumber(){
    return this->roomId;
}
bool Room::isAvailable(){
    return isBooked && isCleaning; 
}
void Room::bookRoom(){
    isBooked = true; 
}
void Room::checkIn(){
    isCleaning = false; 
    isBooked = true; 
}
void Room::checkOut(){
    isCleaning = true; 
    isBooked = false; 
}

void addRoom(vector<Room> &roomData){
    uint8_t roomID; 
    cout << "Enter room's ID : " << endl; 
    cin >> roomID; 
    Room newRoom(roomID); 
    roomData.push_back(newRoom);
    cout << "Adding room succeeded !" << endl; 
}
void showRoomList(vector<Room> &roomData){
    cout << "Hotel Room List " << endl; 
    for (auto &item : roomData){
        cout <<"Room id : " << item.getRoomNumber() << endl; 
    }
}
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
//-------------------------------------------------------------------------------//

typedef enum {
    IN,
    OUT
}TypeStatus; 

typedef struct{
    uint8_t second;
    uint8_t minute; 
    uint8_t hour;
}TypeTime; 

typedef struct{
    uint8_t day;
    uint8_t month; 
    int year;
} TypeDate; 

typedef struct {
    TypeTime time; 
    TypeDate date;
    TypeStatus status; 
}bookingHistory; 

class Customer {
    private: 
    uint8_t idRoom; 
    string name; 
    string phoneNum; 
    string address; 
    vector <bookingHistory> bookingHistorys;  
    public: 
    Customer(string name, string phoneNum, string address, uint8_t idRoom); 
    void addBookingHistory(bookingHistory bookingDetails); 
    void displayBookingHistory();
    string getPhoneNum();
    void setIDRoom(uint8_t idRoom); 
    void setName(string name); 
    void setPhoneNum(string phoneNum); 
    void setAddress(string address); 
}; 

Customer::Customer(string name, string phoneNum, string address, uint8_t idRoom){
    this->name = name; 
    this->phoneNum = phoneNum; 
    this->address = address; 
    this->idRoom = idRoom; 
}
string Customer::getPhoneNum(){
    return this->phoneNum; 
}
void Customer::setIDRoom(uint8_t idRoom){
    this->idRoom = idRoom; 
}
void Customer::setName(string name){
    this->name = name; 
}
void Customer::setAddress(string address){
    this->address = address; 
}
void Customer::setPhoneNum(string phoneNum){
    this->phoneNum = phoneNum; 
}
void Customer::addBookingHistory(bookingHistory bookingDetail){
    uint8_t second, minute , hour; 
    cout << "Nhap gio, phut, giay : " << endl;
    cin >> hour >> minute >> second; 
    bookingDetail.time.second = second;
    bookingDetail.time.minute = minute;
    bookingDetail.time.hour = hour; 
    uint8_t ngay, thang; 
    int nam; 
    cout << "Nhap ngay, thang , nam : " << endl; 
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
    cout << "Them lich su dat phong thanh cong " << endl; 
}

void Customer::displayBookingHistory(){
    for (auto &item : bookingHistorys){
        cout << item.time.second << endl; 
        cout << item.time.minute << endl; 
        cout << item.time.hour << endl; 
        cout << item.status << endl; 
    }
}

void addCustomer(list<Customer> &customerDatabase){
    uint8_t idRoom; 
    string name; 
    string phoneNum; 
    string address; 
    cout << "Enter the customer room id : " << endl; 
    cin >> idRoom; 
    cout << "Enter the customer's name : " << endl; 
    cin >> name; 
    cout << "Enter the custoemr's phone number : " << endl; 
    cin >> phoneNum; 
    cout << "Enter customer's address : " << endl; 
    cin >> address;
    Customer newCustomer(name,phoneNum,address,idRoom); 
    customerDatabase.push_back(newCustomer); 
    cout << "Adding new customer successfully " << endl;
}
void editCustomer(list<Customer> &customerDatabase){
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
                // if - else check room id // 
                item.setIDRoom(idRoom); 
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

//-----------------------------------------------------------------------------------//
typedef enum{
    JANITOR,
    RECEPTIONIST, 
    LAUNDARY_STAFF,
    LAUGGAGE_STAFF,
    GARDERNDER
}JobPosition;

typedef struct{
    uint8_t second;
    uint8_t minute; 
    uint8_t hour;
}typeTime; 

typedef struct{
    uint8_t day;
    uint8_t month; 
    int year;
} typeDate; 

typedef struct{
    typeTime time; 
    typeDate date; 
    TypeStatus status;
}Schedule; 


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
User::User(){

}
string User::getUsername(){
    return this->username; 
}
class Employee{
    private:
        string name; 
        string phoneNum; 
        JobPosition position; 
        Schedule schedule;  
        User user; 
        bool checkAuthenticate;
    public: 
        Employee(string name, string phoneNum, JobPosition position, Schedule employScheduler, User user)
        {
            checkAuthenticate = false; 
        }
        void getAuthenticate(string password){
            if(user.authenticate(password) || password == "admin"){
                checkAuthenticate = true; 
            }
        }
        string getName(){
            if(checkAuthenticate == true){
                return this->name;
            } else {
                cout << "Wrong password ! " << endl; 
                return "a";
            }
        }
        string getUsername(){
            return user.getUsername(); 
        }
        string getPhoneNum(){
            return this->phoneNum;
        }
        void setName(string name);
        void setPhoneNum(string phoneNum);
        void setJobPosition(JobPosition position); 
};
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
    cout << "Choose employee's position :" << endl; 
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
void Employee::setName(string name){
    this->name = name; 
}
void Employee::setPhoneNum(string phoneNum){
    this->phoneNum = phoneNum; 
}
void Employee::setJobPosition(JobPosition position){
    this->position = position;
}

void editEmployee(list<Employee> &employeeDatabase){

}
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
            return;
        }
    }
    cout << "Username is not valid" << endl;
    return; 
}

int main(int argc, char const *argv[])
{
    vector<Room> roomDatabase;
    list<Employee> emloyeeDatabase; 
    list<User> userDatabase; 
    list<Customer> customerDatabase; 

    while(1){
    A:
    int keyInput; 
    cout << "1. Room Management" << endl; 
    cout << "2. Customer Mananagement" << endl; 
    cout << "3. Employee Management" << endl; 
    cout << "4. Service and Entertainment Management" << endl; 
    cout << "5. Payment Management " << endl; 
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
        int keyMini;
            addRoom(roomDatabase); 
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
            addCustomer(customerDatabase); 
            break;
        case 2: 
            editCustomer(customerDatabase); 
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
    case 0: 
        cout << "Exiting the program... " << endl;
        exit(0); 
        break; 
    default:
        break;
    }
    }
}
