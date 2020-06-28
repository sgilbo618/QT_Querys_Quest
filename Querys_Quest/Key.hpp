/******************************************************************************
** Program name: Query's Quest
** File: Key.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Key which is a subclass
**      of Space and represents Key tiles in the game board.
******************************************************************************/

#ifndef KEY_HPP
#define KEY_HPP

#include "Space.hpp"


class Key : public Space
{
private:
    std::string name;

public:
    Key();
    Key(ItemType itemType);
    Key(std::string symbol, ItemType itemType, std::string name);
    ~Key();

    std::string getName();
    virtual void displayMessage();
};

#endif // !KEY_HPP
