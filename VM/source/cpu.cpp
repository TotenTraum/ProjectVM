#include "../include/cpu.h"
#include "../include/command.h"

void CPU_VM::reset()
{   psw.resetFlags();
    psw.IP = 0;
    Adder.Integer = 0;
    BP.Integer = 0;
}
void CPU_VM::readDWORD(data& arg)
{   for(int i = 0; i<4;i++)
        arg.byte[i] = mem[currentCommand.address+i];
}
void CPU_VM::writeDWORD(data& arg)
{   for(int i = 0; i<4;i++)
        mem[currentCommand.address+i] = arg.byte[i];
}
void CPU_VM::exec() 
{   while(!psw.flags.WF)
    {
        psw.flags.TF = 1;
        currentCommand.code = (opcode)mem[psw.IP];
        currentCommand.address = mem[psw.IP+1];
		currentCommand.address += mem[psw.IP+2]<<8;
        psw.IP +=3;
        if(currentCommand.code & 128)
        {   if((int)((currentCommand.code&127)-CALL)<0)
                currentCommand.address+=BP.Integer;
            else
                currentCommand.address+=psw.IP;
        }
        while(psw.flags.TF)
        {   using namespace std;
            cout<<endl<<setw(5)<<+psw.IP/3<<hex<<
            setw(4)<<+(currentCommand.code)<<dec<<":";
            mem.printMemory(150,162);
            cout<<endl;
            break;
        }
        Commands[currentCommand.code&127]->operator()();
    }
}
void CPU_VM::InitCommand()
{   CommandCPU::setCPU(this);
    Commands[STOP] = new StopCommand();
    Commands[INC] = new IncCommand();  Commands[INCF] = new IncFloatCommand();
    Commands[DEC] = new DecCommand();  Commands[DECF] = new DecFloatCommand();
    Commands[ADD] = new AddCommand();  Commands[ADDF] = new AddFloatCommand();
    Commands[SUB] = new SubCommand();  Commands[SUBF] = new SubFloatCommand();
    Commands[MUL] = new MulCommand();  Commands[MULF] = new MulFloatCommand();
    Commands[DIV] = new DivCommand();  Commands[DIVF] = new DivFloatCommand();
    Commands[OR] = new OrCommand();    Commands[AND] = new AndCommand();
    Commands[XOR] = new XorCommand();
    Commands[NOT] = new NotCommand();
    Commands[SHL] = new SHLCommand();  Commands[SHR] = new SHRCommand();
    Commands[LEA] = new LeaCommand();
    Commands[MOV] = new MovCommand();
    Commands[I2F] = new IntegerToFloatCommand();
    Commands[F2I] = new FloatToIntegerCommand();
    Commands[INPUT] = new InputCommand();    Commands[INPUTF] = new InputFCommand();
    Commands[OUTPUT] = new OutputCommand();  Commands[OUTPUTF] = new OutputFCommand();
    Commands[SAVE] = new SaveCommand(); Commands[LOAD] = new LoadCommand();
    Commands[CMP] = new CmpCommand();   Commands[CMPF] = new CmpFloatCommand();
    Commands[CALL] = new CallCommand(); Commands[RTN] = new RtnCommand();
    Commands[JUMP] = new JumpCommand();
    Commands[JE] = new JECommand();     Commands[JNE] = new JNECommand();
    Commands[JL] = new JLCommand();     Commands[JLE] = new JLECommand();
    Commands[JG] = new JGCommand();     Commands[JGE] = new JGECommand();
    Commands[JS] = new JSCommand();     Commands[JNS] = new JNSCommand();
    Commands[JO] = new JOCommand();     Commands[JNO] = new JNOCommand();
    for(int i = 44; i < 128; i++) Commands[i] = new EmptyCommand();
}