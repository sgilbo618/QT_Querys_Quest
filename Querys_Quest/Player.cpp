/******************************************************************************
** Program name: Query's Quest
** File: Player.cpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the implementation of class Player which represents
**      the main character, Query, in the game Query's Quest. Player has
**      container to keep track of keys, boots, and queries.
******************************************************************************/

#include "Player.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "Boots.hpp"

#include <QKeyEvent>


/******************************************************************************
** Function: Player()
** Description: Default constructor for Player object.
******************************************************************************/
Player::Player()
{
    playerPtr = nullptr;
    direction = UP;
    isAlive = true;
    numberOfItems = 0;
    queries = QUERIES_NEEDED;

    setPixmap(QPixmap(":/images/walking_guy.png"));
}


/******************************************************************************
** Function: ~Player()
** Description: Destructor for Player object.
******************************************************************************/
Player::~Player()
{
}


/******************************************************************************
** Description: Getter for direction.
******************************************************************************/
Direction Player::getDirection()
{
    return direction;
}


/******************************************************************************
** Function: checkIsAlive()
** Description: Checks number of steps and what space the player is on and
**      determines if the player is still alive or not. Sets and returns
**      isAlive. Will return true if still alive or false if not.
******************************************************************************/
bool Player::checkIsAlive()
{
    return isAlive;
}


/******************************************************************************
** Function: makeMove(Space*, qreal, qreal)
** Description: Takes in the space of the game board and the coordinates of the
**      game display that the player is attempting to move to and moves there
**      if it is a legal move. Returns true if the move is made, and false if
**      the move is not made.
******************************************************************************/
bool Player::makeMove(Space * moveSpace, qreal move_x, qreal move_y)
{
    // Check if space is legal move
    if (checkLegalMove(moveSpace))
    {
        // Move player on display
        setPos(move_x, move_y);

        // Move player to new space
        playerPtr = moveSpace;

        // reset symbol to original
        resetSpaceSymbol();

        return true;
    }
    return false;
}


/******************************************************************************
** Function: checkLegalMove(Space*)
** Description: Checks the space Player is attempting to access and determines
**      if the space is a legal move. Returns true if it is, false if not.
******************************************************************************/
bool Player::checkLegalMove(Space* moveSpace)
{
    bool isLegal = true;
    SpaceType moveType = moveSpace->getSpaceType();

    // Checks if next space is a wall
    if (moveType == WALL)
    {
        moveSpace->playSound();
        isLegal = false;
    }

    // Checks if Door is locked
    if (moveType == DOOR)
    {
        if (static_cast<Door*>(moveSpace)->getIsLocked())
        {
            moveSpace->playSound();
            isLegal = false;
        }
        else
        {
            if (static_cast<Door*>(moveSpace)->getIsFirstTimeHere())
            {
                moveSpace->updateSound(QUrl("qrc:/sounds/unlock_door.wav"));
                moveSpace->playSound();
                static_cast<Door*>(moveSpace)->setIsFirstTimeHere(false);
            }
        }
    }

    return isLegal;
}


/******************************************************************************
** Function: resetSpaceSymbol()
** Description: Looks up the space type that the player is on and changes its
**      symbol back to its orignal state.
******************************************************************************/
void Player::resetSpaceSymbol()
{
    SpaceType type = playerPtr->getSpaceType();

    switch (type)
    {
        // Unlocked Doors and items become vacant spaces after collection
    case DOOR:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case KEY:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case BOOTS:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case QUERY:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    default:
        break;
    }
}


/******************************************************************************
** Function: hasThisItem(ItemType)
** Description: Takes in an ItemType and loops through the item array to search
**      for it. Returns true if the item is found, false if it is not found.
******************************************************************************/
bool Player::hasThisItem(ItemType item)
{
    for (int i = 0; i < numberOfItems; i++)
    {
        if (items[i]->getItemType() == item)
            return true;
    }
    return false;
}
