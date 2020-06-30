/******************************************************************************
** Program: Query's Quest
** File: Game.cpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#include "Game.hpp"
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

#include <QFont>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>


/******************************************************************************
** Function: Game()
** Description: Game constructor.
******************************************************************************/
Game::Game(QWidget *parent)
{
    // Make view bigger
    this->resize(810, 900);
    setStyleSheet("background-image: url(:images/bg.png);");

    /* Create and set scene */
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Set size of scene
    scene->setSceneRect(0, -90, 750, 845);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add title
    QGraphicsTextItem *title = new QGraphicsTextItem();
    title->setPlainText("Query's Quest");
    title->setFont(QFont("times", 36));

    title->setPos(225, -40);
    scene->addItem(title);

    // Add images
    QPixmap big_query(":/images/big_query.gif");
    QGraphicsPixmapItem *img1 = scene->addPixmap(big_query);
    QGraphicsPixmapItem *img2 = scene->addPixmap(big_query);
    QGraphicsPixmapItem *img3 = scene->addPixmap(big_query);
    img1->setPos(-15, 75);
    img2->setPos(251, 75);
    img3->setPos(517, 75);

    // Play game button
    playBtn = new QPushButton();
    playBtn->setGeometry(QRect(225, 450, 300, 75));
    playBtn->setText("Play Game");
    playBtn->setStyleSheet("background-color: red; "
                           "border: 5px solid black;"
                           "font-size: 20px;");
    proxyPlay = scene->addWidget(playBtn);
    connect(playBtn, SIGNAL(clicked()), this, SLOT(onPlayBtnClicked()));

    // Exit button
    quitBtn = new QPushButton();
    quitBtn->setGeometry(QRect(225, 550, 140, 60));
    quitBtn->setText("Exit");
    quitBtn->setStyleSheet("background-color: #787878;");
    proxyQuit = scene->addWidget(quitBtn);
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(onQuitBtnClicked()));

    // Info button
    infoBtn = new QPushButton();
    infoBtn->setGeometry(QRect(385, 550, 140, 60));
    infoBtn->setText("About");
    infoBtn->setStyleSheet("background-color: #787878;");
    proxyInfo = scene->addWidget(infoBtn);
    connect(infoBtn, SIGNAL(clicked()), this, SLOT(onInfoBtnClicked()));
}


/******************************************************************************
** Function: ~Game()
** Description: Destructor for Board object.
******************************************************************************/
Game::~Game()
{
}


/******************************************************************************
** Function: resetGame()
** Description: Creates new game board, player, and scene.
******************************************************************************/
void Game::resetGame()
{    
    /* Build 2D board */
    gameBoard = new Space**[ROWS];

    for (int i = 0; i < COLS; i++)
    {
        gameBoard[i] = new Space*[COLS];
    }

    // Set all pointers to nullptr
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = nullptr;
        }
    }

    // Add rooms
    Level01 level01(gameBoard);
    setSpacePointers();
    addAllItemsToScene();

    /* Build player */
    player = new Player;

    // Attach player to board
    player->playerPtr = gameBoard[15][15]; //15 15

    // Attach player to scene
    player->setPos(15*GRID_STEP+7, 15*GRID_STEP); // the +8 is just to make him centered
    scene->addItem(player);

    // Make player focusalbe and set it to current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    /* Draw buttons */
    // Quit
    quitBtn = new QPushButton();
    quitBtn->setGeometry(QRect(620, -110, 75, 30));
    quitBtn->setText("Exit");
    quitBtn->setStyleSheet("background-color: #787878;");
    proxyQuit = scene->addWidget(quitBtn);
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(onQuitBtnClicked()));

    // Info
    infoBtn = new QPushButton();
    infoBtn->setGeometry(QRect(700, -110, 75, 30));
    infoBtn->setText("About");
    infoBtn->setStyleSheet("background-color: #787878;");
    proxyInfo = scene->addWidget(infoBtn);
    connect(infoBtn, SIGNAL(clicked()), this, SLOT(onInfoBtnClicked()));


    /* Draw Query tracker */
    query_count = new QGraphicsTextItem();
    query_count->setPlainText("Queries Left: " + QString::number(player->queries));
    query_count->setFont(QFont("times", 16));
    query_count->setDefaultTextColor("red");
    query_count->setPos(-30, -120);
    scene->addItem(query_count);

    /* Draw Items tracker */
    items = new QGraphicsTextItem();
    items->setPlainText("Items:");
    items->setFont(QFont("times", 16));
    items->setDefaultTextColor("red");
    items->setPos(-30, -90);
    scene->addItem(items);

    item_x = -25;
    player->isOnIce = false;
}


/******************************************************************************
** Function: gameOver()
** Description: Clears the game scene, deletes the board, and displays game
**          over options.
******************************************************************************/
void Game::gameOver()
{
    // Create game over sound
    QMediaPlayer *gameOver = new QMediaPlayer;
    gameOver->setMedia(QUrl("qrc:/sounds/game_over.wav"));
    gameOver->play();

    // Create winning message box
    QMessageBox *loseBox = new QMessageBox();
    loseBox->setIconPixmap(QPixmap(":/images/game_over.png"));
    //loseBox->setText("\nYou died!");

    // Add buttons
    QAbstractButton *playAgain = loseBox->addButton("Play Again", QMessageBox::YesRole);
    QAbstractButton *quit = loseBox->addButton("Quit", QMessageBox::NoRole);

    loseBox->exec();

    if (loseBox->clickedButton() == playAgain)
    {
        scene->clear();
        resetGame();
    }
    else if (loseBox->clickedButton() == quit)
        exit(0);
    else
        exit(0);
}


/******************************************************************************
** Function: gameWon()
** Description: Creates message box pop up declaring a win. Provides option to
**      play again or quit.
******************************************************************************/
void Game::gameWon()
{
    // Create level complete sound
    QMediaPlayer *levelCom = new QMediaPlayer;
    levelCom->setMedia(QUrl("qrc:/sounds/level_complete.wav"));
    levelCom->play();

    // Create winning message box
    QMessageBox *winBox = new QMessageBox();
    winBox->setIconPixmap(QPixmap(":/images/you_win.png"));
    //winBox->setText("You won!");

    // Add buttons
    QAbstractButton *playAgain = winBox->addButton("Play Again", QMessageBox::YesRole);
    QAbstractButton *quit = winBox->addButton("Quit", QMessageBox::NoRole);

    winBox->exec();

    if (winBox->clickedButton() == playAgain)
    {
        scene->clear();
        resetGame();
    }
    else if (winBox->clickedButton() == quit)
        exit(0);
    else
        exit(0);
}




/******************************************************************************
** Function: getPlayerMove(QKeyEvent* event)
** Description: Gets and validates user input for player movement and moves the
**      player if the move is valid.
******************************************************************************/
void Game::keyPressEvent(QKeyEvent *event)
{
    qreal x = player->x();
    qreal y = player->y();
    bool made_move = false;

    // Up
    if (player->isOnIce)
    {
        // do nothing
    }
    else if (event->key() == Qt::Key_Up && player->playerPtr->getUp() != nullptr) // && is for bounds checking
    {
        made_move = player->makeMove(player->playerPtr->getUp(), x, y-GRID_STEP, false);
        player->direction = UP;
        player->updatePixmap(QPixmap(":/images/up_guy.png"));
    }
    // Down
    else if (event->key() == Qt::Key_Down && player->playerPtr->getDown() != nullptr)
    {
        made_move = player->makeMove(player->playerPtr->getDown(), x, y+GRID_STEP, false);
        player->direction = DOWN;
        player->updatePixmap(QPixmap(":/images/down_guy.png"));
    }
    // Left
    else if (event->key() == Qt::Key_Left && player->playerPtr->getLeft() != nullptr)
    {
        made_move = player->makeMove(player->playerPtr->getLeft(), x-GRID_STEP, y, false);
        player->direction = LEFT;
        player->updatePixmap(QPixmap(":/images/left_guy.png"));
    }
    // Right
    else if (event->key() == Qt::Key_Right && player->playerPtr->getRight() != nullptr)
    {
        made_move = player->makeMove(player->playerPtr->getRight(), x+GRID_STEP, y, false);
        player->direction = RIGHT;
        player->updatePixmap(QPixmap(":/images/right_guy.png"));
    }

    // Made valid move so update game as needed
    if (made_move)
    {
        checkForElements();
        checkForItems();
        checkForQueries();
        if (!player->checkIsAlive())
            gameOver();
        if (checkForWin())
            gameWon();
    }
    player->resetForwardTimer();
}

/******************************************************************************
** Function: setSpacePointers()
** Description: Loop through gameBoard and set all of the Space's directional
**      pointers to its surrounding Spaces.
******************************************************************************/
void Game::setSpacePointers()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Set ups - not top row
            if (i != 0)
                gameBoard[i][j]->setUp(gameBoard[i - 1][j]);

            // Set downs - not bottom row
            if (i != ROWS - 1)
                gameBoard[i][j]->setDown(gameBoard[i + 1][j]);

            // Set lefts - not first col
            if (j != 0)
                gameBoard[i][j]->setLeft(gameBoard[i][j - 1]);

            // Set rights - not last col
            if (j != COLS - 1)
                gameBoard[i][j]->setRight(gameBoard[i][j + 1]);
        }
    }
}


/******************************************************************************
** Function: addAllItemsToScene()
** Description: Loops through the game board and adds each space to the scene.
**      Also adds a borader of wall spaces around the playing area.
******************************************************************************/
void Game::addAllItemsToScene()
{
    // Add items from gameBoard
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (gameBoard[i][j])
            {
                gameBoard[i][j]->setPos(j*GRID_STEP, i*GRID_STEP);
                scene->addItem(gameBoard[i][j]);
            }
        }
    }

    // Add border walls
    for (int i = 0; i < COLS+1; i++)
    {
        Wall *wr = new Wall;
        wr->setPos(-GRID_STEP, i*GRID_STEP);
        scene->addItem(wr);

        Wall *wl = new Wall;
        wl->setPos(COLS*GRID_STEP, i*GRID_STEP);
        scene->addItem(wl);

        Wall *wt = new Wall;
        wt->setPos(i*GRID_STEP, -GRID_STEP);
        scene->addItem(wt);

        Wall *wb = new Wall;
        wb->setPos(i*GRID_STEP, COLS*GRID_STEP);
        scene->addItem(wb);
    }
    // One more wall at top corner to fill in border
    Wall *tc = new Wall;
    tc->setPos(-GRID_STEP, -GRID_STEP);
    scene->addItem(tc);
}


/******************************************************************************
** Function: checkForElements()
** Description: Gets the player's current position and checks to see if player
**      is on any element spaces. If it is, it calls the appropriate element
**      function.
******************************************************************************/
void Game::checkForElements()
{
    // Gets the current space element type
    ElementType elementType = player->playerPtr->getElementType();

    switch (elementType)
    {
    case ICE:
        onIce();
        break;

    case FIRE:
        onFire();
        break;

    case WATER:
        onWater();
        break;

    default:
        break;
    }
}


/******************************************************************************
** Function: onIce()
** Description: Checks if player has ice boots. If they don't, player slides
**      until not on ice anymore. If they do, player walks like normal.
******************************************************************************/
void Game::onIce()
{
    // When player has ice boots the ice spaces act like free spaces
    if (player->hasThisItem(ICEBOOTS))
    {
        player->playerPtr->updateSound(QUrl("qrc:/sounds/ice_crack.wav"));
        player->playerPtr->playSound();
    }
    // No ice boots makes player slide to next non-ice space
    else
    {
        // Flag to ignore keyPressEvents
        player->isOnIce = true;

        // Has to be separate call here or else too many sound calls will crash
        player->playerPtr->playSound();

        // Get direction
        Direction direction = player->getDirection();
        Direction prevDir = direction;
        qreal x_tracker = player->x();
        qreal y_tracker = player->y();
        bool isBounce = false;

        // Slides player along each subsequent ice space
        while (player->playerPtr->getElementType() == ICE)
        {
            //x = player->x();
            //y = player->y();

            switch (direction)
            {
            case UP:
                // Next space is not a border or wall
                if (player->playerPtr->getUp() != nullptr && player->playerPtr->getUp()->getSpaceType() != WALL)
                {
                    // Move player to the next space up
                    //player->makeMove(player->playerPtr->getUp(), x, y-GRID_STEP, true);
                    player->makeMove(player->playerPtr->getUp(), 0, 0, true);
                    y_tracker -= GRID_STEP;
                }
                // Next space is a border or wall
                else
                    // Change to opposite direction to bounce player back
                    direction = DOWN;
                break;

            case DOWN:
                if (player->playerPtr->getDown() != nullptr && player->playerPtr->getDown()->getSpaceType() != WALL)
                {
                    player->makeMove(player->playerPtr->getDown(), 0, 0, true);
                    y_tracker += GRID_STEP;
                }
                else
                    direction = UP;
                break;

            case LEFT:
                if (player->playerPtr->getLeft() != nullptr && player->playerPtr->getLeft()->getSpaceType() != WALL)
                {
                    player->makeMove(player->playerPtr->getLeft(), 0, 0, true);
                    x_tracker -= GRID_STEP;
                }
                else
                    direction = RIGHT;
                break;

            case RIGHT:
                if (player->playerPtr->getRight() != nullptr && player->playerPtr->getRight()->getSpaceType() != WALL)
                {
                    player->makeMove(player->playerPtr->getRight(), 0, 0, true);
                    x_tracker += GRID_STEP;
                }
                else
                    direction = LEFT;
                break;
            }

            // If direction has changed call animation
            if (prevDir != direction)
            {
                player->animateIce(prevDir, x_tracker, y_tracker, true);
                prevDir = direction;
                isBounce = true;
            }
            else if (player->playerPtr->getElementType() != ICE && !isBounce)
            {
                player->animateIce(prevDir, x_tracker, y_tracker, false);
                prevDir = direction;
            }
        }

        // Check for elements in case the slide ends on fire or water
        checkForElements();
    }
}


/******************************************************************************
** Function: onFire()
** Description: Checks if player has fire boots. If it does not, sets isAlive
**      to false. Displays fire message.
******************************************************************************/
void Game::onFire()
{
    // Fire boots make fire spaces act like free spaces
    if (player->hasThisItem(FIREBOOTS))
        player->playerPtr->updateSound(QUrl("qrc:/sounds/sizzle.wav"));

    // No fire boots kills Query and ends game
    else
        player->isAlive = false;

    player->playerPtr->playSound();
}


/******************************************************************************
** Function: onWater()
** Description: Checks if player has water boots. If it does not, sets isAlive
**      to false. Displays water message.
******************************************************************************/
void Game::onWater()
{
    // Water boots make water spaces act like free spaces
    if (player->hasThisItem(WATERBOOTS))
        player->playerPtr->updateSound(QUrl("qrc:/sounds/water_click.wav"));

    // No water boots kills Query and ends game
    else
        player->isAlive = false;

    player->playerPtr->playSound();
}


/******************************************************************************
** Function: checkForItems()
** Description: Determines if the current space is an item. If it is the item
**      is added to the item array.
******************************************************************************/
void Game::checkForItems()
{
    // Gets space type and item type
    SpaceType type = player->playerPtr->getSpaceType();
    ItemType itemType = player->playerPtr->getItemType();

    // Player has not landed on this space before
    if (!player->hasThisItem(itemType))
    {
        switch (type)
        {
        case KEY:
        {
            // Unlocks corresponding door
            unlockDoor();

            // Add item to item container
            player->items[player->numberOfItems] = player->playerPtr;
            player->numberOfItems++;

            // Add item to item display
            Key *key = new Key(itemType, 0);
            key->setPos(item_x, -55);
            item_x += 50;
            scene->addItem(key);

            player->playerPtr->playSound();

            break;
        }
        case BOOTS:
        {
            // Add item to item container
            player->items[player->numberOfItems] = player->playerPtr;
            player->numberOfItems++;

            // Add item to item display
            Boots *boot = new Boots(itemType, 0);
            boot->setPos(item_x, -55);
            item_x += 50;
            scene->addItem(boot);

            player->playerPtr->playSound();

            break;
        }
        default:
            break;
        }
    }
}


/******************************************************************************
** Function: unlockDoor()
** Description: When a key is found this function gets the type of key and
**      unlocks the corrisponding door.
******************************************************************************/
void Game::unlockDoor()
{
    // Get the item on current space to use in switch
    switch (player->playerPtr->getItemType())
    {
    case ORANGEKEY:
        static_cast<Door*>(gameBoard[11][16])->setIsLocked(false);
        break;

    case YELLOWKEY:
        static_cast<Door*>(gameBoard[15][18])->setIsLocked(false);
        break;

    case GREENKEY:
        static_cast<Door*>(gameBoard[17][13])->setIsLocked(false);
        break;

    default:
        break;
    }
}


/******************************************************************************
** Function: checkForQueries()
** Description: Gets the space type and if it is a query, one is added to the
**      total number of queries found.
******************************************************************************/
void Game::checkForQueries()
{
    // Current space is a query and this is the first time on this space
    if (player->playerPtr->getSpaceType() == QUERY && !static_cast<Query*>(player->playerPtr)->getHasBeenCollected())
    {
        // Update queries left and display
        player->queries--;
        query_count->setPlainText("Queries Left: " + QString::number(player->queries));
        player->playerPtr->playSound();

        // Update space to indicate this query has been collected already
        static_cast<Query*>(player->playerPtr)->setHasBeenCollected(true);
    }

    // Lets player in final door only if they have all the queries
    if (player->queries == 0)
    {
        // Only play sound if final door hasn't been unlocked yet
        if (static_cast<Door*>(gameBoard[0][24])->getIsLocked())
        {
            gameBoard[0][24]->updateSound(QUrl("qrc:/sounds/portal.mp3"));
            gameBoard[0][24]->playSound();
        }

        static_cast<Door*>(gameBoard[0][24])->setIsLocked(false);
        gameBoard[0][24]->setPixmap(QPixmap(":/images/unlocked_portal.png"));
    }
}


/******************************************************************************
** Function: checkForWin()
** Description: Returns true if player is on the final door and they have all
**      the queries. Returns false otherwise
******************************************************************************/
bool Game::checkForWin()
{
    if (player->playerPtr == gameBoard[0][24] && player->queries == 0)
    {
        return true;
    }

    return false;
}


/******************************************************************************
** Function: onPlayBtnClicked()
** Description: Ran when 'play' button is clicked. Creates an instance of the
**      Game and plays it.
******************************************************************************/
void Game::onPlayBtnClicked()
{
    // Remove buttons from scene
    scene->removeItem(proxyPlay);
    scene->removeItem(proxyQuit);
    scene->removeItem(proxyInfo);

    resetGame();
}


/******************************************************************************
** Function: onQuitBtnClicked()
** Description: Exits applciation when quit or exit is clicked().
******************************************************************************/
void Game::onQuitBtnClicked()
{
    exit(0);
}


/******************************************************************************
** Function: onInfoBtnClicked()
** Description: Displays message pop up with information on how to play.
******************************************************************************/
void Game::onInfoBtnClicked()
{
    // Create info message box
    QMessageBox *infoBox = new QMessageBox();
    infoBox->setWindowTitle("About Query's Quest");
    infoBox->setText("Query has always been curious about the meaning of the "
                     "information around him, so naturally, he became a data "
                     "mining explorer! Query's quest is to traverse his world in "
                     "search of queries to help answer his questions about life - "
                     "no matter what obstacles he may encounter.\n"
                     "\nKeys:\n"
                     "Use the arrow keys to navigate.\n"
                     "\nHow to Play:\n"
                     "In the game Query's Quest, the player, Query, must explore "
                     "his world in search of queries (?). Query must find "
                     "all of the queries in order to end his quest and move on to "
                     "the next level of understanding. Along the way, Query will "
                     "encounter different elements of his world, including water, "
                     "fire, and ice. Be careful when traversing these elements "
                     "because some of them may harm Query if you have not found "
                     "the proper equipment. Also, not all places in Query's world "
                     "will be accesible without finding the proper keys to unlock"
                     "doors. Good luck to you on your journey!");

    infoBox->exec();
}
