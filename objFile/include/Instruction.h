#pragma once
#include <cstdint>

enum opcode : uint8_t //Нужно переработать коды
{
	STOP = 0x0, //End program

	//Арифметические команды
	INC = 0x01,	 //increment adder integer
	INCF = 0x02, //increment adder float
	ADD = 0x03,	 //ADDITION INTEGER (address)
	ADDF = 0x04, //ADDITION FLOAT (address)
	SUB = 0x05,	 //SUBTRACT INTEGER (address)
	SUBF = 0x06, //SUBTRACT FLOAT (address)
	MUL = 0x07,	 //MULTIPLY INTEGER (address)
	MULF = 0x08, //MULTIPLY FLOAT (address)
	DIV = 0x09,	 //DIVIDE INTEGER (address)
	DIVF = 0x0a, //DIVIDE FLOAT (address)

	//логические команды
	OR = 0x0b,
	AND = 0x0c,
	XOR = 0x0d,
	NOT = 0x0e,
	//команды сдвига
	SHL = 0x0f,
	SHR = 0x10,

	//команды пересылки
	LEA = 0x11,		   //load effective address (address)
	MOV = 0x12,		   //MOVE Data from memory to data of register (address)
	I2F = 0x13,		   //INT to FLOAT adder(0)
	F2I = 0x14,		   //FLOAT to INT adder(0)
	READ = 0x15,	   //READ INTEGER (address)
	READF = 0x16,	   //READ FLOAT (address)
	PRINT = 0x17,	   //PRINT INTEGER (address)
	PRINTF = 0x18,	   //PRINT FLOAT (address)
	SAVEADDER = 0x19,  //SAVE integer Adder in memory (address)
	SAVEADDERF = 0x1a, //SAVE float Adder in memory (address)
	LOADADDER = 0x1b,  //Load integer adder from memory (address)
	LOADADDERF = 0x1c, //Load float adder from memory (address)

	//Команды сравнения
	CMP = 0x1d,	 //Compare int with int (address)
	CMPF = 0x1e, //Compare float with float (address)

	//Команды передачи управления
	CALL = 0x1f, //Call procedure
	RTN = 0x20,
	JUMP = 0x21, //Jump (address)
	JE = 0x22,	 //jump (address),if equal
	JNE = 0x23,	 //jump (address),if not equal
	JL = 0x24,	 //jump (address),if less
	JLE = 0x25,	 //jump (address),if less equal
	JG = 0x26,	 //jump (address),if greater
	JGE = 0x27,	 //jump (address),if greater equal
	JS = 0x28,	 //jump (address),if sign flag = 1
	JC = 0x29,	 //jump (address),if carry flag = 1
	JO = 0x2a,	 //jump (address),if overflow flag = 1
	JP = 0x2b,	 //jump (address),if purity flag = 1
	JNS = 0x2c,	 //jump (address),if sign flag = 0
	JNC = 0x2d,	 //jump (address),if carry flag = 0
	JNO = 0x2e,	 //jump (address),if overflow flag = 0
	JNP = 0x2f,	 //jump (address),if purity flag = 0
};

#pragma pack(push, 1)
struct instruction
{
	opcode code;
	uint16_t address;
};
#pragma pack(pop)