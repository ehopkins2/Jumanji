#include "Deck.h"
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

//default constructor
Deck::Deck() : size(0), position(0) {}

//constructor that takes in the size of the deck and a vector of all the possible cards
//assumes it will use all of the possible cards at lest once
//first checks that the size of the deck is at least as big as the number of possible cards
//places all the possible cards into the vector then randomly selects cards to fill up the deck
Deck::Deck(unsigned int n, const vector<Card>& possibleCards) : size(n), position(0)
{
    int numCards = possibleCards.size();
    if(n < numCards)
    {
        cout << "The given size of deck is too small to fit all the possible cards." << endl;
        exit(1);
    }

    if(n > 50)
    {
        cout << "The given size of deck is too big. A deck can be at most 50 cards." << endl;
    }

    for(int i = 0; i < numCards; ++i)
        deck.push_back(possibleCards[i]);
    n -= numCards;

    for(;n > 0; --n)
        deck.push_back(possibleCards[rand() % numCards]);
    
    shuffle();
}

//shuffles the cards in the deck
void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

//draws the next card in the deck
//if currently at the last card in the deck, it shufffles the deck and then draws the first card
const Card Deck::draw()
{
    Card currentCard = deck[position];
    position += 1;
    if (position == size)
    {
        shuffle();
        position = 0;
    }
    return currentCard;
}