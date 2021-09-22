#include "../include/flags.h"

void Flags::resetFlags(){
    flags=0;
}

void Flags::setFlag(const NameOfFlags& name)
{
    flags |= 1<<name;
}
void Flags::unsetFlag(const NameOfFlags& name)
{
    flags &= UINT16_MAX ^ (1<<name);
}

bool Flags::getFlag(const NameOfFlags& name)
{
    return flags & (1<<name);

}