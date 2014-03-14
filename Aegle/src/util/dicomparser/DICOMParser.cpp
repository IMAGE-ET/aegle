/**
@file DICOMParser.h

Created March 6th 2014
*/

#include "DICOMParser.h"
#include "../../dicom/DICOM.h"

TagDictionary DICOMParser::td_;

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
	bool ret;

	if (f.is_open())
	{
		// file was successfully open - now parse!

		// parse preamble
		ret = parsePreamble(&f, d);
		if (!ret)
		{
			return false;
		}

		Tag t;
		ret = parseTag(&f, &t);

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
	std::cout << "--- PARSING PREAMBLE" << std::endl;

	// check to see if null parameters where passed in
	// if so return null
	if (f == NULL || d == NULL || !f->is_open()) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
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
		std::cout << "ERROR: Prefix not found: " << prefixBuff[0] << prefixBuff[1] << prefixBuff[2] << prefixBuff[3] << std::endl;
		return false;
	}
	else
	{
		std::cout << "SUCESS: Prefix found" << std::endl;
	}

	// set preamble
	d->setPreamble(preambleBuff);

	std::cout << "SUCESS: Parsed preamble -" << d->getPreamble() << "-" << std::endl;

	return true;
}

bool DICOMParser::parseTag(std::ifstream *f, Tag *t)
{
	std::cout << "--- PARSING TAG" << std::endl;

	if (f == NULL || t == NULL || !f->is_open()) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	char *groupBuff = new char[10];

	// read in the group and element
	f->read(groupBuff, 10);

	t->setTagDescription(toTagDescription(groupBuff[1], groupBuff[0], groupBuff[3], groupBuff[2]));

	return true;
}

Tag_Description DICOMParser::toTagDescription(char a0, char a1, char a2, char a3)
{


	int i = 0x00000000;
	i |= a0 << 24 | a1 << 16 | a2 << 8 | a3;

	std::cout << "Tag: " << hex(i) << std::endl;

	return td_.search(i);
}