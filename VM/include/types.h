#pragma once
#include <cstdint>

#define BYTE int8_t

union types
{
	int32_t Integer;
	float Float;
	uint16_t address;
};