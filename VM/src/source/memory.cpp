#include "../include/memory.h"
using namespace std;

void Memory::printMemory(uint16_t maxAddress) const{printMemory(0,maxAddress);}

void Memory::printMemory(uint16_t minAddress, uint16_t maxAddress) const
{   if(minAddress<maxAddress)
    {   cout<<setfill('0')<<hex;
        for(int i = minAddress;i<maxAddress;i++)
            cout<<setw(2)<<static_cast<int>(segment[i])<<" ";
        cout<<setfill(' ')<<dec;
    }
}