#include "../include/memory.h"
using namespace std;

void Memory::printMemory(uint16_t maxAddress, uint16_t minAddress=0) const
{   if(minAddress<maxAddress)
    {   cout<<setfill('0')<<hex;
        for(int i = minAddress;i<maxAddress;i++)
            cout<<setw(2)<<static_cast<int>(segment[i])<<" ";
        cout<<setfill(' ')<<dec;
    }
}
void Memory::printMemory(const char* fileName) const
{   ofstream stream(fileName,ios::binary);
    for(int i=0;i<65536;i++)
        stream.write((char*)&segment[i],1);
}