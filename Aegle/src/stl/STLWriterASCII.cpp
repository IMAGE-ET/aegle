/** 
@file STLWriterASCII.cpp

Created March 11th 2014
*/

#include "STLWriterASCII.h"

STLWriterASCII::STLWriterASCII() : filename_(""), filedir_("")
{}

STLWriterASCII::STLWriterASCII(const string& filename, const string& filedir) : filename_(filename), filedir_(filedir)
{}

STLWriterASCII::STLWriterASCII(const string& filename) : filename_(filename), filedir_("")               
{}

bool STLWriterASCII::writeSTL(const string& filename, const STL& stl)
{

    return false;
}

bool STLWriterASCII::writeSTLHeader(const STL&)
{
    return false;
}

bool STLWriterASCII::writeSTLFacets(const STL&)
{
    return false;
}

bool STLWriterASCII::writeSTLFacet(const Facet&)
{
    return false;
}

