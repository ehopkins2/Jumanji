#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Path.h"

using std::ostream;
using std::string;


class Player
{
    public: 

        //constructors
        Player();
        Player(const string, const string, const vector<unsigned int>&); //takes in player name, color and path data
                                                                         //the path data consists of size of path, number of wait for 5 or 8, 
                                                                         //number of jungle and number of rhino

        //accessors
        string get_username() const {return username;}
        string get_gameColor() const {return gameColor;}
        unsigned int get_lives() const {return lives;}
        Path get_playerPath() const {return playerPath;}
    
        //mutators
        void set_lives(unsigned int new_lives) {lives = new_lives;}

        //overloaded insertion operator
        friend ostream& operator <<(ostream&, const Player&);


    private: 
        string username; //player's username
        string gameColor; //player's game piece color
        unsigned int lives; //player's lives remaining
        Path playerPath; //player's path
};

#endif//PLAYER_H
