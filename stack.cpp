/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This program will use a stack to create a function 
*               that creates a palindrome, which is a string that is 
*               the same forwards and backwards
*********************************************************************/
#include "stack.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

/********************************************************************* 
** Description: Stack::Stack()
*               Default Stack class constructor
*********************************************************************/
Stack::Stack()
{
    targetWord="Blank";
}

/********************************************************************* 
** Description: void Stack::mainMenu()
*               Prompts user to run palindrome function or exit
*********************************************************************/
void Stack::mainMenu()
{
    std::cout << std::endl << "  ********** Welcome to the Stack function! **********" << std::endl << std::endl;
    std::cout << "       Please select from an option below:" << std::endl;
    std::cout << "         1. Run the Stack function" << std::endl;
    std::cout << "           2. Exit the Stack function" << std::endl;
    std::cout << "      -> ";
    int userSelection=subMenuValidate();
    switch (userSelection)
    {
        case 1:
        stackInfo();
        break;
        
        case 2:
        break;
    }
}

/********************************************************************* 
** Description: void Stack::stackInfo()
*               Prompts user to enter string used to create palindrome 
*********************************************************************/
void Stack::stackInfo()
{
    std::cout << std::endl << "   Which word would you like to turn into a palindrome?" << std::endl;
    std::cout << "       -> ";
    std::cin >> targetWord;
    std::cout << std::endl;
    fillStack();
}

/********************************************************************* 
** Description: void Stack::fillStack()
*               Fills stack with individual characters from user specified
*               string
*********************************************************************/
void Stack::fillStack()
{
    int wordLength=targetWord.length();
    for (int i=0; i<wordLength; i++)
    {
        palindrome.push(targetWord[i]);
    }
    outputStack();
}

/********************************************************************* 
** Description: void Stack::outputStack()
*               Outputs to consol the finished palindrome by removing
*               one letter at a time from the stack.
*********************************************************************/
void Stack::outputStack()
{
    std::cout << "   Your palindrome is printed below:" << std::endl << std::endl;
    std::cout << "       -> ";
    std::cout << targetWord;
    char tempVar;
    int wordLength=targetWord.length();
    for (int j=0; j<wordLength; j++)
    {
        tempVar=palindrome.top();
        std::cout << tempVar;
        palindrome.pop();
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: Stack::~Stack()
*               Stack class deconstructor
*********************************************************************/
Stack::~Stack()
{
    
}