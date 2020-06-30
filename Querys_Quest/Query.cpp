/******************************************************************************
** Program name: Query's Quest
** File: Query.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of class Query which is a subclass
**      of Space and represents open tiles on the game board. Has a data
**      member to track if it has been collected, and methods to get and set
**      the data member. Query spaces must be collected by the player in order
**      to unlock the final door.
******************************************************************************/

#include "Query.hpp"


/******************************************************************************
** Function: Query()
** Description: Default constructor for Query object.
******************************************************************************/
Query::Query()
{
    spaceType = QUERY;
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
** Description: Getter and Setter for hasBeenCollected. Used to make sure the
**      player can only collect a query space one time.
******************************************************************************/
bool Query::getHasBeenCollected()
{
    return hasBeenCollected;
}

void Query::setHasBeenCollected(bool collected)
{
    this->hasBeenCollected = collected;
}
