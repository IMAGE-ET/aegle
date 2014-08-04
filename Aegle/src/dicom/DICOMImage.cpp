/**
@file DICOMImage.cpp

Created June 5th 2014
*/

#include "DICOMImage.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

DICOMImage::DICOMImage() 
{
	bitsAllocated_ = 0;
	bitsStored_ = 0;
	columns_ = 0;
	highBit_ = 0;
	numFrames_ = 1;
	photometricInterpratation_ = PhotometricInterpratation::UNKNOWN_PI;
	planarConfiguration_ = PlanarConfiguration::INTERLACED;
	rows_ = 0;
	samplesPerPixel_ = 0;
}

DICOMImage::~DICOMImage() 
{

}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

unsigned int DICOMImage::getBitsAllocated() const
{
	return bitsAllocated_;
}

unsigned int DICOMImage::getBitsStored() const
{
	return bitsStored_;
}

unsigned int DICOMImage::getColumns() const
{
	return columns_;
}

unsigned int DICOMImage::getHighBit() const
{
	return highBit_;
}

unsigned int DICOMImage::getNumFrames() const
{
	return numFrames_;
}

DICOMImage::PhotometricInterpratation DICOMImage::getPhotometricInterpratation() const
{
	return photometricInterpratation_;
}

DICOMImage::PlanarConfiguration DICOMImage::getPlanarConfiguration() const
{
	return planarConfiguration_;
}

unsigned int DICOMImage::getRows() const
{
	return rows_;
}

unsigned int DICOMImage::getSamplesPerPixel() const
{
	return samplesPerPixel_;
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void DICOMImage::setBitsAllocated(unsigned int bitsAllocated)
{
	bitsAllocated_ = bitsAllocated;
}

void DICOMImage::setBitsStored(unsigned int bitsStored)
{
	bitsStored_ = bitsStored;
}

void DICOMImage::setColumns(unsigned int columns)
{
	columns_ = columns;
}

void DICOMImage::setHighBit(unsigned int highBit)
{
	highBit_ = highBit;
}

void DICOMImage::setPhotometricInterpratation(DICOMImage::PhotometricInterpratation pI)
{
	photometricInterpratation_ = pI;
}

void DICOMImage::setPlanarConfiguration(DICOMImage::PlanarConfiguration pC)
{
	planarConfiguration_ = pC;
}

void DICOMImage::setRows(unsigned int rows)
{
	rows_ = rows;
}

void DICOMImage::setSamplesPerPixel(unsigned int samplesPerPixel)
{
	samplesPerPixel_ = samplesPerPixel;
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/
DICOMImage::PhotometricInterpratation DICOMImage::toPhotometricInterpratation(std::string str)
{
	if (str.compare("MONOCHROME2"))
	{
		return DICOMImage::PhotometricInterpratation::MONOCHROME2;
	}

	return DICOMImage::PhotometricInterpratation::UNKNOWN_PI;
}