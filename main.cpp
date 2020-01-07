/*

A virtual game, where a player navugates in a maze.
*/


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Thing.h"
#include "Room.h"
#include "Agent.h"
#include "Grue.h"
#include "Player.h"

using namespace std;


int main()
{

    srand(time(NULL));  // controls rand

    // Create rooms, set name, description, key and lock
    Room *entrance = new Room("Entrance",
                                "\nYou are at the entrance of the house, it may look spooky, but remember, you are here to unlock the treasure.\n"
                                ,false,false);
    Room *lobby = new Room("Lobby",
                                "\nYou are now in the lobby, dont let the bats scare you.\n",
                                false,false);
    Room *garden = new Room("Garden",
                                "\nYou are now in the garden, beware of those grave stones.\n",
                                false,false);
    Room *restroom = new Room("Restroom",
                                "\nYou are in the restroom, the darkest place in the house.\n",
                                false,true);
    Room *bedroom = new Room("Bedroom",
                               "You are inside the bedroom where the family was killed, good luck survivng here.",
                               false,false);
    Room *kitchen = new Room("Kitchen",
                               "Do you see that fire? That's what keeps the ghosts warm. You are now in the kitchen",
                               true,false);

    // Create players and monsters, and set there initial location
    Grue *Monster = new Grue("Monster",garden);
    garden->enter(Monster);                     //Insert in that room's set
    Player *p1 = new Player("Ahmed",entrance);
    entrance->enter(p1);
    Player *p2 = new Player("Ankita",entrance);
    entrance->enter(p2);

    //Add created agents into a vector
    vector<Agent* > agents;
    agents.push_back(p1);
    agents.push_back(p2);
    agents.push_back(Monster);

    //Add created rooms into a vector
    vector<Room*> rooms;
    rooms.push_back(entrance);
    rooms.push_back(lobby);
    rooms.push_back(garden);
    rooms.push_back(restroom);
    rooms.push_back(bedroom);
    rooms.push_back(kitchen);

    //Create links between rooms (your map)
    entrance->link("west",garden);
    entrance->link("east",bedroom);
    entrance->link("north",lobby);
    garden->link("east",entrance);
    lobby->link("south",entrance);
    lobby->link("west",restroom);
    restroom->link("east",lobby);
    kitchen->link("south",bedroom);
    bedroom->link("west",entrance);
    bedroom->link("north",kitchen);

    cout <<"\nWELCOME TO THE HAUNTED HOUSE, YOUR OBJECTIVE IS TO FIND THE KEY AND OPEN THE LOCKED DOOR. WATCH OUT FOR THE MONSTER, IF YOU WALK INTO HIM YOU ARE DEAD, BUT IF HE WALKS INTO YOUR ROOM,YOU HAVE A CHANCE TO ESCAPE, GOOD LUCK\n" <<endl;
    // Execution of the game starts here
   while(true)
   {
        // Iterate between agents, monster and players
        for(int i = 0; i < agents.size(); i++)
            {
                //Ask agent to act
                bool ok = agents[i]->act();
                //Check current room that results from his act
                Room *currm = agents[i]->cur_room;
                //If act reurns false
                if(!ok)
                    {   //Print quit message
                        cout << "\n" << agents[i]->getName() << ", you quit.\n" << endl;
                        //Remove player from the occupants of the room he is in
                        currm->leave(agents[i]);
                        //Remove player from Agents vector
                        agents.erase(agents.begin()+i);
                    }
                //If the agent is a player not a monster
                if (!agents[i]->horns)
                {
                    //check if there is a monster in the room he is in
                    bool in = currm->check_monster(Monster,agents[i]);
                    // If there is
                    if (in)
                    {
                        //Remove agent from agent vector
                        agents.erase(agents.begin()+i);
                    }
                }
                //Check if there are any players besides the monster, if there is'nt ..
                if (agents.size()<=1)
                {
                    //End game
                    cout << "\nThere are no more players . Game ends\n" << endl;
                    return 0;
                }
            }
    }

    //Delete from memory
    delete entrance;
    delete lobby;
    delete kitchen;
    delete restroom;
    delete p1;
    delete p2;
    delete Monster;
    delete bedroom;
    return 0;

}





