/**
@file STL.cpp

Created March 11th 2014
*/

#include "STL.h"

STL::STL() : header_(""), numFacets_(0)
{
    facets_ = new Facet[numFacets_];
}

STL::STL(int numFacets) : header_(""), numFacets_(numFacets)
{
    facets_ = new Facet[numFacets_];
}

STL::~STL()
{
    delete facets_;
}

// Accesors
string STL::getHeader() const
{
    return header_;
}

int STL::getHeaderLength() const
{
    return header_.length();
}

int STL::getNumFacets() const
{
    return numFacets_;
}

string STL::getName() const
{
    return name_;
}

Facet* STL::getFacets() const
{
    return facets_;
}

Facet STL::getFacetAt(const int& i) 
{
    if(isFacetIndexValid(i))
    {
        return Facet();
    }

    return facets_[i];
}

// Mutators
void STL::setHeader(const string& s)
{
    header_ = s;
}

void STL::setNumFacets(const int& l)
{
    delete facets_;
    facets_ = new Facet[l];

    numFacets_ = l;
}

void STL::setName(const string& name)
{
    name_ = name;
}
void STL::setFacets(const Facet*& facets)
{
    for(int i = 0; i < numFacets_; i++)
    {
        facets_[i] = facets[i];
    }
}

void STL::setFacets(const Facet*& facets, const int& size)
{
    this->setNumFacets(size);
    this->setFacets(facets);
}


void STL::setFacetAt(const Facet& facet, const int& i)
{
    int index = i;
    if(isFacetIndexValid(i))
    {
        facets_[index] = facet;
    }
}

void STL::addFacet(const Facet& facet)
{
    Facet* temp = new Facet[numFacets_+1];
    for(int i = 0; i < numFacets_; i++)
    {
        temp[i] = facets_[i];
    }
  
    temp[numFacets_] = facet;
    numFacets_++; 
}

bool STL::isFacetIndexValid(const int& i)
{
    return (i > 0 && i < numFacets_);
}