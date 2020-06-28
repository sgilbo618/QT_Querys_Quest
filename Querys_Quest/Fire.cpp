/******************************************************************************
** Program name: Query's Quest
** File: Fire.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Fire which is a
**      subclass of Space and represents Fire tiles in the game board.
******************************************************************************/

#include "Fire.hpp"


/******************************************************************************
** Function: Fire()
** Description: Default constructor for Fire object.
******************************************************************************/
Fire::Fire()
{
    spaceType = ELEMENT;
    elementType = FIRE;

    setPixmap(QPixmap(":/images/fire.png"));

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/lava_death.wav"));
}


/******************************************************************************
** Function: ~Fire()
** Description: Destructor for Fire object.
******************************************************************************/
Fire::~Fire()
{
}
