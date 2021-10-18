#pragma once
#include "memory.h"
#include "psw.h"
#include "command.h"
#include "Instruction.h"

class Command;

class CPU_VM final
{public:
	CPU_VM(){InitCommand();}
	void exec();
	void reset();
	void readDWORD(data&);
	void writeDWORD(data&);
	Memory mem;		//Memory
	PSW psw; 		//PSW
	data Adder;		//Adder
	data BP;		//Base pointer
	instruction currentCommand;
private:
	void InitCommand();
	Command* Commands[128];
};