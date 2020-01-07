#include "Grue.h"

Grue::Grue(string _name, Room *starting_room)
    {
        name = _name;               //sets name
        horns = true;               //sets horns
        cur_room = starting_room;   //sets starting room
    }

bool Grue::act()
    {
        int n = rand() % 4; //generates a random int from 1-4 each time
        string direction;
        //Direction will be assigned according to random number
        switch(n)
            {
                case 0: direction = "north"; break;
                case 1: direction = "south"; break;
                case 2: direction = "west"; break;
                case 3: direction = "east"; break;
            }

        //If the direction is valid
        if(cur_room->getLinked(direction, this ) != NULL)
        {
            //move into room
            cur_room = cur_room->getLinked(direction,this);
        }
        return true;
    }
