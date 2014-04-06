/**
@file DICOMParser.h

Created March 6th 2014
*/

#ifndef DICOMPARSER_H
#define DICOMPARSER_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <string>

#include "../../dicom/Tag.h"
#include "../../dicom/TagDictionary.h"

class DICOM;

class DICOMParser 
{
	public:

		DICOMParser();
		~DICOMParser();

		bool parse(std::string fileName, DICOM *d);

	private:

		int getLength(Value_Representation vr);

		bool isValid(std::ifstream *f, DICOM *d);
		bool isValid(std::ifstream *f, Tag *t);

		bool parsePreamble(std::ifstream *f, DICOM *d);
		bool parseTag(std::ifstream *f, Tag *t);

		int toInt(char c0, char c1);
		int toInt(char c0, char c1, char c2, char c3);
		Tag_Description toTagDescription(int value);
		Value_Representation toValueRepresentation(int value);

		static TagDictionary td_;
};

#endif /*DICOMPARSER_H*/