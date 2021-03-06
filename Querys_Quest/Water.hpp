/******************************************************************************
** Program name: Query's Quest
** File: Water.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Water which is a subclass
**      of Space and represents Water tiles in the game board. Water spaces will
**      kill the player if the player attempts to access the space without the
**      water boots.
******************************************************************************/

#ifndef WATER_HPP
#define WATER_HPP

#include "Space.hpp"


class Water : public Space
{
public:
    Water();
    ~Water();
};

#endif // !WATER_HPP
