#define ENUM_COMMAND

#include <bitset>
#include <iostream>
#include <fstream>
#include "include/cpu.h"
#include "include/Instruction.h"
#include "include/psw.h"

void loader(Memory& tmpName,const char* file) 
{
	std::ifstream stream(file,std::ios::binary);
	if(stream.is_open())
	{
		uint16_t i=0;
		instruction tmp;
		while(!stream.eof())
		{
			stream.read((char*)&tmp,sizeof(tmp));
			if(!stream.eof())
			{
				tmpName.loadMemory(i,(char*)&tmp,sizeof(tmp));
				i+=3;
			}
		}
		tmpName.unloadMemory(1,(char*)&i,sizeof(i));
		tmpName.printMemory(128);
	}
}



int main(int argc, const char* argv[]) {
	CPU_VM cpu;
	cpu.mem.printMemory(128);
	std::cout<<std::endl;
	loader(cpu.mem,argv[1]);
	for(int i = 0;i<11;i++)
	{
	cpu.loadCommand();
	cpu.exec();
	}
	
}