/******************************************************************************
** Program: Query's Quest
** File: Space.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the implementation of the class Space which is an
**              abstract base case that represents the basic tile of the game
**              board for Query's Quest. Each Space has a character to signify
**              it's type and four pointers to other Spaces in the directions
**              of up, down, left, and right.
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
** Description: Getter and Setter for symbol.
******************************************************************************/
std::string Space::getSpaceSymbol()
{
    return symbol;
}

void Space::setSpaceSymbol(std::string symbol)
{
    this->symbol = symbol;
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
