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

#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsProxyWidget>

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
    QGraphicsScene *scene;

    // For information display
    QGraphicsTextItem *query_count;
    QGraphicsTextItem *items;
    int item_x;

    // Buttons
    QPushButton *playBtn;
    QGraphicsProxyWidget *proxyPlay;
    QPushButton *quitBtn;
    QGraphicsProxyWidget *proxyQuit;
    QPushButton *infoBtn;
    QGraphicsProxyWidget *proxyInfo;

public:
    // Constructor - Destructor
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    // Utility Methods
    void resetGame();
    void gameOver();
    void gameWon();
    void keyPressEvent(QKeyEvent* event);
    void setSpacePointers();
    void addAllItemsToScene();

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
    void onQuitBtnClicked();
    void onInfoBtnClicked();
};

#endif // GAME_HPP
