/******************************************************************************
** Program name: Query's Quest
** File: Boots.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Boots which is a subclass
**      of Space and represents Boots tiles in the game board. Has two over-
**      loaded contructors. One is used for the game board spaces, the other
**      is a dummy for the items display. Boots are items that can be collected
**      by the player. They are used to be able to traverse the corresponding
**      elements.
******************************************************************************/

#ifndef BOOTS_HPP
#define BOOTS_HPP

#include "Space.hpp"


class Boots : public Space
{
public:
    Boots();
    Boots(ItemType itemType, int dummy);
    Boots(ItemType itemType);
    ~Boots();
};

#endif // !BOOTS_HPP
