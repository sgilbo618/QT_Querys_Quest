/******************************************************************************
** Program name: Query's Quest
** File: Boots.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Boots which is a subclass
**      of Space and represents Boots tiles in the game board.
******************************************************************************/

#ifndef BOOTS_HPP
#define BOOTS_HPP

#include "Space.hpp"


class Boots : public Space
{
private:
    std::string name;

public:
    Boots();
    Boots(std::string symbol, ItemType itemType, std::string name);
    ~Boots();

    std::string getName();
    virtual void displayMessage();
};

#endif // !BOOTS_HPP
