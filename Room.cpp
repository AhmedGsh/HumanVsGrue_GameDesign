#include "Room.h"

//set room features
Room::Room(string _name, string _description, bool _key, bool _lock)
    {
        key = _key;
        lock = _lock;
        name = _name;
        description = _description;
    }
//return rooms name
string Room::getName()
    {
        return name;
    }
//return room description
string Room::getDescription()
    {
        return description;
    }
//insert agent into room
void Room::enter(Agent *a)
    {
        occupants.insert(a);
    }
//remove agent from room
void Room::leave(Agent *a)
    {
        occupants.erase(a);
    }
//print the agents in the room
void Room::printOccupants()
    {
        cout << "Occupants in this room:" << endl;
        set<Agent*>::iterator it;
        for(it = occupants.begin(); it != occupants.end(); ++it)
            {
                cout << (*it)->getName() << endl;
            }
        cout << endl;
    }
//link rooms
void Room::link(string direction, Room *r)
    {
        links[direction] = r;
    }

//A function that links the agent to a room
Room* Room::getLinked(string direction, Agent* current)
    {
        it = links.find(direction);     //check if the direction is in the links SET
        //if the direction is not a link in the room
        if (it == links.end())
            {
                return 0;
            }
        //if the agent is a monster, he can enter any room without a key
        else if (current->horns)
        {
            leave(current);                    //remove from current room
            links[direction]->enter(current);   //add to the new rooms SET
            return links[direction];            //return the new room
        }

        //If the new room has a key
        else if (links[direction]->key)
        {
            cout << "\nYou have found the key.\n" << endl;
            //Set agents key to true
            current->setkey();
            leave(current);      //remove from current room
            links[direction]->enter(current);       //add to the new rooms SET
            return links[direction];       //return the new room
        }

        else if (links[direction]->lock)
        {
            if (current->key)
            {
                cout << "\nYou unlocked the room, and found the treasure. You WIN." <<endl;
                leave(current);                 //remove from current room
                links[direction]->enter(current);   //add to the new rooms SET
                return links[direction];    //return the new room
            }
            //If the player does not have a key
            else
            {
                cout<< "This room is locked.\n" << endl;
                return 0;
            }
        }
        else
        {
            leave(current);         //remove from current room
            links[direction]->enter(current);       //add to the new rooms SET
            return links[direction];            //return the new room
        }
    }
//print rooms linked to this room
void Room::printLinked()
    {
        cout << "There is an exit to ";
        for (it= links.begin(); it!=links.end(); ++it)
        {
            Room* NR = it->second;       //gets room
            string NOR = NR->getName();     //gets rooms name
            cout << ", ";
            cout << it->first << "(" << NOR << ") ";   //prints
        }
        cout << "." << endl;
    }

//check if a monster is inside the room
bool Room::check_monster(Agent *Monster,Agent *player)
    {
        const bool is_in = occupants.find(Monster) != occupants.end();  //check if monster is in the rooms SET
        if (is_in)
        {
            cout << "\nOops, you faced the monster. " << player->getName() << ", you are now dead.\n" << endl;
            //remove player from the rooms occupants
            occupants.erase(player);
            return true;
        }

        else {return false;}

    }
