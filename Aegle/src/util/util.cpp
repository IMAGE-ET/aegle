#include "util.h"
#include <string>


unsigned int toUnsignedInt(char c0, char c1)
{
	//@TODO: There has got to be a more elegant way
	//@TODO: Check that eindianess is correct

	return toUnsignedInt(0, 0, c0, c1);
}

unsigned int toUnsignedInt(char c0, char c1, char c2, char c3)
{
	//@TODO: There has got to be a more elegant way
	//@TODO: Check that eindianess is correct

	unsigned int val = 0;
	unsigned char charArr[4] = {c0, c1, c2, c3};

	for (int i = 0; i < 4; i++)
	{
		val = val << 8;
		val += charArr[i];
	}

	return val;
}