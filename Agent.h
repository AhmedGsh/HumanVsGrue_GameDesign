#ifndef AGENT_H
#define AGENT_H
#include "Thing.h"
#include <iostream>
#include <string>
using namespace std;

class Room;  // forward declaration

class Agent : public Thing
{
    protected:
    string name;   //agents name

    public:
    Room *cur_room;              //hold the room the agent is in
    virtual bool act() = 0;      //Purely virtual function that controls how the agent moves
    string getName();            //returns agents name
    void setkey();               //Set if agent has a key
};

#endif // AGENT_H
