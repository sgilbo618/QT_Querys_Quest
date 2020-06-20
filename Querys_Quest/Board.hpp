/******************************************************************************
** Program name: Query's Quest
** File: Board.hpp
** Author: Samantha Guilbeault
** Date: 6-20-2020
** Description: Contains the declaration of the class Board which represtents
**      the 2D game board for Query's Quest. It is responsible for building the
**      world made up of different Spaces.
******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"
//#include "Player.hpp"

#define ROWS 25 // i
#define COLS 25 // j

class Board
{
private:
    Space*** gameBoard;
//    Player player;

public:
    // Constructor and Destructor
    Board(QGraphicsScene *scene);
    ~Board();

//    // Utility Methods
//    void runGame();
//    void printGameBoard();
//    void setSpacePointers();

      // Create Room methods
      void createGameBoard();
//    void createMainRoom();
//    void createIceRoom();
//    void createMazeRoom();
//    void createWaterRoom();
//    void createMixRoom();
//    void createFinishRoom();
//    void fillInEmptySpaces();

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

#endif // !BOARD_HPP
