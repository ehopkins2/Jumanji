#include "Player.h"

using std::endl;

//default constructor
Player::Player() : user(false), lives(0) {}

//constructor that takes in player name, if it is a user or not, color and path data
//path data consists of size of path, number of wait for 5 or 8, number of jungle and number of rhino
//always initializes the number of lives to 5
Player::Player(const string st1, const bool bl, const string st2, const vector<unsigned int>& pathData) 
 : username(st1), user(bl), gameColor(st2), lives(5), playerPath(pathData) {}

ostream& operator <<(ostream& os, const Player& player)
{
    os << "Player Info:" << endl;
    os << "Name: " << player.username << endl;
    os << "Color: " << player.gameColor << endl;
    os << "Lives left: " << player.lives << endl;
    os << "Position: " << (player.playerPath).get_position() << endl;
    os << endl;
    return os;
}