/**
@file TagDictionary.h

Created March 10th 2014
*/

#ifndef TAGDICTIONARY_H
#define TAGDICTIONARY_H

#include <map>

#include "Tag.h"

class TagDictionary 
{
	public:

		TagDictionary();

	private:

		static std::map<char,Tag_Description> dictionary_;
};

#endif /*TAGDICTIONARY_H*/