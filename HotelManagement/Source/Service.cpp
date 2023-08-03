/*
* File: Service.cpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class customer 
*/
#include "..\Header\Service.hpp"
#include <iostream> 
using namespace std; 

ServiceAndEnter::ServiceAndEnter(){

}
/*
* Class: Service
* Function: addService
* Description: This function use for adding the service object to the service list 
* Input:
*   none  
* Output:
*   return : none
*/
void ServiceAndEnter::addService(){
    int keyInput; 
    TypeService service; 
    cout << "Add service : " << endl; 
    cin >> keyInput; 
    switch (keyInput)
    {
    case 1:
        service = RESTAURANT;
        serviceData.push_back(service);
        cout << "Add service successfully ! " << endl; 
        break;
    case 2 : 
        service = BAR;
        break; 
    default:
        break;
    }
}
/*
* Class: Service
* Function: deleteService
* Description: This function use for deleting the service object of the service list 
* Input:
*   none  
* Output:
*   return : none
*/
void ServiceAndEnter::deleteService(){
    int keyInput; 
    cout << "Choose service to delete : " << endl; 
    cin >> keyInput; 
    auto position = serviceData.begin(); 
    for (auto &item : serviceData){
        if (item == keyInput){
            serviceData.erase(position);
        }
        position++;
    }
}