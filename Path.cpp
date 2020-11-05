#include "Path.h"
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;

//default constructor
Path::Path() : position(0) {}

//constructor that takes in vector containing number of spaces in path, number of wait for 5 or 8, number of jungle, and number of rhino
//first puts all of the wait for 5 or 8, jungle and rhino spaces in the vector
//then fills the rest of the vector with blanks and randomly shuffles the vector
//finally it adds a blank at the beginning and Jumanji at the end
Path::Path(const vector<unsigned int>& pathData) : position(0) 
{
    if((pathData[1] + pathData[2] + pathData[3]) > pathData[0] - 2)
    {
        cout << "The size of path is too small to fit the desired number of each type of space." << endl;
        exit(1);
    }

    for(int i = 0; i < pathData[1]; ++i)
        path.push_back("Wait for 5 or 8");
    
    for(int i = 0; i < pathData[2]; ++i)
        path.push_back("Jungle");
    
    for(int i = 0; i < pathData[3]; ++i)
        path.push_back("Rhino");
    
    for(int i = 0; i < pathData[0] - (pathData[1] + pathData[2] + pathData[3] + 2); ++i)
        path.push_back("Blank");
    
    std::random_shuffle(path.begin(), path.end());
    
    path.push_back("Blank");
    std::swap(path[0], path[pathData[0]-2]);
    
    path.push_back("JUMANJI!");
}

ostream& operator <<(ostream& os, Path pathObj)
{
    unsigned int size = (pathObj.get_path()).size();
    for(int i = 0; i < size; ++i)
    {
        os << i << ": " << pathObj.get_path()[i] << endl; 
    }
    return os;
}

