/******************************************************************************
** Program: Query's Quest
** File: Game.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Space.hpp"
#include "Player.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#define ROWS 25 // i
#define COLS 25 // j

class Game: public QGraphicsView
{
    Q_OBJECT
private:
    // Data
    Space*** gameBoard;
    Player *player;

public:
    // Data
    QGraphicsScene *scene;

    // Constructor - Destructor
    Game(QWidget *parent = NULL);
    ~Game();

//    // Utility Methods
//    void runGame();
//    void printGameBoard();
//    void setSpacePointers();
    void addAllItemsToScene();

    // Create Room methods
    void createGameBoard();
    void createMainRoom();
    void createIceRoom();
    void createMazeRoom();
    void createWaterRoom();
    void createMixRoom();
    void createFinishRoom();
    void fillInEmptySpaces();

//    // Element Methods
//    void checkForElements();
//    void onIce();
//    void onFire();
//    void onWater();

//    // Item Methods
//    void checkForItems();
//    void unlockDoor();
//    void checkForQueries();

//    bool checkForWin();
};

#endif // GAME_HPP
