#pragma once
#include "command.h"
#include "Instruction.h"
#include "memory.h"
#include "psw.h"
#include "registers.h"
#include "types.h"
//Base class Fabric
class BaseCommandFabric
{
public:
    virtual Command* make(const instruction&)=0;
    BaseCommandFabric(){}
};

class CommandFabric:public BaseCommandFabric
{
public:
    Command* make(const instruction&);
    CommandFabric(Memory* memory,PSW *psw,Registers* registers,types* adder):
        memory(memory),psw(psw),registers(registers),adder(adder),BaseCommandFabric(){}
private:
    Memory* memory;
    PSW* psw;
    types* adder;
    Registers* registers;
};