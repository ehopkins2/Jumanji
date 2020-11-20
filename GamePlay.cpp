#include "GamePlay.h"

const unsigned int rescue(map<string, Player> &players, string item)
{
    map<unsigned int, string> rescueDie;
    rescueDie[0] = "axe";
    rescueDie[1] = "die";
    rescueDie[2] = "open door";
    rescueDie[3] = "racquet";
    rescueDie[4] = "raft";
    rescueDie[5] = "rope";
    rescueDie[6] = "saber";
    rescueDie[7] = "hourglass";

    for(int i = 0; i < 50; ++i)
    {
        bool success = true;
        for(auto &p : players)
        {
            string roll = rescueDie[rand()%8];
            if(roll != item && roll != "hourglass")
            {
                success = false;
                break;
            }
        }
        if(success)
            return 0; //saved
    }
    return 1; //wasn't saved
}

const unsigned int faceDanger(map<string, Player> &players, Player &currentPlayer, Deck &mainDeck, Card &currentCard)
{
    string guess;
    cout << "Can you guess the answer to the riddle?";

    if(currentPlayer.get_user())
        getline(cin, guess);
    else
    {
        guess = mainDeck.get_possibleAnswers()[rand() % mainDeck.get_numPossibleCards()];
        cout << endl;
        cout << currentPlayer.get_username() << " guessed " << guess << "." << endl;
    }
            
    if(guess == currentCard.get_answer())
    {
        cout << "That is correct! You escape the danger and can move forward " << currentCard.get_moveSpaces() << "." << endl;
        currentPlayer.movePlayer("forward", currentCard.get_moveSpaces(), players);
        players[currentPlayer.get_gameColor()] = currentPlayer;
        return 3; //escaped
    }
    else
    {
        cout << "That is incorrect! The answer was " << currentCard.get_answer() << ". Let's see if your friends can rescue you." << endl;
        cout << "Everyone will now roll the rescue die to try and rescue " << currentPlayer.get_username() << "." << endl;
        cout << endl;
        return rescue(players, currentCard.get_rescueItem());
    }
}

void doActionOnPath(map<string, Player> &players, Player &currentPlayer, Deck &mainDeck, unsigned int &numPlayersAlive, bool &winner)
{
    enum pathType {jumanji, waitFor5Or8, jungle, rhino, blank};
    map<string, pathType> mapPathType;
    mapPathType["JUMANJI!"] = jumanji;
    mapPathType["Wait for 5 or 8"] = waitFor5Or8;
    mapPathType["Jungle"] = jungle;
    mapPathType["Rhino"] = rhino;
    mapPathType["Blank"] = blank;

    Path currentPlayerPath = currentPlayer.get_playerPath();
    string currentPathType = currentPlayerPath.get_path()[currentPlayerPath.get_position()];

    cout << "You have landed on " << currentPathType << "." << endl;

    switch(mapPathType[currentPathType])
    {
        case jumanji:
        {
            cout << currentPlayer.get_username() << " has won the game!" << endl;
            cout << endl;
            winner = true;
            break;
        }

        case waitFor5Or8:
        {
            cout << "Your turn is done when you roll a 5 or an 8." << endl;
            cout << "Each time, you fail to roll a 5 or an 8, you will move backwards one space." << endl;
            cout << endl;
            unsigned int roll = rollGameDie();
            cout << "You have rolled a " << roll << "." << endl;
            while(roll != 5 && roll != 8)
            {
                currentPlayer.movePlayer("backward", 1, players);
                if(currentPlayer.get_playerPath().get_position() == 0)
                {
                    cout << "You are back at position 0 in your path, so your turn is now over." << endl;
                    cout << endl;
                    players[currentPlayer.get_gameColor()] = currentPlayer;
                    break;
                }
                roll = rollGameDie();
                cout << "You have rolled a " << roll << "." << endl;
            }
            if(roll == 5 || roll == 8)
            {
                cout << "Your turn is now over." << endl;
                cout << endl;
                players[currentPlayer.get_gameColor()] = currentPlayer;
            }
            break;
        }

        case jungle:
        {
            cout << "You drag your friends into the jungle with you, but you get separated." << endl;
            cout << "In order for everyone to escape with their lives, you need to escape a danger by guessing the answer to a riddle," 
                 << "or your friends need to rescue you." << endl;
            cout << endl;
            int chancesLeft = 3;
            bool success = false;
                
            while(!success && chancesLeft > 0)
            {
                cout << "You have " << chancesLeft << " chances left to try and escape." << endl;
                Card currentCard = mainDeck.draw();
                cout << "You draw the next card in the main deck." << endl;
                cout << currentCard << endl;

                unsigned int result = faceDanger(players, currentPlayer, mainDeck, currentCard);

                switch(result)
                {
                    case 0:
                    {
                        unsigned int numMoves = currentCard.get_moveSpaces();
                        cout << "Your friends have saved you! Everyone gets to move forward " << numMoves << "." << endl;
                        for(auto& p : players)
                        {
                            p.second.movePlayer("forward", numMoves, players);
                        }  
                        success = true;
                        break;
                    }

                    case 1:
                    {
                        cout << "Your friends did not save you!" << endl;
                        --chancesLeft;
                        break;
                    }

                    case 3:
                        success = true;
                        break;
                }
            }
            if(!success)
            {
                cout << "Since you and your friends were not successful, you all lose a life." << endl;
                for(auto &p : players)
                {
                    bool playerDied = p.second.loseLife();
                    if(playerDied)
                        --numPlayersAlive;
                }
            }
            cout << "Your turn is now over." << endl;
            cout << endl;
            break;            
        }

        case rhino:
        {
            cout << "Your turn is now over." << endl;
            cout << endl;
            break;
        }

        case blank:
        {
            cout << "You are faced with a danger. "
                 << "In order to survive, you need to guess the answer to the riddle or your friends need to save you." << endl;
            Card currentCard = mainDeck.draw();
            unsigned int numMoves = currentCard.get_moveSpaces();
            cout << "You draw the next card in the main deck." << endl;
            cout << currentCard << endl;

            unsigned int result = faceDanger(players, currentPlayer, mainDeck, currentCard);

            switch(result)
            {
                case 0:
                {
                    cout << "Your friends have saved you! All of your friends get to move forward " << numMoves << "." << endl;
                    for(auto& p : players)
                    {
                        if(p.second.get_gameColor() != currentPlayer.get_gameColor())
                            p.second.movePlayer("forward", numMoves, players);
                    }        
                    break;
                }

                case 1:
                {
                    cout << "Your friends did not save you! You lose a life and move backward " << numMoves << " spaces." << endl;
                    currentPlayer.movePlayer("backward", numMoves, players);
                    bool playerDied = currentPlayer.loseLife();
                    players[currentPlayer.get_gameColor()] = currentPlayer;
                    if(playerDied)
                        --numPlayersAlive;
                    break;
                }

                case 3:
                    break;
            }
            break;
        }

        default:
        {
            cout << "The path has an invalid path type." << endl;
            exit(1);
        }
    }
}
