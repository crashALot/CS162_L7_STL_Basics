/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This file contains the initial menu options and basic 
*               driver functions for the program.
*********************************************************************/
#include "containerMenu.hpp"
#include <iostream>

/********************************************************************* 
** Description: Menu::Menu()
*               Menu class default constructor.
*********************************************************************/
Menu::Menu()
{
    
}

/********************************************************************* 
** Description: void Menu::mainMenu()
*               Main menu output to user first starting program. Allows 
*               user to choose which function they'd like to use
*********************************************************************/
void Menu::mainMenu()
{
    std::cout << std::endl << "  ********** Welcome to the Stack and Queue STL Containers program! **********" << std::endl << std::endl;
    std::cout << "       Please select from an option below:" << std::endl;
    std::cout << "         1. Go to Queue function" << std::endl;
    std::cout << "           2. Go to Stack function" << std::endl;
    std::cout << "             3. Exit the program" << std::endl;
    std::cout << "      -> ";
    int userSelection=mainMenuValidate();
    switch (userSelection)
    {
        case 1:
        queue();
        break;
        
        case 2:
        stack();
        break;
        
        case 3:
        exitMenu();
        break;
    }
}

/********************************************************************* 
** Description: void Menu::queue()
*               Driver function used to call queue function. Returns
*               user to main menu when done
*********************************************************************/
void Menu::queue()
{
   Queue newQueue;
   newQueue.mainMenu();
   mainMenu();
}

/********************************************************************* 
** Description: void Menu::stack()
*               Driver function used to call stack function. Returns
*               user to main menu when done
*********************************************************************/
void Menu::stack()
{
    Stack newStack;
    newStack.mainMenu();
    mainMenu();
}

/********************************************************************* 
** Description: void Menu::exitMenu()
*               Exit message left to user upon quitting the 
*               program
*********************************************************************/
void Menu::exitMenu()
{
    std::cout << std::endl << "    ************ See you again soon! ************" << std::endl << std::endl;
}

/********************************************************************* 
** Description: Menu::~Menu()
*               Menu class destructor
*********************************************************************/
Menu::~Menu()
{
    
}