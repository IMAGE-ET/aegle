/**
@file DICOMParser.h

Created March 6th 2014
*/

#include "DICOMParser.h"
#include "../../dicom/DICOM.h"

DICOMParser::DICOMParser() 
{
		
}

DICOMParser::~DICOMParser() 
{
		
}

bool DICOMParser::parse(string fileName, DICOM *d)
{
	ifstream f;
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

bool DICOMParser::parsePreamble(ifstream *f, DICOM *d)
{
	// check to see if null parameters where passed in
	// if so return null
	if (f == NULL || d == NULL) 
	{
		cout << "Null parameter passed in" << endl;
		return false;
	}

	// get the size of the prefix and preamble and set up a buffer
	int size = (*d).getSizeOfPreamble();
	char *buff = new char[size + 4];

	// read in the preable and prefix
	f->read(buff, size + 4);

	// verify prefix
	if (buff[size] != 'D' || buff[size + 1] != 'I' || buff[size + 2] != 'C' || buff[size + 3] != 'M') 
	{
		cout << "Prefix not found: " << buff[size] << buff[size + 1] << buff[size + 2] << buff[size + 3] << endl;
		return false;
	}

	return true;
}