# HumanVsGrue_GameDesign

![Alt text](/AhmedGsh/HumanVsGrue_GameDesign/grues-uml.png?raw=true )


In my game, there are one or more human players (the Player class), and some grues (the Grue class; a grue is a scary monster that eats people, but is never present in lighted rooms, for what it’s worth). The Game class tells the grues and players to make their moves (the grues’ moves are random, the players’ moves come from asking the person at the keyboard to make a move).

Rooms are connected to each other by arbitrary exits (e.g. “south,” “out the window”). Each room keeps track of the things inside it (using a set). Also, there are generic things (the Thing class) such as statues and forks and knives, lying around the maze. Since Players and Grues are Agents and Agents are Things, each room is keeping track of the things, players, and grues inside of it.

The solid-line arrows in the diagram indicate inheritance relationships. The dotted-line arrows represent “dependency,” which means, for example, that the Player and Grue classes may need to be modified if the Room class changes its definition.

Private variables/methods start with a dash (-), protected variables/methods start with a hash (#), and public variables/methods start with a plus (+). Pure virtual methods are bold and italicized.

