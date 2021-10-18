#pragma once
#include <cstdint>

using byte_t = unsigned char;
using address_t = uint16_t;

union data
{	byte_t byte[4];
	int32_t Integer;
	float Float;
	address_t address[2];
	data(){Integer=0;}
};