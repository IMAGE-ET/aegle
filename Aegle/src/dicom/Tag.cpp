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
int Tag::getLength() const
{
	return length_;
}

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
void Tag::setLength(int len)
{
	length_ = len;
}

void Tag::setTagDescription(Tag_Description td)
{
	tagDescription_ = td;
}

void Tag::setValue(char* buff)
{
	delete value_;

	value_ = new char[length_];

	for(int i = 0; i < length_; i++)
	{
		value_[i] = *(buff + i);
	}
}

void Tag::setValue(char* buff, int length)
{
	setLength(length);
	setValue(buff);
}

void Tag::setValueRepresentation(Value_Representation vr)
{
	vr_ = vr;
}