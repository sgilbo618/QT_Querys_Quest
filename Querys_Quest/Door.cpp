/******************************************************************************
** Program name: Query's Quest
** File: Door.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of class Door which is a subclass
**      of Space and represents Door tiles in the game board. Has members for
**      tracking if the door is locked and tracking if it is the first time at
**      the door. Has an overloaded constructor for setting door type and
**      methods for getting/setting data members.
******************************************************************************/

#include "Door.hpp"


/******************************************************************************
** Function: Door()
** Description: Default constructor for Door object.
******************************************************************************/
Door::Door()
{
    spaceType = DOOR;
    isLocked = true;
    isFirstTimeHere = true;
}


/******************************************************************************
** Function: Door(string)
** Description: Constructor that takes in a string for the symbol of a door
**      and uses it to create a specific version of a Door.
******************************************************************************/
Door::Door(std::string symbol)
{
    spaceType = DOOR;
    isLocked = true;
    isFirstTimeHere = true;

    // Set image
    if (symbol == "O ")
    {
        setPixmap(QPixmap(":/images/orange_door.png"));
    }
    else if (symbol == "G ")
    {
        setPixmap(QPixmap(":/images/green_door.png"));
    }
    else if (symbol == "Y ")
    {
        setPixmap(QPixmap(":/images/yellow_door.png"));
    }
    else if (symbol == "! ")
    {
        setPixmap(QPixmap(":/images/locked_portal.png"));
    }

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/oof.wav"));
}


/******************************************************************************
** Function: ~Door()
** Description: Destructor for Door object.
******************************************************************************/
Door::~Door()
{
}


/******************************************************************************
** Description: Getter and Setter for isLocked. Used to prevent door use until
**      the corresponding key is found.
******************************************************************************/
bool Door::getIsLocked()
{
    return isLocked;
}

void Door::setIsLocked(bool isLocked)
{
    this->isLocked = isLocked;
}


/******************************************************************************
** Description: Getter and Setter for isFirstTimeHere. Used to only play door
**      unlocking sound the first time it is passed.
******************************************************************************/
bool Door::getIsFirstTimeHere()
{
    return isFirstTimeHere;
}

void Door::setIsFirstTimeHere(bool swap)
{
    isFirstTimeHere = swap;
}
