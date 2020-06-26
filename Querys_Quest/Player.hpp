/******************************************************************************
** Program name: Query's Quest
** File: Player.hpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the declaration of the class Player which represents
**      the main character, Query, in the game Query's Quest. Player has
**      containers to keep track of keys, boots, and queries.
******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include <QObject>
#include <QGraphicsPixmapItem>

#define MAX_STEPS 600
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
    int steps;
    Space* items[6];
    int numberOfItems;
    int queries;

public:
    // Constructor and Destructor
    Player();
    ~Player();

    Direction getDirection();
    bool checkIsAlive();

    // Move methods
//    void keyPressEvent(QKeyEvent* event);
    bool makeMove(Space* moveSpace, qreal move_x, qreal move_y);
    bool checkLegalMove(Space* moveSpace);
    void resetSpaceSymbol();

    // Item methods
    bool hasThisItem(ItemType item);
//    void displayItems();

//    void displayMapKey();

    friend class Game;
};

#endif // !PLAYER_HPP
