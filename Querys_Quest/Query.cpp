/******************************************************************************
** Program name: Query's Quest
** File: Query.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Query which is a
**      subclass of Space and represents query tiles on the game board.
******************************************************************************/

#include "Query.hpp"
#include <iostream>


/******************************************************************************
** Function: Query()
** Description: Default constructor for Query object.
******************************************************************************/
Query::Query()
{
    spaceType = QUERY;
    symbol = "? ";
    hasBeenCollected = false;

    // Set image
    setPixmap(QPixmap(":/images/query.png"));

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/query_pickup.wav"));
}


/******************************************************************************
** Function: ~Query()
** Description: Destructor for Query object.
******************************************************************************/
Query::~Query()
{
}


/******************************************************************************
** Description: Getter and Setter for hasBeenCollected.
******************************************************************************/
bool Query::getHasBeenCollected()
{
    return hasBeenCollected;
}

void Query::setHasBeenCollected(bool collected)
{
    this->hasBeenCollected = collected;
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays the direction the Player moved.
******************************************************************************/
void Query::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** Query found a query!" << std::endl;
}
