#include "../include/command.h"

void IncCommand::operator()(){(Adder->Integer)++;}

void IncFloatCommand::operator()(){(Adder->Float)++;}

void AddCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer += tmp.Integer;
}
void AddFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
    Adder->Float += tmp.Float;
}

void SubCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer -= tmp.Integer;
}
void SubFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
    Adder->Float -= tmp.Float;
}

void MulCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer *= tmp.Integer;
}
void MulFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
    Adder->Float *= tmp.Float;
}

void DivCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer /= tmp.Integer;
}
void DivFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
    Adder->Float /= tmp.Float;
}

void OrCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer |= tmp.Integer;
}

void AndCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer &= tmp.Integer;
}

void XorCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer ^= tmp.Integer;
}

void NotCommand::operator()()
{
    Adder->Integer = ~Adder->Integer;
}

void SHLCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer <<= tmp.Integer;
}

void SHRCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    Adder->Integer >>= tmp.Integer;
}
void ReadCommand::operator()()
{
    types tmp;
    std::cin >> tmp.Integer;
    mem->loadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
}
void ReadFloatCommand::operator()()
{
    types tmp;
    std::cin >> tmp.Float;
    mem->loadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
}

void PrintCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Integer, sizeof(tmp.Integer));
    std::cout << tmp.Integer << std::endl;
}
void PrintFloatCommand::operator()()
{
    types tmp;
    mem->unloadMemory(address, (char *)&tmp.Float, sizeof(tmp.Float));
    std::cout << tmp.Float << std::endl;
}

void FloatToIntegerCommand::operator()()
{
    Adder->Integer = Adder->Float;
}

void IntegerToFloatCommand::operator()()
{
    Adder->Float = Adder->Integer;
}

void JECommand::operator()()
{
    if (psw->flags.ZF) psw->changeIP(address);
}

void JNECommand::operator()()
{
    if (!psw->flags.ZF) psw->changeIP(address);
}

void JLCommand::operator()()
{
    if (psw->flags.SF != psw->flags.OF) psw->changeIP(address);
}

void JLECommand::operator()()
{
    if (psw->flags.SF != psw->flags.OF || psw->flags.ZF) psw->changeIP(address);
}

void JGCommand::operator()()
{
    if (psw->flags.SF == psw->flags.OF) psw->changeIP(address);
}

void JGECommand::operator()()
{
    if (psw->flags.SF == psw->flags.OF || psw->flags.ZF) psw->changeIP(address);
}

void JumpCommand::operator()() {psw->changeIP(address);}

void CallCommand::operator()()
{
    BP->address = psw->getIP();
    psw->changeIP(address);
}

void RtnCommand::operator()() {psw->changeIP(BP->address);}

void CmpCommand::operator()()
{
    int32_t tmp1, tmp2;
    mem->unloadMemory(BP->address, (char *)&tmp1, sizeof(tmp1));
    mem->unloadMemory(address, (char *)&tmp2, sizeof(tmp2));
    if (((tmp1 >> 30) & 1) && ((tmp2 >> 30) & 1))
        psw->flags.CF = 1;
    if (psw->flags.CF || (((tmp1 >> 31) & 1) && ((tmp2 >> 31) & 1)))
        psw->flags.OF = 1;
    tmp1 = tmp1 - tmp2;
    if (tmp1 >> 31) psw->flags.SF = 1;
    if (!tmp1)      psw->flags.ZF = 1;
    if (tmp1 & 1)   psw->flags.PF = 1;
}

void CmpFloatCommand::operator()()
{
    int32_t tmp1,tmp2;
    mem->unloadMemory(BP->address, (char *)&tmp1, sizeof(tmp1));
    mem->unloadMemory(address, (char *)&tmp2, sizeof(tmp2));
    if(!tmp1^tmp2)
        psw->flags.ZF = 1;
}

void JSCommand::operator()()
{
    if (psw->flags.SF) psw->changeIP(address);
}

void JCCommand::operator()()
{
    if (psw->flags.CF) psw->changeIP(address);
}

void JOCommand::operator()()
{
    if (psw->flags.OF) psw->changeIP(address);
}

void JPCommand::operator()()
{
    if (psw->flags.PF) psw->changeIP(address);
}

void JNSCommand::operator()()
{
    if (!psw->flags.SF) psw->changeIP(address);
}

void JNCCommand::operator()()
{
    if (!psw->flags.CF) psw->changeIP(address);
}

void JNOCommand::operator()()
{
    if (!psw->flags.OF) psw->changeIP(address);
}

void JNPCommand::operator()()
{
    if (!psw->flags.PF) psw->changeIP(address);
}

void LeaCommand::operator()()
{
    BP->address = address;
}

void SaveAdderCommand::operator()()
{
    mem->loadMemory(address, (char *)&(Adder->Integer), sizeof(Adder->Integer));
}

void LoadAdderCommand::operator()()
{
    mem->unloadMemory(address, (char *)&(Adder->Integer), sizeof(Adder->Integer));
}

void SaveAdderFloatCommand::operator()()
{
    mem->loadMemory(address, (char *)&(Adder->Float), sizeof(Adder->Float));
}

void LoadAdderFloatCommand::operator()()
{
    mem->unloadMemory(address, (char *)&(Adder->Float), sizeof(Adder->Float));
}

void MovCommand::operator()()
{
    int32_t tmp;
    mem->unloadMemory(address, (char *)&tmp, sizeof(tmp));
    mem->loadMemory(BP->address, (char *)&tmp, sizeof(tmp));
}