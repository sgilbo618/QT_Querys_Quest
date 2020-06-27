/******************************************************************************
** Program: Query's Quest
** File: main.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description: Contains main function for the game Query's Quest.
******************************************************************************/

#include "mainwindow.hpp"
#include "Game.hpp"
#include <QApplication>


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;

//    w.show();

//    return a.exec();

    QApplication a(argc, argv);
    Game* game = new Game();
    game->show();
    return a.exec();
//    const int RESTART = 1000;
//    QApplication a(argc, argv);
//    do
//    {
//        Game* game = new Game();
//        game->show();
//    } while (a.exec() == RESTART);

//    QApplication a(argc, argv);

//    Game* game = new Game();

//    game->show();

//    a.exec();

//    return 0;
}


// Comment block pasties

/******************************************************************************
** Program: Query's Quest
** File:
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

/******************************************************************************
** Function:
** Description:
******************************************************************************/
