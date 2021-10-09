#include "../include/psw.h"

void PSW::resetFlags()
{
    flags = Flags();
}

void PSW::changeIP(uint16_t address)
{
    IP = address;
}

uint16_t PSW::getIP()
{
    return IP;
}