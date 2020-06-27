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
#include <QWidget>

#define ROWS 25 // i
#define COLS 25 // j
#define GRID_STEP 30

class Game: public QGraphicsView
{
    Q_OBJECT
private:
    // Data
    Space*** gameBoard;
    Player *player;
    QGraphicsTextItem *query_count;
    QGraphicsTextItem *items;
    int item_x;

public:
    // Data
    QGraphicsScene *scene;

    // Constructor - Destructor
    Game(QWidget *parent = nullptr);
    ~Game();

    // Utility Methods
    void resetGame();
    void gameOver();
    void gameWon();
    void keyPressEvent(QKeyEvent* event);
    void setSpacePointers();
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
    void createItemsDisplay();

    // Element Methods
    void checkForElements();
    void onIce();
    void onFire();
    void onWater();

    // Item Methods
    void checkForItems();
    void unlockDoor();
    void checkForQueries();

    bool checkForWin();

private slots:
    void onPlayBtnClicked();
};

#endif // GAME_HPP
