#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Card
{
    public:
        //constructors
        Card();
        Card(const unsigned int, const string, const string, const string); //takes in moveSpaces, riddle, answer, rescueItem

        //accessors
        unsigned int get_moveSpaces() const {return moveSpaces;}
        string get_riddle() const {return riddle;}
        string get_answer() const {return answer;}
        string get_rescueItem() const {return rescueItem;}

        //overloaded insertion operator
        friend ostream& operator <<(ostream&, Card);


    private:
        unsigned int moveSpaces; //number of spaces to move
        string riddle; //riddle to be answered
        string answer; //answer to the riddle
        string rescueItem; //item that will rescue the player

};

#endif//CARD_H