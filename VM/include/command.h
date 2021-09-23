#pragma once
#include <iostream>
#include "psw.h"
#include "registers.h"
#include "memory.h"
//Base class
class Command
{
public:
	virtual void operator()() = 0;
	Command(Memory *mem, uint16_t &address) : memory(mem), address(address){};
	Command(Memory *mem, uint16_t &address,Registers *reg,PSW *psw) : memory(mem), address(address),
																	  registers(reg),psw(psw){};
	Command(uint16_t &address,PSW *psw) : address(address),psw(psw){};
	Command(uint16_t address,Registers *reg) : address(address),registers(reg){};
protected:
	uint16_t address;
	Memory *memory = nullptr;
	PSW *psw= nullptr;
	Registers *registers= nullptr;
};

//Add integer
class AddCommand : public Command
{
public:
	void operator()();
	AddCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
};
//Sub Integer
class SubCommand : public Command
{
public:
	void operator()();
	SubCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
};
//Mul integer
class MulCommand : public Command
{
public:
	void operator()();
	MulCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
};
//Div integer
class DivCommand : public Command
{
public:
	void operator()();
	DivCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
};
//Register = address
class LeaCommand : public Command
{
public:
	void operator()();
	LeaCommand(uint16_t address, Registers *reg) : Command(address,reg) {}
};
//Add Float
class AddFloatCommand : public Command
{
public:
	AddFloatCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw) {}
	void operator()();
};
//Mul Float
class SubFloatCommand : public Command
{
public:
	SubFloatCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw) {}
	void operator()();
};
//Mul Float
class MulFloatCommand : public Command
{
public:
	MulFloatCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
	void operator()();
};
//Div Float
class DivFloatCommand : public Command
{
public:
	DivFloatCommand(Memory *mem, uint16_t address, Registers* reg, PSW *psw) : Command(mem, address,reg,psw){};
	void operator()();
};
//Read Integer
class ReadCommand : public Command
{
public:
	ReadCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	void operator()();

private:
};
//Read float
class ReadFloatCommand : public Command
{
public:
	ReadFloatCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	void operator()();

private:
};
//Print Float
class PrintFloatCommand : public Command
{
public:
	PrintFloatCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	void operator()();

private:
};
//Print integer
class PrintCommand : public Command
{
public:
	PrintCommand(Memory *mem, uint16_t address) : Command(mem, address){};
	void operator()();

private:
};
//Convert float to integer
class FloatToIntegerCommand : public Command
{
public:
	FloatToIntegerCommand(Registers* reg) : Command(0,reg){};
	void operator()();
};
//Convert integer to float
class IntegerToFloatCommand : public Command
{
public:
	IntegerToFloatCommand(Registers* reg) : Command(0,reg){};
	void operator()();
};

//Loading in memory
class SaveAdderCommand : public Command
{
public:
	SaveAdderCommand(Memory *mem, uint16_t address, Registers* reg) : Command(mem,address,reg,nullptr){};
	void operator()();
};
//Unloading from memory
class LoadAdderCommand : public Command
{
public:
	LoadAdderCommand(Memory *mem, uint16_t address, Registers* reg) : Command(mem,address,reg,nullptr){};
	void operator()();
};
//Loading in memory
class SaveAdderFloatCommand : public Command
{
public:
	SaveAdderFloatCommand(Memory *mem, uint16_t address, Registers* reg) : Command(mem,address,reg,nullptr){};
	void operator()();
};
//Unloading from memory
class LoadAdderFloatCommand : public Command
{
public:
	LoadAdderFloatCommand(Memory *mem, uint16_t address, Registers* reg) : Command(mem,address,reg,nullptr){};
	void operator()();
};

class MovCommand : public Command
{
public:
	void operator()();
	MovCommand(Memory *mem, uint16_t address, Registers* reg) : Command(mem,address,reg,nullptr) {}
};

class IncCommand : public Command
{
public:
	void operator()();
	IncCommand(Registers* reg) : Command(0,reg){}
};

class IncFloatCommand : public Command
{
public:
	void operator()();
	IncFloatCommand(Registers* reg) : Command(0,reg){}
};

//Jump to second program
class CallCommand : public Command
{
public:
	CallCommand(uint16_t address,Registers *reg, PSW *psw) : Command(nullptr, address,reg,psw){}
	void operator()();
};
//return to main program
class RtnCommand : public Command
{
public:
	RtnCommand(uint16_t address,Registers *reg, PSW *psw) : Command(nullptr, address,reg,psw){};
	void operator()();
};

//Compare integer
class CmpCommand : public Command
{
public:
	CmpCommand(Memory *mem, uint16_t address,Registers *reg, PSW *psw) : Command(mem, address,reg,psw){};
	void operator()();
};
//Compare Float
class CmpFloatCommand : public Command
{
public:
	CmpFloatCommand(Memory *mem, uint16_t address,Registers *reg, PSW *psw) : Command(mem, address,reg,psw){};
	void operator()();
};

//Jump
class JumpCommand : public Command
{
public:
	JumpCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};

//Jump equal
class JECommand : public Command
{
public:
	JECommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not equal
class JNECommand : public Command
{
public:
	JNECommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump less
class JLCommand : public Command
{
public:
	JLCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump less equal
class JLECommand : public Command
{
public:
	JLECommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump greater
class JGCommand : public Command
{
public:
	JGCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump greater equal
class JGECommand : public Command
{
public:
	JGECommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump zero flag
class JZCommand : public Command
{
public:
	JZCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump sign flag
class JSCommand : public Command
{
public:
	JSCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump carry flag
class JCCommand : public Command
{
public:
	JCCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump overflow flag
class JOCommand : public Command
{
public:
	JOCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump purity flag
class JPCommand : public Command
{
public:
	JPCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not zero flag
class JNZCommand : public Command
{
public:
	JNZCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not sign flag
class JNSCommand : public Command
{
public:
	JNSCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not carry flag
class JNCCommand : public Command
{
public:
	JNCCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not overflow flag
class JNOCommand : public Command
{
public:
	JNOCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};
//Jump not purity flag
class JNPCommand : public Command
{
public:
	JNPCommand(uint16_t address, PSW *psw) : Command(address,psw){};
	void operator()();
};