//Game Description

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include "Path.h"
#include "Player.h"
#include "SetupGame.h"
#include "GamePlay.h"


using std::cin;     using std::vector;      using std::string;
using std::cout;    using std::map;         
using std::endl;    using std::tuple;



int main()

{
    srand(time(NULL)); //makes sure the random numbers are not the same every game
     
    //Into
    cout << "Welcome to Jumanji!" << endl;
    
    //Setup the game
    map<string, Player> players = setupPlayers();
    Deck mainDeck = setupDeck();
    
    bool winner = false;
    unsigned int numPlayersAlive = 4;
    bool exit = false;

    while(!winner || numPlayersAlive <=1)
    {
        if(exit)
        {
            cout << "You will now exit the game." << endl;
            break;
        }

        for(auto &p : players)
        {
            Player currentPlayer = p.second;
            if(currentPlayer.get_lives() == 0)
                break;

            cout << endl;
            cout << "________________" << endl;
            cout << endl;
            cout << currentPlayer.get_username() << ", it is now your turn." << endl;
            cout << endl;

            string temp;
            cout << "At this time, you may exit the game by typing exit or you can continue by typing anything else.";
            getline(cin, temp);
            cout << endl;
            std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c){return std::tolower(c);}); //uses Lambda expression

            if(temp == "exit")
            {
                exit = true;
                break;
            }

            bool moveSuccessful = false;
            const unsigned int numMove = rollGameDie();

            if(currentPlayer.get_playerPath().get_path()[currentPlayer.get_playerPath().get_position()] != "Rhino")
            {
                cout << "You roll the game die." << endl;
                cout << "You rolled a " << numMove << "." << endl;
                moveSuccessful = currentPlayer.movePlayer("forward", numMove, players);
                players[currentPlayer.get_gameColor()] = currentPlayer;
            }
            else
            {
                cout << "You are currently stuck on a Rhino." << endl;
                if(currentPlayer.get_playerPath().get_position() == 40)
                {
                    cout << "Since you are currently at position 40, you can ignore the Rhino. You need to roll a 1 to win." << endl;
                    cout << "You rolled a " << numMove << "." << endl;
                    moveSuccessful = currentPlayer.movePlayer("forward", numMove, players);
                    players[currentPlayer.get_gameColor()] = currentPlayer;
                }
                else
                {
                    cout << "You roll the game die. You need to roll an even number to move forward." << endl;
                    cout << "You rolled a " << numMove << "." << endl;
                    if(numMove%2 == 0)
                    {
                        moveSuccessful = currentPlayer.movePlayer("forward", numMove, players);
                        players[currentPlayer.get_gameColor()] = currentPlayer;
                    }
                    else
                        cout << "You did not roll an even number, so you are stuck." << endl;
                }
            }

            if(moveSuccessful || currentPlayer.get_playerPath().get_position() == 41)
                doActionOnPath(players, currentPlayer, mainDeck, numPlayersAlive, winner);     
                        
            if(winner || numPlayersAlive <= 1)
                break;
        }

    }

    if(numPlayersAlive <= 1)
        cout << "There are not enough players alive to continue. The game is now over" << endl;

    cout << "Thank you for playing Jumanji!" << endl;

    return 0;
}

