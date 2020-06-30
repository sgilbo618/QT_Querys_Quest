/******************************************************************************
** Program name: Query's Quest
** File: Water.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of class Water which is a subclass
**      of Space and represents Water tiles in the game board. Water spaces will
**      kill the player if the player attempts to access the space without the
**      water boots.
******************************************************************************/

#include "Water.hpp"


/******************************************************************************
** Function: Water()
** Description: Default constructor for Water object.
******************************************************************************/
Water::Water()
{
    spaceType = ELEMENT;
    elementType = WATER;

    // Set image
    setPixmap(QPixmap(":/images/water.png"));

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/splash.wav"));
}


/******************************************************************************
** Function: ~Water()
** Description: Destructor for Water object.
******************************************************************************/
Water::~Water()
{
}
