#include "Player.h"

//default constructor
Player::Player() : lives(3) {}

//constructor that takes in player name, color and path data
//path data consists of size of path, number of wait for 5 or 8, number of jungle and number of rhino
//always initializes the number of lives to 3
Player::Player(const string st1, const string st2, const vector<unsigned int>& pathData) 
 : username(st1), gameColor(st2), lives(3), playerPath(pathData) {}