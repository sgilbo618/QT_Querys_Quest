/******************************************************************************
** Program: Query's Quest
** File: Space.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the implementation of the base class Space.  It has
**      enums to difine the types of spaces, the types of elements, and the
**      types of items. Each space object will have members to categorize the
**      type of space it is. Each space object has pointers to the four spaces
**      that surround it for game board navigation. Spaces also have sounds.
**      All spaces will have methods for getting and setting the default data
**      members.
******************************************************************************/

#include "Space.hpp"


/******************************************************************************
** Function: Space()
** Description: Default constructor for Space object.
******************************************************************************/
Space::Space()
{
    elementType = NON;
    itemType = NONE;
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}


/******************************************************************************
** Function: ~Space()
** Description: Destructor for Space object.
******************************************************************************/
Space::~Space()
{
}


/******************************************************************************
** Description: Getters for types.
******************************************************************************/
SpaceType Space::getSpaceType()
{
    return spaceType;
}

ElementType Space::getElementType()
{
    return elementType;
}

ItemType Space::getItemType()
{
    return itemType;
}


/******************************************************************************
** Description: Getter and Setter for up.
******************************************************************************/
Space * Space::getUp()
{
    return up;
}

void Space::setUp(Space * up)
{
    this->up = up;
}


/******************************************************************************
** Description: Getter and Setter for down.
******************************************************************************/
Space * Space::getDown()
{
    return down;
}

void Space::setDown(Space * down)
{
    this->down = down;
}


/******************************************************************************
** Description: Getter and Setter for left.
******************************************************************************/
Space * Space::getLeft()
{
    return left;
}

void Space::setLeft(Space * left)
{
    this->left = left;
}


/******************************************************************************
** Description: Getter and Setter for right.
******************************************************************************/
Space * Space::getRight()
{
    return right;
}

void Space::setRight(Space * right)
{
    this->right = right;
}


/******************************************************************************
** Description: Plays the sound associated with the space.
******************************************************************************/
void Space::playSound()
{
    sound->play();
}

void Space::updateSound(QUrl url)
{
    sound->setMedia(QUrl(url));
}
