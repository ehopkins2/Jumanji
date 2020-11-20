#include "Player.h"

//default constructor
Player::Player() : user(false), lives(0) {}

//constructor that takes in player name, if it is a user or not, color and path data
//path data consists of size of path, number of wait for 5 or 8, number of jungle and number of rhino
//always initializes the number of lives to 5
Player::Player(const string st1, const bool bl, const string st2, const vector<unsigned int>& pathData,
               const vector<pair<unsigned int, string>>& vec) 
 : username(st1), user(bl), gameColor(st2), lives(5), playerPath(pathData), intersections(vec) {}


bool Player::movePlayer(const string dir, const unsigned int n, map<string, Player>& players)
{
    cout << username << " was at position " << playerPath.get_position() << "." << endl;

    if(dir == "forward")
    {
        unsigned int newPosition = playerPath.get_position() + n;
        if(newPosition > 41)
        {
            cout << username << " cannot move forward " << n << " spaces because they would go off their path." << endl;
            cout << "They will stay at their current position." << endl;
            cout << endl;
            return false;
        }

        for(auto x : intersections)
        {
            if(newPosition == x.first && (players[x.second]).get_playerPath().get_position() == newPosition)
            {
                cout << username << " cannot move forward " << n << " spaces because " << players[x.second].get_username()
                     << " is in the space." << endl;
                cout << "They will stay at their current position." << endl;
                cout << endl;
                return false;
            }
        }

        playerPath += n;
        cout << username << " is now at position " << playerPath.get_position() << "." << endl;
        cout << endl;
        return true;
    }

    if(dir == "backward")
    {
        if(playerPath.get_position() < n)
        {
            cout << username << " cannot move backward " << n << " spaces because they would go off their path." << endl;
            cout << "They will just go back to position 0." << endl;
            playerPath -= playerPath.get_position();
            cout << endl;
            return false;
        }

        for(auto x : intersections)
        {
            unsigned int newPosition = playerPath.get_position() - n;
            if(newPosition == x.first && players[x.second].get_playerPath().get_position() == newPosition)
            {
                cout << username << " cannot move backward " << n << " spaces because " << players[x.second].get_username()
                     << " is in the space." << endl;
                cout << "They will stay at their current position." << endl;
                cout << endl;
                return false;
            }
        }

        playerPath -= n;
        cout << username << " is now at position " << playerPath.get_position() << "." << endl;
        cout << endl;
        return true;   
    }
    return false;
}

bool Player::loseLife()
{
    if(lives == 0)
        return false;
    --lives;
    if(lives == 0)
    {
        cout << username << " has died and can no longer continue playing the game." << endl;
        return true;
    }
    return false;
}

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