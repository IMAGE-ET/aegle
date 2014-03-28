/**
@file DICOM.h

Created March 6th 2014
*/

#ifndef DICOM_H
#define DICOM_H

#include <string>

#include "../util/dicomparser/DICOMParser.h"

#include "TagDictionary.h"

class DICOM 
{
	public:

		DICOM();
		~DICOM();

		std::string getPreamble() const;

		void setPreamble(char *pa);
		
		static const int SIZE_OF_GROUP_TAG = 4;
		static const int SIZE_OF_LENGTH = 1;
		static const int SIZE_OF_PREAMBLE = 128;
		static const int SIZE_OF_PREFIX = 4;
		static const int SIZE_OF_VR = 2;

	private:

		std::string preamble_;
};

#endif /*DICOM_H*/