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
        Player(string, string);


        //accessors
        string get_username() const {return username;}
        string get_gameColor() const {return gameColor;}
        unsigned int get_lives() {return lives;}
        Path get_playerPath() {return playerPath;}
    
        //mutators
        void set_lives(unsigned int new_lives) {lives = new_lives;}


        //Move the player a certain number of places (not sure if I actually want this here)

        //operators
        friend ostream& operator >>(ostream& os, const Player& player);


    private: 
        string username; //player's username
        string gameColor; //player's game piece color
        unsigned int lives; //player's lives remaining
        Path playerPath; //player's path
};


#endif//PLAYER_H
