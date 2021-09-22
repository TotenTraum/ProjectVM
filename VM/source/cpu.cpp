#include "../include/cpu.h"

void CPU_VM::loadCommand()
{
    delete currentCommand;
    instruction tmp;
    mem.unloadMemory(psw.getIP(),(char*)&tmp,sizeof(tmp));
    psw.changeIP(psw.getIP()+3);
    currentCommand = fabric->make(tmp);
}

void CPU_VM::exec() {
    currentCommand->operator()();
}