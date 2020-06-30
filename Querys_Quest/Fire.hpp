/******************************************************************************
** Program name: Query's Quest
** File: Fire.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Fire which is a subclass
**      of Space and represents Fire tiles in the game board. Fire spaces will
**      kill the player if the player attempts to access the space without the
**      fire boots.
******************************************************************************/

#ifndef FIRE_HPP
#define FIRE_HPP

#include "Space.hpp"


class Fire : public Space
{
public:
    Fire();
    ~Fire();
};

#endif // !FIRE_HPP
