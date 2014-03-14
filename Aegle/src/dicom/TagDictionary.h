/**
@file TagDictionary.h

Created March 10th 2014
*/

#ifndef TAGDICTIONARY_H
#define TAGDICTIONARY_H

#include <map>

#include "Tag.h"
#include "TagDescription.h"

class TagDictionary 
{
	public:

		TagDictionary();

		Tag_Description search(int i);

	private:

		static std::map<int, Tag_Description> dictionary_;
};

#endif /*TAGDICTIONARY_H*/