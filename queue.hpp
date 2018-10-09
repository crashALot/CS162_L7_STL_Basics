/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        8/14/2018
** Description: This file contains that associated prototypes and
*               interfaces required to use the queue.cpp file. 
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "menuValidation.hpp"
#include <queue>

class Queue
{
private:

    int numRounds, percentPush, percentPop, counts;
    std::queue<int> howDoYouQueue;
    double averageLength;

public:

    Queue();
    void mainMenu();
    void queueInfo();
    double randomGenerator();
    void fillQueue();
    void outputBuffer();
    void averageBuffer();
    void setNumRounds(int);
    void setPercentEnd(int);
    void setPercentBegin(int);
    int getNumRounds();
    int getPercentEnd();
    int getPercentBegin();
    ~Queue();

};

#endif