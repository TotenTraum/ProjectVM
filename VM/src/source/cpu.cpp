#include "../include/cpu.h"
#include "../include/command.h"
#include "../include/ArifmeticCommand.h"
#include "../include/jumpCommands.h"
#include "../include/TransferCommands.h"

void CPU_VM::reset()
{   psw.resetFlags();
    Adder.Integer = 0;
    BP = 0;
}
void CPU_VM::loadInstruction()
{   for(int i=0;i<3;i++)
        currentCommand.byte[i] = mem[psw.IP++];
    if(currentCommand.cmd.b)
        {   if(currentCommand.cmd.code<CALL)
                currentCommand.cmd.arg+=BP;
            else
                currentCommand.cmd.arg+=psw.IP;
        }
}
void CPU_VM::trapFlagHandler()
{   using namespace std;
    cout<<endl<<setw(5)<<+psw.IP<<hex<<
    setw(4)<<+(currentCommand.cmd.code)<<dec<<":";
    mem.printMemory(currentCommand.cmd.arg,currentCommand.cmd.arg+4);
    cout<<endl;
    char ch;
    address_t left,right;
    while(psw.flags.TF)
    {   cout<<"TFHandler << ";
        cin >> ch;
        switch (ch)
        {case 'p':
            cout<<hex<<"adder :"<<+Adder.byte[0]<<' '<<+Adder.byte[1]<<' '<<
                              +Adder.byte[2]<<' '<<+Adder.byte[3]<<dec<<endl;
            cout<<"BP :"<<BP<<endl;
            cout<<"psw{\n"<<"\tZF = "<<psw.flags.ZF<<endl;
            cout<<"\tOF = "<<psw.flags.OF<<endl;
            cout<<"\tSF = "<<psw.flags.SF<<endl<<"}\n";                
            continue;
        case 'n':
            break;
        case 'm':
            cout<<"input left and right border"; cin>>left>>right;
            mem.printMemory(left,right);
            cout<<endl;
            continue;
        case 'h':
            cout<<"n - переход к след.команде,p - вывод adder,BP и psw,m - вывод памяти [l,r]\n";
            continue;
        case 'c':
            cout<<"COP :"<<+currentCommand.cmd.code<<endl<<"b :"<<+currentCommand.cmd.b<<endl
                <<"arg :"<<currentCommand.cmd.arg<<endl;
            continue;
        default:
            continue;
        }
        break;
    }
}
void CPU_VM::exec() 
{   loadInstruction();
    while(currentCommand.cmd.code!= STOP)
    {   if(psw.flags.TF)
            trapFlagHandler();
        Commands[currentCommand.cmd.code]->operator()();
        loadInstruction();
    }
}
void CPU_VM::InitCommand()
{   CommandCPU::setCPU(this);
    Commands[STOP] = new StopCommand();
    Commands[INC] = new IncCommand();       Commands[INCF] = new IncFloatCommand();
    Commands[DEC] = new DecCommand();       Commands[DECF] = new DecFloatCommand();
    Commands[ADD] = new AddCommand();       Commands[ADDF] = new AddFloatCommand();
    Commands[SUB] = new SubCommand();       Commands[SUBF] = new SubFloatCommand();
    Commands[MUL] = new MulCommand();       Commands[MULF] = new MulFloatCommand();
    Commands[DIV] = new DivCommand();       Commands[DIVF] = new DivFloatCommand();
    Commands[OR] = new OrCommand();         Commands[AND] = new AndCommand();
    Commands[XOR] = new XorCommand();
    Commands[NOT] = new NotCommand();
    Commands[SAL] = new SALCommand();       Commands[SAR] = new SARCommand();
    Commands[LEA] = new LeaCommand();
    Commands[MOV] = new MovCommand();
    Commands[I2F] = new IntToFloatCommand();
    Commands[F2I] = new FloatToIntCommand();
    Commands[INPUT] = new InputCommand();    Commands[INPUTF] = new InputFCommand();
    Commands[OUTPUT] = new OutputCommand();  Commands[OUTPUTF] = new OutputFCommand();
    Commands[SAVE] = new SaveCommand();      Commands[LOAD] = new LoadCommand();
    Commands[CMP] = new CmpCommand();        Commands[CMPF] = new CmpFloatCommand();
    Commands[CALL] = new CallCommand();      Commands[RTN] = new RtnCommand();
    Commands[JUMP] = new JumpCommand();
    Commands[JE] = new JECommand();          Commands[JNE] = new JNECommand();
    Commands[JL] = new JLCommand();          Commands[JLE] = new JLECommand();
    Commands[JG] = new JGCommand();          Commands[JGE] = new JGECommand();
    Commands[JS] = new JSCommand();          Commands[JNS] = new JNSCommand();
    Commands[JO] = new JOCommand();          Commands[JNO] = new JNOCommand();
    Commands[STT] = new STTCommand();          Commands[CLT] = new CLTCommand();
    for(int i = 46; i < 128; i++) Commands[i] = new EmptyCommand();
}