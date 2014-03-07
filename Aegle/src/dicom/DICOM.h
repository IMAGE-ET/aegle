/**
@file DICOM.h

Created March 6th 2014
*/

#ifndef DICOM_H
#define DICOM_H

#include <string>

#include "../util/dicomparser/DICOMParser.h"

using namespace std;

class DICOM {
	public:

		DICOM();
		~DICOM();

		int getSizeOfPreamble();

		bool parseFromFile(string fileName);

	private:

		static const int sizeOfPreamble = 128;
};

#endif /*DICOM_H*/