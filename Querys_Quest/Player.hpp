/******************************************************************************
** Program name: Query's Quest
** File: Player.hpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the declaration of the class Player which represents
**      the main character, Query, in the game Query's Quest. Is responsible
**      for maintaining the item container, keeping track of the player's
**      direction, moving the player on the gameBoard/display, and animating
**      the ice sliding feature of the game.
******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"

#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>


#define QUERIES_NEEDED 25
#define GRID_STEP 30

enum Direction { UP, DOWN, LEFT, RIGHT };


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Space* playerPtr;
    Direction direction;
    bool isAlive;

    Space* items[6];
    int numberOfItems;
    int queries;

    QTimer *forwardTimer;

    bool isOnIce;
    QTimer *timer;
    qreal move_x;
    qreal move_y;
    Direction ice_direction;

    qreal bounce_x;
    qreal bounce_y;
    bool isBounce;

public:
    // Constructor and Destructor
    Player();
    ~Player();

    Direction getDirection();
    bool checkIsAlive();
    void updatePixmap(QPixmap pixmap);
    void resetForwardTimer();

    // Move methods
    bool makeMove(Space* moveSpace, qreal move_x, qreal move_y, bool onIce);
    void animateIce(Direction direction, qreal x_total, qreal y_total, bool isBounce);
    bool checkLegalMove(Space* moveSpace);
    void resetSpaceSymbol();
    void iceBounce();

    // Item methods
    bool hasThisItem(ItemType item);

public slots:
    void move();
    void turnPlayerForward();

    friend class Game;
};

#endif // !PLAYER_HPP
