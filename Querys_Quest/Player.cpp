/******************************************************************************
** Program name: Query's Quest
** File: Player.cpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the implementation of class Player which represents
**      the main character, Query, in the game Query's Quest. Player has
**      container to keep track of keys, boots, and queries.
******************************************************************************/

#include "Player.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "Boots.hpp"

#include <QKeyEvent>


/******************************************************************************
** Function: Player()
** Description: Default constructor for Player object.
******************************************************************************/
Player::Player()
{
    playerPtr = nullptr;
    direction = UP;
    isAlive = true;
    numberOfItems = 0;
    queries = QUERIES_NEEDED;

    setPixmap(QPixmap(":/images/down_guy.png"));

    // Start timer to animate move()
    forwardTimer = new QTimer();
    connect(forwardTimer, SIGNAL(timeout()), this, SLOT(turnPlayerForward()));
    forwardTimer->start(200);
}


/******************************************************************************
** Function: ~Player()
** Description: Destructor for Player object.
******************************************************************************/
Player::~Player()
{
}


/******************************************************************************
** Description: Getter for direction.
******************************************************************************/
Direction Player::getDirection()
{
    return direction;
}


/******************************************************************************
** Function: checkIsAlive()
** Description: Checks number of steps and what space the player is on and
**      determines if the player is still alive or not. Sets and returns
**      isAlive. Will return true if still alive or false if not.
******************************************************************************/
bool Player::checkIsAlive()
{
    return isAlive;
}


/******************************************************************************
** Function: updatePixmap(QPixmap pixmap)
** Description: Destructor for Player object.
******************************************************************************/
void Player::updatePixmap(QPixmap pixmap)
{
    setPixmap(pixmap);
}


/******************************************************************************
** Function: resetForwardTimer()
** Description: Stops and restarts the forwardTimer. The forward timer makes
**      the player image turn forward when the player is idle. Each time the
**      player makes a move, the timer is reset so that it does not interrupt
**      valid moves.
******************************************************************************/
void Player::resetForwardTimer()
{
    forwardTimer->stop();
    forwardTimer->start(300);
}


/******************************************************************************
** Function: makeMove(Space*, qreal, qreal)
** Description: Takes in the space of the game board and the coordinates of the
**      game display that the player is attempting to move to and moves there
**      if it is a legal move. Returns true if the move is made, and false if
**      the move is not made.
******************************************************************************/
bool Player::makeMove(Space * moveSpace, qreal move_x, qreal move_y, bool onIce)
{
    // Check if space is legal move
    if (checkLegalMove(moveSpace))
    {
        // Move player on display - don't move here if it is on ice
        if (!onIce)
            setPos(move_x, move_y);

        // Move player to new space
        playerPtr = moveSpace;

        // reset symbol to original
        resetSpaceSymbol();

        return true;
    }
    return false;
}


/******************************************************************************
** Function: makeMoveOnIce()
** Description: Sets up player variables for moving on ice animation. The
**      player will slide across the ice until it reaches the passed in x/y
**      values. The flag isBounce is set when the player has made a move that
**      will result in him sliding into a wall and bouncing back. Creates a
**      timer to call move() every x milliseconds.
******************************************************************************/
void Player::animateIce(Direction direction, qreal x_total, qreal y_total, bool isBounce)
{
    // Set these so move() knows how far and direction to move player
    move_x = x_total;
    move_y = y_total;
    ice_direction = direction;
    this->isBounce = isBounce;
    bounce_x = this->x();
    bounce_y = this->y();

    // Start timer to animate move()
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}


/******************************************************************************
** Function: move()
** Description: This is a slot function that drives the animation for sliding
**      on ice. Each call results in the player moving one grid step on the
**      display. If the isBounce flag is set, a new timer is created and the
**      coordinates are set to move the player back to the original space.
******************************************************************************/
void Player::move()
{
    qreal curr_x = this->x();
    qreal curr_y = this->y();

    // Only adjust coordinates if not done
    if (curr_x != move_x || curr_y != move_y)
    {
        switch (ice_direction)
        {
        case UP:
           curr_y -= GRID_STEP;
           break;

        case DOWN:
           curr_y += GRID_STEP;
           break;

        case LEFT:
           curr_x -= GRID_STEP;
           break;

        case RIGHT:
           curr_x += GRID_STEP;
           break;
        }
   }

   setPos(curr_x, curr_y);
   resetForwardTimer();

   // Move coordinates match current coordinates, so stop this animation
   if (curr_x == move_x && curr_y == move_y)
   {
       timer->stop();
       isOnIce = false;

       // If this is a bounce animation, reset data to bounce player back to where he started
       if (isBounce)
       {
            move_x = bounce_x;
            move_y = bounce_y;
            isBounce = false;
            isOnIce = true;

            // Update direction to the opposite direction and add one more step
            switch (ice_direction)
            {
            case UP:
                ice_direction = DOWN;
                move_y += GRID_STEP;
                updatePixmap(QPixmap(":/images/down_guy.png"));
                break;

            case DOWN:
                ice_direction = UP;
                move_y -= GRID_STEP;
                updatePixmap(QPixmap(":/images/up_guy.png"));
                break;

            case LEFT:
                ice_direction = RIGHT;
                move_x += GRID_STEP;
                updatePixmap(QPixmap(":/images/right_guy.png"));
                break;

            case RIGHT:
                ice_direction = LEFT;
                move_x -= GRID_STEP;
                updatePixmap(QPixmap(":/images/left_guy.png"));
                break;
            }

            timer = new QTimer();
            connect(timer, SIGNAL(timeout()), this, SLOT(move()));
            timer->start(50);
       }
   }
}


/******************************************************************************
** Function: turnPlayerForward()
** Description: Slot function that is called when forwardTimer expires. If the
**      player is idle long enough, the player image turns forward.
******************************************************************************/
void Player::turnPlayerForward()
{
    updatePixmap(QPixmap(":/images/down_guy.png"));
}


/******************************************************************************
** Function: checkLegalMove(Space*)
** Description: Checks the space Player is attempting to access and determines
**      if the space is a legal move. Returns true if it is, false if not.
******************************************************************************/
bool Player::checkLegalMove(Space* moveSpace)
{
    bool isLegal = true;
    SpaceType moveType = moveSpace->getSpaceType();

    // Checks if next space is a wall
    if (moveType == WALL)
    {
        moveSpace->playSound();
        isLegal = false;
    }

    // Checks if Door is locked
    if (moveType == DOOR)
    {
        if (static_cast<Door*>(moveSpace)->getIsLocked())
        {
            moveSpace->playSound();
            isLegal = false;
        }
        else
        {
            if (static_cast<Door*>(moveSpace)->getIsFirstTimeHere())
            {
                moveSpace->updateSound(QUrl("qrc:/sounds/unlock_door.wav"));
                moveSpace->playSound();
                static_cast<Door*>(moveSpace)->setIsFirstTimeHere(false);
            }
        }
    }

    return isLegal;
}


/******************************************************************************
** Function: resetSpaceSymbol()
** Description: Looks up the space type that the player is on and changes its
**      symbol back to its orignal state.
******************************************************************************/
void Player::resetSpaceSymbol()
{
    SpaceType type = playerPtr->getSpaceType();

    switch (type)
    {
        // Unlocked Doors and items become vacant spaces after collection
    case DOOR:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case KEY:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case BOOTS:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    case QUERY:
        playerPtr->setPixmap(QPixmap(":/images/floor.png"));
        break;

    default:
        break;
    }
}


/******************************************************************************
** Function: hasThisItem(ItemType)
** Description: Takes in an ItemType and loops through the item array to search
**      for it. Returns true if the item is found, false if it is not found.
******************************************************************************/
bool Player::hasThisItem(ItemType item)
{
    for (int i = 0; i < numberOfItems; i++)
    {
        if (items[i]->getItemType() == item)
            return true;
    }
    return false;
}

