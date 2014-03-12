/**
@file Facet.h

STL Files are made up of several facets combined together
to form a solid. Each facet has a normal vector and three
vertices. 

Created March 11th 2014
*/

#ifndef FACET_H
#define FACET_H

#include <string>

using namespace std;

typedef struct {
    float x;
    float y;
    float z;
} vertex;

class Facet
{
public:
    Facet();
    Facet(float* normal, vertex* vertices);
    ~Facet();

private:
    // Constants for Facet
    static const int VECTOR_SIZE = 3;
    static const int NUM_VERTICES = 3;
    static const int NUM_COORDINATES = 3;

    static const int X_INDEX = 0;
    static const int Y_INDEX = 1;
    static const int Z_INDEX = 2;


    float* normal; // a vector of normals
    vertex* vertices; // an array of <x,y,z> coordinates        
};

#endif /* FACET_H */
