/**
@file TagDictionaru.cpp

Created March 10th 2014
*/

#include "TagDictionary.h"

std::map<char,Tag_Description> TagDictionary::dictionary_;

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

TagDictionary::TagDictionary() 
{
	// check to see if dictionary has already been created
	if (dictionary_.size())
	{
		// create dictionary
	}
}