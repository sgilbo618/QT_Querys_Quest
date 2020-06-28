/******************************************************************************
** Program name: Query's Quest
** File: Ice.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Ice which
**				is a subclass of Space and represents Ice tiles in
**				the game board.
******************************************************************************/

#include "Ice.hpp"
#include <iostream>


/******************************************************************************
** Function: Ice()
** Description: Default constructor for Ice object.
******************************************************************************/
Ice::Ice()
{
    spaceType = ELEMENT;
    elementType = ICE;
    symbol = "/ ";

    setPixmap(QPixmap(":/images/ice.png"));

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/slip.wav"));
}


/******************************************************************************
** Function: ~Ice()
** Description: Destructor for Ice object.
******************************************************************************/
Ice::~Ice()
{
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays message if player attempts to go onto a Ice space.
******************************************************************************/
void Ice::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** Query is on ice without ice boots." << std::endl;
    std::cout << "Ice makes him slide until he gets a non-ice space" << std::endl;
}
