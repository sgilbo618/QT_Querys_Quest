/******************************************************************************
** Program name: Query's Quest
** File: Boots.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Boots which is a
**      subclass of Space and represents Boots tiles in the game board. Has two
**      over- loaded contructors. One is used for the game board spaces, the
**      other is a dummy for the items display. Boots are items that can be
**      collected by the player. They are used to be able to traverse the
**      corresponding elements.
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
** Description: Dummy Constructor that takes in the itemType and creates a Boots
**      object with the corresponding item image. Used for item display only.
**      Uses dummy parameter to distinguish it from the other constructor.
******************************************************************************/
Boots::Boots(ItemType itemType, int dummy)
{
    spaceType = BOOTS;
    this->itemType = itemType;

    // Set image - these images are different from the other constructor
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
** Function: Boots(ItemType)
** Description: Constructor that takes in an ItemType to define what boot
**      this will be. Uses the input to create a specific version of a Boot.
******************************************************************************/
Boots::Boots(ItemType itemType)
{
    spaceType = BOOTS;
    this->itemType = itemType;

    // Set image
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
