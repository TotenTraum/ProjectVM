#pragma once
#include "flags.h"

class PSW
{
public:
    PSW():IP(0){}

    void resetFlags();
    
    void setFlag(NameOfFlags name);

    void unsetFlag(NameOfFlags name);

    bool getFlag(NameOfFlags name);

    void changeIP(uint16_t address);

    uint16_t getIP();
private:    
uint16_t IP;
Flags flags;
};