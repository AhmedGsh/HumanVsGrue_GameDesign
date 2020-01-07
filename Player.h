#ifndef PLAYER_H
#define PLAYER_H
#include "Agent.h"
#include "Room.h"
#include <string>


class Player : public Agent
{
    public:
    Player(string _name, Room *starting_room);  //constructor
    bool act();
};


#endif // PLAYER_H
