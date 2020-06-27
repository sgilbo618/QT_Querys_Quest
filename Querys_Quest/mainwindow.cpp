/******************************************************************************
** Program: Query's Quest
** File: mainwindow.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "Game.hpp"


/******************************************************************************
** Function: MainWindow(Qwidget *parent)
** Description: MainWindow constructor. Sets up the main window ui.
******************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    Game *game = new Game();
    setCentralWidget(game);
    game->show();
}


/******************************************************************************
** Function: ~MainWindow()
** Description: MainWindow destructor.
******************************************************************************/
MainWindow::~MainWindow()
{
    //delete ui;
}


void MainWindow::restartGame()
{
    Game *game = new Game();
    setCentralWidget(game);
    game->show();
}


/******************************************************************************
** Function: on_pushButton_clicked()
** Description: Ran when 'play' button is clicked on main window ui. Creates an
**      instance of the Game and plays it.
******************************************************************************/
void MainWindow::on_pushButton_clicked()
{
    restartGame();
}
