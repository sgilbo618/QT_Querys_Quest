/******************************************************************************
** Program name: Query's Quest
** File: Fire.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Fire which is a subclass
**      of Space and represents Fire tiles in the game board.
******************************************************************************/

#ifndef FIRE_HPP
#define FIRE_HPP

#include "Space.hpp"


class Fire : public Space
{
public:
    Fire();
    ~Fire();
    virtual void displayMessage();
};

#endif // !FIRE_HPP
