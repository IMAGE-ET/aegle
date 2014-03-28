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
#include <array>

using namespace std;

static const int VECTOR_SIZE = 3;
static const int NUM_VERTICES = 3;
static const int NUM_COORDINATES = 3;

typedef struct {
    float x;
    float y;
    float z;
} vertex;

typedef array<float,VECTOR_SIZE> normal;
typedef array<vertex,NUM_VERTICES> vertices;


class Facet
{
public:

    // Constructors
    Facet();
    Facet(normal n);
    Facet(normal normal, vertices vertices);
    
    // Destructors
    ~Facet();

    // Accesors
    normal getNormal() const;
    vertices getVertices() const;
    vertex getVertexAt(const int& i) const;

    // Mutators
    void setNormal(const normal&);
    void setVertices(const vertices& v);
    void setVertexAt(const vertex& v, const int& i);

private:
    // Constants for Facet


    static const int I_INDEX = 0;
    static const int J_INDEX = 1;
    static const int K_INDEX = 2;

    // Members
    normal normal_; // a vector of normals
    vertices vertices_; // an array of <x,y,z> coordinates     
};

#endif /* FACET_H */
