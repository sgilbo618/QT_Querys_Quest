/******************************************************************************
** Program name: Query's Quest
** File: Door.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Door which is a
**      subclass of Space and represents Door tiles in the game board.
******************************************************************************/

#include "Door.hpp"
#include <iostream>


/******************************************************************************
** Function: Door()
** Description: Default constructor for Door object.
******************************************************************************/
Door::Door()
{
    spaceType = DOOR;
    symbol = "D ";
    isLocked = true;
}


/******************************************************************************
** Function: Door(string)
** Description: Constructor that takes in a string for the symbol of a door
**      and uses it to create a specific version of a Door.
******************************************************************************/
Door::Door(std::string symbol)
{
    spaceType = DOOR;
    this->symbol = symbol;
    isLocked = true;

    if (symbol == "O ")
    {
        setPixmap(QPixmap(":/images/orange_door.png"));
    }
    else if (symbol == "G ")
    {
        setPixmap(QPixmap(":/images/green_door.png"));
    }
    else if (symbol == "Y ")
    {
        setPixmap(QPixmap(":/images/yellow_door.png"));
    }
    else if (symbol == "! ")
    {
        setPixmap(QPixmap(":/images/locked_portal.png"));
    }

    // Set sound
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/oof.wav"));
}


/******************************************************************************
** Function: ~Door()
** Description: Destructor for Door object.
******************************************************************************/
Door::~Door()
{
}


/******************************************************************************
** Description: Getter and Setter for isLocked.
******************************************************************************/
bool Door::getIsLocked()
{
    return isLocked;
}

void Door::setIsLocked(bool isLocked)
{
    this->isLocked = isLocked;
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays message if player attempts to go onto a Door space.
******************************************************************************/
void Door::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** ";

    // When a door is locked, it cannot be passed
    if (isLocked)
    {
        if (symbol == "O ")
        {
            std::cout << "This door is locked - Query needs the orange key to go in here." << std::endl;
        }
        else if (symbol == "G ")
        {
            std::cout << "This door is locked - Query needs the green key to go in here." << std::endl;
        }
        else if (symbol == "Y ")
        {
            std::cout << "This door is locked - Query needs the yellow key to go in here." << std::endl;
        }
        else if (symbol == "! ")
        {
            std::cout << "The final door is locked - Query needs to collect all of the queries to win." << std::endl;
        }
    }
    // The door is unlocked messages
    else
    {
        if (symbol == "O ")
        {
            std::cout << "Query used the orange key to unlock the orange door!" << std::endl;
        }
        else if (symbol == "G ")
        {
            std::cout << "Query used the green key to unlock the green door!" << std::endl;
        }
        else if (symbol == "Y ")
        {
            std::cout << "Query used the yellow key to unlock the yellow door!" << std::endl;
        }
        else if (symbol == "! ")
        {
            std::cout << "Query completed level 1 of Query's Quest! Congrats!!" << std::endl;
        }
    }
}
