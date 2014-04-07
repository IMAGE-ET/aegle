/**
@file STLWriter.cpp

Created March 11th 2014
*/

#include "STLWriter.h"
#include <time.h>
#include <sstream>

STLWriter::STLWriter() : filename_(""),
                         filedir_(""), 
                         isBinaryMode_(false)
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

STLWriter::STLWriter(const string& filename, const string& filedir) : filename_(filename),
                                                                        filedir_(filedir), 
                                                                        isBinaryMode_(false)
{
}

STLWriter::STLWriter(const string& filename) : filename_(filename), 
                                                filedir_(""),
                                                isBinaryMode_(false)
{
}

STLWriter::~STLWriter()
{
}

// Helper function to verify the STL is appropriate for writing
bool STLWriter::validateSTL(const STL& stl)
{
    return true;
}

// Function to be implemented by derived classes
bool STLWriter::writeSTL(const STL& stl)
{
    if(!validateSTL(stl)) 
    {
        std::cout << "Invalid STL model given." << std::endl;
        return false;
    }


    // open output file
    outputFile_.open(filename_.data());

    // write header
    if(!writeSTLHeader(stl, isBinaryMode_))
    {
        std::cout << "Error in writing STL header!" << std::endl;
        return false;
    }

    // write facets
    if(!writeSTLFacets(stl, isBinaryMode_))
    {
        std::cout << "Error in writing STL facets!" << std::endl;
        return false;
    }

    // write terminating line
    if(!writeEndline(stl, isBinaryMode_))
    {
        std::cout << "Error in writing last line!" << std::endl;
        return false;
    }

    // close file
    outputFile_.close();

    return true;
}

bool STLWriter::writeSTL(const STL& stl, const bool& isBinaryMode)
{
    isBinaryMode_ = isBinaryMode;
    return writeSTL(stl);
}

bool STLWriter::writeSTLHeader(const STL& stl, const bool& isBinaryMode)
{
    if(isBinaryMode)
    {
        outputFile_.write("STLWRITER:THIS IS 80 BYTES OF CHARACTERSSTLWRITER:THIS IS 80 BYTES OF CHARACTERS",80);
        unsigned long numTriangles = stl.getFacets().size();
        outputFile_.write((char*)numTriangles, sizeof(unsigned long));
    }
    else
    {
        string name = "solid " + stl.getName() + "\n"; 
        outputFile_.write(name.data(), name.length());
    }

    return true;
}

bool STLWriter::writeSTLFacets(const STL& stl, const bool& isBinaryMode)
{
    for(size_t i = 0; i < stl.getFacets().size(); ++i)
    {
       if(!writeSTLFacet(stl.getFacetAt(i), isBinaryMode))
       {
           return false;
       }
    }

    return true;
}

bool STLWriter::writeSTLFacet(const Facet& facet, const bool& isBinaryMode)
{
    if(isBinaryMode)
    {
        char* c = new char[12 * sizeof(float) + 2];

        ((float*) c)[0] = facet.getNormal()[0];
        ((float*) c)[1] = facet.getNormal()[1];
        ((float*) c)[2] = facet.getNormal()[2];

        for(int i = 0; i < 3; ++i)
        {
            ((float*) c)[i + 0 + 2] = facet.getVertexAt(i).x;
            ((float*) c)[i + 1 + 2] = facet.getVertexAt(i).y;
            ((float*) c)[i + 2 + 2] = facet.getVertexAt(i).z;
        }

        outputFile_.write(c, 12 * sizeof(float) + 2);
    }
    else
    {
        string s = buildFacetString(facet);
        outputFile_.write(s.data(), s.length());
    }

    return true;
}

string STLWriter::buildFacetString(const Facet& facet)
{
    normal n = facet.getNormal();
    vertices v = facet.getVertices();
    std::ostringstream ss;
    string ret = "\nfacet normal ";

    for(size_t i = 0; i < n.size(); ++i)
    {
        ss << n[i];
        ret += ss.str() + " ";
    }

    ret += "\n\t outer loop\n";

    for(size_t i = 0; i < v.size(); ++i)
    {
        ret += "\t\tvertex ";
        
        ss << v[i].x;
        ret += ss.str() + " ";

        ss << v[i].y;
        ret += ss.str() + " ";

        ss << v[i].z;
        ret += ss.str() + " ";
        
        ret += "\n";
    }

    ret += "\tendloop\n";
    ret += "endfacet\n";
    return ret;
}

bool STLWriter::writeEndline(const STL& stl, const bool& isBinaryMode)
{
    if(isBinaryMode)
    {
        string s = "endsolid " + stl.getName();
        outputFile_.write(s.data(), s.length());
    }

    return true;
}
