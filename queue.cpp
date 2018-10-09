/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This file allows the user to create and program a
*               small exercise using queues. 
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include "queue.hpp"

/********************************************************************* 
** Description: Queue::Queue()
*               Queue class default constructor
*********************************************************************/
Queue::Queue()
{
    numRounds=-1;
    percentPush=-1;
    percentPop=-1;
    counts=1;
}

/********************************************************************* 
** Description: void Queue::mainMenu()
*               Prompts the user to run the simulation or exit
*********************************************************************/
void Queue::mainMenu()
{
    std::cout << std::endl << "  ********** Welcome to the Queue function! **********" << std::endl << std::endl;
    std::cout << "       Please select from an option below:" << std::endl;
    std::cout << "         1. Run the Queue function" << std::endl;
    std::cout << "           2. Exit the Queue function" << std::endl;
    std::cout << "      -> ";
    int userSelection=subMenuValidate();
    switch (userSelection)
    {
        case 1:
        queueInfo();
        break;
        
        case 2:
        break;
    }
}

/********************************************************************* 
** Description: void Queue::queueInfo()
*               Prompts user for information regarding the queue
*               simulation
*********************************************************************/
void Queue::queueInfo()
{
    std::cout << std::endl << "  How many rounds will be simulated?" << std::endl;
    std::cout << "      -> ";
    numRounds=queueRoundsValidate();
    std::cout << "  What is the percentage chance to put a randomly generated number at the end of buffer?" << std::endl;
    std::cout << "      -> ";
    percentPush=queuePercentValidate();
    std::cout << "  What is the percentage chance to take out a randomly generated number at the front of buffer?" << std::endl;
    std::cout << "      -> ";
    percentPop=queuePercentValidate();
    fillQueue();
}

/********************************************************************* 
** Description: double Queue::randomGenerator()
*               Generates a double value between 0 and 1
*********************************************************************/
double Queue::randomGenerator()
{
    return (static_cast<double>(rand()))/(static_cast<double>(RAND_MAX));
}

/********************************************************************* 
** Description: void Queue::fillQueue()
*               The following is the flow of each round in the 
*               simulation: Generate a random number from 1 – 1000
*               called N. Appending number: Generate another random 
*               number from 1 – 100, if the outcome is less than or
*               equal to the user specified percentage for adding value
*               (Ex: 25), then append the number N into the queue. 
*               Removing numbers: Generate another random number from 
*               1 – 100, if the outcome is less than or equal to the
*               user specified percentage for removing value (Ex: 25), 
*               then remove a number from the front of queue. Output
*               the values in the buffer, and then output the length 
*               of the buffer. Output the average length of buffer.
*********************************************************************/
void Queue::fillQueue()
{
    std::cout << std::endl << "Starting function. Queue contains: " << howDoYouQueue.size() << " elements." << std::endl << std::endl;
    int N, numRange=1000, probability=100;
    for (int i=0; i<numRounds; i++)
    {
        N=randomGenerator()*numRange;
        std::cout << "   The randomly generated value N is " << N << std::endl;
        double randomPush=randomGenerator()*probability;
        std::cout << "   The randomPush value is " << randomPush << std::endl;
        if (randomPush<=percentPush)
        {
            std::cout << "      -> The randomly generated value " << N << " was added to the end of the queue." << std::endl;
            howDoYouQueue.push(N);
        }
        double randomPop=randomGenerator()*probability;
        std::cout << "   The randomPop value is " << randomPop << std::endl;
        if (randomPop<=percentPop)
        {
            if (howDoYouQueue.empty()!=true)
            {
                std::cout << "      -> The previously generated value " << howDoYouQueue.front() << " was removed from the front of the queue." << std::endl;
                howDoYouQueue.pop();
            }
            else
                std::cout << "    -> There are no values in the queue which can be removed this turn." << std::endl;
        }
        outputBuffer();
        averageBuffer();
        std::cout << "   After turn " << i+1 << " the queue holds " << howDoYouQueue.size() << " elements." << std::endl;
        std::cout << "   _________________________________________" << std::endl << std::endl;
    }
}

/********************************************************************* 
** Description: void Queue::outputBuffer()
*               Prints to consol the contents of the queue
*********************************************************************/
void Queue::outputBuffer()
{
    std::cout << std::endl << "  Current buffer list: " << std::endl;
    int tempVar;
    for (int j=0; (unsigned)j<howDoYouQueue.size(); j++)
    {
        tempVar=howDoYouQueue.front();
        std::cout << std::setw(j+6) << tempVar << std::endl;
        howDoYouQueue.pop();
        howDoYouQueue.push(tempVar);
    }
    std::cout << std::endl;
}

/********************************************************************* 
** Description: void Queue::averageBuffer()
*               Determines the running average of the randomly 
*               generated list found in the queue
*********************************************************************/
void Queue::averageBuffer()
{
    // Average list length calaculated from below equation:
    // ALi = (ALi-1 * (i – 1) + Li ) / i 
    averageLength=(static_cast<double>(averageLength)*static_cast<double>(counts-1)+static_cast<double>(howDoYouQueue.size()))/static_cast<double>(counts);   
    std::cout << "   Average length is: " << averageLength << std::endl; 
    counts++;
}

/********************************************************************* 
** Description: Get and Set functions
*               Allows the user to edit or retrieve queue class 
*               member variables.
*********************************************************************/
void Queue::setNumRounds(int numRoundsIn)
{
    numRounds=numRoundsIn;
}

void Queue::setPercentEnd(int chanceEnd)
{
    percentPush=chanceEnd;
}

void Queue::setPercentBegin(int chanceBegin)
{
    percentPop=chanceBegin;
}

int Queue::getNumRounds()
{
    return numRounds;
}

int Queue::getPercentEnd()
{
    return percentPush;
}

int Queue::getPercentBegin()
{
    return percentPop;
}

/********************************************************************* 
** Description: Queue::~Queue()
*               Queue class destructor              
*********************************************************************/
Queue::~Queue()
{
    
}

