#pragma once
#include <cstdint>
#include "types.h"
#include "psw.h"
#include "registers.h"
#include "memory.h"
#include <iostream>
//Base class
class Command
{
public:
	virtual void operator()() = 0;
	Command(uint16_t &address) : mem(nullptr), address(address){};
	Command(Memory *mem, uint16_t &address) : mem(mem), address(address){};
	Command() : mem(nullptr), address(0){};

protected:
	uint16_t address;
	Memory *mem;
};

//Add integer
class AddCommand : public Command
{
public:
	void operator()();
	AddCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~AddCommand() {}

private:
	types *ADDER;
	PSW *psw;
	AddCommand();
};
//Sub Integer
class SubCommand : public Command
{
public:
	void operator()();
	SubCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~SubCommand() {}

private:
	types *ADDER;
	PSW *psw;
	SubCommand();
};
//Mul integer
class MulCommand : public Command
{
public:
	void operator()();
	MulCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~MulCommand() {}

private:
	types *ADDER;
	PSW *psw;
	MulCommand();
};
//Div integer
class DivCommand : public Command
{
public:
	void operator()();
	DivCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~DivCommand() {}

private:
	types *ADDER;
	PSW *psw;
	DivCommand();
};
//Register = address
class LeaCommand : public Command
{
public:
	void operator()();
	LeaCommand(uint16_t address, Registers *reg) : Command(address), reg(reg) {}
	~LeaCommand() {}

private:
	Registers *reg;
	LeaCommand();
};
//Add Float
class AddFloatCommand : public Command
{
public:
	AddFloatCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw) {}
	~AddFloatCommand() {}
	void operator()();

private:
	types *ADDER;
	PSW *psw;
	AddFloatCommand();
};
//Mul Float
class SubFloatCommand : public Command
{
public:
	SubFloatCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw) {}
	~SubFloatCommand() {}
	void operator()();

private:
	types *ADDER;
	PSW *psw;
	SubFloatCommand();
};
//Mul Float
class MulFloatCommand : public Command
{
public:
	MulFloatCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~MulFloatCommand() {}
	void operator()();

private:
	types *ADDER;
	PSW *psw;
	MulFloatCommand();
};
//Div Float
class DivFloatCommand : public Command
{
public:
	DivFloatCommand(Memory *mem, uint16_t address, types *ADDER, PSW *psw) : Command(mem, address), ADDER(ADDER), psw(psw){};
	~DivFloatCommand() {}
	void operator()();

private:
	types *ADDER;
	PSW *psw;
	DivFloatCommand();
};
//Read Integer
class ReadCommand : public Command
{
public:
	ReadCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	~ReadCommand() {}
	void operator()();

private:
	ReadCommand();
};
//Read float
class ReadFloatCommand : public Command
{
public:
	ReadFloatCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	~ReadFloatCommand() {}
	void operator()();

private:
	ReadFloatCommand();
};
//Print Float
class PrintFloatCommand : public Command
{
public:
	PrintFloatCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	~PrintFloatCommand() {}
	void operator()();

private:
	PrintFloatCommand();
};
//Print integer
class PrintCommand : public Command
{
public:
	PrintCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	~PrintCommand() {}
	void operator()();

private:
	PrintCommand();
};
//Convert float to integer
class FloatToIntegerCommand : public Command
{
public:
	FloatToIntegerCommand(types *Adder) : Command(), Adder(Adder){};
	~FloatToIntegerCommand() {}
	void operator()();

private:
	types *Adder;
	FloatToIntegerCommand();
};
//Convert integer to float
class IntegerToFloatCommand : public Command
{
public:
	IntegerToFloatCommand(types *Adder) : Command(), Adder(Adder){};
	~IntegerToFloatCommand() {}
	void operator()();

private:
	types *Adder;
	IntegerToFloatCommand();
};

//Loading in memory
class SaveAdderCommand : public Command
{
public:
	SaveAdderCommand(Memory *mem, uint16_t address, types *Adder) : Command(mem, address), Adder(Adder){};
	~SaveAdderCommand() {}
	void operator()();

private:
	types *Adder;
	SaveAdderCommand();
};
//Unloading from memory
class LoadAdderCommand : public Command
{
public:
	LoadAdderCommand(Memory *mem, uint16_t address, types *Adder) : Command(mem, address), Adder(Adder){};
	~LoadAdderCommand() {}
	void operator()();

private:
	types *Adder;
	LoadAdderCommand();
};
//Loading in memory
class SaveAdderFloatCommand : public Command
{
public:
	SaveAdderFloatCommand(Memory *mem, uint16_t address, types *Adder) : Command(mem, address), Adder(Adder){};
	~SaveAdderFloatCommand() {}
	void operator()();

private:
	types *Adder;
	SaveAdderFloatCommand();
};
//Unloading from memory
class LoadAdderFloatCommand : public Command
{
public:
	LoadAdderFloatCommand(Memory *mem, uint16_t address, types *Adder) : Command(mem, address), Adder(Adder){};
	~LoadAdderFloatCommand() {}
	void operator()();

private:
	types *Adder;
	LoadAdderFloatCommand();
};

class MovCommand : public Command
{
public:
	void operator()();
	MovCommand(Memory *mem, uint16_t address, Registers *reg) : Command(mem, address), reg(reg) {}
	~MovCommand() {}

private:
	Registers *reg;
	MovCommand();
};

class IncCommand : public Command
{
public:
	void operator()();
	IncCommand(types *Adder) : Adder(Adder){};
	~IncCommand() {}

private:
	types *Adder;
	IncCommand();
};

class IncFloatCommand : public Command
{
public:
	void operator()();
	IncFloatCommand(types *Adder) : Adder(Adder){};
	~IncFloatCommand() {}

private:
	types *Adder;
	IncFloatCommand();
};

//Jump to second program
class CallCommand : public Command
{
public:
	CallCommand(uint16_t address, PSW *psw, Registers *reg) : Command(address), reg(reg), psw(psw){};
	~CallCommand() {}
	void operator()();

private:
	Registers *reg;
	PSW *psw;
	CallCommand();
};
//return to main program
class RtnCommand : public Command
{
public:
	RtnCommand(uint16_t address, PSW *psw, Registers *reg) : Command(address), reg(reg), psw(psw){};
	~RtnCommand() {}
	void operator()();

private:
	Registers *reg;
	PSW *psw;
	RtnCommand();
};

//Compare integer
class CmpCommand : public Command
{
public:
	CmpCommand(Memory *mem, uint16_t address, PSW *psw, Registers *reg) : Command(mem, address), psw(psw), reg(reg){};
	~CmpCommand() {}
	void operator()();

private:
	PSW *psw;
	Registers *reg;
	CmpCommand();
};
//Compare Float
class CmpFloatCommand : public Command
{
public:
	CmpFloatCommand(Memory *mem, uint16_t address, PSW *psw, Registers *reg) : Command(mem, address), psw(psw), reg(reg){};
	~CmpFloatCommand() {}
	void operator()();

private:
	PSW *psw;
	Registers *reg;
	CmpFloatCommand();
};

//Jump
class JumpCommand : public Command
{
public:
	JumpCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JumpCommand() {}
	void operator()();

private:
	PSW *psw;
	JumpCommand();
};

//Jump equal
class JECommand : public Command
{
public:
	JECommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JECommand() {}
	void operator()();

private:
	PSW *psw;
	JECommand();
};
//Jump not equal
class JNECommand : public Command
{
public:
	JNECommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNECommand() {}
	void operator()();

private:
	PSW *psw;
	JNECommand();
};
//Jump less
class JLCommand : public Command
{
public:
	JLCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JLCommand() {}
	void operator()();

private:
	PSW *psw;
	JLCommand();
};
//Jump less equal
class JLECommand : public Command
{
public:
	JLECommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JLECommand() {}
	void operator()();

private:
	PSW *psw;
	JLECommand();
};
//Jump greater
class JGCommand : public Command
{
public:
	JGCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JGCommand() {}
	void operator()();

private:
	PSW *psw;
	JGCommand();
};
//Jump greater equal
class JGECommand : public Command
{
public:
	JGECommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JGECommand() {}
	void operator()();

private:
	PSW *psw;
	JGECommand();
};

//Jump zero flag
class JZCommand : public Command
{
public:
	JZCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JZCommand() {}
	void operator()();

private:
	PSW *psw;
	JZCommand();
};
//Jump sign flag
class JSCommand : public Command
{
public:
	JSCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JSCommand() {}
	void operator()();

private:
	PSW *psw;
	JSCommand();
};
//Jump carry flag
class JCCommand : public Command
{
public:
	JCCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JCCommand() {}
	void operator()();

private:
	PSW *psw;
	JCCommand();
};
//Jump overflow flag
class JOCommand : public Command
{
public:
	JOCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JOCommand() {}
	void operator()();

private:
	PSW *psw;
	JOCommand();
};
//Jump purity flag
class JPCommand : public Command
{
public:
	JPCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JPCommand() {}
	void operator()();

private:
	PSW *psw;
	JPCommand();
};
//Jump not zero flag
class JNZCommand : public Command
{
public:
	JNZCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNZCommand() {}
	void operator()();

private:
	PSW *psw;
	JNZCommand();
};
//Jump not sign flag
class JNSCommand : public Command
{
public:
	JNSCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNSCommand() {}
	void operator()();

private:
	PSW *psw;
	JNSCommand();
};
//Jump not carry flag
class JNCCommand : public Command
{
public:
	JNCCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNCCommand() {}
	void operator()();

private:
	PSW *psw;
	JNCCommand();
};
//Jump not overflow flag
class JNOCommand : public Command
{
public:
	JNOCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNOCommand() {}
	void operator()();

private:
	PSW *psw;
	JNOCommand();
};
//Jump not purity flag
class JNPCommand : public Command
{
public:
	JNPCommand(uint16_t address, PSW *psw) : Command(address), psw(psw){};
	~JNPCommand() {}
	void operator()();

private:
	PSW *psw;
	JNPCommand();
};
