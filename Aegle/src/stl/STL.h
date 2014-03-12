/**
@file STL.H

STL class. Encompasses everything needed to 
write out an STL file. 

Created March 11th 2014
*/

#ifndef STL_H 
#define STL_H

#include <string>
#include <stdlib.h>
#include "Facet.h"

using namespace std;

class STL
{
public:
    STL();
    ~STL();
    STL(int numTriangles);

    string getHeader() const;
    int getHeaderLength() const;

    bool addFacet();

private:
    string header_;
    int numFacets_;

    Facet* facets_;
};

#endif /* STL_H */