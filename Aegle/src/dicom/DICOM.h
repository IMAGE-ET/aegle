/**
@file DICOM.h

Created March 6th 2014
*/

#ifndef DICOM_H
#define DICOM_H

#include <string>
#include <vector>

#include "Sequence.h"

#include "../util/dicomparser/DICOMParser.h"

#include "TagDictionary.h"
#include "DICOMImage.h"

class DICOM 
{
	public:

		DICOM();
		~DICOM();

		std::string getPreamble() const;

		void setPreamble(char *pa);

		void addSequence(Sequence s) const;
		void addTag(Tag t) const;

		std::string DICOMImagetoString();

		static const int SIZE_OF_GROUP_TAG = 4;
		static const int SIZE_OF_LENGTHA = 2;
		static const int SIZE_OF_LENGTHB = 4;
		static const int SIZE_OF_PREAMBLE = 128;
		static const int SIZE_OF_PREFIX = 4;
		static const int SIZE_OF_VR = 2;

	private:

		std::string preamble_;
		std::vector<Tag> tags_;
		DICOMImage *image_;
};

#endif /*DICOM_H*/