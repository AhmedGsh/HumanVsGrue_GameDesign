#ifndef ROOM_H
#define ROOM_H
#include "Thing.h"
#include "Agent.h"
#include <string>
#include <map>
#include <set>

class Room : public Thing
{
    private:
    string name;
    string description;
    set<Agent*> occupants;
    map<string, Room*> links;
    map<string, Room*>::iterator it;

    public:
    Room(string _name, string _description, bool _key, bool _lock);
    string getName();
    string getDescription();
    void enter(Agent *a);
    void leave(Agent *a);
    void printOccupants();
    void link(string direction, Room *r);
    Room* getLinked(string direction, Agent* current);
    void printLinked();
    bool check_monster(Agent *Monster,Agent *player);

};



#endif // ROOM_H
