#include "Card.h"

//default constructor
Card::Card():moveSpaces(0), riddle(""), answer(""), rescueItem("") {}

//constructor that takes in a value for member variable
Card::Card(unsigned int n, string str1, string str2, string str3)
 : moveSpaces(n), riddle(str1), answer(str2), rescueItem(str3) {}

//Overloaded insertion operator
ostream& operator <<(ostream& os, Card card)
{
    os << card.riddle;
    return os; 
}