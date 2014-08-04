/**
@file Tag.h

Created March 10th 2014
*/

#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "TagDescription.h"
#include "ValueRepresentation.h"

#include "../util/util.h"

class Tag 
{
	public:

		Tag();
		Tag(const Tag& other);
		~Tag();

		unsigned int getLength() const;
		Tag_Description getTagDescription() const;
		char* getValue() const;
		Value_Representation getValueRepresentation() const;
		
		unsigned long getValueUL() const;

		void setLength(unsigned int len);
		void setTagDescription(Tag_Description td);
		void setValue(char* buff);
		void setValue(char* buff, unsigned int length);
		void setValueRepresentation(Value_Representation vr);

		std::string valueToString();

	private:

		std::string valueToDateString();
		std::string valueToTimeString();
		std::string valueToUnsignedShortString();

		Tag_Description tagDescription_;
		Value_Representation vr_;
		unsigned int length_;
		char* value_;
};

#endif /*TAG_H*/