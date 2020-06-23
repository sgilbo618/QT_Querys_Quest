/*********************************************************************
** Program name: Query's Quest
** File: Wall.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the implementation of the class Wall which
**				is a subclass of Space and represents wall tiles in
**				the game board.
*********************************************************************/

#include "Wall.hpp"
#include <iostream>


/*********************************************************************
** Function: Wall()
** Description: Default constructor for Wall object.
*********************************************************************/
Wall::Wall()
{
    spaceType = WALL;
    symbol = "# ";

    setPixmap(QPixmap(":/images/wall.png"));
}


/*********************************************************************
** Function: ~Wall()
** Description: Destructor for Wall object.
*********************************************************************/
Wall::~Wall()
{
}


/*********************************************************************
** Function: displayMessage()
** Description: Displays message to user if player attempts to go
**				onto a Wall space.
*********************************************************************/
void Wall::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** This is a wall - can't go here!" << std::endl;
}
