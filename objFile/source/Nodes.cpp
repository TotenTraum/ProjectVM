#include "../include/Nodes.h"

using namespace std;

void dataIntNode::write(ostream& file)
{
    tags tag = DWORD_TAG;
    file.write((char*)&tag,sizeof(tags));
    file.write((char*)&_number,sizeof(_number));
}

void dataFloatNode::write(ostream& file)
{
    tags tag = DWORD_TAG;
    file.write((char*)&tag,sizeof(tags));
    file.write((char*)&_number,sizeof(_number));
}

void AddressLineNode::write(ostream& file)
{
    tags tag = ADDRESS_TAG;
    file.write((char*)&tag,sizeof(tags));
    file.write((char*)&_line,sizeof(_line));
}

void CommandNode::write(ostream& file)
{
    tags tag = COMMAND_TAG;
    file.write((char*)&tag,sizeof(tags));
    file.write((char*)&_instruction,sizeof(instruction));
}

