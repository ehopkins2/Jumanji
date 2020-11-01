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
        Path(unsigned int, unsigned int, unsigned int, unsigned int); //takes in number of spaces in path, number of wait for 5 or 8, number of jungle, and number of rhino

        //accessors
        vector<string> get_tiles() const {return path;}
        unsigned int get_position() {return position;}

        //mutators
        void set_position(unsigned int new_position) {position = new_position;}

        //overloarded insertion operator
        friend ostream& operator >>(ostream&, Path); //Do I really need this?

    private:
        vector<string> path; //vector that contains the path
        unsigned int position; //position where the player is in the path

};

#endif//PATH_H