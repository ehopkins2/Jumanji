#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <string>
#include <vector>

using std::ostream;
using std::string;
using std::vector;


class Path
{
    public:
        //constructors
        Path();

        //accessors
        vector<string> get_tiles() const {return tiles;}
        unsigned int get_position() {return position;}

        //mutators
        void set_position(unsigned int new_position) {position = new_position;}

        //operators
        friend ostream& operator >>(ostream& os, Path path); //Do I really need this?

    private:
        vector<string> tiles; //vector that contains the tiles that make up the path
        unsigned int position; //position where the player is in the path

};

#endif//PATH_H