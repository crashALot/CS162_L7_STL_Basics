/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This file contains that associated prototypes and
*               interfaces required to use the stack.cpp file. 
*********************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include <stack>
#include <string>
#include "menuValidation.hpp"

class Stack
{
private:

    std::stack<char> palindrome;
    std::string targetWord;

public:

    Stack();
    void mainMenu();
    void stackInfo();
    void fillStack();
    void outputStack();
    ~Stack();

};

#endif
