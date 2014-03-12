/**
@file STL.cpp

Created March 11th 2014
*/

#include "STL.h"

STL::STL()
{
    header_ = "";
    numFacets_ = 0;
    facets_ = new Facet[numFacets_];
}

STL::STL(int numFacets)
{
    header_ = "";
    numFacets_ = numFacets;
    facets_ = new Facet[numFacets_];
}

STL::~STL()
{
    delete facets_;
}

string STL::getHeader() const
{
    return header_;
}

int STL::getHeaderLength() const
{
    return header_.length();
}

