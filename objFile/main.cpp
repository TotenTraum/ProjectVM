#include <iostream>
#include "include/parserVMT.h"

using namespace std;

int main(int argc,const char* argv[])
{
    char* input,*output;
    VMFile tmp;
    for(int i=1;i<argc;i++)
    {
        if(argv[i][1]=='i')
        {
            input = (char*)argv[++i];
            tmp.loadFile(input);
            tmp.parse();
        }
        else if(argv[i][1]=='o')
        {
            output = (char*)argv[++i];
            tmp.saveFile((const char*)output);
        }
    }
}
