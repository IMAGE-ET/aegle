/**
@file Sequence.h

Created April 12th 2014
*/

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Tag.h"	
#include "TagDescription.h"
#include "ValueRepresentation.h"

class Sequence
{
	public:

		Sequence();
		~Sequence();

		int getLength() const;
		int getNumTags() const;
		Tag getTag(unsigned int index) const;
		Tag_Description getTagDescription() const;
		Value_Representation getValueRepresentation() const;

		void setLength(int len);
		void setTagDescription(Tag_Description td);
		void setValueRepresentation(Value_Representation vr);

		void addTag(Tag t);
		void removeTag(unsigned int index);

	private:

		Tag_Description tagDescription_;
		Value_Representation vr_;
		int length_;
		std::vector<Tag> value_;
};

#endif /*SEQUENCE_H*/