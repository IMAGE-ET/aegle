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

    // Constructors
    STL();
    STL(int numFacets);
    STL(string name, int numFacets);

    // Destructors
    ~STL();
    
    // Accesors
    string getHeader() const;
    int getHeaderLength() const;
    int getNumFacets() const;
    string getName() const;
    Facet* getFacets() const;
    Facet getFacetAt(const int& i) ;

    // Mutators
    void setHeader(const string& s);
    void setNumFacets(const int& l);
    void setName(const string& name);
    void setFacets(const Facet*& facets);
    void setFacets(const Facet*& facets, const int& size);
    void setFacetAt(const Facet& facet, const int& i);
    void addFacet(const Facet& facet);

private:
    bool isFacetIndexValid(const int& i);

    //Members
    string header_;
    int numFacets_;
    string name_;
    Facet* facets_;
};

#endif /* STL_H */