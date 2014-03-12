/**
@file Triangle.h

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
    const int VECTOR_SIZE = 3;
    const int NUM_VERTICES = 3;
    const int NUM_COORDINATES = 3;

    const int X_INDEX = 0;
    const int Y_INDEX = 1;
    const int Z_INDEX = 2;

    float* normal; // a vector of normals
    vertex* vertices; // an array of <x,y,z> coordinates        
};

#endif /* FACET_H */
