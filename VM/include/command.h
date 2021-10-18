#pragma once
#include "cpu.h"

class CPU_VM;
//Base class
class Command{public: virtual void operator()() = 0;};
class CommandCPU: public Command
{public:
	inline static CPU_VM* CPU;
	address_t getAddress();
	PSW::Flags& getFlags();
	static void setCPU(CPU_VM*);
};
class EmptyCommand: public CommandCPU{public: void operator()() override {}};
class StopCommand: public CommandCPU{public: void operator()() override;};

#pragma region Arifmetic
class ArifmeticCommands:public CommandCPU{};

class IncCommand : public ArifmeticCommands{public:void operator()() override;};
class IncFloatCommand : public ArifmeticCommands{public:void operator()() override;};
class DecCommand : public ArifmeticCommands{public:void operator()() override;};
class DecFloatCommand : public ArifmeticCommands{public:void operator()() override;};
//Not command
class NotCommand: public ArifmeticCommands{public:void operator()() override;};
//Add integer
class AddCommand : public ArifmeticCommands {public:void operator()() override;};
//Add Float
class AddFloatCommand: public ArifmeticCommands{public:void operator()() override;};
//Sub Integer
class SubCommand: public ArifmeticCommands{public:void operator()() override;};
//Sub Float
class SubFloatCommand: public ArifmeticCommands {public:void operator()() override;};
//Mul integer
class MulCommand: public ArifmeticCommands {public:void operator()() override;};
//Mul Float
class MulFloatCommand: public ArifmeticCommands {public:void operator()() override;};
//Div integer
class DivCommand: public ArifmeticCommands {public:void operator()() override;};
//Div Float
class DivFloatCommand: public ArifmeticCommands {public:void operator()() override;};
//Or Command
class OrCommand: public ArifmeticCommands {public:void operator()() override;};
//And command
class AndCommand: public ArifmeticCommands {public:void operator()() override;};
//Xor Command
class XorCommand: public ArifmeticCommands {public:void operator()() override;};
//Shift left 
class SHLCommand: public ArifmeticCommands {public:void operator()() override;};
//Shift right
class SHRCommand: public ArifmeticCommands {public:void operator()() override;};

class CmpCommand: public ArifmeticCommands {public:void operator()() override;};
//Compare Float
class CmpFloatCommand: public ArifmeticCommands {public: void operator()() override;};
#pragma endregion Arifmetic
#pragma region IO
class IOCommand:public CommandCPU{};
//Read Integer
class InputCommand: public IOCommand {public:void operator()() override;};
//Read float
class InputFCommand: public IOCommand {public:void operator()() override;};
//Print Float
class OutputFCommand: public IOCommand {public:void operator()() override;};
//Print integer
class OutputCommand: public IOCommand {public:void operator()() override;};
#pragma endregion IO
#pragma region transfer
class TransferCommands: public CommandCPU{}; 
//Convert float to integer
class FloatToIntegerCommand : public TransferCommands {public:void operator()() override;};
//Convert integer to float
class IntegerToFloatCommand : public TransferCommands {public:void operator()() override;};
//Register = address
class LeaCommand : public TransferCommands {public: void operator()() override;};
//Loading in memory
class SaveCommand: public TransferCommands {public: void operator()() override;};
//Unloading from memory
class LoadCommand: public TransferCommands {public: void operator()() override;};
class MovCommand: public TransferCommands {public: void operator()() override;};
#pragma endregion transfer
#pragma region Jumps
class JCommands:public CommandCPU{};
//Jump to second program
class CallCommand : public JCommands{public: void operator()() override;};
//return to main program
class RtnCommand : public JCommands{public: void operator()() override;};
//Jump
class JumpCommand: public JCommands{public: void operator()() override;};
//Jump equal
class JECommand: public JCommands{public: void operator()() override;};
//Jump not equal
class JNECommand: public JCommands{public: void operator()() override;};
//Jump less
class JLCommand: public JCommands {public: void operator()() override;};
//Jump less equal
class JLECommand: public JCommands {public: void operator()() override;};
//Jump greater
class JGCommand: public JCommands {public: void operator()() override;};
//Jump greater equal
class JGECommand: public JCommands {public: void operator()() override;};
//Jump sign flag
class JSCommand: public JCommands {public: void operator()() override;};
//Jump overflow flag
class JOCommand: public JCommands {public: void operator()() override;};
//Jump not sign flag
class JNSCommand: public JCommands {public: void operator()() override;};
//Jump not overflow flag
class JNOCommand: public JCommands {public: void operator()() override;};
#pragma endregion Jumps