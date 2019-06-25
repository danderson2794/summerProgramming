/*
 * =====================================================================================
 *
 *       Filename:  aeromethods.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/2019 02:09:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include<cstdlib>

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

extern Flights *head;

void printMenu();
int getUserInput();
void addFlights();
void printList();
void getPassengerInfo(Flights* f, int& id);
void addPassenger(int&, int&);
void startProgram(int&);

