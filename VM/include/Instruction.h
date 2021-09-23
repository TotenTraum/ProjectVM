#pragma once
#include <cstdint>

enum opcode : uint8_t //Нужно переработать коды
{
	END = 0x0,			//End program

	INC = 0x1,			//increment adder integer
	ADD = 0x2,			//ADDITION INTEGER (address)
	SUB = 0x3,			//SUBTRACT INTEGER (address)
	MUL = 0x4,			//MULTIPLY INTEGER (address)
	DIV = 0x5,			//DIVIDE INTEGER (address)
	
	INCF = 0x6,			//increment adder float
	ADDF = 0x7,			//ADDITION FLOAT (address)
	SUBF = 0x8,			//SUBTRACT FLOAT (address)
	MULF = 0x9,			//MULTIPLY FLOAT (address)
	DIVF = 0xa,			//DIVIDE FLOAT (address)

	READF = 0xb,		//READ FLOAT (address)
	READ  = 0xc,		//READ INTEGER (address)
	PRINTF = 0xd,		//PRINT FLOAT (address)
	PRINT = 0xe,		//PRINT INTEGER (address)

	LEA = 0xf,			//load effective address (address)
	MOV = 0x10,			//MOVE Data from memory to data of register (address)

	SAVEADDER = 0x11,	//SAVE integer Adder in memory (address)
	LOADADDER = 0x12,	//Load integer adder from memory (address)
	SAVEADDERF = 0x13,	//SAVE float Adder in memory (address)
	LOADADDERF = 0x14,	//Load float adder from memory (address)
	
	F2I = 0x15, 		//FLOAT to INT (address)
	I2F = 0x16, 		//INT to FLOAT (address)
	
	CALL = 0x17,		//Call procedure
	JUMP = 0x18,		//Jump (address)
	
	CMP = 0x19,			//Compare int with int (address)
	CMPF = 0x1a,		//Compare float with float (address)
	
	JE  = 0x1b,			//jump (address),if equal
	JNE = 0x1c, 		//jump (address),if not equal
	JL  = 0x1d,			//jump (address),if less
	JLE = 0x1e, 		//jump (address),if less equal
	JG  = 0x2f,			//jump (address),if greater
	JGE = 0x20, 		//jump (address),if greater equal
	
	JZ  = 0x21,			//jump (address),if zero flag = 1
	JS  = 0x22,			//jump (address),if sign flag = 1
	JC  = 0x23,			//jump (address),if carry flag = 1
	JO  = 0x24,			//jump (address),if overflow flag = 1
	JP  = 0x25,			//jump (address),if purity flag = 1
	
	JNZ = 0x26, 		//jump (address),if zero flag = 0
	JNS = 0x27, 		//jump (address),if sign flag = 0
	JNC = 0x28, 		//jump (address),if carry flag = 0
	JNO = 0x29, 		//jump (address),if overflow flag = 0
	JNP = 0x2a, 		//jump (address),if purity flag = 0
	
	ADDb = 0x81, 		//ADDITION INTEGER (BP:address)
	SUBb = 0x82, 		//SUBTRACT INTEGER (BP:address)
	MULb = 0x83, 		//MULTIPLY INTEGER (BP:address)
	DIVb = 0x84, 		//DIVIDE INTEGER (BP:address)
	
	ADDFb = 0x85, 		//ADDITION FLOAT (BP:address)
	SUBFb = 0x86, 		//SUBTRACT FLOAT (BP:address)
	MULFb = 0x87, 		//MULTIPLY FLOAT (BP:address)
	DIVFb = 0x88, 		//DIVIDE FLOAT (BP:address)
	
	READFb  = 0x89,		//READ FLOAT (BP:address)
	READb   = 0x8a,		//READ INTEGER (BP:address)
	PRINTFb = 0x8b, 	//PRINT FLOAT (BP:address)
	PRINTb  = 0x8c,		//PRINT INTEGER (BP:address)
	
	LEAb = 0x8d, 		//load effective address (BP:address)
	MOVb = 0x8e,		//MOVE Data from memory to data of register (BP:address)
	
	SAVEADDERb  = 0x8f,	//SAVE integer Adder in memory (BP:address)
	LOADADDERb  = 0x90,	//Load integer adder from memory (BP:address)
	SAVEADDERFb = 0x91, //SAVE float Adder in memory (BP:address)
	LOADADDERFb = 0x92, //Load float adder from memory (BP:address)
	
	CALLb = 0x93,		//Call procedure (BP:address)
	RTNb = 0x94,		//Return in main program
	
	CMPb = 0x95,		//Compare int with int (BP:address)
	CMPFb = 0x96,		//Compare float with float (BP:address)
	JUMPb = 0x97,		//Jump (BP:address)
	
	JEb  = 0x98,		//jump (BP:address),if equal
	JNEb = 0x99, 		//jump (BP:address),if not equal
	JLb  = 0x9a,		//jump (BP:address),if less
	JLEb = 0x9b, 		//jump (BP:address),if less equal
	JGb  = 0x9e,		//jump (BP:address),if greater
	JGEb = 0x9f, 		//jump (BP:address),if greater equal
	
	JZb  = 0xa0,		//jump (BP:address),if zero flag = 1
	JSb  = 0xa1,		//jump (BP:address),if sign flag = 1
	JCb  = 0xa2,		//jump (BP:address),if carry flag = 1
	JOb  = 0xa3,		//jump (BP:address),if overflow flag = 1
	JPb  = 0xa4,		//jump (BP:address),if purity flag = 1
	
	JNZb = 0xa5, 		//jump (BP:address),if zero flag = 0
	JNSb = 0xa6, 		//jump (BP:address),if sign flag = 0
	JNCb = 0xa7, 		//jump (BP:address),if carry flag = 0
	JNOb = 0xa8, 		//jump (BP:address),if overflow flag = 0
	JNPb = 0xa9  		//jump (BP:address),if purity flag = 0
};

#pragma pack(push, 1)
struct instruction
{
	opcode code;
	uint16_t address;
};
#pragma pack(pop)
