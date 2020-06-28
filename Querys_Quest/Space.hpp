/******************************************************************************
** Program: Query's Quest
** File: Space.hpp
** Author: Samantha Guilbeault
** Date: 6-19-2020
** Description:
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

enum SpaceType {FREE, WALL, DOOR, KEY, ELEMENT, BOOTS, QUERY};
enum ElementType {NON, ICE, FIRE, WATER};
enum ItemType {NONE, ORANGEKEY, YELLOWKEY, GREENKEY, WATERBOOTS, FIREBOOTS, ICEBOOTS};

class Space : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    SpaceType spaceType;
    ElementType elementType;
    ItemType itemType;

    Space* up;
    Space* down;
    Space* left;
    Space* right;

    QMediaPlayer *sound;

public:
    // Constructor and Destructor
    Space();
    virtual ~Space();

    // Getters and Setters
    SpaceType getSpaceType();
    ElementType getElementType();
    ItemType getItemType();

    Space* getUp();
    void setUp(Space* up);

    Space* getDown();
    void setDown(Space* down);

    Space* getLeft();
    void setLeft(Space* left);

    Space* getRight();
    void setRight(Space* right);

    void playSound();
    void updateSound(QUrl url);
};

#endif // SPACE_HPP
