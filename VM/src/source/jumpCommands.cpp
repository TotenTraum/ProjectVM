#include "../include/jumpCommands.h"
#include "../include/cpu.h"

void CallCommand::operator()()
{   setBP(getIP());
    setIP(getArg());
}
void RtnCommand::operator()() {setIP(getBP());}
void JumpCommand::operator()() {setIP(getArg());}
void JECommand::operator()(){if (Flags().ZF) setIP(getArg());}
void JNECommand::operator()(){if (!Flags().ZF) setIP(getArg());}
void JLCommand::operator()(){if (Flags().SF != Flags().OF) setIP(getArg());}
void JLECommand::operator()(){if (Flags().SF != Flags().OF || Flags().ZF) setIP(getArg());}
void JGCommand::operator()(){if (Flags().SF == Flags().OF && !Flags().ZF) setIP(getArg());}
void JGECommand::operator()(){if (Flags().SF == Flags().OF || Flags().ZF) setIP(getArg());}
void JSCommand::operator()(){if (Flags().SF) setIP(getArg());}
void JOCommand::operator()(){if (Flags().OF) setIP(getArg());}
void JNSCommand::operator()(){if (!Flags().SF) setIP(getArg());}
void JNOCommand::operator()(){if (!Flags().OF) setIP(getArg());}