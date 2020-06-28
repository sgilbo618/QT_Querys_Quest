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
public:
    Key();
    Key(ItemType itemType, int dummy);
    Key(ItemType itemType);
    ~Key();
};

#endif // !KEY_HPP
