/**
@file DICOM.cpp

Created March 6th 2014
*/

#include "DICOM.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

DICOM::DICOM() 
{
	image_ = new DICOMImage();
}

DICOM::~DICOM() 
{
	image_->~DICOMImage();
}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

std::string DICOM::getPreamble() const
{
	return preamble_;
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void DICOM::setPreamble(char *pa)
{
	preamble_ = std::string(pa, SIZE_OF_PREAMBLE);
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/
void DICOM::addSequence(Sequence s) const
{
	// TODO: implement
}

void DICOM::addTag(Tag t) const
{
	switch (t.getTagDescription())
	{
	case BITS_ALLOCATED:
		image_->setBitsAllocated(t.getValueUL());
		break;
	case BITS_STORED:
		image_->setBitsStored(t.getValueUL());
		break;
	case COLUMNS:
		image_->setColumns(t.getValueUL());
		break;
	case HIGH_BIT:
		image_->setHighBit(t.getValueUL());
		break;
	case PHOTOMETRIC_INTERPRETATION:
		image_->setPhotometricInterpratation(DICOMImage::toPhotometricInterpratation(t.valueToString()));
		break;
	case PLANAR_CONFIGURATION:
		image_->setPlanarConfiguration((DICOMImage::PlanarConfiguration)t.getValueUL());
		break;
	case ROWS:
		image_->setRows(t.getValueUL());
		break;
	case SAMPLES_PER_PIXEL:
		image_->setSamplesPerPixel(t.getValueUL());
		break;
	default:
		// TODO: implement
		break;
	}
}

std::string DICOM::DICOMImagetoString()
{
	std::string s = "";

	s += "DICOM Image - Bits Allocated: " + std::to_string(image_->getBitsAllocated()) + "\n";
	s += "\tBits Stored: " + std::to_string(image_->getBitsStored()) + "\n";
	s += "\tColumns: " + std::to_string(image_->getColumns()) + "\n";
	s += "\tHigh Bit: " + std::to_string(image_->getHighBit()) + "\n";
	s += "\tNum Frames: " + std::to_string(image_->getNumFrames()) + "\n";
	s += "\tPhotometric Interpretation: " + std::to_string(image_->getPhotometricInterpratation()) + "\n";
	s += "\tPlanar Configuration: " + std::to_string(image_->getPlanarConfiguration()) + "\n";
	s += "\tRows: " + std::to_string(image_->getRows()) + "\n";
	s += "\tSamples Per Pixel: " + std::to_string(image_->getSamplesPerPixel()) + "\n";

	return s;
}