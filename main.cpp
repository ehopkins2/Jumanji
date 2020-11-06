//Game Description

//Events: Start of game; player moving on the path: blank, wait_for_5_or_8, jungle, rhino; players intersecting; end of game

#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <sstream>
#include "Card.h"
#include "Deck.h"
#include "Path.h"
#include "Player.h"


using std::cin;     using std::vector;  
using std::cout;    using std::map;
using std::endl;    using std::tolower;

bool has_only_digits(const string);

int main()

{
    srand(time(NULL)); //makes sure the random numbers are not the same every game
 
    vector<Player> players;
    int numberPlayers;
    vector<unsigned int> pathData = {42, 5, 3, 7};
    vector<string> npcNames = {"Dwayne", "Karen", "Kevin", "Jack"};
    map<string,unsigned int> possibleColors;
    possibleColors["red"] = 0;
    possibleColors["blue"] = 0;
    possibleColors["green"] = 0;
    possibleColors["orange"] = 0;

    //Into
    cout << "Welcome to Jumanji!" << endl;
    
    string numberEntered;
    cout << "How many players will be playing (0-4)? ";
    getline(cin, numberEntered);
    cout << endl;
    while (!(has_only_digits(numberEntered)) || stoi(numberEntered) > 4 || stoi(numberEntered) < 0)
    {
        cout << "You have entered an invalid number of players." << endl;
        cout << "This is a four player game so please enter a number between 0 and 4." << endl;
        cout << "How many players will be playing? ";
        getline(cin, numberEntered);
        cout << endl;
    }
    
    numberPlayers = stoi(numberEntered);
    cout << "Next each player will give their name and choose a color." << endl;
    cout << "The possible colors are: red, blue, green and orange." << endl;
    cout << endl;

    for(int i = 0; i < numberPlayers; ++i)
    {
        string tempColor;
        string name;
        bool chosenColor = false;

        cout << "Player " << i + 1 << " what is your name? ";
        getline(cin, name);

        while(!chosenColor)
        {
            cout << name << " what color would you like to be? ";
            getline(cin, tempColor);
            std::transform(tempColor.begin(), tempColor.end(), tempColor.begin(), [](unsigned char c){return tolower(c);}); //uses Lambda expression
            if(possibleColors.find(tempColor) == possibleColors.end())
            {
                cout << "The color you entered is not a possible game color." << endl;
                cout << "The possible colors are: red, blue, green and orange." << endl;
                cout << endl;
            }
            else if(possibleColors[tempColor])
            {
                cout << "This color has already been chosen by another player." << endl;
                cout << "Please choose a different color." << endl;
                cout << endl;
            }
            else
            {
                cout << name << " your game color is now " << tempColor << "." << endl;
                cout << endl;
                possibleColors[tempColor] = 1;
                chosenColor = true;
                players.push_back(Player(name, true, tempColor, pathData));  
            }   
        }
    }

    vector<string> colorsLeft;
    auto it = possibleColors.begin();
    while(it != possibleColors.end())
    {
        if(!(it-> second))
            colorsLeft.push_back(it-> first);
        ++it;
    }

    for(int i = 0; i < colorsLeft.size(); ++i)
        players.push_back(Player(npcNames[i], false, colorsLeft[i], pathData));
    

    vector<Card> possibleCards;
    std::ifstream fin;
    fin.open("CardData.txt");

    string line;
    while(std::getline(fin, line))
    {
        if(line == "-1")
            break;
        std::stringstream sin;
        sin.str(line);
        vector<string> splitLine;
        string temp;
        while(getline(sin, temp, '\t'))
            splitLine.push_back(temp);
        possibleCards.push_back(Card(stoi(splitLine[0]),splitLine[1], splitLine[2], splitLine[3]));
    }
    Deck mainDeck((rand()%20)+30, possibleCards);

    Card nextCard = mainDeck.draw();
    cout << nextCard;


    return 0;
}

bool has_only_digits(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}