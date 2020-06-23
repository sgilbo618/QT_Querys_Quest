/******************************************************************************
** Program name: Query's Quest
** File: Key.cpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the implementation of the class Key which is a
**      subclass of Space and represents Key tiles in the game board.
******************************************************************************/

#include "Key.hpp"
#include <iostream>


/******************************************************************************
** Function: Key()
** Description: Default constructor for Key object.
******************************************************************************/
Key::Key()
{
    spaceType = KEY;
    symbol = "k ";
    name = "k";
}


/******************************************************************************
** Function: Key(string, ItemType, string)
** Description: Constructor that takes in a string for the symbol of the key,
**      a string for the name of the key, and an ItemType for the specific
**      version of the key. Uses input to create a specific version of a Key.
******************************************************************************/
Key::Key(std::string symbol, ItemType itemType, std::string name)
{
    spaceType = KEY;
    this->symbol = symbol;
    this->itemType = itemType;
    this->name = name;

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
}


/******************************************************************************
** Function: ~Key()
** Description: Destructor for Key object.
******************************************************************************/
Key::~Key()
{
}


/******************************************************************************
** Description: Getter for name.
******************************************************************************/
std::string Key::getName()
{
    return name;
}



/******************************************************************************
** Function: displayMessage()
** Description: Displays message if player attempts to go onto a Key space.
******************************************************************************/
void Key::displayMessage()
{
    std::cout << std::endl;
    std::cout << "** ";

    // Display message based on the spefic key that was found
    if (itemType == ORANGEKEY)
    {
        std::cout << "Query found the orange key!" << std::endl;
    }
    else if (itemType == GREENKEY)
    {
        std::cout << "Query found the green key!" << std::endl;
    }
    else if (itemType == YELLOWKEY)
    {
        std::cout << "Query found the yellow key!" << std::endl;
    }
}
