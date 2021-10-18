#include "../include/command.h"
#include "../include/cpu.h"

address_t CommandCPU::getAddress(){return CPU->currentCommand.address;}
PSW::Flags& CommandCPU::getFlags(){return CPU->psw.flags;}
void CommandCPU::setCPU(CPU_VM* cpuArg){CPU = cpuArg;}
void StopCommand::operator()(){CPU->psw.flags.WF=1;}
void InputCommand::operator()()
{   data tmp;
    std::cin >> tmp.Integer;
    CPU->writeDWORD(tmp);
}
void InputFCommand::operator()()
{   data tmp;
    std::cin >> tmp.Float;
    CPU->writeDWORD(tmp);
}
void OutputCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    std::cout << tmp.Integer << std::endl;
}
void OutputFCommand::operator()()
{   data tmp;
    CPU->readDWORD(tmp);
    std::cout << tmp.Float << std::endl;
}
void FloatToIntegerCommand::operator()(){CPU->Adder.Integer = CPU->Adder.Float;}
void IntegerToFloatCommand::operator()(){CPU->Adder.Float = CPU->Adder.Integer;}
void CmpCommand::operator()()
{   data tmp1 = CPU->Adder, tmp2;
    CPU->readDWORD(tmp2);
    if(tmp1.Integer==tmp2.Integer)
        getFlags().ZF=1;
    else if(tmp1.Integer<tmp2.Integer)
        getFlags().SF=1;
    bool signResult = (tmp1.Integer<0)!=(tmp1.Integer+tmp2.Integer<0);
    getFlags().OF = ((tmp1.Integer<0)==(tmp2.Integer <0) && signResult);
}
void CmpFloatCommand::operator()()
{   data tmp1 = CPU->Adder,tmp2;
    CPU->readDWORD(tmp2);
    if(tmp1.Float==tmp2.Float)
        getFlags().ZF=1;
    else if(tmp1.Float<tmp2.Float)
        getFlags().SF=1;
    bool signResult = (tmp1.Float<0)!=(tmp1.Float+tmp2.Float<0);
    getFlags().OF = ((tmp1.Float<0)==(tmp2.Float <0) && signResult);
}
void LeaCommand::operator()(){CPU->BP.address[0] = getAddress();}
void SaveCommand::operator()(){CPU->writeDWORD(CPU->Adder);}
void LoadCommand::operator()(){CPU->readDWORD(CPU->Adder);}
void MovCommand::operator()()
{   for(int i = 0; i<4;i++)
        CPU->mem[CPU->BP.address[0]+i] = CPU->mem[getAddress()+i];
}