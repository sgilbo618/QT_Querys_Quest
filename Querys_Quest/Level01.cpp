/******************************************************************************
** Program: Query's Quest
** File: Level01.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Implementation of the class Level01. It receives a reference to
**      the gameBoard pointer and allocates the appropriate spaces to create
**      the layout for level 1. Has methods to toggle rooms on and off of the
**      main game scene.
******************************************************************************/

#include "Level01.hpp"
#include "Wall.hpp"
#include "Free.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Water.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "Boots.hpp"
#include "Query.hpp"


/******************************************************************************
** Function: Level01(Space ***&gameBoard)
** Description: Constructor for Level01. Takes in a reference to the gameBoard
**      pointer and creates the layout for level01. Calls all of the create
**      room functions and fills in empty spaces with floor.
******************************************************************************/
Level01::Level01(Space ***&gameBoard)
{
    this->gameBoard = gameBoard;

    createMainRoom();
    createIceRoom();
    createMazeRoom();
    createWaterRoom();
    createMixRoom();
    createFinishRoom();

    fillInEmptySpaces();
}


/******************************************************************************
** Function: updateWindow(QGraphicsScene, int, int, Direction)
** Description: Takes in the scene with the current position of the player and
**      the direction they are moving on the gameBoard.Checks the position to
**      see if the player is moving through a door way. If they are, the
**      current room is toggled off and the room being moved to is toggled on.
******************************************************************************/
void Level01::updateWindow(QGraphicsScene *scene, int xPos, int yPos, Direction direction)
{
    // Main room to ice room
    if (xPos == 11 && (yPos == 8 || yPos == 9) && direction == UP)
    {
        toggleMainRoomScene(scene, 0);
        toggleIceRoomScene(scene, 1);
    }
    // Ice room to main room
    else if (xPos == 12 && (yPos == 8 || yPos == 9) && direction == DOWN)
    {
            toggleIceRoomScene(scene, 0);
            toggleMainRoomScene(scene, 1);
    }


    // Main Room to maze room
    if (xPos == 15 && yPos == 5 && direction == LEFT)
    {
        toggleMainRoomScene(scene, 0);
        toggleMazeRoomScene(scene, 1);
    }
    // Maze room to main room
    else if (xPos == 15 && yPos == 6 && direction == RIGHT)
    {
        toggleMazeRoomScene(scene, 0);
        toggleMainRoomScene(scene, 1);
    }


    // Main room to water room
    if (xPos == 17 && yPos == 13 && direction == DOWN)
    {
        toggleMainRoomScene(scene, 0);
        toggleWaterRoomScene(scene, 1);
    }
    // Water room to main room
    else if (xPos == 16 && yPos == 13 && direction == UP)
    {
        toggleWaterRoomScene(scene, 0);
        toggleMainRoomScene(scene, 1);
    }


    // Main room to mix room
    if (xPos == 15 && yPos == 18 && direction == RIGHT)
    {
        toggleMainRoomScene(scene, 0);
        toggleMixRoomScene(scene, 1);
    }
    // Mix room to main room
    else if (xPos == 15 && yPos == 17 && direction == LEFT)
    {
        toggleMixRoomScene(scene, 0);
        toggleMainRoomScene(scene, 1);
    }


    // Main room to final room
    if (xPos == 11 && yPos == 16 && direction == UP)
    {
        toggleMainRoomScene(scene, 0);
        toggleFinishRoomScene(scene, 1);
    }
    // Final room to main room
    else if (xPos == 12 && yPos == 16 && direction == DOWN)
    {
        toggleFinishRoomScene(scene, 0);
        toggleMainRoomScene(scene, 1);
    }
}


/******************************************************************************
** Function: createMainRoom()
** Description: Adds all the spaces that make up the central starting room.
******************************************************************************/
void Level01::createMainRoom()
{
    // Yellow Key
    gameBoard[13][6] = new Key(YELLOWKEY);

    // Queries
    gameBoard[15][8] = new Query;

    // Walls
    gameBoard[11][5] = new Wall; gameBoard[11][6] = new Wall; gameBoard[11][7] = new Wall;
    gameBoard[11][10] = new Wall; gameBoard[11][11] = new Wall; gameBoard[11][12] = new Wall;
    gameBoard[11][13] = new Wall; gameBoard[11][14] = new Wall; gameBoard[11][15] = new Wall;
    gameBoard[11][17] = new Wall; gameBoard[11][18] = new Wall; gameBoard[12][5] = new Wall;
    gameBoard[12][18] = new Wall; gameBoard[13][5] = new Wall; gameBoard[13][18] = new Wall;
    gameBoard[14][5] = new Wall; gameBoard[14][18] = new Wall; gameBoard[16][5] = new Wall;
    gameBoard[16][18] = new Wall; gameBoard[17][5] = new Wall; gameBoard[17][6] = new Wall;
    gameBoard[17][7] = new Wall; gameBoard[17][8] = new Wall; gameBoard[17][9] = new Wall;
    gameBoard[17][10] = new Wall; gameBoard[17][11] = new Wall; gameBoard[17][12] = new Wall;
    gameBoard[17][14] = new Wall; gameBoard[17][15] = new Wall; gameBoard[17][16] = new Wall;
    gameBoard[17][17] = new Wall; gameBoard[17][18] = new Wall;

}


/******************************************************************************
** Function: toggleMainRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the main room is toggled on to the scene.
**      If the switch is not set, the main room is toggle off of the scene.
******************************************************************************/
void Level01::toggleMainRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through values of the main room coordinates
    for (int i = 11; i <= 17; i++)
    {
        for (int j = 5; j <= 18; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: createIceRoom()
** Description: Adds all the spaces that make up the ice room.
******************************************************************************/
void Level01::createIceRoom()
{
    // Green Key
    gameBoard[1][5] = new Key(GREENKEY);

    // Queries
    gameBoard[10][10] = new Query; // gameBoard[][] = new Query; gameBoard[][] = new Query;

    // Walls
    gameBoard[0][12] = new Wall; gameBoard[1][12] = new Wall; gameBoard[2][12] = new Wall;
    gameBoard[3][12] = new Wall; gameBoard[4][12] = new Wall; gameBoard[5][12] = new Wall;
    gameBoard[6][12] = new Wall; gameBoard[7][12] = new Wall; gameBoard[8][12] = new Wall;
    gameBoard[9][12] = new Wall; gameBoard[10][12] = new Wall; gameBoard[11][0] = new Wall;
    gameBoard[11][1] = new Wall; gameBoard[11][2] = new Wall; gameBoard[11][3] = new Wall;
    gameBoard[11][4] = new Wall;

    // Free
    gameBoard[1][3] = new Free; gameBoard[2][1] = new Free;
    gameBoard[2][6] = new Free; gameBoard[4][7] = new Free; gameBoard[4][10] = new Free;
    gameBoard[5][3] = new Free; gameBoard[5][6] = new Free; gameBoard[7][4] = new Free;
    gameBoard[7][9] = new Free; gameBoard[9][1] = new Free; gameBoard[9][7] = new Free;
    gameBoard[10][4] = new Free;

    // Water
    for (int i = 0; i < 11; i++)
    {
        gameBoard[0][i] = new Water;
        gameBoard[i][0] = new Water;
        gameBoard[i][11] = new Water;
    }
    gameBoard[10][1] = new Water; gameBoard[10][2] = new Water; gameBoard[10][3] = new Water;

    // Ice
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (gameBoard[i][j] == nullptr)
                gameBoard[i][j] = new Ice;
        }
    }
    gameBoard[10][5] = new Ice; gameBoard[10][6] = new Ice; gameBoard[10][7] = new Ice;
    gameBoard[10][8] = new Ice; gameBoard[10][9] = new Ice;
}


/******************************************************************************
** Function: toggleIceRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the ice room is toggled on to the scene.
**      If the switch is not set, the ice room is toggle off of the scene.
******************************************************************************/
void Level01::toggleIceRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through ice room coordinates
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: createMazeRoom()
** Description: Adds all the spaces that make up the maze-like room.
******************************************************************************/
void Level01::createMazeRoom()
{
    // Orange Key
    gameBoard[22][8] = new Key(ORANGEKEY);

    // Water boots
    gameBoard[22][4] = new Boots(WATERBOOTS);

    // Queries
    gameBoard[13][3] = new Query; gameBoard[17][2] = new Query; gameBoard[24][8] = new Query;

    // Walls
    gameBoard[13][1] = new Wall; gameBoard[13][2] = new Wall; gameBoard[14][1] = new Wall;
    gameBoard[14][2] = new Wall; gameBoard[14][3] = new Wall; gameBoard[14][4] = new Wall;
    gameBoard[16][1] = new Wall; gameBoard[16][2] = new Wall; gameBoard[16][3] = new Wall;
    gameBoard[16][4] = new Wall; gameBoard[17][1] = new Wall; gameBoard[17][3] = new Wall;
    gameBoard[17][4] = new Wall; gameBoard[18][1] = new Wall; gameBoard[18][3] = new Wall;
    gameBoard[18][9] = new Wall; gameBoard[19][1] = new Wall; gameBoard[19][3] = new Wall;
    gameBoard[19][5] = new Wall; gameBoard[19][6] = new Wall; gameBoard[19][7] = new Wall;
    gameBoard[19][9] = new Wall; gameBoard[20][1] = new Wall; gameBoard[20][3] = new Wall;
    gameBoard[20][5] = new Wall; gameBoard[20][9] = new Wall; gameBoard[21][3] = new Wall;
    gameBoard[21][5] = new Wall; gameBoard[21][7] = new Wall; gameBoard[21][9] = new Wall;
    gameBoard[22][1] = new Wall; gameBoard[22][3] = new Wall; gameBoard[22][5] = new Wall;
    gameBoard[22][7] = new Wall; gameBoard[22][9] = new Wall; gameBoard[23][1] = new Wall;
    gameBoard[23][2] = new Wall; gameBoard[23][3] = new Wall; gameBoard[23][4] = new Wall;
    gameBoard[23][5] = new Wall; gameBoard[23][7] = new Wall; gameBoard[23][8] = new Wall;
    gameBoard[23][9] = new Wall; gameBoard[24][9] = new Wall;

    // Fire
    gameBoard[21][8] = new Fire;
}


/******************************************************************************
** Function: toggleMazeRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the maze room is toggled on to the scene.
**      If the switch is not set, the maze room is toggle off of the scene.
******************************************************************************/
void Level01::toggleMazeRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through upper part of maze room - it does not have rectangular shape
    for (int i = 11; i <= 24; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }

    // Loop through lower part of room
    for (int i = 17; i <= 24; i++)
    {
        for (int j = 6; j <= 9; j++)
        {
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: createWaterRoom()
** Description: Adds all the spaces that make up the water-maze room.
******************************************************************************/
void Level01::createWaterRoom()
{
    // Green Door
    gameBoard[17][13] = new Door("G ");

    // Fire Boots
    gameBoard[22][15] = new Boots(FIREBOOTS);

    // Queries
    gameBoard[18][17] = new Query; gameBoard[24][17] = new Query; // gameBoard[][] = new Query;

    // Walls
    gameBoard[18][18] = new Wall;
    gameBoard[19][18] = new Wall; gameBoard[20][18] = new Wall; gameBoard[21][18] = new Wall;
    gameBoard[22][18] = new Wall; gameBoard[23][18] = new Wall; gameBoard[24][18] = new Wall;

    // Water
    gameBoard[19][11] = new Water; gameBoard[19][12] = new Water; gameBoard[19][13] = new Water;
    gameBoard[19][14] = new Water; gameBoard[19][15] = new Water; gameBoard[19][16] = new Water;
    gameBoard[19][17] = new Water; gameBoard[20][11] = new Water; gameBoard[21][11] = new Water;
    gameBoard[21][13] = new Water; gameBoard[21][14] = new Water; gameBoard[21][15] = new Water;
    gameBoard[21][16] = new Water; gameBoard[22][11] = new Water; gameBoard[22][16] = new Water;
    gameBoard[23][11] = new Water; gameBoard[23][12] = new Water; gameBoard[23][13] = new Water;
    gameBoard[23][14] = new Water; gameBoard[23][15] = new Water; gameBoard[23][16] = new Water;
}


/******************************************************************************
** Function: toggleWaterRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the water room is toggled on to the scene.
**      If the switch is not set, the water room is toggle off of the scene.
******************************************************************************/
void Level01::toggleWaterRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through water room coordinates
    for (int i = 17; i <= 24; i++)
    {
        for (int j = 9; j <= 18; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: createMixRoom()
** Description: Adds all the spaces to the room that has all elements.
******************************************************************************/
void Level01::createMixRoom()
{
    // Yellow Door
    gameBoard[15][18] = new Door("Y ");

    // Ice Boots
    gameBoard[24][22] = new Boots(ICEBOOTS);

    // Queries
    gameBoard[13][21] = new Query;

    for (int i = 19; i <= 24; i++)
    {
        // Queries
        gameBoard[20][i] = new Query;
        gameBoard[21][i] = new Query;

        // Walls
        gameBoard[11][i] = new Wall;

        // Fire
        gameBoard[12][i] = new Fire; gameBoard[19][i] = new Fire; gameBoard[22][i] = new Fire;

        // Ice
        gameBoard[17][i] = new Ice; gameBoard[18][i] = new Ice;

        if (i >= 21 && i <= 23)
        {
            gameBoard[14][i] = new Ice; gameBoard[15][i] = new Ice; gameBoard[16][i] = new Ice;
        }
    }
    // More ice
    gameBoard[13][19] = new Ice; gameBoard[13][20] = new Ice; gameBoard[13][22] = new Ice;
    gameBoard[13][23] = new Ice;

    // More fire
    gameBoard[13][24] = new Fire; gameBoard[14][24] = new Fire; gameBoard[15][24] = new Fire;
    gameBoard[16][24] = new Fire; gameBoard[17][24] = new Fire; gameBoard[18][24] = new Fire;
}


/******************************************************************************
** Function: toggleMixRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the mix room is toggled on to the scene.
**      If the switch is not set, the mix room is toggle off of the scene.
******************************************************************************/
void Level01::toggleMixRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through mix room coordinates
    for (int i = 11; i <= 24; i++)
    {
        for (int j = 18; j <= 24; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: createFinsihRoom()
** Description: Adds all the spaces that make up the final room.
******************************************************************************/
void Level01::createFinishRoom()
{
    // Final Door
    gameBoard[0][24] = new Door("! ");

    // Orange Door
    gameBoard[11][16] = new Door("O ");

    // Queries
    gameBoard[0][13] = new Query; gameBoard[2][20] = new Query; gameBoard[3][13] = new Query;
    gameBoard[10][13] = new Query; gameBoard[10][24] = new Query;

    // Walls
    gameBoard[0][17] = new Wall; gameBoard[0][23] = new Wall; gameBoard[1][17] = new Wall;
    gameBoard[1][19] = new Wall; gameBoard[1][20] = new Wall; gameBoard[1][21] = new Wall;
    gameBoard[1][23] = new Wall; gameBoard[2][13] = new Wall; gameBoard[2][14] = new Wall;
    gameBoard[2][15] = new Wall; gameBoard[2][17] = new Wall; gameBoard[2][19] = new Wall;
    gameBoard[2][21] = new Wall; gameBoard[2][23] = new Wall; gameBoard[3][14] = new Wall;
    gameBoard[3][15] = new Wall; gameBoard[3][19] = new Wall; gameBoard[3][23] = new Wall;
    gameBoard[4][14] = new Wall; gameBoard[4][15] = new Wall; gameBoard[4][17] = new Wall;
    gameBoard[4][18] = new Wall; gameBoard[4][19] = new Wall; gameBoard[4][21] = new Wall;
    gameBoard[4][22] = new Wall; gameBoard[4][23] = new Wall; gameBoard[5][14] = new Wall;
    gameBoard[5][15] = new Wall; gameBoard[5][17] = new Wall; gameBoard[5][21] = new Wall;
    gameBoard[6][17] = new Wall; gameBoard[6][21] = new Wall; gameBoard[6][23] = new Wall;
    gameBoard[7][13] = new Wall; gameBoard[7][14] = new Wall; gameBoard[7][15] = new Wall;
    gameBoard[7][17] = new Wall; gameBoard[7][18] = new Wall; gameBoard[7][19] = new Wall;
    gameBoard[7][21] = new Wall; gameBoard[7][23] = new Wall; gameBoard[8][19] = new Wall;
    gameBoard[8][21] = new Wall; gameBoard[8][23] = new Wall; gameBoard[9][19] = new Wall;
    gameBoard[9][23] = new Wall; gameBoard[10][19] = new Wall; gameBoard[10][23] = new Wall;

    // Ice
    gameBoard[6][16] = new Ice; gameBoard[7][16] = new Ice; gameBoard[8][16] = new Ice;
    gameBoard[9][15] = new Ice; gameBoard[9][16] = new Ice; gameBoard[9][17] = new Ice;
    gameBoard[9][20] = new Ice; gameBoard[9][21] = new Ice; gameBoard[9][22] = new Ice;
    gameBoard[10][15] = new Ice; gameBoard[10][16] = new Ice; gameBoard[10][17] = new Ice;
    gameBoard[10][20] = new Ice; gameBoard[10][21] = new Ice; gameBoard[10][22] = new Ice;

    // Fire
    gameBoard[5][18] = new Fire; gameBoard[5][19] = new Fire; gameBoard[5][20] = new Fire;
    gameBoard[6][18] = new Fire; gameBoard[6][19] = new Fire; gameBoard[6][20] = new Fire;

    // Water
    gameBoard[8][13] = new Water; gameBoard[8][14] = new Water; gameBoard[8][15] = new Water;
    gameBoard[8][17] = new Water; gameBoard[8][18] = new Water; gameBoard[9][13] = new Water;
    gameBoard[9][14] = new Water; gameBoard[9][18] = new Water; gameBoard[10][14] = new Water;
    gameBoard[10][18] = new Water;
}


/******************************************************************************
** Function: toggleFinishRoomScene(QGraphicsScene, bool)
** Description: Takes in the scene and a bool that acts as a toggle switch. If
**      the switch is set (=1) then the finish room is toggled on to the scene.
**      If the switch is not set, the finish room is toggle off of the scene.
******************************************************************************/
void Level01::toggleFinishRoomScene(QGraphicsScene *scene, bool addToScene)
{
    // Loop through finish room coordinates
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 12; j <= 24; j++)
        {
            // Toggle on to scene
            if (addToScene)
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
            // Toggle off of scene
            else
                scene->removeItem(gameBoard[i][j]);
        }
    }
}


/******************************************************************************
** Function: fillInEmptySpaces()
** Description: Loops through gameBoard and creates a free space where ever
**      there is a nullptr.
******************************************************************************/
void Level01::fillInEmptySpaces()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (gameBoard[i][j] == nullptr)
                gameBoard[i][j] = new Free;
        }
    }
}

