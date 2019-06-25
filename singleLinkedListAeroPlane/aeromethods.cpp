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
    if(menu == 2)
    {
        removePassenger();
    }
    if(menu == 4)
    {
        display();
    }
}

/* -------------------------------------------------------------------------------------------------- */
           
//  Below will be used for removing a ticket item

/* -------------------------------------------------------------------------------------------------- */

void removePassenger()
{
    std::string lname = "", fname = "";
    std::cout << "What is your last name?\n";
    std::cin >> lname;
    std::cout << "What is your first name?\n";
    std::cin >> fname;
    //This is the brute force method.. In the future I could implement my linkedList as a BST for faster search time. 
    //current run time for brute force method is O(n^2).. BST would cut it down to O(n log N).  
    for(Flights *it = head->next; it != NULL; it = it->next)
    {
        for(int i = 0; i < it->passengers.size(); i++)
        {
            if(it->passengers[i].first_name == fname && it->passengers[i].last_name == lname)
            {
                std::string temp;
                std::cout << "Your ticket has been found. Are you sure you want to cancel your reservation? Y or N\n";
                std::cin >> temp;
                if(temp == "Y")
                {
                    std::cout << "Please confirm your id number:\nID: ";
                    int testID = 0;
                    std::cin >> testID;
                    //Once the ID has been confirmed, then delete that passenger from the flight. 
                    if(testID == it->passengers[i].id) 
                    {
                        it->passengers.erase(it->passengers.begin() + i); 
                        std::cout << "Confirmed, you are removed from this flight\n"; 
                    }
                }
            }
        }
    }
  //  FIXME need to finish. 
}



/* -------------------------------------------------------------------------------------------------- */
           
//  Below will be used for displaying LinkedList

/* -------------------------------------------------------------------------------------------------- */

void display()
{
    for(Flights *it = head->next; it != NULL; it = it->next)
    {
        std::cout << "For " << it->location << "\n"; 
        for(int i = 0; i < it->passengers.size(); i++)
        {
            std::cout << it->passengers[i].last_name << ", " << it->passengers[i].first_name <<"\n"; 
        }
    }
    std::cout << std::endl;
}







