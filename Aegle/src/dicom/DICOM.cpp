/**
@file DICOM.h

Created March 6th 2014
*/

#include "DICOM.h"

DICOM::DICOM() 
{

}

DICOM::~DICOM() 
{
		
}

int DICOM::getSizeOfPreamble() 
{
	return sizeOfPreamble;
}

bool DICOM::parseFromFile(string fileName)
{
	DICOMParser p;

	return p.parse(fileName, this);
}