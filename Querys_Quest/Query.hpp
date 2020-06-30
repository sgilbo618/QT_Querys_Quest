/******************************************************************************
** Program name: Query's Quest
** File: Query.hpp
** Author: Samantha Guilbeault
** Date: 6-23-2020
** Description: Contains the declaration of the class Query which is a subclass
**      of Space and represents open tiles on the game board. Has a data
**      member to track if it has been collected, and methods to get and set
**      the data member. Query spaces must be collected by the player in order
**      to unlock the final door.
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
};

#endif // !QUERY_HPP
