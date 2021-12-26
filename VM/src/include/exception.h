#pragma once
#include <stdexcept>
//Базовый класс исключений виртуальной машины
class VMException:public std::exception
{protected:
    char msg[256]; 
public:
    VMException(const char* arg1,const char* arg2, unsigned int arg3)
        {sprintf(msg,"%s\nline:%u\nfile:%s\n",arg1,arg3,arg2);}
    virtual const char* what()const noexcept{return msg;}
};
///Исключение, которое можно получить в случае деления на нуль
class DivideByZeroException: public VMException
{public:
    DivideByZeroException(const char* arg1,const char* arg2, unsigned int arg3):
        VMException(arg1,arg2,arg3){}
};
///Исключение, которое можно получить, если был получен некорректный код команды
class UndefinedOpcodeException: public VMException
{public:
    UndefinedOpcodeException(const char* arg1,const char* arg2, unsigned int arg3):
        VMException(arg1,arg2,arg3){}
};