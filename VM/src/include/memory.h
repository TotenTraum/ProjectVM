#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "types.h"
/**
 * @brief Представление памяти машины фон Неймана
 */
class Memory final
{    byte_t* segment = nullptr; ///<Массив байтов
public:
    Memory(){segment = new byte_t[65536];}
    ~Memory(){delete[] segment;}
    ///Даёт доступ к элементам памяти
    byte_t& operator[](const address_t& address){return segment[address];}
    ///Вывод всей байтовой памяти в консоль
    void printMemory(address_t) const;
    ///Вывод сегмента байтовой памяти в консоль
    void printMemory(address_t, address_t) const;
    ///Вывод всей байтовой памяти в бинарный файл
    void printMemory(const char* fileName) const;
};