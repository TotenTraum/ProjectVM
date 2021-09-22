#include "../include/memory.h"

    //write in memory
    void Memory::loadMemory(const size_t &address,char* value,size_t size)
    {
        for(int i = 0 ; i< size;i++)
        {
            segment[address+i]=value[i];
        }
    }
    //read from memory
    void Memory::unloadMemory(const size_t &address,char* value,size_t size) const
    {
        for(int i = 0 ; i< size;i++)
        {
            value[i]=segment[address+i];

        }
    }

    void Memory::copyMemory(const size_t &from,const size_t &to,size_t size)
    {
        for(int i = 0 ; i< size;i++)
        {
            segment[to+i]=segment[from+i];
        }
    }

    void Memory::printMemory(uint16_t maxAddress) const
    {
        for(int i = 0;i<maxAddress;i++)
            std::cout<<std::hex<<+segment[i]<<" ";
        std::cout<<std::dec;
    }

    void Memory::printMemory(uint16_t minAddress, uint16_t maxAddress) const
    {
        if(minAddress<maxAddress)
        {
            for(int i = minAddress;i<maxAddress;i++)
                std::cout<<std::hex<<+segment[i]<<" ";
            std::cout<<std::dec;
        }
    }