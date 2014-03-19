/**
@file TagDictionary.h

Created March 10th 2014
*/

#ifndef TAGDICTIONARY_H
#define TAGDICTIONARY_H

#include <map>
#include <string>

#include "Tag.h"
#include "TagDescription.h"

class TagDictionary 
{
	public:

		TagDictionary();

		Tag_Description searchDescription(int value);
		std::string toString(Tag_Description tagDescription);
		std::string toString(int value);

	private:

		void createEnumDictionary();
		void createNameDictionary();

		static std::map<int, Tag_Description> enumDictionary_;
		static std::map<Tag_Description, std::string> nameDictionary_;
};

#endif /*TAGDICTIONARY_H*/