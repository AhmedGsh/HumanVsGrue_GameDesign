#ifndef GRUE_H
#define GRUE_H
#include "Agent.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


class Grue : public Agent
{
    public:
    Grue(string _name, Room *starting_room);  //constructor
    bool act();
};

#endif // GRUE_H
