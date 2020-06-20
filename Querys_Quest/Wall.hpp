/*********************************************************************
** Program name: Query's Quest
** File: Wall.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the declaration of the class Wall which is
**				a subclass of Space and represents wall tiles in the
**				game board.
*********************************************************************/

#ifndef WALL_HPP
#define WALL_HPP

#include "Space.hpp"


class Wall : public Space
{
public:
    Wall();
    ~Wall();
    virtual void displayMessage();
};

#endif // !WALL_HPP
