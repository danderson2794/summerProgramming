#include <iostream>
#include <vector>
#include "aeromethods.h"
#include <cstdlib>

//structs to be used. 
struct Tickets
{
    std::string last_name, first_name;
    int id;
    Tickets(){last_name = first_name = "NULL";};
    Tickets(std::string f, std::string l, int i){ id = i; last_name = l; first_name = f;}
};

struct Flights 
{
    std::string location;
    int size, cap, id; 
    std::vector<Tickets> passengers;
    Flights *next; 
    Flights(){size = id = 0; location = "null"; cap = 5; next = nullptr;};
    Flights(int ID, std::string city) {id = ID; cap = 100; location = city; passengers.reserve(100); next = nullptr;};
};

Flights *head; //I could just pass it by reference the whole time, but I'm doing it the Dr. Dean way with a global variable. 

// private methods to be used in this file. 
/*
 * addFlights is used only to add flights to our linked list. Since this a basic program from a
 * textbook I'm going through over the summer and not actual production code, I will only add 3 basic
 * locations. IF this were to be production code, I would not do this. I am giving myself only 4 hours to finish
 * this programming assignment. 
 *
 * @pre *head != NULL
 * @post if(head != NULL) counter++; counter == 3;
 */
void addFlights()
{
    head->next = new Flights(1, "New York");
    head->next->next = new Flights(2, "San Jose");
    head->next->next->next = new Flights(3, "Houston");
}
/*
    startProgram is used as the main method for user interaction with the program. This may be an
    anti-pattern I change in the future, right now I'm just trying to create this program as fast as
    possible for the challenge.
    @pre *head != NULL  
*/
void startProgram(int& menu);


//FIXME one potential issue that would need to be fixed before this would actually be accepted
// is that there is potential for duplicate ticket ID's. I'll come back and input safety checks later. 
int hash(){return std::rand() % 2707;};

/*
 * printList() is only used to iterate through the Flights linked list. 
 * @pre *head != NULL
 * @post none. 
 */
void printList()
{
    for(Flights *itr = head->next; itr != NULL; itr = itr->next)
    {
        std::cout << itr->location << " ID: "<< itr->id << " Available: " << itr->cap - itr->size << "/" << itr->cap << std::endl;
    }
    std::cout << "\n";
}

int main()
{
    head = new Flights();
    addFlights();
    int menu = 0;
    while(menu != 5)
    {
        printMenu();
        menu = getUserInput();
        if(menu < 5) startProgram(menu); 
    }

    return 0;
}

void getPassengerInfo(Flights* f, int& id)
{
    bool correct = false;
    while(correct == false)
    {
        std::string first, last, userCorrect;
        std::cout << "I need some information from you.. \nWhat is your first name? "; 
        std::cin >> first;
        std::cout << "Great " << first << "! What's your last name? ";
        std::cin >> last;
        std::cout << "Your name is " << first << " " << last << " Your id is " << id << "\nIs this information correct? Y or N\n";
        std::cin >> userCorrect;
        if(userCorrect == "Y" || userCorrect == "y") correct = true;
    }
}

/*
 * @pre: head != NULL && head->passengers.size() <= head->cap;
 */
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
        addPassenger(idLocation, ticketID);
        
    }
}
