/******************************************************************************
** Program name: Query's Quest
** File: Free.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Free which is a
**      subclass of Space and represents open tiles on the game board.
******************************************************************************/

#include "Free.hpp"


/******************************************************************************
** Function: Free()
** Description: Default constructor for Free object.
******************************************************************************/
Free::Free()
{
    spaceType = FREE;

    // Set image
    setPixmap(QPixmap(":/images/floor.png"));
}


/******************************************************************************
** Function: ~Free()
** Description: Destructor for Free object.
******************************************************************************/
Free::~Free()
{
}
