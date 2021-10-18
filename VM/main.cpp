#include <fstream>
#include "include/cpu.h"

enum tags : uint8_t
{	ADDRESS_TAG = 0x41,
	COMMAND_TAG = 0x43,
	DWORD_TAG = 0x44,
};
void loader(CPU_VM &CPU, const char *file)
{	std::ifstream stream(file, std::ios::binary);
	instruction tmp;
	tags tag;
	data value;
	if (stream.is_open())
		while (stream.read((char *)&tag, 1))
			switch (tag)
			{
			case COMMAND_TAG:
				if (stream.read((char *)&tmp, 3))
				{
					CPU.mem[CPU.psw.IP++] = tmp.code;
					CPU.mem[CPU.psw.IP++] = tmp.address;
					CPU.mem[CPU.psw.IP++] = tmp.address >> 8;
				}
				break;
			case DWORD_TAG:
				if (stream.read((char *)&value, 4))
					for (int j = 0; j < 4; j++)
						CPU.mem[CPU.psw.IP++] = value.byte[j];
				break;
			case ADDRESS_TAG:
				if (stream.read((char *)value.address, 2))
					CPU.psw.IP = value.address[0];
				break;
			default:
				/*throw exception();*/ 
				break;
			}
}
int main(int argc, const char *argv[])
{	CPU_VM cpu;
	loader(cpu, argv[1]);
	cpu.exec();
}