/******************************************************************************
** Program: Query's Quest
** File: Level01.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Interface of the class Level01. The constructor takes in a
**      reference to the game board pointer and uses it to build the level.
**      There are functions for creating each room and toggling the rooms on
**      and off of the main game scene.
******************************************************************************/

#ifndef LEVEL01_HPP
#define LEVEL01_HPP

#include "Space.hpp"
#include "Player.hpp"
#include <QGraphicsScene>

#define GRID_STEP 30
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

    void toggleIceRoomScene(QGraphicsScene *scene, bool addToScene);
    void toggleMazeRoomScene(QGraphicsScene *scene, bool addToScene);
    void toggleWaterRoomScene(QGraphicsScene *scene, bool addToScene);
    void toggleMixRoomScene(QGraphicsScene *scene, bool addToScene);
    void toggleFinishRoomScene(QGraphicsScene *scene, bool addToScene);

public:
    Level01(Space ***&gameBoard);
    void updateWindow(QGraphicsScene *scene, int xPos, int yPos, Direction direction);
    void toggleMainRoomScene(QGraphicsScene *scene, bool addToScene);
};

#endif // LEVEL01_HPP
