/**
@file DICOMImage.h

Created June 5th 2014
*/

#ifndef DICOMIMAGE_H
#define DICOMIMAGE_H

#include <string>

class DICOMImage
{
	public:

		DICOMImage();
		~DICOMImage();

		enum PhotometricInterpratation
		{
			UNKNOWN_PI,
			MONOCHROME1,
			MONOCHROME2,
			YBR_FULL,
			YBR_FULL_422
		};

		enum PlanarConfiguration
		{
			UNKNOWN_PC,
			INTERLACED,
			SEPARATED
		};

		unsigned int getBitsAllocated() const;
		unsigned int getBitsStored() const;
		unsigned int getColumns() const;
		unsigned int getHighBit() const;
		unsigned int getNumFrames() const;
		PhotometricInterpratation getPhotometricInterpratation() const;
		PlanarConfiguration getPlanarConfiguration() const;
		unsigned int getRows() const;
		unsigned int getSamplesPerPixel() const;

		void setBitsAllocated(unsigned int bitsAllocated);
		void setBitsStored(unsigned int bitsStored);
		void setColumns(unsigned int columns);
		void setHighBit(unsigned int highBit);
		void setNumFrames(unsigned int numFrames);
		void setPhotometricInterpratation(PhotometricInterpratation pI);
		void setPlanarConfiguration(PlanarConfiguration pC);
		void setRows(unsigned int rows);
		void setSamplesPerPixel(unsigned int buff);

		static PhotometricInterpratation toPhotometricInterpratation(std::string str);

    private:

		unsigned int bitsAllocated_;
		unsigned int bitsStored_;
		unsigned int columns_;
		unsigned int highBit_;
		unsigned int numFrames_;
		PhotometricInterpratation photometricInterpratation_;
		PlanarConfiguration planarConfiguration_;
		unsigned int rows_;
		unsigned int samplesPerPixel_;
};

#endif /*DICOMIMAGE_H*/