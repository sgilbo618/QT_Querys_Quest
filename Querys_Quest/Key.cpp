/******************************************************************************
** Program name: Query's Quest
** File: Key.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of class Key which is a subclass
**      of Space and represents Key tiles in the game board. Has two over-
**      loaded constructors. One is used for the game board spaces. The other
**      is a dummy for the items display. Keys are items that can be collected
**      by the player. They are needed to unlock the corresponding colored door.
******************************************************************************/

#include "Key.hpp"


/******************************************************************************
** Function: Key()
** Description: Default constructor for Key object.
******************************************************************************/
Key::Key()
{
    spaceType = KEY;
}


/******************************************************************************
** Function: Key(ItemType itemType, int dummy)
** Description: Dummy Constructor that takes in the itemType and creates a Key
**      object with the corresponding item image. Used for item display only.
**      Uses dummy parameter to distinguish it from the other constructor.
******************************************************************************/
Key::Key(ItemType itemType, int dummy)
{
    spaceType = KEY;
    this->itemType = itemType;

    // Set image - these images are different from the game board images
    if (itemType == ORANGEKEY)
    {
        setPixmap(QPixmap(":/images/plain_orange_key.png"));
    }
    else if (itemType == GREENKEY)
    {
        setPixmap(QPixmap(":/images/plain_green_key.png"));
    }
    else if (itemType == YELLOWKEY)
    {
        setPixmap(QPixmap(":/images/plain_yellow_key.png"));
    }
}


/******************************************************************************
** Function: Key(ItemType)
** Description: Constructor that takes in an ItemType for the specific
**      version of the key. Uses input to create a specific version of a Key.
******************************************************************************/
Key::Key(ItemType itemType)
{
    spaceType = KEY;
    this->itemType = itemType;

    // Set image
    if (itemType == ORANGEKEY)
    {
        setPixmap(QPixmap(":/images/orange_key.png"));
    }
    else if (itemType == GREENKEY)
    {
        setPixmap(QPixmap(":/images/green_key.png"));
    }
    else if (itemType == YELLOWKEY)
    {
        setPixmap(QPixmap(":/images/yellow_key.png"));
    }

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/pickup.wav"));
}


/******************************************************************************
** Function: ~Key()
** Description: Destructor for Key object.
******************************************************************************/
Key::~Key()
{
}
