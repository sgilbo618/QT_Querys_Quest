/******************************************************************************
** Program name: Query's Quest
** File: Fire.cpp
** Author: Samantha Guilbeault
** Date: 2-26-2019
** Description: Contains the implementation of the class Fire which is a
**      subclass of Space and represents Fire tiles in the game board.
**      Fire spaces will kill the player if the player attempts to access the
**      space without the fire boots.
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

    // Set image
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
