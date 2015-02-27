#include <stdio.h>
#include "bitpack.h"
#include "assert.h"

Except_T Bitpack_Overflow = {"Crap! Too many bits!"};

bool Bitpack_fitsu(uint64_t n, unsigned width)
{
	assert(!(width > 64));
	if(width == 0)
	{
		if(n == 0) return true;
		else return false;
	}
	else
	{
		uint64_t mask = 1;
		for(unsigned i = 0; i < width; i++)
		{
			mask *= 2;
		}
		mask--; /*Converts to all 1's*/
		if(n > mask) return false;
		else return true;
	}
}

bool Bitpack_fitss( int64_t n, unsigned width)
{	
	assert(!(width > 64));
	/*Base case, will be changed by the end of the function*/
	if(n < 0)
	{
		uint64_t result = ~n;
		result++;
		return Bitpack_fitsu(result, width-1);
	}
	else return Bitpack_fitsu((uint64_t)(n), width-1);
}

uint64_t Bitpack_getu(uint64_t word, unsigned width, unsigned lsb)
{
	assert(!((width + lsb) > 64));
	uint64_t mask = 1;
	for(unsigned i = width; i != 1; i /= 2)
	{
		mask *= 2;
	}
	mask--;
	if(lsb != 64) mask = mask << lsb;
	/*The only legal case where we don't want to slide is lsb == 64.*/
	/*That would push us clear into the next bitpack.*/
	uint64_t ret = mask & word;
	ret = ret >> lsb;
	return ret;
	/*We can't return the result, we have to store the data somewhere,
	too.*/
}

int64_t Bitpack_gets(uint64_t word, unsigned width, unsigned lsb)
{
	assert(!((width + lsb) > 64));
	unsigned offset = width-1+lsb;
	if((((uint64_t)(1) << offset) & word) > 0)
	{
		uint64_t max = 1;
		for(unsigned i = 0; i < width; i++)
		{
			max *= 2;
		}
		return Bitpack_getu(word, width, lsb) - max;
	}
	else return Bitpack_getu(word, width, lsb);
}

uint64_t Bitpack_newu(uint64_t word, unsigned width, unsigned lsb,
	uint64_t value)
{
	assert(!((width + lsb) >= 64));
	if(!(Bitpack_fitsu(value, width))) RAISE(Bitpack_Overflow);
	uint64_t allones = 1;
	for(unsigned i = 0; i < width; i++)
	{
		allones *= 2;
	}
	allones--; /*Converts to all 1's*/
	uint64_t mask = allones << lsb;
	mask = ~mask;
	word = word & mask;
	word = word | (value << lsb);
	return word;
}

uint64_t Bitpack_news(uint64_t word, unsigned width, unsigned lsb,
	int64_t value)
{	
	assert(lsb > 0);
	assert(!((width + lsb) >= 64));
	if(!(Bitpack_fitsu(value, width))) RAISE(Bitpack_Overflow);	
	uint64_t allones = 1;
	for(unsigned i = 0; i < width; i++)
	{
		allones *= 2;
	}
	allones--; /*Converts to all 1's*/
	value = value & allones; /*Converts to unsigned*/
	return Bitpack_newu(word, width, lsb, value);
}
