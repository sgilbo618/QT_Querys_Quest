/******************************************************************************
** Program name: Query's Quest
** File: Free.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Free which is a
**      subclass of Space and represents open tiles on the game board.
******************************************************************************/

#include "Free.hpp"
#include <iostream>


/******************************************************************************
** Function: Free()
** Description: Default constructor for Free object.
******************************************************************************/
Free::Free()
{
    spaceType = FREE;
    symbol = "  ";

    setPixmap(QPixmap(":/images/floor.png"));
}


/******************************************************************************
** Function: ~Free()
** Description: Destructor for Free object.
******************************************************************************/
Free::~Free()
{
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays the direction the Player moved.
******************************************************************************/
void Free::displayMessage()
{
    // Does not need a message
}
