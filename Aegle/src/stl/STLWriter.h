/**
@file STLWriter.h

Created March 11th 2014
*/
#ifndef STLWRITER_H
#define STLWRITER_H

#include "STL.h"
#include "Facet.h"
#include <fstream>

using namespace std;

/* Base class for writing out STL files.
*/

class STLWriter 
{
public:

    STLWriter();
    ~STLWriter();

    // Helper function to verify the STL is appropriate for writing
    bool validateSTL(const STL&);

    // Function to be implemented by derived classes
    virtual bool writeSTL(const STL&) = 0;

private:
    virtual bool writeSTLHeader(const STL&) = 0;
    virtual bool writeSTLFacets(const STL&) = 0;
    virtual bool writeSTLFacet(const Facet&) = 0;
};

#endif /* STLWRITER_H */