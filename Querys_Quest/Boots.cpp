/******************************************************************************
** Program name: Query's Quest
** File: Boots.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Boots which is a
**      subclass of Space and represents Boots tiles in the game board.
******************************************************************************/

#include "Boots.hpp"
#include <iostream>


/******************************************************************************
** Function: Boots()
** Description: Default constructor for Boots object.
******************************************************************************/
Boots::Boots()
{
    spaceType = BOOTS;
    symbol = "D ";
    name = "";
}


/******************************************************************************
** Function: Boots(ItemType itemType)
** Description: Constructor that takes in the itemType and creates a Boots
**      object with the corresponding item image. Used for item display only.
******************************************************************************/
Boots::Boots(ItemType itemType)
{
    spaceType = BOOTS;
    symbol = "D ";
    name = "";
    this->itemType = itemType;

    if (itemType == WATERBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_water_boots.png"));
    }
    else if (itemType == FIREBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_fire_boots.png"));
    }
    else if (itemType == ICEBOOTS)
    {
        setPixmap(QPixmap(":/images/plain_ice_boots.png"));
    }
}


/******************************************************************************
** Function: Boots(string, ItemType, string)
** Description: Constructor that takes in a string for the boot symbol, a
**      string for the boot name, and an ItemType to define what kind of boot
**      this will be. Uses the input to create a specific version of a Boot.
******************************************************************************/
Boots::Boots(std::string symbol, ItemType itemType, std::string name)
{
    spaceType = BOOTS;
    this->symbol = symbol;
    this->itemType = itemType;
    this->name = name;

    if (itemType == WATERBOOTS)
    {
        setPixmap(QPixmap(":/images/water_boots.png"));
    }
    else if (itemType == FIREBOOTS)
    {
        setPixmap(QPixmap(":/images/fire_boots.png"));
    }
    else if (itemType == ICEBOOTS)
    {
        setPixmap(QPixmap(":/images/ice_boots.png"));
    }
}


/******************************************************************************
** Function: ~Boots()
** Description: Destructor for Boots object.
******************************************************************************/
Boots::~Boots()
{
}


/******************************************************************************
** Description: Getter for name.
******************************************************************************/
std::string Boots::getName()
{
    return name;
}


/******************************************************************************
** Function: displayMessage()
** Description: Displays message if player attempts to go onto a Boots space.
******************************************************************************/
void Boots::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** ";

    // Displays a different message for each type of different Boot
    if (itemType == WATERBOOTS)
    {
        std::cout << "Query found the water boots!" << std::endl;
        std::cout << "Now he can walk on water!" << std::endl;
    }
    else if (itemType == FIREBOOTS)
    {
        std::cout << "Query found the fire boots!" << std::endl;
        std::cout << "Now he can walk on fire!" << std::endl;
    }
    else if (itemType == ICEBOOTS)
    {
        std::cout << "Query found the ice boots!" << std::endl;
        std::cout << "Now he can walk on ice!" << std::endl;
    }
}
