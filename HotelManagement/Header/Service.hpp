/*
* File: Service.hpp
* Author: Khanh Pham
* Date: 1/08/2023
* Description: This is the file create the class service 
*/
#ifndef SERVICE_HPP
#define SERVICE_HPP 
#include "main.hpp"
#include <list> 
using namespace std; 
/*
 * Function: class service
 * Description: Used to create the service and entertainment list include type of services 
 * Property:
 * - typeService  : types of service
 * Contructor:
 * - ServiceAndEnter(): This function is used to add a service object 
 * Method:
 * - addService(): This function is used to add new service to the list 
 * - editService(): This function is used to edit the list service
 * - deleteService() : This function is used to delete the service
 * */
class ServiceAndEnter{
    private: 
    list <TypeService> serviceData; 
    public : 
    ServiceAndEnter();
    void addService(); 
    void editService();
    void deleteService();  
};

#endif 