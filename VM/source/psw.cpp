#include "../include/psw.h"

void PSW::resetFlags()
{
    flags.resetFlags();
}
    
void PSW::setFlag(NameOfFlags name)
{
    flags.setFlag(name);
}

void PSW::unsetFlag(NameOfFlags name)
{
    flags.unsetFlag(name);
}

bool PSW::getFlag(NameOfFlags name)
{
    flags.getFlag(name);
}

void PSW::changeIP(uint16_t address)
{
    IP = address;
}

uint16_t PSW::getIP()
{
    return IP;
}