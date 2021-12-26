#pragma once
#include "types.h"
/*!	\brief Program Special Word(PSW) - регистр специального назначения 
	\details Выполняет функции регистра состояния и указателя на исполняюемую команду.
*/
class PSW
{public:
    ///Конструктор класса
    PSW():IP(0){}
    /*! \brief Сброс флагов.
        \details Обнуляет регистр флагов.
    */
    void resetFlags(){flags = Flags();}
    /// Регистр флагов состояния процессора
    struct Flags
    {   uint16_t ZF:1;   ///< Zero flag
        uint16_t SF:1;   ///< Sign flag
        uint16_t OF:1;   ///< Overflow flag
        uint16_t TF:1;   ///< Trap flag
    } flags;
    ///Instruction pointer - указатель на исполняемую команду
    address_t IP;
};