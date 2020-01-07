#include "Player.h"

//sets the following features
 Player::Player(string _name, Room *starting_room)
    {
        name = _name;
        horns = false;
        cur_room = starting_room;
        key = false;
    };

//function controls how the player moves
bool Player::act()
    {
        Room *tester;    //room used for tests
        string exit;     //holds direction from player
        cout << "\n" << name << ", it is now your turn." << endl;
        cout << cur_room->getDescription() <<endl;    //prints current rooms description
        cur_room->printOccupants();                   //prints occupants inside room
        cur_room->printLinked();                      //prints the rooms linked to the current room

        cout << name << " , which exit ? or (quit) " << endl; //ask for direction
        loop:
        cin >> exit;
        //if player quits
        if (exit == "quit" || exit =="Quit")
        {
            return false;
        }
        else
        {
            //Test the room that was eeturned
            tester = cur_room->getLinked(exit, this);
            //If the getLinked returns a 0
            if (tester == false)
            {
                //Room is either locked or there is no room in that direction
                cout << "You cant go there.\n" <<endl;
                cout << "Enter another direction." <<endl;
                goto loop;  //repeat for input
            }
            //otherwise
            else
            {
                //update agents current room
                cur_room = tester;
                return true;
            }

        }
    }

