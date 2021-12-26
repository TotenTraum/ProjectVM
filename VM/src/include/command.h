#pragma once
#include "cpu.h"
#include "exception.h"

class CPU_VM;
///Родительский класс команд
class Command
{	public:
	 virtual void operator()() = 0;
};
/**
 * @brief Позволяет остальным командам обращаться к процессору
 * @details Содержит в себе методы чтения из памяти и записи в неё,
 * получения аргумента команды и также регистров 
 */
class CommandCPU: public Command
{protected:
	data_t& readDWORD(data_t& DWORD);	 //Читает двойное слово
	void writeDWORD(const data_t& DWORD);//Записывает двойное слово
	address_t getArg();					 //Возвращает аргумент команды
	PSW::Flags& Flags();				 //Возвращает ссылку на регистр флагов
	address_t getIP();					 //Возвращает текущий адрес команды
	void setIP(const address_t&);		 //Устанавливает новый адрес команд
	data_t& Adder();					 //Возвращает ссылку на сумматор
	address_t getBP();					 //Возвращает адресный регистр
	void setBP(const address_t&);		 //Присваивает BP новое значение
	inline static CPU_VM* CPU;
public:
	static void setCPU(CPU_VM*);
};
/// "Нулевой" класс
class EmptyCommand: public CommandCPU{public: void operator()() override {throw UndefinedOpcodeException("called empty command",__FILE__,__LINE__);}};
/// Приостанавливает работу процессора
class StopCommand: public CommandCPU{public: void operator()() override{}};
/// Set trap flag command
class STTCommand: public CommandCPU{public: void operator()() override{Flags().TF = 1;}};
/// Clear trap flag command
class CLTCommand: public CommandCPU{public: void operator()() override{Flags().TF = 0;}};