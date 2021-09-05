#pragma once
#include <cstdint>
#include "InstructionAndCodeOfCommand.h"
#include "types.h"
class CPU {
public:
	virtual void exec(instruction )=0;

private:

};

class CPU_VM:public CPU {
public:
	void exec(instruction);
private:
	REGISTER R1;

};