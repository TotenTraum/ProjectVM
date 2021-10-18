#include "../include/command.h"
#include "../include/cpu.h"

void CallCommand::operator()()
{   CPU->BP.address[1] = CPU->psw.IP;
    CPU->psw.IP = getAddress();
}
void RtnCommand::operator()() {CPU->psw.IP = CPU->BP.address[1];}

void JumpCommand::operator()() {CPU->psw.IP = getAddress();}
void JECommand::operator()(){if (CPU->psw.ZF) CPU->psw.IP = getAddress();}
void JNECommand::operator()(){if (!CPU->psw.ZF) CPU->psw.IP = getAddress();}
void JLCommand::operator()(){if (CPU->psw.SF != CPU->psw.OF) CPU->psw.IP = getAddress();}
void JLECommand::operator()(){if (CPU->psw.SF != CPU->psw.OF || CPU->psw.ZF) CPU->psw.IP = getAddress();}
void JGCommand::operator()(){if (CPU->psw.SF == CPU->psw.OF && !CPU->psw.ZF) CPU->psw.IP = getAddress();}
void JGECommand::operator()(){if (CPU->psw.SF == CPU->psw.OF) CPU->psw.IP = getAddress();}
void JSCommand::operator()(){if (CPU->psw.SF) CPU->psw.IP = getAddress();}
void JOCommand::operator()(){if (CPU->psw.OF) CPU->psw.IP = getAddress();}
void JNSCommand::operator()(){if (!CPU->psw.SF) CPU->psw.IP = getAddress();}
void JNOCommand::operator()(){if (!CPU->psw.OF) CPU->psw.IP = getAddress();}