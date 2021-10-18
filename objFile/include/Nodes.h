#pragma once
#include "Instruction.h"
#include <fstream>

enum tags:uint8_t{
	COMMAND_TAG=0x43,
	DWORD_TAG=0x44,
	ADDRESS_TAG=0x41
};

class Node
{
public:
    virtual void write(std::ostream&)=0;
};

class dataIntNode: public Node
{
public:
    dataIntNode(int32_t arg):_number(arg){}
    void write(std::ostream&);
private:
    int32_t _number;
};

class dataFloatNode: public Node
{
public:
    dataFloatNode(float arg):_number(arg){}
    void write(std::ostream&);
private:
    float _number;
};

class AddressLineNode: public Node
{
public:
    AddressLineNode(uint16_t arg):_line(arg){}
    void write(std::ostream&);
private:
    uint16_t _line;
};

class CommandNode: public Node
{
public:
    CommandNode(instruction arg):_instruction(arg){}
    void write(std::ostream&);
private:
    instruction _instruction;
};