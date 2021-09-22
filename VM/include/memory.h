#pragma once
#include <cstdint>
#include <iostream>
#include "types.h"

#define BYTE int8_t

const int SizeMemory = 65536;

class Memory
{
public:
    //write in memory
    void loadMemory(const size_t &address,char* value,size_t size);
    //read from memory
    void unloadMemory(const size_t &address,char* value,size_t size) const;

    void copyMemory(const size_t &from,const size_t &to,size_t size);

    void printMemory(uint16_t maxAddress) const;

    void printMemory(uint16_t minAddress, uint16_t maxAdress) const;

private:
    BYTE segment[SizeMemory]; 
};