/**
@file TagDictionary.h

Created March 10Sth 2014
*/

#ifndef TAGDICTIONARY_H
#define TAGDICTIONARY_H

#include <map>

using namespace std;

class TagDictionary 
{
	public:

		TagDictionary();

		enum Tag
		{
			GROUP_LENGTH,
			META_INFO_VERSION,
			MEDIA_STORAGE_SOP_CLASS_UID,
			MEDIA_STORAGE_SOP_INSTANCE_UID,
			TRANSFER_SYNTAX_UID,
			IMPLEMENTATION_CLASS_UID,
			IMPLEMENTATION_VERSION_NAME,
			SOURCE_APPLICATION_ENTITY_TITLE,
			PRIVATE_INFO_CREATOR_UID,
			PRIVATE_INFORMATION
		};

	private:

		static map<char,Tag> dictionary;
};

#endif /*TAGDICTIONARY_H*/