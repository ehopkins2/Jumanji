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
        unsigned int get_numPossibleCards() const {return numPossibleCards;}
        vector<Card> get_deck() const {return deck;}
        vector<string> get_possibleAnswers() const {return possibleAnswers;}
        unsigned int get_position() const {return position;}

        //other member functions
        void shuffle();//shuffles the current deck
        const Card draw();

        //overloaded insertion operator
        friend ostream& operator <<(ostream& os, Deck deck); //Do I really need this?

    private:
        unsigned int size; //number of cards in the deck
        unsigned int numPossibleCards; //number of unique cards in the deck
        vector<Card> deck; //current deck
        vector<string> possibleAnswers; //all the possible answers to the cards in the deck
        unsigned int position; //current place in deck
};

#endif//DECK_H