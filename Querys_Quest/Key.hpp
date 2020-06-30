/******************************************************************************
** Program name: Query's Quest
** File: Key.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Key which is a subclass
**      of Space and represents Key tiles in the game board. Has two over-
**      loaded constructors. One is used for the game board spaces. The other
**      is a dummy for the items display. Keys are items that can be collected
**      by the player. They are needed to unlock the corresponding colored door.
******************************************************************************/

#ifndef KEY_HPP
#define KEY_HPP

#include "Space.hpp"


class Key : public Space
{
public:
    Key();
    Key(ItemType itemType, int dummy);
    Key(ItemType itemType);
    ~Key();
};

#endif // !KEY_HPP
