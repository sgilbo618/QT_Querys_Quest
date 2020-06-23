/******************************************************************************
** Program name: Query's Quest
** File: Query.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Query which is a subclass
**      of Space and represents open tiles on the game board.
******************************************************************************/

#ifndef QUERY_HPP
#define QUERY_HPP

#include "Space.hpp"


class Query : public Space
{
private:
    bool hasBeenCollected;

public:
    Query();
    ~Query();
    bool getHasBeenCollected();
    void setHasBeenCollected(bool collected);
    virtual void displayMessage();
};

#endif // !QUERY_HPP
