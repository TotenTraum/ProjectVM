#include "../include/TransferCommands.h"
#include "../include/cpu.h"

void InputCommand::operator()()
{   data_t tmp;
    std::cin >> tmp.Integer;
    writeDWORD(tmp);
}
void InputFCommand::operator()()
{   data_t tmp;
    std::cin >> tmp.Float;
    writeDWORD(tmp);
}
void OutputCommand::operator()()
{   data_t tmp;
    std::cout << readDWORD(tmp).Integer << std::endl;
}
void OutputFCommand::operator()()
{   data_t tmp;
    std::cout << readDWORD(tmp).Float << std::endl;
}
void FloatToIntCommand::operator()(){Adder().Integer = Adder().Float;}
void IntToFloatCommand::operator()(){Adder().Float = Adder().Integer;}
void LeaCommand::operator()(){setBP(getArg());}
void SaveCommand::operator()(){writeDWORD(Adder());}
void LoadCommand::operator()(){readDWORD(Adder());}
void MovCommand::operator()()
{   address_t BP = getBP(),arg = getArg();
    for(int i = 0; i<4;i++)
        CPU->mem[BP+i] = CPU->mem[arg+i];
}