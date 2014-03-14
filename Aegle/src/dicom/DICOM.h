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

		std::string getPreamble();
		int getSizeOfPreamble();

		void setPreamble(char *pa);

	private:

		static const int sizeOfPreamble_ = 128;
		std::string preamble;
};

#endif /*DICOM_H*/