#pragma once
#include <iostream>
#include "psw.h"
#include "memory.h"
//Base class
class Command
{
public:
	virtual void operator()() = 0;
};

class EmptyCommand: public Command
{
public: void operator()(){}
};

class CommandAddress: public virtual Command
{
public:
	static const uint16_t& getAddress(){return address;}
	static void setAddress(uint16_t addressArg){address = addressArg;}
protected:
	inline static uint16_t address;
};

class CommandBP: public virtual Command
{
public:
	static void setBP(types* BPArg){BP = BPArg;}
protected:
	inline static types* BP;
};

class CommandAdder: public virtual Command
{
public:
	static void setAdder(types* AdderArg){Adder = AdderArg;}
protected:
	inline static types* Adder;
};

class CommandMem: public virtual Command
{
public:
	static void setMemory(Memory* memArg){mem = memArg;}
protected:
	inline static Memory* mem; 
};

class CommandPSW: public virtual Command
{
public:
	static void setPSW(PSW* pswArg){psw = pswArg;}
protected:
	inline static PSW* psw; 
};

class StopCommand: public CommandPSW
{
public:
	void operator()(){psw->flags.WF=1;}
};

#pragma region Arifmetic
class ArifmeticCommands:public CommandMem,public CommandPSW, public CommandAddress,public CommandAdder{};

class IncCommand : public CommandAdder{
public:
	void operator()();
};

class IncFloatCommand : public CommandAdder{
public:
	void operator()();
};
//Not command
class NotCommand: public CommandAdder{
public:
	void operator()();
};
//Add integer
class AddCommand : public ArifmeticCommands{
public:
	void operator()();
};
//Add Float
class AddFloatCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Sub Integer
class SubCommand: public ArifmeticCommands{
	public:void operator()();
};
//Sub Float
class SubFloatCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Mul integer
class MulCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Mul Float
class MulFloatCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Div integer
class DivCommand : public ArifmeticCommands{
public:
	void operator()();
};
//Div Float
class DivFloatCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Or Command
class OrCommand: public ArifmeticCommands{
public:
	void operator()();
};
//And command
class AndCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Xor Command
class XorCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Shift left 
class SHLCommand: public ArifmeticCommands{
public:
	void operator()();
};
//Shift right
class SHRCommand: public ArifmeticCommands{
public:
	void operator()();
};
#pragma endregion Arifmetic

#pragma region IO
class IOCommand:public CommandMem,public CommandAddress{};
//Read Integer
class ReadCommand: public IOCommand{
public:
	void operator()();
};
//Read float
class ReadFloatCommand: public IOCommand{
public:
	void operator()();
};
//Print Float
class PrintFloatCommand: public IOCommand{
public:
	void operator()();
};
//Print integer
class PrintCommand: public IOCommand{
public:
	void operator()();
};
#pragma endregion IO

#pragma region compare
class CompareCommand:public CommandAddress,public CommandBP,public CommandMem,public CommandPSW{};
//Compare integer
class CmpCommand: public CompareCommand{
public:
	void operator()();
};
//Compare Float
class CmpFloatCommand: public CompareCommand{
public:
	void operator()();
};
#pragma endregion compare

#pragma region transfer
class TransferCommands: public CommandMem, public CommandAdder, public CommandAddress,public CommandBP{}; 
//Convert float to integer
class FloatToIntegerCommand : public CommandAdder{
public:
	void operator()();
};
//Convert integer to float
class IntegerToFloatCommand : public CommandAdder{
public:
	void operator()();
};
//Register = address
class LeaCommand : public TransferCommands{
public:
	void operator()();
};
//Loading in memory
class SaveAdderCommand: public TransferCommands{
public:
	void operator()();
};
//Unloading from memory
class LoadAdderCommand: public TransferCommands{
public:
	void operator()();
};
//Loading in memory
class SaveAdderFloatCommand: public TransferCommands{
public:
	void operator()();
};
//Unloading from memory
class LoadAdderFloatCommand: public TransferCommands{
public:
	void operator()();
};

class MovCommand: public TransferCommands{
public:
	void operator()();
};
#pragma endregion transfer

#pragma region Jumps
class JCommands:public CommandPSW, public CommandAddress,public CommandBP{};
//Jump to second program
class CallCommand : public JCommands{
public:
	void operator()();
};
//return to main program
class RtnCommand : public JCommands{
public:
	void operator()();
};
//Jump
class JumpCommand: public JCommands{
public:
	void operator()();
};
//Jump equal
class JECommand: public JCommands{
public:
	void operator()();
};
//Jump not equal
class JNECommand: public JCommands{
public:
	void operator()();
};
//Jump less
class JLCommand: public JCommands{
public:
	void operator()();
};
//Jump less equal
class JLECommand: public JCommands{
public:
	void operator()();
};
//Jump greater
class JGCommand: public JCommands{
public:
	void operator()();
};
//Jump greater equal
class JGECommand: public JCommands{
public:
	void operator()();
};
//Jump sign flag
class JSCommand: public JCommands{
public:
	void operator()();
};
//Jump carry flag
class JCCommand: public JCommands{
public:
	void operator()();
};
//Jump overflow flag
class JOCommand: public JCommands{
public:
	void operator()();
};
//Jump purity flag
class JPCommand: public JCommands{
public:
	void operator()();
};
//Jump not sign flag
class JNSCommand: public JCommands{
public:
	void operator()();
};
//Jump not carry flag
class JNCCommand: public JCommands{
public:
	void operator()();
};
//Jump not overflow flag
class JNOCommand: public JCommands{
public:
	void operator()();
};
//Jump not purity flag
class JNPCommand: public JCommands{
public:
	void operator()();
};
#pragma endregion Jumps