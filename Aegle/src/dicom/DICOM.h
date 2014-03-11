/**
@file DICOM.h

Created March 6th 2014
*/

#ifndef DICOM_H
#define DICOM_H

#include <string>

#include "../util/dicomparser/DICOMParser.h"

using namespace std;

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

		static const int sizeOfPreamble = 128;
		string preamble;
};

#endif /*DICOM_H*/