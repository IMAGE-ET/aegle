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
#include "ValueRepresentation.h"

class TagDictionary 
{
	public:

		TagDictionary();

		Tag_Description searchDescription(int value);
		Value_Representation searchVr(int value);
		std::string toString(Tag_Description td);
		std::string toString(Value_Representation vr);
		std::string toTagName(int value);
		std::string toVrName(int value);

	private:

		void createTdEnumDictionary();
		void createTdNameDictionary();
		void createVrEnumDictionary();
		void createVrNameDictionary();

		static std::map<int, Tag_Description> tdEnumDictionary_;
		static std::map<Tag_Description, std::string> tdNameDictionary_;
		static std::map<int, Value_Representation> vrEnumDictionary_;
		static std::map<Value_Representation, std::string> vrNameDictionary_;
};

#endif /*TAGDICTIONARY_H*/