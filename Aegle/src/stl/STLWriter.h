/**
@file STLWriter.h

Created March 11th 2014
*/
#ifndef STLWRITER_H
#define STLWRITER_H
#include "STL.h"

using namespace std;

class STLWriter 
{
public:

    STLWriter();
    STLWriter(string filename);
    STLWriter(string filename, string filedir);

    ~STLWriter();

    bool validateSTL(const STL&);

    virtual bool writeSTL(const STL&);

private:
    virtual bool writeSTLHeader(const STL&);
    virtual bool writeSTLTriangles(const STL&);
    virtual bool writeSTLTriangle(const Facet&);

    string filename_;
    string filedir_;

};

#endif /* STLWRITER_H */