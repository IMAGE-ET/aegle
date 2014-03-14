/**
@file DICOMParser.h

Created March 6th 2014
*/

#include "DICOMParser.h"
#include "../../dicom/DICOM.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

DICOMParser::DICOMParser() 
{
		
}

DICOMParser::~DICOMParser() 
{
		
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

bool DICOMParser::parse(std::string fileName, DICOM *d)
{
	std::ifstream f;
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
		std::cout << "Unable to open: " << fileName << std::endl;
		return false;
	}
}

bool DICOMParser::parsePreamble(std::ifstream *f, DICOM *d)
{
	// check to see if null parameters where passed in
	// if so return null
	if (f == NULL || d == NULL) 
	{
		std::cout << "Null parameter passed in" << std::endl;
		return false;
	}

	// get the size of the prefix and preamble and set up a buffer
	int size = (*d).getSizeOfPreamble();
	char *preambleBuff = new char[size];
	char *prefixBuff = new char[4];

	// read in the preable and prefix
	f->read(preambleBuff, size);
	f->read(prefixBuff, 4);

	// verify prefix
	if (prefixBuff[0] != 'D' || prefixBuff[1] != 'I' || prefixBuff[2] != 'C' || prefixBuff[3] != 'M') 
	{
		std::cout << "Prefix not found: " << prefixBuff[0] << prefixBuff[1] << prefixBuff[2] << prefixBuff[3] << std::endl;
		return false;
	}

	// set preamble
	d->setPreamble(preambleBuff);

	return true;
}