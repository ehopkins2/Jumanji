#include "Card.h"

//default constructor
Card::Card():moveSpaces(0) {}

//constructor that takes in a value for each member variable
Card::Card(const unsigned int n, const string str1, const string str2, const string str3)
 : moveSpaces(n), riddle(str1), answer(str2), rescueItem(str3) {}

//Overloaded insertion operator
ostream& operator <<(ostream& os, Card card)
{
    os << card.riddle;
    return os; 
}