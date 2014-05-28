/**
@file ValueRepresentation.h

Created March 26th 2014
*/

#ifndef VALUEREPRESENTATION_H
#define VALUEREPRESENTATION_H

/**
 *	This enumeration contains all the possiblilites for value representation values
*/
enum Value_Representation
{
	UN, // Unknown
	AE, // Application Entity
	AS, // Age String
	AT, // Attribute Tag
	CS, // Code String
	DA, // Date
	DS, // Decimal String
	DT, // Date Time 
	FL, // Single Precision Floating Point
	FD, // Double Precision Floating Point
	IS, // Integer String
	LO, // Character String
	LT, // Long Text
	OB, // Other Byte String
	OF, // Other Float String
	OW, // Other Word String
	PN, // Person's Name
	SH, // Short String
	SL, // Signed Long Integer
	SQ, // Sequence of Zero or More
	SS, // Signed Short Integer
	ST, // Short Text
	TM, // Time
	UI, // Uniqe Identifier
	UL, // Unsigned Long Integer
	US, // Unsigned Short Integer
	UT  // Unlimited Text
};

#endif /*VALUEREPRESENTATION_H*/