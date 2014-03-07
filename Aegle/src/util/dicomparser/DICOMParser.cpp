/**
@file DICOMParser.h

Created March 6th 2014
*/

#include "DICOMParser.h"

DICOMParser::DICOMParser() 
{
		
}

DICOMParser::~DICOMParser() 
{
		
}

bool DICOMParser::parse(string fileName, DICOM *d)
{
	ofstream f;
	f.open(fileName);

	if (f.is_open())
	{
		// file was successfully open - now parse!

		// parse preamble

		return true;
	}
	else 
	{
		// unable to open the designated file
		cout << "Unable to open: " << fileName << endl;
		return false;
	}
}