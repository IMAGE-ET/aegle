/**
@file DICOMParser.h

Created March 6th 2014
*/

#ifndef DICOMPARSER_H
#define DICOMPARSER_H

#include <fstream>
#include <iomanip>
#include <iostream>
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

		bool isValid(std::ifstream *f, DICOM *d);
		bool isValid(std::ifstream *f, Tag *t);

		bool parsePreamble(std::ifstream *f, DICOM *d);
		bool parseTag(std::ifstream *f, Tag *t);

		Tag_Description toTagDescription(char c0, char c1, char c2, char c3);
		Value_Representation toValueRepresentation(char c0, char c1);

		static TagDictionary td_;
};

#endif /*DICOMPARSER_H*/