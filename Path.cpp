#include "Path.h"
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

//default constructor
Path::Path() : position(0) {}

//constructor that takes in number of spaces in path, number of wait for 5 or 8, number of jungle, and number of rhino
//first puts all of the wait for 5 or 8, jungle and rhino spaces in the vector
//then fills the rest of the vector with blanks
//finally it randomly shuffles the vector
Path::Path(unsigned int size, unsigned int numWait, unsigned int numJungle, unsigned int numRhino) : position(0) 
{
    if((numWait + numJungle + numRhino) > size)
    {
        cout << "Size of path is too small to fit the desired number of each type of space." << endl;
        exit(1);
    }

    for(int i = 0; i < numWait; ++i)
        path.push_back("Wait for 5 or 8");
    
    for(int i = 0; i < numJungle; ++i)
        path.push_back("Jungle");
    
    for(int i = 0; i < numRhino; ++i)
        path.push_back("Rhino");
    
    for(int i = 0; i < size - (numWait + numJungle + numRhino); ++i)
        path.push_back("Blank");
    
    std::random_shuffle(path.begin(), path.end());
}

