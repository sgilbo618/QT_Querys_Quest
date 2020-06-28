/******************************************************************************
** Program name: Query's Quest
** File: Boots.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Boots which is a
**      subclass of Space and represents Boots tiles in the game board.
******************************************************************************/

#include "Boots.hpp"


/******************************************************************************
** Function: Boots()
** Description: Default constructor for Boots object.
******************************************************************************/
Boots::Boots()
{
    spaceType = BOOTS;
}


/******************************************************************************
** Function: Boots(ItemType itemType, int dummy)
** Description: Constructor that takes in the itemType and creates a Boots
**      object with the corresponding item image. Used for item display only.
******************************************************************************/
Boots::Boots(ItemType itemType, int dummy)
{
    spaceType = BOOTS;
    this->itemType = itemType;

    if (itemType == WATERBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_water_boots.png"));
    }
    else if (itemType == FIREBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_fire_boots.png"));
    }
    else if (itemType == ICEBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_ice_boots.png"));
    }
}


/******************************************************************************
** Function: Boots(string, ItemType, string)
** Description: Constructor that takes in a string for the boot symbol, a
**      string for the boot name, and an ItemType to define what kind of boot
**      this will be. Uses the input to create a specific version of a Boot.
******************************************************************************/
Boots::Boots(ItemType itemType)
{
    spaceType = BOOTS;
    this->itemType = itemType;

    if (itemType == WATERBOOTS)
    {
        setPixmap(QPixmap(":/images/water_boots.png"));
    }
    else if (itemType == FIREBOOTS)
    {
        setPixmap(QPixmap(":/images/fire_boots.png"));
    }
    else if (itemType == ICEBOOTS)
    {
        setPixmap(QPixmap(":/images/ice_boots.png"));
    }

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/pickup.wav"));
}


/******************************************************************************
** Function: ~Boots()
** Description: Destructor for Boots object.
******************************************************************************/
Boots::~Boots()
{
}
