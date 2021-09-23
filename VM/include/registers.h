#pragma once
#include "types.h"

struct Registers
{
    //Data segment
    uint16_t DS;
    //Code segment
    uint16_t CS;
    //Base pointer
    uint16_t BP;
    //Source Index
    uint16_t SI;
    //Destination Index
    uint16_t DI;

    types Adder;
};