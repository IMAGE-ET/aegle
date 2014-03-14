/**
@file TagDictionaru.cpp

Created March 10th 2014
*/

#include "TagDictionary.h"

std::map<int, Tag_Description> TagDictionary::dictionary_;

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

TagDictionary::TagDictionary() 
{
	// check to see if dictionary has already been created
	if (dictionary_.size())
	{
		// create dictionary
		dictionary_[0x00020000] = GROUP_LENGTH;
		dictionary_[0x00020001] = FILE_META_INFORMATION_VERSION;
		dictionary_[0x00020002] = MEDIA_STORAGE_SOP_CLASS_UID;
	}
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

Tag_Description TagDictionary::search(int i)
{
	return dictionary_[i];
}