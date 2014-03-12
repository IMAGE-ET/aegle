/**
@file DICOM.h

Created March 6th 2014
*/

#include "DICOM.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

DICOM::DICOM() 
{
}

DICOM::~DICOM() 
{
		
}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

string DICOM::getPreamble()
{
	return preamble;
}


int DICOM::getSizeOfPreamble() 
{
	return sizeOfPreamble_;
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void DICOM::setPreamble(char *pa)
{
	preamble = string(pa, sizeOfPreamble_);
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

bool DICOM::parseFromFile(string fileName)
{
	DICOMParser p;

	return p.parse(fileName, this);
}