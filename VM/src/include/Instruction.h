#pragma once
#include <cstdint>
enum opcode : uint8_t 
{	STOP = 0x0, //End program
	//Арифметические команды
	INCF = 0x01, INC = 0x02,	 //increment adder
	DECF = 0x03, DEC = 0x04,	 //decrement adder
	ADDF = 0x05, ADD = 0x06,	 //ADDITION(address)
	SUBF = 0x07, SUB = 0x08,	 //SUBTRACT(address)
	MULF = 0x09, MUL = 0x0a,	 //MULTIPLY (address)
	DIVF = 0x0b, DIV = 0x0c,	 //DIVIDE INTEGER (address)
	CMPF = 0x0d, CMP = 0x0e,	 //Compare int with int (address)
	//логические команды
	OR = 0x0f,
	AND = 0x10,
	XOR = 0x11,
	NOT = 0x12,
	//команды арифметического сдвига
	SAL = 0x13, SAR = 0x14,
	//команды пересылки
	LEA = 0x15,		                   //load effective address (address)
	MOV = 0x16,		   				   //MOVE Data from memory to data of register (address)
	I2F = 0x17,		   				   //INT to FLOAT adder(0)
	F2I = 0x18,		   				   //FLOAT to INT adder(0)
	INPUTF = 0x19,  INPUT = 0x1a,	   //READ INTEGER (address)
	OUTPUTF = 0x1b, OUTPUT = 0x1c,	   //PRINT INTEGER (address)
	SAVE = 0x1d, 	   				   //SAVE Adder in memory (address)
	LOAD = 0x1e,  					   //Load adder from memory (address)
	//Команды передачи управления
	CALL = 0x1f, //Call procedure
	RTN = 0x20,	 
	JUMP = 0x21, //Jump (address)
	JE = 0x22,	 //jump (address),if (ZF)
	JNE = 0x23,	 //jump (address),if (!ZF)
	JLE = 0x24,	 //jump (address),if (SF != OF || ZF)
	JL = 0x25,	 //jump (address),if (SF != OF)
	JGE = 0x26,	 //jump (address),if (SF == OF || ZF)
	JG = 0x27,	 //jump (address),if (SF == OF && !ZF)
	JS = 0x28,	 //jump (address),if (SF)
	JO = 0x29,	 //jump (address),if (OF)
	JNS = 0x2a,	 //jump (address),if (!SF)
	JNO = 0x2b,	 //jump (address),if (!OF)

	CLT = 0x2c,  //Clear trap flag
	STT = 0x2d   //Set trap flag
};