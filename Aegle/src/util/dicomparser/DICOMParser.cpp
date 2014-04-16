/**
@file DICOMParser.h

Created March 6th 2014
*/

#include "DICOMParser.h"

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
	f.open(fileName, std::ios::binary);
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

		for (int i = 0; i < 30; i++)
		{
			char *buff = new char[DICOM::SIZE_OF_GROUP_TAG + DICOM::SIZE_OF_VR];
			Value_Representation vr;
			int value;

			// read in the value representation
			f.read(buff, DICOM::SIZE_OF_GROUP_TAG + DICOM::SIZE_OF_VR);

			// parse the value representation
			value = toInt(buff[DICOM::SIZE_OF_GROUP_TAG], buff[DICOM::SIZE_OF_GROUP_TAG + 1]);
			vr = toValueRepresentation(value);

			std::cout << "Value Representation: " << "0x" << std::setfill('0') << std::hex <<  std::setw(8) << value;
			std::cout << " - " << td_.toVrName(value) << std::endl;

			delete buff;
			
			f.seekg(-6, std::ios_base::cur);

			Tag t;
			ret = parseTag(&f, &t);
			d->addTag(t);
		}

		char *groupBuff = new char[20];

		f.read(groupBuff, 20);

		delete groupBuff;

		return true;
	}
	else 
	{
		// unable to open the designated file
		std::cout << "Unable to open: " << fileName << std::endl;
		return false;
	}
}

int DICOMParser::getLength(Value_Representation vr)
{
	switch (vr)
	{
	default:
		return DICOM::SIZE_OF_LENGTHA;
	case OB:
	case OW:
	case SQ:
	case UN:
		return DICOM::SIZE_OF_LENGTHB;
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

Tag_Description DICOMParser::parseGroup(std::ifstream *f)
{
	char *groupBuff = new char[DICOM::SIZE_OF_GROUP_TAG];
	int group;
	Tag_Description ret;

	// read in the group and element
	f->read(groupBuff, DICOM::SIZE_OF_GROUP_TAG);

	// determine what type of tag it is.
	group = toInt(groupBuff[1], groupBuff[0], groupBuff[3], groupBuff[2]);
	ret = toTagDescription(group);

	std::cout << "Tag: " << "0x" << std::setfill('0') << std::hex <<  std::setw(8) << group;
	std::cout << " - " << td_.toTagName(group) << std::endl;

	// clean up
	delete groupBuff;
	return ret;
}

unsigned int DICOMParser::parseLength(std::ifstream *f, Value_Representation vr)
{
	int lengthSize = getLength(vr);
	char *lengthBuff = new char[lengthSize];
	unsigned int length;

	// read in the lenth
	f->read(lengthBuff, lengthSize);

	// convert char array to unsigned int
	if (lengthSize == DICOM::SIZE_OF_LENGTHA)
	{
		length = toInt(lengthBuff[1], lengthBuff[0]);
	}
	else
	{
		length = toInt(lengthBuff[3], lengthBuff[2], lengthBuff[1], lengthBuff[0]);
	}

	std::cout << "Length: " << std::dec << length << std::endl;

	// clean up
	delete lengthBuff;		
	return length;
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
	
	// check to see if null parameters were passed in
	if (!isValid(f, t)) 
	{
		std::cout << "ERROR: Invalid parameter passed in" << std::endl;
		return false;
	}

	// parse the tag description
	Tag_Description td;
	td = parseGroup(f);

	t->setTagDescription(td);

	// parse the value representation
	Value_Representation vr;
	vr = parseValueRepresentation(f);

	t->setValueRepresentation(vr);

	// burn through reserved bytes
	switch (t->getValueRepresentation())
	{
	default:
		break;
	case OB:
	case OW:
	case SQ:
	case UN:
		char *burnBuff = new char[2];
		// read in the group and element
		f->read(burnBuff, 2);
		delete burnBuff;
		break;
	}

	// parse the length
	unsigned int length;
	length = parseLength(f, vr);

	t->setLength(length);

	// parse the value
	parseValue(f, t);

	return true;
}

void parseValue(std::ifstream *f, Tag *t)
{
	char *valueBuff = new char[t->getLength()];

	// read in the value
	f->read(valueBuff, t->getLength());

	// set the value
	t->setValue(valueBuff);

	std::cout << "Value: " << std::dec << t->valueToString() << std::endl;

	delete valueBuff;
}

void parseValue(std::ifstream *f, Tag *t, unsigned int length)
{
	char *valueBuff = new char[length];

	// read in the value
	f->read(valueBuff, length);

	// set the value
	t->setValue(valueBuff, length);

	std::cout << "Value: " << std::dec << t->valueToString() << std::endl;

	delete valueBuff;
}

Value_Representation DICOMParser::parseValueRepresentation(std::ifstream *f)
{
	char *vrBuff = new char[DICOM::SIZE_OF_VR];
	int value;
	Value_Representation vr;

	// read in the value representation
	f->read(vrBuff, DICOM::SIZE_OF_VR);

	// parse the value representation
	value = toInt(vrBuff[0], vrBuff[1]);
	vr = toValueRepresentation(value);

	std::cout << "Value Representation: " << "0x" << std::setfill('0') << std::hex <<  std::setw(8) << value;
	std::cout << " - " << td_.toVrName(value) << std::endl;

	delete vrBuff;
	return vr;
}

int DICOMParser::toInt(char c0, char c1)
{
	//@TODO: There has got to be a more elegant way
	//@TODO: Check that eindianess is correct

	int val = 0x00000000;
	val |= c0 << 8 | c1;

	return val;
}

int DICOMParser::toInt(char c0, char c1, char c2, char c3)
{
	//@TODO: There has got to be a more elegant way
	//@TODO: Check that eindianess is correct

	int val = 0x00000000;
	val |= c0 << 24 | c1 << 16 | c2 << 8 | c3;

	return val;
}

Tag_Description DICOMParser::toTagDescription(int value)
{
	return td_.searchDescription(value);
}

Value_Representation DICOMParser::toValueRepresentation(int value)
{
	return td_.searchVr(value);
}