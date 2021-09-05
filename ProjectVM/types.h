#pragma once

#include <cstdint>


#define BYTE uint8_t

#define REGISTER uint16_t*

#define ADDER uint32_t

struct INTEGER {
	int32_t sign : 1;
	int32_t number : 31;
};

struct UINTEGER {
	int32_t number : 32;
};

struct DOUBLE {
	int32_t sign : 1;
	int32_t exponent : 8;//Порядок
	int32_t fraction : 23;//Мантисса
	DOUBLE(int num) {
		sign = num >> 31;
		fraction = num & 0x007f'ffff;
		exponent = num >> 23;
	}
};

