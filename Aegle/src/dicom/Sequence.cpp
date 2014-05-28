/**
@file Sequence.cpp

Created April 12th 2014
*/

#include "Sequence.h"

/*-----------------------------------------------------------------------------
CONSTRUCTORS AND DESTRUCTORS
-----------------------------------------------------------------------------*/

Sequence::Sequence() 
{
}

Sequence::~Sequence()
{
}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

int Sequence::getLength() const
{
	return length_;
}

int Sequence::getNumTags() const
{
	return value_.size();
}

Tag_Description Sequence::getTagDescription() const
{
	return tagDescription_;
}

Value_Representation Sequence::getValueRepresentation() const
{
	return vr_;
}

Tag Sequence::getTag(unsigned int index) const
{
	if (index < value_.size())
	{
		return Tag(value_.at(index));
	}

	return Tag();
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void Sequence::setLength(int len)
{
	length_ = len;
}

void Sequence::setTagDescription(Tag_Description td)
{
	tagDescription_ = td;
}

void Sequence::setValueRepresentation(Value_Representation vr)
{
	vr_ = vr;
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

void Sequence::addTag(Tag t)
{
	value_.push_back(t);
}

void Sequence::removeTag(unsigned int index)
{
	if (index < value_.size())
	{
		value_.erase(value_.begin() + index);
	}
}