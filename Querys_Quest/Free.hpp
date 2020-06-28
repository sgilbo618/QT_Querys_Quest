/******************************************************************************
** Program name: Query's Quest
** File: Free.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Free which is a subclass
**      of Space and represents open tiles on the game board.
******************************************************************************/

#ifndef FREE_HPP
#define FREE_HPP

#include "Space.hpp"


class Free : public Space
{
public:
    Free();
    ~Free();
};

#endif // !FREE_HPP
