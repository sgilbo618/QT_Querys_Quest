/******************************************************************************
** Program name: Query's Quest
** File: Door.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Door which is a subclass
**      of Space and represents Door tiles in the game board.
******************************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Space.hpp"


class Door : public Space
{
private:
    bool isLocked;
    bool isFirstTimeHere;

public:
    Door();
    Door(std::string symbol);
    ~Door();

    bool getIsLocked();
    void setIsLocked(bool isLocked);

    bool getIsFirstTimeHere();
    void setIsFirstTimeHere(bool swap);

    virtual void displayMessage();
};

#endif // !DOOR_HPP
