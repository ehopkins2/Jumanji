#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <vector>
#include "Path.h"

using std::cout;        using std::ostream;     using std::vector;
using std::cin;         using std::string;      using std::map;
using std::endl;        using std::pair;


class Player
{
    public: 

        //constructors
        Player();
        //takes in player name, if a user or not, color, path data, and intersections with other players
        //the path data consists of size of path, number of wait for 5 or 8, number of jungle and number of rhino
        Player(const string, const bool, const string, const vector<unsigned int>&, const vector<pair<unsigned int, string>>&); 

        //accessors
        string get_username() const {return username;}
        bool get_user() const {return user;}
        string get_gameColor() const {return gameColor;}
        unsigned int get_lives() const {return lives;}
        Path get_playerPath() const {return playerPath;}
    
        //mutators
        void set_lives(unsigned int new_lives) {lives = new_lives;}

        //other member functions
        bool movePlayer(const string, const unsigned int, map<string, Player>&);
        bool loseLife();

        //overloaded insertion operator
        friend ostream& operator <<(ostream&, const Player&);


    private: 
        string username; //player's username
        bool user; //true if the player is a user and false if it is an npc
        string gameColor; //player's game piece color
        unsigned int lives; //player's lives remaining
        Path playerPath; //player's path
        vector<pair<unsigned int, string>> intersections; //where player's path intersects with other players
};

#endif//PLAYER_H
