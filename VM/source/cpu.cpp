#include "../include/cpu.h"

void CPU_VM::reset()
{
    psw.resetFlags();
    psw.IP = 0;
    Adder.Integer = 0;
    BP.address = 0;
}

void CPU_VM::exec() 
{
    while(!psw.flags.WF)
    {
        instruction tmp;
        mem.unloadMemory(psw.getIP(),(char*)&tmp,sizeof(tmp));
        psw.changeIP(psw.getIP()+3);
        if(tmp.code >= 128) tmp.address+=BP.Integer;
        CommandAddress::setAddress(tmp.address);
        Commands[tmp.code&127]->operator()();
    }
}

void CPU_VM::InitCommand()
{   
    CommandPSW::setPSW(&psw);
    CommandMem::setMemory(&mem);
    CommandBP::setBP(&BP);
    CommandAdder::setAdder(&Adder);
    Commands[0x00] = new StopCommand();
    Commands[0x01] = new IncCommand();
    Commands[0x02] = new IncFloatCommand();
    Commands[0x03] = new AddCommand();
    Commands[0x04] = new AddFloatCommand();
    Commands[0x05] = new SubCommand();
    Commands[0x06] = new SubFloatCommand();
    Commands[0x07] = new MulCommand();
    Commands[0x08] = new MulFloatCommand();
    Commands[0x09] = new DivCommand();
    Commands[0x0a] = new DivFloatCommand();
    Commands[0x0b] = new OrCommand();
    Commands[0x0c] = new AndCommand();
    Commands[0x0d] = new XorCommand();
    Commands[0x0e] = new NotCommand();
    Commands[0x0f] = new SHLCommand();
    Commands[0x10] = new SHRCommand();
    Commands[0x11] = new LeaCommand();
    Commands[0x12] = new MovCommand();
    Commands[0x13] = new IntegerToFloatCommand();
    Commands[0x14] = new FloatToIntegerCommand();
    Commands[0x15] = new ReadCommand();
    Commands[0x16] = new ReadFloatCommand();
    Commands[0x17] = new PrintCommand();
    Commands[0x18] = new PrintFloatCommand();
    Commands[0x19] = new SaveAdderCommand();
    Commands[0x1a] = new SaveAdderFloatCommand();
    Commands[0x1b] = new LoadAdderCommand();
    Commands[0x1c] = new LoadAdderFloatCommand();
    Commands[0x1d] = new CmpCommand();
    Commands[0x1e] = new CmpFloatCommand();
    Commands[0x1f] = new CallCommand();
    Commands[0x20] = new RtnCommand();
    Commands[0x21] = new JumpCommand();
    Commands[0x22] = new JECommand();
    Commands[0x23] = new JNECommand();
    Commands[0x24] = new JLCommand();
    Commands[0x25] = new JLECommand();
    Commands[0x26] = new JGCommand();
    Commands[0x27] = new JGECommand();
    Commands[0x28] = new JSCommand();
    Commands[0x29] = new JCCommand();
    Commands[0x2a] = new JOCommand();
    Commands[0x2b] = new JPCommand();
    Commands[0x2c] = new JNSCommand();
    Commands[0x2d] = new JNCCommand();
    Commands[0x2e] = new JNOCommand();
    Commands[0x2f] = new JNPCommand();
    for(int i = 48; i < 128; i++)
        Commands[i] = new EmptyCommand();
}