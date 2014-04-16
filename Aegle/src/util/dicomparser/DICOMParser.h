/**
@file DICOMParser.h

Created March 6th 2014
*/

#ifndef DICOMPARSER_H
#define DICOMPARSER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "../../dicom/DICOM.h"
#include "../../dicom/Sequence.h"
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
		bool isValid(std::ifstream *f, Sequence *s);
		bool isValid(std::ifstream *f, Tag *t);

		Tag_Description parseGroup(std::ifstream *f);
		unsigned int parseLength(std::ifstream *f, Value_Representation vr);
		bool parsePreamble(std::ifstream *f, DICOM *d);
		bool parseSequence(std::ifstream *f, Sequence *s);
		bool parseTag(std::ifstream *f, Tag *t);
		void parseValue(std::ifstream *f, Tag *t);
		void parseValue(std::ifstream *f, Tag *t, unsigned int length);
		Value_Representation parseValueRepresentation(std::ifstream *f);

		int toInt(char c0, char c1);
		int toInt(char c0, char c1, char c2, char c3);
		Tag_Description toTagDescription(int value);
		Value_Representation toValueRepresentation(int value);

		static TagDictionary td_;
};

#endif /*DICOMPARSER_H*/