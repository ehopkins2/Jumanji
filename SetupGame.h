#ifndef SETUP_GAME_H
#define SETUP_GAME_H

#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Card.h"
#include "Deck.h"
#include "Path.h"
#include "Player.h"

using std::cin;     using std::vector;      using std::tuple; 
using std::cout;    using std::map;         using std::make_tuple;
using std::endl;    using std::tolower;


bool has_only_digits(const string);

map<string, Player> setupPlayers();

Deck setupDeck();

map<string, vector<tuple<unsigned int, string>>> setupIntersections();


#endif//SETUP_GAME_H