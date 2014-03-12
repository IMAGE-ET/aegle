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

		string getPreamble();
		int getSizeOfPreamble();

		void setPreamble(char *pa);

		bool parseFromFile(string fileName);

	private:

		static const int sizeOfPreamble_ = 128;
		string preamble;
};

#endif /*DICOM_H*/