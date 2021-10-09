#pragma once
#include <iostream>
#include "types.h"

class Memory
{
public:
    Memory():maxSize(UINT16_MAX)
    {
        segment = new BYTE[maxSize];
    }

    Memory(uint16_t size):maxSize(size)
    {
        segment = new BYTE[maxSize];
    }

    ~Memory()
    {
        delete[] segment;
    }

    //write in memory
    void loadMemory(const uint16_t &address,char* value,size_t size);
    //read from memory
    void unloadMemory(const uint16_t &address,char* value,size_t size) const;

    void printMemory(uint16_t maxAddress) const;

    void printMemory(uint16_t minAddress, uint16_t maxAdress) const;

private:
    BYTE* segment; 
    uint16_t maxSize;
};