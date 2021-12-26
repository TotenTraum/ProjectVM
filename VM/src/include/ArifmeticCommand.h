#pragma once
#include <cmath>
#include <cfloat>
#include "command.h"
#include "exception.h"

class CPU_VM;
///Базовый класс для всех арифметических команд 
class ArifmeticCommands:public CommandCPU
{protected:
    ///<Виртуальная функция, которая выставляет необходимые флаги
    virtual void setFlags() {setSF(); setOF(); setZF();}
    virtual void setSF() = 0;       ///<Виртуальная функция, которая выставляет sign flag
    virtual void setOF() = 0;       ///<Виртуальная функция, которая выставляет overflow flag
    virtual void setZF() = 0;       ///<Виртуальная функция, которая выставляет zero flag
    virtual void changeAdder()=0;   ///<Виртуальная функция, которая изменяет adder
    virtual void callFunc()=0;      ///<Виртуальная функция, которая выбирает функцию
public:
    void operator()() final;
};
/// Базовый класс для целых арифметических операций
class IntAC : public ArifmeticCommands
{protected:
    void setSF();   ///<Выставляет sign flag для int32
    void setOF();   ///<Выставляет overflow flag для int32
    void setZF();   ///<Выставляет zero flag для int32
    virtual void changeAdder(){Adder().Integer = static_cast<int32_t>(result);}
    inline static int64_t result;
};
/// Базовый класс для вещественных арифметических операций
class FloatAC : public ArifmeticCommands
{protected:
    void setSF();   ///<Выставляет sign flag для float
    void setOF();   ///<Выставляет overflow flag для float
    void setZF();   ///<Выставляет zero flag для float
    virtual void changeAdder(){Adder().Float = static_cast<float>(result);}
    inline static double result;
};
///Базовый класс для арифметических унарных целых команд 
class UnarIntAC:public IntAC
{protected:
    virtual void function(int64_t) = 0;
    void callFunc(){function(Adder().Integer);} ///<Вызывает унарную функцию для int32     
};
///Базовый класс для арифметических бинарных целых команд 
class BinarIntAC:public IntAC
{protected:
    virtual void function(int64_t, int64_t) = 0; 
    void callFunc();    ///<Вызывает бинарную функцию для int32
};
///Базовый класс для арифметических унарных вещественных команд 
class UnarFloatAC:public FloatAC
{protected:
    virtual void function(double) = 0;
    void callFunc(){function(Adder().Float);} ///<Вызывает унарную функцию для float
};
///Базовый класс для арифметических бинарных вещественных команд 
class BinarFloatAC:public FloatAC
{protected:
    virtual void function(double, double) = 0;
    void callFunc(); ///<Вызывает бинарную функцию для float
};
///Инкрементировать сумматор целого типа
class IncCommand : public UnarIntAC{protected: void function(int64_t) override;};
///Инкрементировать сумматор вещественного типа
class IncFloatCommand : public UnarFloatAC{protected: void function(double) override;};
///Декрементировать сумматор целого типа
class DecCommand : public UnarIntAC{protected: void function(int64_t) override;};
///Декрементировать сумматор вещественного типа
class DecFloatCommand : public UnarFloatAC{protected: void function(double) override;};
///Операция not
class NotCommand: public UnarIntAC
{protected:
    void setFlags()override{}
    void function(int64_t) override;
};
///Сложение целых чисел
class AddCommand : public BinarIntAC {protected: void function(int64_t,int64_t) override;};
///Сложение вещественных чисел
class AddFloatCommand: public BinarFloatAC{protected: void function(double,double) override;};
///Вычитание целых чисел
class SubCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Вычитание вещественных чисел
class SubFloatCommand: public BinarFloatAC{protected: void function(double,double) override;};
///Произведение целых чисел
class MulCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Произведение вещественных чисел
class MulFloatCommand: public BinarFloatAC{protected: void function(double,double) override;};
///Деление целых чисел
class DivCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Деление вещественных чисел
class DivFloatCommand: public BinarFloatAC{protected: void function(double,double) override;};
///Операция or
class OrCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Операция and
class AndCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Операция xor
class XorCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Логический сдвиг влево 
class SALCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Логический сдвиг вправо
class SARCommand: public BinarIntAC{protected: void function(int64_t,int64_t) override;};
///Сравнить два объекта типа Integer
class CmpCommand: public BinarIntAC
{protected:
    void changeAdder()override{}
    void function(int64_t,int64_t) override;
};
///Сравнить два объекта типа Float
class CmpFloatCommand: public BinarFloatAC
{protected:
    void changeAdder()override{}
    void function(double,double) override;
};