#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>


using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;


class Path
{
    public:
        //constructors
        Path();
        Path(const vector<unsigned int>&); //takes in vector that contains: 
                                           //number of spaces in path, number of wait for 5 or 8, number of jungle, and number of rhino

        //accessors
        vector<string> get_path() const {return path;}
        unsigned int get_position() const {return position;}

        //mutators
        void set_position(unsigned int new_position) {position = new_position;}

        //add and sub assign operators
        Path& operator +=(const unsigned int);
        Path& operator -=(const unsigned int);

        //overloaded insertion operator
        friend ostream& operator <<(ostream&, const Path);

    private:
        vector<string> path; //vector that contains the path
        unsigned int position; //position where the player is in the path

};

#endif//PATH_H