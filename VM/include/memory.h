#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "types.h"

class Memory final
{
public:
    Memory(){segment = new byte_t[65536];}
    ~Memory(){delete[] segment;}

    void printMemory(uint16_t maxAddress) const;
    void printMemory(uint16_t minAddress, uint16_t maxAdress) const;
    void printMemory(const char* fileName) const;

    byte_t& operator[](uint16_t address){return segment[address];}
private:
    byte_t* segment; 
};