/******************************************************************************
** Program: Query's Quest
** File: Menu.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#include "Menu.hpp"


/******************************************************************************
** Function: Menu()
** Description: Constructor for Menu class.
******************************************************************************/
Menu::Menu()
{
    /* Create and set scene */
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Set size of scene
    scene->setSceneRect(0, 0, 810, 810);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


/******************************************************************************
** Function: ~Menu()
** Description: Destructor for Menu class.
******************************************************************************/
Menu::~Menu()
{
}


/******************************************************************************
** Function: mainMenu()
** Description:
******************************************************************************/
void mainMenu()
{

}
