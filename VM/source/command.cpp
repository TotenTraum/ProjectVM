#include "../include/command.h"

void IncCommand::operator()()
{
    (registers->Adder.Integer)++;

}

void IncFloatCommand::operator()()
{
    (registers->Adder.Float)++;

}

void AddCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    registers->Adder.Integer += tmp.Integer;

}

void SubCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    registers->Adder.Integer -= tmp.Integer;
}

void MulCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    registers->Adder.Integer *= tmp.Integer;
}

void DivCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    registers->Adder.Integer /= tmp.Integer;
}

void AddFloatCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    registers->Adder.Float += tmp.Float;
}

void SubFloatCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    registers->Adder.Float -= tmp.Float;
}

void MulFloatCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    registers->Adder.Float *= tmp.Float;
}

void DivFloatCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    registers->Adder.Float /= tmp.Float;
}

void ReadFloatCommand::operator()()
{
    types tmp;
    std::cin>>tmp.Float;
    memory->loadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
}

void ReadCommand::operator()()
{
    types tmp;
    std::cin>>tmp.Integer;
    memory->loadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
}

void PrintCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    std::cout<<tmp.Integer<<std::endl;
}

void PrintFloatCommand::operator()()
{
    types tmp;
    memory->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    std::cout<<tmp.Float<<std::endl;
}

void FloatToIntegerCommand::operator()()
{
    registers->Adder.Integer = registers->Adder.Float;
}

void IntegerToFloatCommand::operator()()
{
    registers->Adder.Float = registers->Adder.Integer;
}

void JECommand::operator()()
{
    if(psw->getFlag(ZF))
        psw->changeIP(address);
}

void JNECommand::operator()()
{
    if(!psw->getFlag(ZF))
        psw->changeIP(address);
}

void JLCommand::operator()()
{
    if(psw->getFlag(SF) != psw->getFlag(OF))
        psw->changeIP(address);
}

void JLECommand::operator()()
{
    if(psw->getFlag(SF) != psw->getFlag(OF) || psw->getFlag(ZF))
        psw->changeIP(address);
}

void JGCommand::operator()()
{
    if(psw->getFlag(SF) == psw->getFlag(OF))
        psw->changeIP(address);
}

void JGECommand::operator()()
{
    if(psw->getFlag(SF) == psw->getFlag(OF) || psw->getFlag(ZF))
        psw->changeIP(address);
}

void JumpCommand::operator()()
{
    psw->changeIP(address);
}

void CallCommand::operator()()
{
    registers->BP = psw->getIP();
    psw->changeIP(address);
}

void RtnCommand::operator()()
{
    psw->changeIP(registers->BP);
}

void CmpCommand::operator()()
{
    int32_t tmp1,tmp2,tmp3;
    memory->unloadMemory(registers->BP,(char*)&tmp1,sizeof(tmp1));
    memory->unloadMemory(address,(char*)&tmp2,sizeof(tmp2));
    if(((tmp1>>30)&1) && ((tmp2>>30)&1))
        psw->setFlag(CF);
    if(psw->getFlag(CF) || ((tmp1>>31)&1) && ((tmp2>>31)&1))
        psw->setFlag(OF);
    tmp3=tmp1-tmp2;
    if(tmp3>>31)
        psw->setFlag(SF);
    if(tmp3)
        psw->setFlag(ZF);
    if(tmp3&1)
        psw->setFlag(PF);
}

void CmpFloatCommand::operator()()
{
    
}

void JZCommand::operator()()
{
    if(psw->getFlag(ZF))
        psw->changeIP(address);
}

void JSCommand::operator()()
{
    if(psw->getFlag(SF))
        psw->changeIP(address);
}

void JCCommand::operator()()
{
    if(psw->getFlag(CF))
        psw->changeIP(address);
}

void JOCommand::operator()()
{
    if(psw->getFlag(OF))
        psw->changeIP(address);
}

void JPCommand::operator()()
{
    if(psw->getFlag(PF))
        psw->changeIP(address);
}

void JNZCommand::operator()()
{
    if(!psw->getFlag(ZF))
        psw->changeIP(address);
}

void JNSCommand::operator()()
{
    if(!psw->getFlag(SF))
        psw->changeIP(address);
}

void JNCCommand::operator()()
{
    if(!psw->getFlag(CF))
        psw->changeIP(address);
}

void JNOCommand::operator()()
{
    if(!psw->getFlag(OF))
        psw->changeIP(address);
}

void JNPCommand::operator()()
{
    if(!psw->getFlag(PF))
        psw->changeIP(address);
}

void LeaCommand::operator()()
{
    registers->BP = address;
}

void SaveAdderCommand::operator()()
{
    memory->loadMemory(address,(char*)&(registers->Adder.Integer),sizeof(registers->Adder.Integer));
}

void LoadAdderCommand::operator()()
{
    memory->unloadMemory(address,(char*)&(registers->Adder.Integer),sizeof(registers->Adder.Integer));
}

void SaveAdderFloatCommand::operator()()
{
    memory->loadMemory(address,(char*)&(registers->Adder.Float),sizeof(registers->Adder.Float));
}

void LoadAdderFloatCommand::operator()()
{
    memory->unloadMemory(address,(char*)&(registers->Adder.Float),sizeof(registers->Adder.Float));
}

void MovCommand::operator()()
{
    memory->copyMemory(address,registers->BP,4);
}
