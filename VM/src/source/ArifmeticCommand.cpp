#include "../include/ArifmeticCommand.h"
#include "../include/cpu.h"

void ArifmeticCommands::operator()()
{   callFunc();   //Вызов функции
    changeAdder();//Изменение сумматора
    setFlags();   //Выставление определённых флагов
}
void IntAC::setSF(){if(static_cast<int32_t>(result)<0) Flags().SF=1; else Flags().SF=0;}
void FloatAC::setSF(){if(static_cast<float>(result)<0) Flags().SF=1; else Flags().SF=0;}
void IntAC::setZF(){if(result==0)Flags().ZF=1; else Flags().ZF=0;}
void FloatAC::setZF(){if(std::fabs(result)<0.001)Flags().ZF=1; else Flags().ZF=0;}
void IntAC::setOF()
{   if(result > INT32_MAX || result < INT32_MIN)
        Flags().OF = 1;
    else
        Flags().OF = 0;
}
void FloatAC::setOF()
{   if(result > FLT_MAX || result < FLT_MIN)
        Flags().OF = 1;
    else
        Flags().OF = 0;
}
void BinarIntAC::callFunc()
{   data_t tmp;
    readDWORD(tmp);
    function(Adder().Integer,tmp.Integer);
}
void BinarFloatAC::callFunc()
{   data_t tmp;
    readDWORD(tmp);
    function(Adder().Float,tmp.Float);
}
void IncCommand::function(int64_t arg){result = arg+1;}
void IncFloatCommand::function(double arg) {result = arg+1;}
void DecCommand::function(int64_t arg) {result = arg-1;}
void DecFloatCommand::function(double arg) {result = arg-1;}
void AddCommand::function(int64_t arg1,int64_t arg2){result = arg1+arg2;}
void AddFloatCommand::function(double arg1,double arg2) {result = arg1+arg2;}
void SubCommand::function(int64_t arg1,int64_t arg2){result = arg1-arg2;}
void SubFloatCommand::function(double arg1,double arg2){result = arg1-arg2;}
void MulCommand::function(int64_t arg1,int64_t arg2){result = arg1*arg2;}
void MulFloatCommand::function(double arg1,double arg2){result = arg1*arg2;}
void DivCommand::function(int64_t arg1,int64_t arg2) 
{   if (arg2 == 0)
        throw DivideByZeroException("int: divide by zero",__FILE__,__LINE__);
    result = arg1/arg2;
}
void DivFloatCommand::function(double arg1,double arg2) 
{   if(std::fabs(arg2)<0.001)
        throw DivideByZeroException("float: divide by zero",__FILE__,__LINE__);
    result = arg1/arg2;
}
void OrCommand::function(int64_t arg1,int64_t arg2) {result = arg1|arg2;}
void AndCommand::function(int64_t arg1,int64_t arg2) {result = arg1&arg2;}
void XorCommand::function(int64_t arg1,int64_t arg2) {result = arg1^arg2;}
void NotCommand::function(int64_t arg) {result = ~arg;}
void SALCommand::function(int64_t arg1,int64_t arg2){result = arg1<<arg2;}
void SARCommand::function(int64_t arg1,int64_t arg2){result = arg1>>arg2;}
void CmpCommand::function(int64_t arg1,int64_t arg2){result = arg1-arg2;}
void CmpFloatCommand::function(double arg1,double arg2){result = arg1 - arg2;}