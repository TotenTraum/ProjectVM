#pragma once
#include <cstdint>
#include <iostream>
#include "Instruction.h"
#include "psw.h"
#include "registers.h"
#include "types.h"
#include "command.h"
#include "Fabric.h"
//Base class CPU
class CPU 
{
public:
	virtual void exec()=0;
private:

};

class CPU_VM:public CPU 
{
public:
	CPU_VM()
	{
		Adder.Integer=0;
		fabric = new CommandFabric(&mem,&psw,&registers,&Adder);
	}
	void loadCommand();
	void exec();
	Memory mem;
private:
	BaseCommandFabric* fabric = nullptr;
	PSW psw; 
	types Adder;
	Registers registers;
	Command* currentCommand = nullptr;
};