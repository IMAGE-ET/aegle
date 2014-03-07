/**
@file DICOMParser.h

Created March 6th 2014
*/

#ifndef DICOMPARSER_H
#define DICOMPARSER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class DICOM;

class DICOMParser {
	public:

		DICOMParser();
		~DICOMParser();

		bool parse(string fileName, DICOM *d);

	private:
};

#endif /*DICOMPARSER_H*/