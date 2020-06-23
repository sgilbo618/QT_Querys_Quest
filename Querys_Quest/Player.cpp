/******************************************************************************
** Program name: Query's Quest
** File: Player.cpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the implementation of class Player which represents
**      the main character, Query, in the game Query's Quest. Player has
**      containers to keep track of keys, boots, and queries.
******************************************************************************/

#include "Player.hpp"
//#include "Door.hpp"
//#include "Key.hpp"
//#include "Boots.hpp"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <QKeyEvent>


/******************************************************************************
** Function: Player()
** Description: Default constructor for Player object.
******************************************************************************/
Player::Player()
{
//    playerPtr = nullptr;
//    direction = UP;
//    isAlive = true;
//    steps = MAX_STEPS;
//    numberOfItems = 0;
//    queries = QUERIES_NEEDED;

    setPixmap(QPixmap(":/images/walking_guy.png"));
}


/******************************************************************************
** Function: ~Player()
** Description: Destructor for Player object.
******************************************************************************/
Player::~Player()
{
}


///******************************************************************************
//** Description: Getter for direction.
//******************************************************************************/
//Direction Player::getDirection()
//{
//    return direction;
//}


///******************************************************************************
//** Function: checkIsAlive()
//** Description: Checks number of steps and what space the player is on
//**				and determines if the player is still alive or not.
//**				Sets and returns isAlive. Will return true if still
//**				alive or false if not.
//******************************************************************************/
//bool Player::checkIsAlive()
//{
//    if (steps == 0)
//    {
//        std::cout << "Query ran out of steps and died!" << std::endl;
//        isAlive = false;
//    }

//    return isAlive;
//}


/******************************************************************************
** Function: getPlayerMove(QKeyEvent* event)
** Description: Gets and validates user input for player movement and
**				moves the player if the move is valid.
******************************************************************************/
void Player::keyPressEvent(QKeyEvent *event)
{
    // Up
    if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-GRID_STEP);
    }
    // Down
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+GRID_STEP);
    }
    // Left
    else if (event->key() == Qt::Key_Left)
    {
       // Don't move off board
       if (pos().x() > 0)
       {
            setPos(x()-GRID_STEP, y());
       }
    }
    // Right
    else if (event->key() == Qt::Key_Right)
    {
        // Don't move off board
        if (pos().x() + 100 < 800)
        {
            setPos(x()+GRID_STEP, y());
        }
    }

//    // Up
//    if ((move == 72 || move == 'A') && playerPtr->getUp() != nullptr) // && is for boundry checking
//    {
//        // Pass disired move to makeMove
//        makeMove(playerPtr->getUp());
//        direction = UP;
//    }
//    // Down
//    else if ((move == 80 || move == 'B') && playerPtr->getDown() != nullptr)
//    {
//        makeMove(playerPtr->getDown());
//        direction = DOWN;
//    }
//    // Left
//    else if ((move == 75 || move == 'D') && playerPtr->getLeft() != nullptr)
//    {
//        makeMove(playerPtr->getLeft());
//        direction = LEFT;
//    }
//    // Right
//    else if ((move == 77 || move == 'C') && playerPtr->getRight() != nullptr)
//    {
//        makeMove(playerPtr->getRight());
//        direction = RIGHT;
//    }
//    // q/Q allows user to exit game
//    else if (move == 'q' || move == 'Q')
//    {
//        isAlive = false;
//    }
//    // i/I allows user to print game information
//    else if (move == 'i' || move == 'I')
//    {
//        displayMapKey();
//    }
//    else
//    {
//        std::cout << std::endl << "** Invalid Move" << std::endl;
//    }
}


///******************************************************************************
//** Function: makeMove(Space*)
//** Description: Takes in the space the player is attempting to move to
//**				and moves there if it is a legal move.
//******************************************************************************/
//void Player::makeMove(Space * moveSpace)
//{
//    // Check if space is legal move
//    if (checkLegalMove(moveSpace))
//    {
//        // reset symbol to original
//        resetSpaceSymbol();

//        // Move player to new space
//        playerPtr = moveSpace;

//        // set new space symbol to Q
//        playerPtr->setSpaceSymbol("Q ");

//        // decrement steps
//        steps--;
//    }
//}


///******************************************************************************
//** Function: checkLegalMove(Space*)
//** Description: Checks the space Player is attempting to access and
//**				determines if the space is a legal move. Returns true
//**				if it is, false if it is not.
//******************************************************************************/
//bool Player::checkLegalMove(Space* moveSpace)
//{
//    bool isLegal = true;
//    SpaceType moveType = moveSpace->getSpaceType();

//    // Checks if next space is a wall
//    if (moveType == WALL)
//    {
//        moveSpace->displayMessage();
//        isLegal = false;
//    }

//    // Checks if Door is locked
//    if (moveType == DOOR)
//    {
//        if (static_cast<Door*>(moveSpace)->getIsLocked())
//        {
//            moveSpace->displayMessage();
//            isLegal = false;
//        }
//        else
//        {
//            moveSpace->displayMessage();
//        }
//    }

//    return isLegal;
//}


///******************************************************************************
//** Function: resetSpaceSymbol()
//** Description: Looks up the space type that the player is on and
//**				changes its symbol back to its orignal state.
//******************************************************************************/
//void Player::resetSpaceSymbol()
//{
//    SpaceType type = playerPtr->getSpaceType();
//    ElementType elementType = playerPtr->getElementType();

//    switch (type)
//    {
//    case FREE:
//        playerPtr->setSpaceSymbol("  ");
//        break;
//        // Unlocked Doors and items become vacant spaces after collection
//    case DOOR:
//        playerPtr->setSpaceSymbol("  ");
//        break;

//    case KEY:
//        playerPtr->setSpaceSymbol("  ");
//        break;

//    case BOOTS:
//        playerPtr->setSpaceSymbol("  ");
//        break;

//    case QUERY:
//        playerPtr->setSpaceSymbol("  ");
//        break;

//    default:
//        break;

//        // Elements return to their prevous symbol
//    case ELEMENT:
//    {
//        switch (elementType)
//        {
//        case ICE:
//            playerPtr->setSpaceSymbol("/ ");
//            break;

//        case FIRE:
//            playerPtr->setSpaceSymbol("* ");
//            break;

//        case WATER:
//            playerPtr->setSpaceSymbol("~ ");
//            break;

//        default:
//            break;
//        }
//        break;
//    }
//    }
//}


///******************************************************************************
//** Function: hasThisItem(ItemType)
//** Description: Takes in an ItemType and loops through the item array
//**				to search for it. Returns true if the item is found,
//**				false if it is not found.
//******************************************************************************/
//bool Player::hasThisItem(ItemType item)
//{
//    for (int i = 0; i < numberOfItems; i++)
//    {
//        if (items[i]->getItemType() == item)
//        {
//            return true;
//        }
//    }
//    return false;
//}


///******************************************************************************
//** Function: displayItems()
//** Description: Displays the items the player has collected.
//******************************************************************************/
//void Player::displayItems()
//{
//    std::cout << std::endl;

//    // Print steps
//    std::cout << "Steps Remaining: " << steps << std::endl;

//    // Print queries
//    std::cout << "Queries Remaining: " << queries << std::endl;

//    // Print keys
//    int numKeys = 0;
//    std::cout << " Keys: ";
//    for (int i = 0; i < numberOfItems; i++)
//    {
//        if (items[i]->getSpaceType() == KEY)
//        {
//            std::cout << static_cast<Key*>(items[i])->getName() << "  ";
//            numKeys++;
//        }
//    }
//    if (numKeys == 0)
//    {
//        std::cout << "empty";
//    }
//    std::cout << std::endl;

//    // Print boots
//    int numBoots = 0;
//    std::cout << "Boots: ";
//    for (int i = 0; i < numberOfItems; i++)
//    {
//        if (items[i]->getSpaceType() == BOOTS)
//        {
//            std::cout << static_cast<Boots*>(items[i])->getName() << "  ";
//            numBoots++;
//        }
//    }
//    if (numBoots == 0)
//    {
//        std::cout << "empty";
//    }
//    std::cout << std::endl;
//}

///******************************************************************************
//** Function: displayMapKey()
//** Description: Prints the key codes for each type of space and item
//**				on the game board.
//******************************************************************************/
//void Player::displayMapKey()
//{
//    std::cout << std::endl;
//    std::cout << "**********************************************************" << std::endl;
//    std::cout << "**                        Map Key                       **" << std::endl;
//    std::cout << "**********************************************************" << std::endl;
//    std::cout << std::endl;
//    std::cout << "   ----------------------------------------------------   " << std::endl;
//    std::cout << "           Elements          |            Boots           " << std::endl;
//    std::cout << "   --------------------------|-------------------------   " << std::endl;
//    std::cout << "    /  ice        ~  water   |     I  ice     W  water    " << std::endl;
//    std::cout << "    *  fire                  |     F  fire                " << std::endl;
//    std::cout << "   --------------------------|-------------------------   " << std::endl;
//    std::cout << "             Doors           |            Keys            " << std::endl;
//    std::cout << "   --------------------------|-------------------------   " << std::endl;
//    std::cout << "    G  green      B  blue    |     g  green    b  blue    " << std::endl;
//    std::cout << "    R  red                   |     r  red                 " << std::endl;
//    std::cout << "   --------------------------|-------------------------   " << std::endl;
//    std::cout << "             Other           |          Controls          " << std::endl;
//    std::cout << "   --------------------------|-------------------------   " << std::endl;
//    std::cout << "    Q  Query      !  finish  |     ^  up       v  down    " << std::endl;
//    std::cout << "    #  walls      ?  queries |     <  left     >  right   " << std::endl;
//    std::cout << std::endl;
//    std::cout << "   Press q to quit" << std::endl;
//    std::cout << "   Press i for map key" << std::endl;
//    std::cout << std::endl;
//}
