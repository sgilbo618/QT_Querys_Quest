/******************************************************************************
** Program name: Query's Quest
** File: Wall.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the implementation of the class Wall which is a
**      subclass of Space and represents wall tiles in the game board. Wall
**      spaces act as a boundary to define the level rooms.
******************************************************************************/

#include "Wall.hpp"


/******************************************************************************
** Function: Wall()
** Description: Default constructor for Wall object.
******************************************************************************/
Wall::Wall()
{
    spaceType = WALL;

    // Set image
    setPixmap(QPixmap(":/images/wall.png"));

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/oof.wav"));
}


/******************************************************************************
** Function: ~Wall()
** Description: Destructor for Wall object.
******************************************************************************/
Wall::~Wall()
{
}
