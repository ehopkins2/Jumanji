#include "SetupGame.h"


bool has_only_digits(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}


map<string, Player> setupPlayers()
{
    map<string, Player> players;
    vector<unsigned int> pathData = {42, 5, 3, 7};
    vector<string> npcNames = {"Dwayne", "Karen", "Kevin", "Jack"};
    map<string,unsigned int> possibleColors;
    possibleColors["red"] = 0;
    possibleColors["blue"] = 0;
    possibleColors["green"] = 0;
    possibleColors["orange"] = 0;

    map<string, vector<pair<unsigned int, string>>> intersections;
    intersections["red"] = {make_pair(23,"green"), make_pair(32, "blue")};
    intersections["blue"] = {make_pair(23, "orange"), make_pair(32, "red")};
    intersections["green"] = {make_pair(23, "red"), make_pair(32,"orange")};
    intersections["orange"] = {make_pair(23, "blue"), make_pair(32, "green")};

    int numberPlayers;
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
                players[tempColor] = Player(name, true, tempColor, pathData, intersections[tempColor]);  
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
    {
        string color = colorsLeft[i];
        players[color] = Player(npcNames[i], false, color, pathData, intersections[color]);
    }

    return players;
}

Deck setupDeck()
{
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
    return Deck((rand()%20)+30, possibleCards);
}
