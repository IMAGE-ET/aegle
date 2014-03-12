/**
@file STLWriter.h

Created March 11th 2014
*/
#ifndef STLWRITER_H
#define STLWRITER_H

#include "STL.h"
#include "Facet.h"
using namespace std;

class STLWriter 
{
public:

    STLWriter();
    STLWriter(string filename);
    STLWriter(string filename, string filedir);

    ~STLWriter();

    bool validateSTL(const STL&);

    virtual bool writeSTL(const STL&) = 0;

private:
    virtual bool writeSTLHeader(const STL&) = 0;
    virtual bool writeSTLFacets(const STL&) = 0;
    virtual bool writeSTLFacet(const Facet&) = 0;

    string filename_;
    string filedir_;

};

#endif /* STLWRITER_H */