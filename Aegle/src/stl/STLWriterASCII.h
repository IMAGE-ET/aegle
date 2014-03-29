/**
@file STLWriterASCII.h

Derived class of STLWriter. Writes out given STL objects
in the STL ASCII format. 

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
    STLWriterASCII(const string& filename, const string& filedir);
    STLWriterASCII(const string& filename);

    bool writeSTL(const string& filename, const STL&);

private:
    bool writeSTLHeader(const STL&);
    bool writeSTLFacets(const STL&);
    bool writeSTLFacet(const Facet&);

    string filename_;
    string filedir_;
    ofstream outputFile_;
};

#endif STLWRITER_ASCII_H