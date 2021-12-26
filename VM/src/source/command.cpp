#include "../include/command.h"
#include "../include/cpu.h"

address_t CommandCPU::getArg(){return CPU->currentCommand.cmd.arg;}
PSW::Flags& CommandCPU::Flags(){return CPU->psw.flags;}
address_t CommandCPU::getIP(){return CPU->psw.IP;}
void CommandCPU::setIP(const address_t& arg){CPU->psw.IP = arg;}
data_t& CommandCPU::Adder(){return CPU->Adder;}
address_t CommandCPU::getBP(){return CPU->BP;}
void CommandCPU::setBP(const address_t& arg){CPU->BP = arg;}
data_t& CommandCPU::readDWORD(data_t& DWORD)
{   for(int i = 0; i<4;i++)
        DWORD.byte[i] = CPU->mem[getArg()+i];
    return DWORD;
}
void CommandCPU::writeDWORD(const data_t& DWORD)
{   for(int i = 0; i<4;i++)
        CPU->mem[getArg()+i] = DWORD.byte[i];
}
void CommandCPU::setCPU(CPU_VM* cpuArg){CPU = cpuArg;}