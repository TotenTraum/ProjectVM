#include "../include/command.h"
#include "../include/cpu.h"

void IncCommand::operator()(){(CPU->Adder.Integer)++;}
void IncFloatCommand::operator()(){(CPU->Adder.Float)++;}
void DecCommand::operator()(){(CPU->Adder.Integer)--;}
void DecFloatCommand::operator()(){(CPU->Adder.Float)--;}
void AddCommand::operator()()
{    data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer += tmp.Integer;
}
void AddFloatCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Float += tmp.Float;
}
void SubCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer -= tmp.Integer;
}
void SubFloatCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Float -= tmp.Float;
}
void MulCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer *= tmp.Integer;
}
void MulFloatCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Float *= tmp.Float;
}
void DivCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer /= tmp.Integer;
}
void DivFloatCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Float /= tmp.Float;
}
void OrCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer |= tmp.Integer;
}
void AndCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer &= tmp.Integer;
}
void XorCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer ^= tmp.Integer;
}
void NotCommand::operator()(){CPU->Adder.Integer = ~CPU->Adder.Integer;}
void SHLCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer <<= tmp.Integer;
}
void SHRCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    CPU->Adder.Integer >>= tmp.Integer;
}