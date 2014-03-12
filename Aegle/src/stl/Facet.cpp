/**
@file Facet.cpp

Created March 11th 2014
*/

#include "Facet.h"

Facet::Facet()
{
    // allocate memory for the normal vector.
    normal = new float[VECTOR_SIZE];

    // allocate memory for the pointer to the vertices
    vertices = new vertex[NUM_VERTICES];
};

Facet::~Facet()
{
    delete normal;
    delete vertices;
}