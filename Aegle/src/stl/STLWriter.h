/**
@file STLWriter.h

Created March 11th 2014
*/
#ifndef STLWRITER_H
#define STLWRITER_H

#include "STL.h"
#include "../cubes/Facet.h"
#include <fstream>
#include <iostream>
#include <string>

/* Base class for writing out STL files.
*/

class STLWriter 
{
public:

    STLWriter();
    STLWriter(const string& filename, const string& filedir);
    STLWriter(const string& filename);

    virtual ~STLWriter();

    // Helper function to verify the STL is appropriate for writing
    bool validateSTL(const STL& stl);

    // Function to be implemented by derived classes
    virtual bool writeSTL(const STL& stl);
    bool STLWriter::writeSTL(const STL& stl, const bool& isBinaryMode);


private:
    virtual bool writeSTLHeader(const STL& stl, const bool& isBinaryMode);
    virtual bool writeSTLFacets(const STL& stl, const bool& isBinaryMode);
    virtual bool writeSTLFacet(const Facet& stl, const bool& isBinaryMode);

    string STLWriter::buildFacetString(const Facet& facet);
    bool STLWriter::writeEndline(const STL& stl, const bool& isBinaryMode);

    string filename_;
    string filedir_;
    ofstream outputFile_;

    bool isBinaryMode_;


};

#endif /* STLWRITER_H */