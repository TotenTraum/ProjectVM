#include "../include/command.h"

void IncCommand::operator()()
{
    (Adder->Integer)++;

}

void IncFloatCommand::operator()()
{
    (Adder->Float)++;

}

void AddCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    ADDER->Integer += tmp.Integer;

}

void SubCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    ADDER->Integer -= tmp.Integer;
}

void MulCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    ADDER->Integer *= tmp.Integer;
}

void DivCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    ADDER->Integer /= tmp.Integer;
}

void AddFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    ADDER->Float += tmp.Float;
}

void SubFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    ADDER->Float -= tmp.Float;
}

void MulFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    ADDER->Float *= tmp.Float;
}

void DivFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    ADDER->Float /= tmp.Float;
}

void ReadFloatCommand::operator()()
{
    types tmp;
    std::cin>>tmp.Float;
    mem->loadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
}

void ReadCommand::operator()()
{
    types tmp;
    std::cin>>tmp.Integer;
    mem->loadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
}

void PrintCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Integer,sizeof(tmp.Integer));
    std::cout<<tmp.Integer<<std::endl;
}

void PrintFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address,(char*)&tmp.Float,sizeof(tmp.Float));
    std::cout<<tmp.Float<<std::endl;
}

void FloatToIntegerCommand::operator()()
{
    Adder->Integer = Adder->Float;
    std::cout<<Adder->Integer<<std::endl;
}

void IntegerToFloatCommand::operator()()
{
    Adder->Float = Adder->Integer;
    std::cout<<Adder->Float<<"  "<<"this"<<std::endl;
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
    reg->BP = psw->getIP();
    psw->changeIP(address);
}

void RtnCommand::operator()()
{
    psw->changeIP(reg->BP);
}

void CmpCommand::operator()()
{
    int32_t tmp1,tmp2,tmp3;
    mem->unloadMemory(reg->BP,(char*)&tmp1,sizeof(tmp1));
    mem->unloadMemory(address,(char*)&tmp2,sizeof(tmp2));
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
    reg->BP = address;
}

void SaveAdderCommand::operator()()
{
    mem->loadMemory(address,(char*)&(Adder->Integer),sizeof(Adder->Integer));
}

void LoadAdderCommand::operator()()
{
    mem->unloadMemory(address,(char*)&(Adder->Integer),sizeof(Adder->Integer));
}

void SaveAdderFloatCommand::operator()()
{
    mem->loadMemory(address,(char*)&(Adder->Float),sizeof(Adder->Float));
}

void LoadAdderFloatCommand::operator()()
{
    mem->unloadMemory(address,(char*)&(Adder->Float),sizeof(Adder->Float));
}

void MovCommand::operator()()
{
    mem->copyMemory(address,reg->BP,4);
}
