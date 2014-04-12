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

class Tag 
{
	public:

		Tag();
		~Tag();

		int getLength() const;
		Tag_Description getTagDescription() const;
		Value_Representation getValueRepresentation() const;
		unsigned long getValueUL() const;

		void setLength(int len);
		void setTagDescription(Tag_Description td);
		void setValue(char* buff);
		void setValue(char* buff, int length);
		void setValueRepresentation(Value_Representation vr);

		std::string valueToString();

	private:

		Tag_Description tagDescription_;
		Value_Representation vr_;
		int length_;
		char* value_;
};

#endif /*TAG_H*/