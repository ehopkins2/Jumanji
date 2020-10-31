#include "Deck.h"
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

//default constructor
Deck::Deck() : size(0) {}

//constructor that takes in the size of the deck and a vector of all the possible cards
//assumes it will use all of the possible cards at lest once
//first checks that the size of the deck is at least as big as the number of possible cards
//places all the possible cards into the vector then randomly selects cards to fill up the deck
Deck::Deck(unsigned int n, const vector<Card>& possibleCards) : size(n)
{
    int numCards = possibleCards.size();
    if(n < numCards)
    {
        cout << "Size of deck is too small." << endl;
        exit(1);
    }

    for(int i = 0; i < numCards; ++i)
        deck.push_back(possibleCards[i]);
    n -= numCards;

    for(;n > 0; --n)
        deck.push_back(possibleCards[rand() % numCards]);
}

void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}