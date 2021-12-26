#pragma once
#include "command.h"

///Базовый класс для команд перессылок
class TransferCommands: public CommandCPU{}; 
///Преобразовывает вещественное в целое число
class FloatToIntCommand : public TransferCommands {public:void operator()() override;};
///Преобразовывает целое в вещественное число
class IntToFloatCommand : public TransferCommands {public:void operator()() override;};
///Меняет значение адресного регистра
class LeaCommand : public TransferCommands {public: void operator()() override;};
///Загружает значение сумматора в память
class SaveCommand: public TransferCommands {public: void operator()() override;};
///Выгружает значение сумматора из памяти
class LoadCommand: public TransferCommands {public: void operator()() override;};
///Записывает значение из памяти в память
class MovCommand: public TransferCommands {public: void operator()() override;};
///Чтение целого числа и запись в память
class InputCommand: public TransferCommands {public:void operator()() override;};
///Чтение дробного числа и запись в память
class InputFCommand: public TransferCommands {public:void operator()() override;};
///Печатает целое число на экран
class OutputCommand: public TransferCommands {public:void operator()() override;};
///Печатает вещественное число на экран
class OutputFCommand: public TransferCommands {public:void operator()() override;};