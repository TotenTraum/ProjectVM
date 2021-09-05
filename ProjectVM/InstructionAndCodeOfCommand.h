#pragma once
#include <cstdint>

enum command : uint8_t {
	INC = 0x80,
	ADD = 0x81,
	SUB = 0x82,
	MUL = 0x83,
	DIV = 0x84,
	MOV = 0x85,
	D2I = 0x86,//DOUBLE to INT
	I2D = 0x87,//INT to DOUBLE
	ADDF = 0x88,
	SUBF = 0x89,
	MULF = 0x8a,
	DIVF = 0x8b,
	MOVF = 0x8c,
	INCF = 0x8d
};

struct instruction {
	command code;
	uint16_t address;
};