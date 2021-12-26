#pragma once
#include "Instruction.h"

using byte_t = unsigned char;
using address_t = uint16_t;
/// Тип данных машины
union data_t
{	byte_t byte[4];
	int32_t Integer;
	float Float;
	address_t address[2];
	data_t(){Integer=0;}			
};

#pragma pack(push, 1)
///Трёхбайтная команда
union instruction
{struct CMD
{	opcode code:7; 	///< Код операции команды
	uint8_t b:1;    ///< Тип адресации
	uint16_t arg;	///< Аргумент команды
} cmd;
byte_t byte[3];
};
#pragma pack(pop)