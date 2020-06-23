/******************************************************************************
** Program name: Query's Quest
** File: Fire.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Fire which is a
**      subclass of Space and represents Fire tiles in the game board.
******************************************************************************/

#include "Fire.hpp"
#include <iostream>


/******************************************************************************
** Function: Fire()
** Description: Default constructor for Fire object.
******************************************************************************/
Fire::Fire()
{
    spaceType = ELEMENT;
    elementType = FIRE;
    symbol = "* ";

    setPixmap(QPixmap(":/images/fire.png"));
}


/******************************************************************************
** Function: ~Fire()
** Description: Destructor for Fire object.
******************************************************************************/
Fire::~Fire()
{
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays message if player attempts to go onto a Fire space.
******************************************************************************/
void Fire::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** Query is on Fire without Fire boots! - He dead" << std::endl;
}
