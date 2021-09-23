#pragma once
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
		fabric = new CommandFabric(&mem,&psw,&registers,&Adder);
	}
	void loadCommand();
	void exec();
	Memory mem;
	PSW psw; 
	types Adder;
	Registers registers;
private:
	BaseCommandFabric* fabric = nullptr;
	Command* currentCommand = nullptr;
};