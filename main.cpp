//Game Description

#include <vector>
#include <tuple>
#include <map>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include "Path.h"
#include "Player.h"
#include "SetupGame.h"


using std::cin;     using std::vector;
using std::cout;    using std::map;         
using std::endl;    using std::tuple;



int main()

{
    srand(time(NULL)); //makes sure the random numbers are not the same every game
     
    //Into
    cout << "Welcome to Jumanji!" << endl;
    
    //Setup the game
    map<string, Player> players = setupPlayers();
    Deck mainDeck = setupDeck();
    map<string, vector<tuple<unsigned int, string>>> intersections = setupIntersections();

    Card nextCard = mainDeck.draw();
    cout << nextCard;

    return 0;
}

