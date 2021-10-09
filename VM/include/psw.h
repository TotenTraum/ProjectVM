#pragma once
#include <cstdint>


class PSW
{
public:
    PSW():IP(0){}

    void resetFlags();

    void changeIP(uint16_t address);

    uint16_t getIP();

    struct Flags
    {
        uint16_t CF:1;   //Carry flag
        uint16_t PF:1;   //Parity flag
        uint16_t ZF:1;   //Zero flag
        uint16_t SF:1;   //Sign flag
        uint16_t OF:1;   //Overflow flag
        uint16_t WF:1;   //Wait flag
    };
    Flags flags;
    uint16_t IP;
};