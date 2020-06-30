/******************************************************************************
** Program name: Query's Quest
** File: Ice.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Ice which is a subclass
**      of Space and represents Ice tiles in the game board. Ice spaces cause
**      the player to slip to the next space unless the player has ice boots.
******************************************************************************/

#ifndef ICE_HPP
#define ICE_HPP

#include "Space.hpp"


class Ice : public Space
{
public:
    Ice();
    ~Ice();
};

#endif // !ICE_HPP
