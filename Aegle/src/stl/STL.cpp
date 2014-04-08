/**
@file STL.cpp

Created March 11th 2014
*/

#include "STL.h"

STL::STL() : header_(""), facets_(0)
{
}

STL::STL(int numFacets) : header_(""), facets_(numFacets)
{
}

STL::~STL()
{

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
    return facets_.size();
}

string STL::getName() const
{
    return name_;
}

vector<Facet> STL::getFacets() const
{
    return facets_;
}

Facet STL::getFacetAt(const int& i) const
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
	facets_.resize(l);
}

void STL::setName(const string& name)
{
    name_ = name;
}
void STL::setFacets(const vector<Facet>& facets)
{
    for(size_t i = 0; i < facets_.size(); i++)
    {
        facets_[i] = facets[i];
    }
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
	facets_.push_back(facet);
}

bool STL::isFacetIndexValid(const int& i) const
{
    return (i > 0 && (size_t)i < facets_.size());
}