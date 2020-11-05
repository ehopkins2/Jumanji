#include "Player.h"

using std::endl;

//default constructor
Player::Player() : lives(0) {}

//constructor that takes in player name, color and path data
//path data consists of size of path, number of wait for 5 or 8, number of jungle and number of rhino
//always initializes the number of lives to 5
Player::Player(const string st1, const string st2, const vector<unsigned int>& pathData) 
 : username(st1), gameColor(st2), lives(5), playerPath(pathData) {}

ostream& operator <<(ostream &os, Player player)
{
    os << "Player Info:" << endl;
    os << "Name: " << player.get_username() << endl;
    os << "Color: " << player.get_gameColor() << endl;
    os << "Lives left: " << player.get_lives() << endl;
    os << "Position: " << (player.get_playerPath()).get_position() << endl;
    return os;
}