/**
@file Tag.cpp

Created March 10th 2014
*/

#include "Tag.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

Tag::Tag() 
{
}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

Tag_Description Tag::getTagDescription() const
{
	return tagDescription_;
}


Value_Representation Tag::getValueRepresentation() const
{
	return vr_;
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void Tag::setTagDescription(Tag_Description td)
{
	tagDescription_ = td;
}

void Tag::setValueRepresentation(Value_Representation vr)
{
	vr_ = vr;
}