/**
@file STLWriterASCII.h

Created March 11th 2014
*/

#ifndef STLWRITER_ASCII_H
#define STLWRITER_ASCII_H

#include "STLWriter.h"

using namespace std;

class STLWriterASCII : STLWriter
{
public:
    STLWriterASCII();
    bool writeSTL(const STL&);

private:
    bool writeSTLHeader(const STL&);
    bool writeSTLFacets(const STL&);
    bool writeSTLFacet(const Facet&);
};

#endif STLWRITER_ASCII_H