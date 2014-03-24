/**
@file STLWriterBinary.h

Derived class of STLWriter. Writes out a STL object
as a STL binary file.

Created March 11th 2014
*/

#ifndef STLWRITER_BINARY_H
#define STLWRITER_BINARY_H

#include "STLWriter.h"

using namespace std;

class STLWriterBinary : STLWriter
{
public:
    STLWriterBinary();
    bool writeSTL(const STL&);

private:
    bool writeSTLHeader(const STL&);
    bool writeSTLFacets(const STL&);
    bool writeSTLFacet(const Facet&);

};

#endif STLWRITER_BINARY_H