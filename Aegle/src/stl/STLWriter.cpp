/**
@file STLWriter.cpp

Created March 11th 2014
*/

#include "STLWriter.h"
#include <time.h>

STLWriter::STLWriter() : filedir_("")
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

STLWriter::STLWriter(string filename) : filename_(filename), filedir_("")
{}

STLWriter::STLWriter(string filename, string filedir) : filename_(filename), filedir_(filedir)
{}

STLWriter::~STLWriter()
{
}

bool STLWriter::validateSTL(const STL&)
{
    // perform checks 
    return false;
}