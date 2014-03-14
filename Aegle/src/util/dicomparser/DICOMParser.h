/**
@file DICOMParser.h

Created March 6th 2014
*/

#ifndef DICOMPARSER_H
#define DICOMPARSER_H

#include <fstream>
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

		bool parsePreamble(std::ifstream *f, DICOM *d);
		bool parseTag(std::ifstream *f, Tag *t);

		Tag_Description toTagDescription(char a0, char a1, char a2, char a3);

		static TagDictionary td_;
};

struct HexCharStruct
{
  unsigned char c;
  HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
  return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
  return HexCharStruct(_c);
}

#endif /*DICOMPARSER_H*/