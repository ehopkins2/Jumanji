#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"

using std::ostream;
using std::vector;

class Deck
{
    public:
        //constructors
        Deck();
        Deck(unsigned int, const vector<Card>&); //takes in size of deck and vector of all possible cards

        //accessors
        unsigned int get_size() const {return size;}
        vector<Card> get_deck() {return deck;}

        //other member functions
        void shuffle();//shuffles the current deck

        //overloaded insertion operator
        friend ostream& operator <<(ostream& os, Deck deck); //Do I really need this?

    private:
        unsigned int size; //number of cards in the deck
        vector<Card> deck; //current deck
};

#endif//DECK_H