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

bool DICOMParser::isValid(std::ifstream *f, DICOM *d)
{
	if (f == NULL || d == NULL || !f->is_open()) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	return true;
}

bool DICOMParser::isValid(std::ifstream *f, Tag *t)
{
	if (f == NULL || t == NULL || !f->is_open()) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	return true;
}

bool DICOMParser::parsePreamble(std::ifstream *f, DICOM *d)
{
	std::cout << "--- PARSING PREAMBLE" << std::endl;

	// check to see if null parameters where passed in
	if (!isValid(f, d)) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	// get the size of the prefix and preamble and set up a buffer
	char *preambleBuff = new char[DICOM::SIZE_OF_PREAMBLE];
	char *prefixBuff = new char[DICOM::SIZE_OF_PREFIX];

	// read in the preable and prefix
	f->read(preambleBuff, DICOM::SIZE_OF_PREAMBLE);
	f->read(prefixBuff, DICOM::SIZE_OF_PREFIX);

	// verify prefix
	if (prefixBuff[0] != 'D' || prefixBuff[1] != 'I' || prefixBuff[2] != 'C' || prefixBuff[3] != 'M') 
	{
		std::cout << "ERROR: Prefix not found: " << prefixBuff[0] << prefixBuff[1] << prefixBuff[2] << prefixBuff[3] << std::endl;
		return false;
	}
	else
	{
		std::cout << "SUCCESS: Prefix found" << std::endl;
	}

	// set preamble
	d->setPreamble(preambleBuff);

	std::cout << "SUCESS: Parsed preamble -" << d->getPreamble() << "-" << std::endl;

	return true;
}

bool DICOMParser::parseTag(std::ifstream *f, Tag *t)
{
	std::cout << "--- PARSING TAG" << std::endl;
	
	// check to see if null parameters where passed in
	if (!isValid(f, t)) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	// parse the group tag
	char *groupBuff = new char[DICOM::SIZE_OF_GROUP_TAG];

	// read in the group and element
	f->read(groupBuff, DICOM::SIZE_OF_GROUP_TAG);

	// determine what type of tag it is.
	t->setTagDescription(toTagDescription(groupBuff[1], groupBuff[0], groupBuff[3], groupBuff[2]));

	delete groupBuff;

	// parse the value representation
	char *vrBuff = new char[DICOM::SIZE_OF_VR];

	// read in the group and element
	f->read(vrBuff, DICOM::SIZE_OF_VR);

	// parse the value representation
	t->setValueRepresentation(toValueRepresentation(vrBuff[0], vrBuff[1]));

	delete vrBuff;

	// parse the length
	char *lengthBuff = new char[DICOM::SIZE_OF_LENGTH];

	// read in the group and element
	f->read(lengthBuff, DICOM::SIZE_OF_LENGTH);

	// parse the value representation
	t->setLength(lengthBuff[0]);
	std::cout << "Length: " << int(lengthBuff[0]) << std::endl;

	delete lengthBuff;

	unsigned long value;

	f->read(reinterpret_cast<char*>(&value), t->getLength());

	return true;
}

Tag_Description DICOMParser::toTagDescription(char c0, char c1, char c2, char c3)
{
	//@TODO: There has got to be a more elegant way
	//@TODO: Check that eindianess is correct
	int tagDescription = 0x00000000;
	tagDescription |= c0 << 24 | c1 << 16 | c2 << 8 | c3;

	std::cout << "Tag: " << "0x" << std::setfill('0') << std::hex <<  std::setw(8) << tagDescription;
	std::cout << " - " << td_.toTagName(tagDescription) << std::endl;

	return td_.searchDescription(tagDescription);
}

Value_Representation DICOMParser::toValueRepresentation(char c0, char c1)
{
	int vr = 0x00000000;
	vr |= c0 << 8 | c1;

	std::cout << "Value Representation: " << "0x" << std::setfill('0') << std::hex <<  std::setw(8) << vr;
	std::cout << " - " << td_.toVrName(vr) << std::endl;

	return td_.searchVr(vr);
}