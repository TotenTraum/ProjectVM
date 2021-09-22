#include <fstream>
#include <iostream>
#include <string>
#include "include/Instruction.h"

const size_t size = 11;

void writer(instruction* inst,std::string name)
{
    std::ofstream stream(name,std::ios::binary);
    for(int i=0;i<size;i++)
        std::cout<<(inst+i)->address<<" ";
    for(int i=0;i<size;i++)
        stream.write((char*)(inst+i),sizeof(instruction));
}

int main(int argc, const char* argv[])
{
	instruction inst[size];
    inst[0].code=READ;
    inst[0].address = 100;
    inst[1].code=ADD;
    inst[1].address = 100;
    inst[2].code=MUL;
    inst[2].address = 100;
    inst[3].code=SAVEADDER;
    inst[3].address = 120;
    inst[4].code=I2F;
    inst[4].address = 0;
    inst[5].code=READF;
    inst[5].address = 140;
    inst[6].code=SUBF;
    inst[6].address = 140;
    inst[7].code=DIVF;
    inst[7].address = 140;
    inst[8].code=SAVEADDERF;
    inst[8].address = 160;
    inst[9].code=PRINT;
    inst[9].address = 120;
    inst[10].code=PRINTF;
    inst[10].address = 160;
    writer(inst,"file.o");
}
