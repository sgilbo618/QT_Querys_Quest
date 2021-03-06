/******************************************************************************
** Program: Query's Quest
** File: Game.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: The main driving class of this game. It is responsible for
**      creating the underlying gameBoard, the game display, the main menu,
**      getting user input, making moves, responding to moves, updating the
**      gameBoard/display, detecting items, detecting game over conditions,
**      and resetting the game.
******************************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Space.hpp"
#include "Player.hpp"
#include "Level01.hpp"

#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#define ROWS 25 // i
#define COLS 25 // j
#define GRID_STEP 30
#define WINDOW 8


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
    bool easyMode;

    // For main menu
    QGraphicsTextItem *title;
    QGraphicsPixmapItem *img1;
    QGraphicsPixmapItem *img2;
    QGraphicsPixmapItem *img3;
    QPushButton *playBtn;
    QGraphicsProxyWidget *proxyPlay; // Buttons need proxy to add/remove as widget
    QPushButton *quitBtn;
    QGraphicsProxyWidget *proxyQuit;
    QPushButton *infoBtn;
    QGraphicsProxyWidget *proxyInfo;

    // Levels
    Level01 *level01;

public:
    // Constructor - Destructor
    Game(QWidget *parent = nullptr);
    ~Game();

private:

    // Utility Methods
    void createMainMenuDisplay();
    void resetGame();
    void build2DBoard();
    void createButton(QPushButton *button, int x, int y, int width, int height);
    void drawGameInfoDisplay();
    void gameOver();
    void gameWon();
    void keyPressEvent(QKeyEvent* event);
    void setSpacePointers();
    void addAllItemsToScene();
    void addBorderWallsToScene();

    // Element Methods
    void checkForElements();
    void onIce();
    void doIceSlide();
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
