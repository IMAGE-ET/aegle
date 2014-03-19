/**
@file Tag.h

Created March 10th 2014
*/

#ifndef TAG_H
#define TAG_H

#include <map>

#include "TagDescription.h"

class Tag 
{
	public:

		Tag();

		Tag_Description getTagDescription() const;

		void setTagDescription(Tag_Description td);

	private:

		Tag_Description tagDescription_;
		int length_;
};

#endif /*TAG_H*/