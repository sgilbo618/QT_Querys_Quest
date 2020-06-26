/******************************************************************************
** Program: Query's Quest
** File: Menu.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>


class Menu : public QGraphicsView
{
    Q_OBJECT
public:
    // Data
    QGraphicsScene *scene;

    // Constructor and Destructor
    Menu();
    ~Menu();

    // Menu functions
    void mainMenu();
};

#endif // MENU_HPP
