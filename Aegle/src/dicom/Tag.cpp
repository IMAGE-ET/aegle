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
	tagDescription_ = UNKNOWN;
	vr_ = UN;
	value_ = NULL;
}

Tag::Tag(const Tag& other)
{
	tagDescription_ = other.getTagDescription();
	vr_ = other.getValueRepresentation();
	length_ = other.getLength();
	value_ = NULL;
	setValue(other.getValue());
}

Tag::~Tag()
{
	if (value_ != NULL)
	{
		delete value_;
	}
}

/*-----------------------------------------------------------------------------
ACCESSORS
-----------------------------------------------------------------------------*/

unsigned int Tag::getLength() const
{
	return length_;
}

Tag_Description Tag::getTagDescription() const
{
	return tagDescription_;
}

char* Tag::getValue() const
{
	return value_;
}

Value_Representation Tag::getValueRepresentation() const
{
	return vr_;
}

unsigned long Tag::getValueUL() const
{
	unsigned long ul = 0;
	
	if (length_ != sizeof(unsigned long))
	{
		// @TODO: some sort of exception
		std::cout << "Unsigned long is " << sizeof(unsigned long) << " but length is " << length_ << std::endl;
		return 0;
	}

	memcpy(&ul, value_, sizeof(unsigned long));

	return ul;
}

/*-----------------------------------------------------------------------------
MUTATORS
-----------------------------------------------------------------------------*/

void Tag::setLength(unsigned int len)
{
	length_ = len;
}

void Tag::setTagDescription(Tag_Description td)
{
	tagDescription_ = td;
}

void Tag::setValue(char* buff)
{
	if (value_ != NULL)
	{
		delete value_;
	}

	value_ = new char[length_];

	for(int i = 0; i < length_; i++)
	{
		value_[i] = *(buff + i);
	}
}

void Tag::setValue(char* buff, unsigned int length)
{
	setLength(length);
	setValue(buff);
}

void Tag::setValueRepresentation(Value_Representation vr)
{
	vr_ = vr;
}

/*-----------------------------------------------------------------------------
OTHER
-----------------------------------------------------------------------------*/

std::string Tag::valueToString()
{
	std::string str = "";
	std::stringstream convert;

	switch(vr_)
	{
	default:
		convert << getValueUL();
		str = convert.str();
		break;

	case AE:
	case CS:
	case LO:
	case OB:
	case PN:
	case SH:
	case UI:
		for (int i = 0; i < length_; i++)
		{
			str += *(value_ + i);
		}
		
		break;

	case DA:
		str += "Y: ";

		for (int i = 0; i < 4; i++)
		{
			str += *(value_ + i);
		}

		str += " M: ";

		for (int i = 0; i < 2; i++)
		{
			str += *(value_ + 4 + i);
		}

		str += " D: ";

		for (int i = 0; i < 2; i++)
		{
			str += *(value_ + 6 + i);
		}
		
		break;

	case TM:
		str += "H: ";

		for (int i = 0; i < 2; i++)
		{
			str += *(value_ + i);
		}

		str += " M: ";

		for (int i = 0; i < 2; i++)
		{
			str += *(value_ + 2 + i);
		}

		str += " S: ";

		for (int i = 0; i < 9; i++)
		{
			str += *(value_ + 4 + i);
		}
		break;
	}

	return str;
}