#include <iostream>
#include "aeromethods.h"
Flights *head;
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
