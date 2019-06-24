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


