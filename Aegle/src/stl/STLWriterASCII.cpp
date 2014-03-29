/** 
@file STLWriterASCII.cpp

Created March 11th 2014
*/

#include "STLWriterASCII.h"
#include <time.h>

STLWriterASCII::STLWriterASCII() : filename_(""), filedir_("")
{
     time_t t = time(0);
    struct tm* n = new tm();
    localtime_s(n, &t);

    // Use the time of construction 
    // for a unique filename
    filename_ = (n->tm_year + 1900) + 
                (n->tm_mon + 1) +
                n->tm_mday + 
                "_" +
                n->tm_hour + 
                n->tm_min + 
                n->tm_sec;
}

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

