/******************************************************************************
** Program: Query's Quest
** File: Level01.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Interface of the class Level01. The constructor takes in a
**      reference to the game board pointer and uses it to build the level.
**      There are functions for creating each room.
******************************************************************************/

#ifndef LEVEL01_HPP
#define LEVEL01_HPP

#include "Space.hpp"

#define ROWS 25 // i
#define COLS 25 // j


class Level01
{
private:
    Space ***gameBoard;

    void createMainRoom();
    void createIceRoom();
    void createMazeRoom();
    void createWaterRoom();
    void createMixRoom();
    void createFinishRoom();

    void fillInEmptySpaces();

public:
    Level01(Space ***&gameBoard);
};

#endif // LEVEL01_HPP
