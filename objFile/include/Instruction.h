#pragma once
#include <cstdint>

enum opcode : uint8_t //Нужно переработать коды
{
	STOP = 0x0, //End program

	//Арифметические команды
	INCF = 0x01, //increment adder float
	INC = 0x02,	 //increment adder integer
	DECF = 0x03,
	DEC = 0x04,
	ADDF = 0x05, //ADDITION FLOAT (address)
	ADD = 0x06,	 //ADDITION INTEGER (address)
	SUBF = 0x07, //SUBTRACT FLOAT (address)
	SUB = 0x08,	 //SUBTRACT INTEGER (address)
	MULF = 0x09, //MULTIPLY FLOAT (address)
	MUL = 0x0a,	 //MULTIPLY INTEGER (address)
	DIVF = 0x0b, //DIVIDE FLOAT (address)
	DIV = 0x0c,	 //DIVIDE INTEGER (address)
	CMPF = 0x0d, //Compare float with float (address)
	CMP = 0x0e,	 //Compare int with int (address)

	//логические команды
	OR = 0x0f,
	AND = 0x10,
	XOR = 0x11,
	NOT = 0x12,
	//команды сдвига
	SHL = 0x13,
	SHR = 0x14,

	//команды пересылки
	LEA = 0x15,		   //load effective address (address)
	MOV = 0x16,		   //MOVE Data from memory to data of register (address)
	I2F = 0x17,		   //INT to FLOAT adder(0)
	F2I = 0x18,		   //FLOAT to INT adder(0)
	INPUTF = 0x19,	   		//READ FLOAT (address)
	INPUT = 0x1a,	   //READ INTEGER (address)
	OUTPUTF = 0x1b,	   //PRINT FLOAT (address)
	OUTPUT = 0x1c,	   		//PRINT INTEGER (address)
	SAVE = 0x1d, 	   //SAVE Adder in memory (address)
	LOAD = 0x1e,  		//Load adder from memory (address)

	//Команды передачи управления
	CALL = 0x1f, //Call procedure
	RTN = 0x20,
	JUMP = 0x21, //Jump (address)
	JE = 0x22,	 //jump (address),if equal
	JNE = 0x23,	 //jump (address),if not equal
	JLE = 0x24,	 //jump (address),if less equal
	JL = 0x25,	 //jump (address),if less
	JGE = 0x26,	 //jump (address),if greater equal
	JG = 0x27,	 //jump (address),if greater
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