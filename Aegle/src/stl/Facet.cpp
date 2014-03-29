/**
@file Facet.cpp

Created March 11th 2014
*/

#include "Facet.h"

Facet::Facet()
{
    // vertices and normal are initialized thanks to constructors. 
};

Facet::Facet(normal n) : normal_(n)
{}

Facet::Facet(normal n, vertices vertices) : normal_(n), vertices_(vertices)
{}

Facet::~Facet()
{}

// Accesors
normal Facet::getNormal() const
{
    return normal_;
}

vertices Facet::getVertices() const
{
    return vertices_;
}

vertex Facet::getVertexAt(const int& i) const
{
    if( i < 0 || i > NUM_VERTICES ) 
    {
        return vertex();
    }

    return vertices_[i];
}

// Mutators
void Facet::setNormal(const normal& n)
{
    if(n.size() != VECTOR_SIZE) return;
    
    normal_ = n;
}

void Facet::setVertices(const vertices& v)
{
    for(int i = 0; i < NUM_VERTICES; i++)
    {
        vertices_[i] = v[i];
    }
}

void Facet::setVertexAt(const vertex& v, const int& i)
{
    if( i < 0 || i > NUM_VERTICES) return;

    vertices_[i] = v;
}


