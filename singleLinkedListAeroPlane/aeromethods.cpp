/*
 * =====================================================================================
 *
 *       Filename:  aeromthods.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/2019 02:07:44 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "aeromethods.h"

void printMenu()
{
    std::cout << "Pick an option below:\n1 reserve a ticket\n2 cancel a reservation\n"
        "3 check ticket reservation\n4 display current passengers\n5 exit program\n\n";
}

int getUserInput()
{
    int temp = 0;
    std::cin >> temp;
    return temp;
}

void addFlights()
{
    head->next = new Flights(1, "New York");
    head->next->next = new Flights(2, "San Jose");
    head->next->next->next = new Flights(3, "Houston");
}

//FIXME one potential issue that would need to be fixed before this would actually be accepted
// is that there is potential for duplicate ticket ID's. I'll come back and input safety checks later. 
int hash(){return std::rand() % 10000000;};

void printList()
{
    for(Flights *itr = head->next; itr != NULL; itr = itr->next)
    {
        std::cout << itr->location << " ID: "<< itr->id << " Available: " << itr->cap - itr->size << "/" << itr->cap << std::endl;
    }
    std::cout << "\n";
}
void getPassengerInfo(Flights* f, int& id)
{
    
    std::string first, last, userCorrect;
    bool correct = false;
    while(correct == false)
    {
        std::cout << "I need some information from you.. \nWhat is your first name? "; 
        std::cin >> first;
        std::cout << "Great " << first << "! What's your last name? ";
        std::cin >> last;
        std::cout << "Your name is " << first << " " << last << " Your id is " << id << "\nIs this information correct? Y or N\n";
        std::cin >> userCorrect;
        if(userCorrect == "Y" || userCorrect == "y") correct = true;
    }
    Tickets temp(first, last, id);
    f->passengers.emplace_back(temp);
    f->size++;
    std::cout << temp.first_name << ", you have been booked for " << f->location << "\n";
}
void addPassenger(int& id, int& passengerID)
{
    for(Flights *itr = head; itr != NULL; itr = itr->next)
    {
        if(itr->id == id)
        {
            getPassengerInfo(itr, passengerID);
        }
    }
}
void startProgram(int& menu)
{
    int ticketID = hash(), idLocation = 0;
    if(menu == 1)
    {
        std::cout << "Please choose a destination\n";
        printList();
        std::cout << "\nYour ticket number is: " << ticketID << "\nPlease save this number.";
        std::cout << "\nWhere would you like to go? Please use the ID code above for your destination.\n";
        std::cin >> idLocation;
        for(Flights *it = head; it != NULL; it = it->next)
        {
            if(it->id == idLocation && (it->cap - it->size >= 0)) addPassenger(idLocation, ticketID);
        }
    }
}

/* -------------------------------------------------------------------------------------------------- */
           
//  Below will be used for removing a ticket item

/* -------------------------------------------------------------------------------------------------- */

void removePassenger()
{
    //std::cout 
    //FIXME need to finish. 
}
