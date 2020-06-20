/******************************************************************************
** Program: Query's Quest
** File: Space.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
//#include <QBrush>
//#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsPixmapItem>


enum SpaceType {FREE, WALL, DOOR, KEY, ELEMENT, BOOTS, QUERY};
enum ElementType {NON, ICE, FIRE, WATER};
enum ItemType {NONE, REDKEY, BLUEKEY, GREENKEY, WATERBOOTS, FIREBOOTS, ICEBOOTS};

class Space : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    SpaceType spaceType;
    ElementType elementType;
    ItemType itemType;
    std::string symbol;

    Space* up;
    Space* down;
    Space* left;
    Space* right;

public:
    // Constructor and Destructor
    Space();
    virtual ~Space();

    // Getters and Setters
    SpaceType getSpaceType();
    ElementType getElementType();
    ItemType getItemType();

    std::string getSpaceSymbol();
    void setSpaceSymbol(std::string symbol);

    Space* getUp();
    void setUp(Space* up);

    Space* getDown();
    void setDown(Space* down);

    Space* getLeft();
    void setLeft(Space* left);

    Space* getRight();
    void setRight(Space* right);

    // Methods
    virtual void displayMessage() = 0;
};

#endif // SPACE_HPP
