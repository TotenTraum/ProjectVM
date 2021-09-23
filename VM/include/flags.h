#pragma once
#include <cstdint>

enum NameOfFlags
{
    CF = 0,    //Carry flag
    WF = 1,    //Wait flag(for VM)
    PF = 2,    //Parity flag
    AF = 4,    //Auxiliary carry flag
    ZF = 6,    //Zero flag
    SF = 7,    //Sign flag
    TF = 8,    //Trap flag
    IF = 9,    //Interrupt Enable Flag
    DF = 10,   //Direction flag
    OF = 11,   //Overflow flag
    IPL = 12,  //Input Privilege level 
    OPL = 13,  //Output Privilege level
    NT = 14    //Nested task
};

class Flags{
public:
    Flags():flags(0){};
    void resetFlags();

    //Устанавливает значение 1 биту name
    void setFlag(const NameOfFlags& name);

    //Устанавливает значение 0 биту name
    void unsetFlag(const NameOfFlags& name);

    //Возвращает значение бита name
    bool getFlag(const NameOfFlags& name);

    //Возвращает все флаги(Проверка//После удалить)
    uint16_t getFlags(){return flags;}
private:
uint16_t flags;
};