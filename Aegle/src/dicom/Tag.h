/**
@file Tag.h

Created March 10th 2014
*/

#ifndef TAG_H
#define TAG_H

#include <map>

#include "TagDescription.h"
#include "ValueRepresentation.h"

class Tag 
{
	public:

		Tag();

		Tag_Description getTagDescription() const;
		Value_Representation getValueRepresentation() const;

		void setTagDescription(Tag_Description td);
		void setValueRepresentation(Value_Representation vr);

	private:

		Tag_Description tagDescription_;
		Value_Representation vr_;
		int length_;
};

#endif /*TAG_H*/