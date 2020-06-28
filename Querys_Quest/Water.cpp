/******************************************************************************
** Program name: Query's Quest
** File: Water.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Water which is a
**      subclass of Space and represents Water tiles in the game board.
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
