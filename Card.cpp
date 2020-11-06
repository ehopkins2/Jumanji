#include "Card.h"

using std::endl;

//default constructor
Card::Card():moveSpaces(0) {}

//constructor that takes in a value for each member variable
Card::Card(const unsigned int n, const string str1, const string str2, const string str3)
 : moveSpaces(n), riddle(str1), answer(str2), rescueItem(str3) {}

//Overloaded insertion operator
ostream& operator <<(ostream& os, Card card)
{
    os << "Moves: " << card.moveSpaces << endl;
    os << "Riddle: " << card.riddle << endl;
    return os; 
}