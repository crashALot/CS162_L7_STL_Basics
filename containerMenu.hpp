/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This file contains that associated prototypes and
*               interfaces required to use the containerMenu.cpp
*               file. 
*********************************************************************/
#ifndef CONTAINERMENU_HPP
#define CONTAINERMENU_HPP
#include "menuValidation.hpp"
#include "queue.hpp"
#include "stack.hpp"

class Menu
{
private:

public:

    Menu();
    void mainMenu();
    void queue();
    void stack();
    void exitMenu();
    ~Menu();

};


#endif