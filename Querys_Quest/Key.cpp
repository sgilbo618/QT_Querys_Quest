/******************************************************************************
** Program name: Query's Quest
** File: Key.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Key which is a
**      subclass of Space and represents Key tiles in the game board.
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
** Description: Constructor that takes in the itemType and creates a Key object
**          with the corresponding item image. Used for item display only.
******************************************************************************/
Key::Key(ItemType itemType, int dummy)
{
    spaceType = KEY;
    this->itemType = itemType;

    // Set image
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
** Function: Key(string, ItemType, string)
** Description: Constructor that takes in a string for the symbol of the key,
**      a string for the name of the key, and an ItemType for the specific
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
