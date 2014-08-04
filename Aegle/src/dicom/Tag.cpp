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
	unsigned int i = 0;

	if (length_ == 2)
	{
		i = toUnsignedInt(value_[1], value_[0]);
	}
	else if (length_ == 4)
	{
		i = toUnsignedInt(value_[3], value_[2], value_[1], value_[0]);
	}
	else
	{
		std::cout << "ERROR: Int will not fit in a size" << std::endl;
	}

	return i;
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
	if (buff == NULL)
	{
		return;
	}

	if (value_ != NULL)
	{
		delete value_;
	}

	value_ = new char[length_];

	for(unsigned int i = 0; i < length_; i++)
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
	case AS:
	case CS:
	case DS:
	case IS:
	case LO:
	case LT:
	case OB:
	case PN:
	case SH:
	case UI:
		for (unsigned int i = 0; i < length_; i++)
		{
			str += *(value_ + i);
		}
		
		break;
	case DA:
		return valueToDateString();
	case TM:
		return valueToTimeString();
	case US:
		return valueToUnsignedShortString();
	}

	return str;
}

std::string Tag::valueToDateString()
{
	std::string str = "";

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

	return str;
}

std::string Tag::valueToTimeString()
{
	std::string str = "";

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

	return str;
}

std::string Tag::valueToUnsignedShortString()
{
	std::string str = "";

	for (unsigned int i = 0; i < length_; i+=2)
	{
		str += "\\" + std::to_string(toUnsignedInt(value_[i+1], value_[i])) + " ";
	}

	return str;
}