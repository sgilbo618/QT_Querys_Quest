/******************************************************************************
** Program name: Query's Quest
** File: Wall.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains the declaration of the class Wall which is a subclass
**      of Space and represents wall tiles in the game board. Wall spaces act
**      as boundarys for the level rooms.
******************************************************************************/

#ifndef WALL_HPP
#define WALL_HPP

#include "Space.hpp"


class Wall : public Space
{
public:
    Wall();
    ~Wall();
};

#endif // !WALL_HPP
