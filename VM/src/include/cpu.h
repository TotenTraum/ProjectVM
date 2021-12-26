#pragma once
#include "memory.h"
#include "psw.h"
#include "command.h"

class Command;
/**
 * @brief Класс процессор
 * @details Выполняет эмуляцию работы реального процессора
 */
class CPU_VM final
{public:
	CPU_VM()
	{	InitCommand();
		reset();
		currentCommand.cmd.code=ADD;
	}
	void exec();				///< Запускает работу процессора
	void reset();				///< Сброс значения Adder, BP, flags
	Memory mem;					///< Представление памяти машины фон Неймана
	PSW psw; 					///< Регистр специального назначения
private:
	void loadInstruction();		///< Подгрузка следующей команды
	void InitCommand();    		///< Инициализирует набор команд процессора
	void trapFlagHandler();		///< Обработчик флага ловушки
	friend class CommandCPU;	///< Предоставляем доступ к закрытым полям классу CommandCPU
	data_t Adder;				///< Регистр-сумматор
	address_t BP;				///< Base pointer - адресный регистр
	instruction currentCommand;	///< Исполняемая инструкция
	Command* Commands[128];		///< Набор команд процессора
};