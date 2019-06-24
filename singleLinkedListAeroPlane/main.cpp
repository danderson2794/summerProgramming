#include <iostream>
#include <vector>
#include "aeromethods.h"
struct Tickets
{
    std::string last_name;
    Tickets *next;
    Tickets(){last_name = " "; next = nullptr; };
    Tickets(std::string n){last_name = n; next = nullptr;}
};

struct Flights 
{
    int flightNumber;
    Flights *next;
    std::vector<Tickets> tickets;
    Flights(){flightNumber = 0; tickets.reserve(100); next = nullptr;};
    Flights(int number) {flightNumber = number; next = nullptr;};
};

Flights *head;

void startProgram(int& menu);
int main()
{
    head = new Flights();
    int menu = 0;
    while(menu != 5)
    {
        printMenu();
        menu = getUserInput();
        if(menu < 5) startProgram(menu); 
    }

    return 0;
}

void startProgram(int& menu)
{
    if(menu == 1)
    {
        std::cout << "Great, we'll go ahead and give you a ticket number... \n\n Your ticket number is: ";kkkkkkkkkkkkkk
    }
}
