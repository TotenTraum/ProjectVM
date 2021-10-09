#pragma once
#include "memory.h"
#include "psw.h"
#include "types.h"
#include "command.h"
#include "Instruction.h"

class CPU_VM
{
public:
	CPU_VM(uint16_t memSize = 65535):mem(memSize)
	{
		Adder.Integer = 0;
		BP.address = 0;
		InitCommand();
	}
	void InitCommand();
	void exec();
	void reset();
	Memory mem;	//Memory
private:
	PSW psw; 	//PSW
	types Adder;//Adder
	types BP;	//Base pointer
	Command* Commands[128];
};