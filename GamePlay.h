#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include <iostream>
#include <cstdlib>
#include <map>
#include "Path.h"
#include "Player.h"
#include "Deck.h"

using std::cout;    using std::map;
using std::cin;     using std::string;
using std::endl;

inline const unsigned int rollGameDie() { return (rand()%8 + 1);}

const unsigned int rescue(map<string, Player>&, string);

const unsigned int faceDanger(map<string, Player>&, Player&, Deck&, Card&);

void doActionOnPath(map<string, Player>&, Player&, Deck&, unsigned int&);

#endif//GAME_PLAY_H