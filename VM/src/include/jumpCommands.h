#pragma once
#include "command.h"
///Базовый класс для  команд прыжков 
class JCommands:public CommandCPU{};
///Прыжок в подпрограмму
class CallCommand : public JCommands{public: void operator()() override;};
///Вернуться в основную программу
class RtnCommand : public JCommands{public: void operator()() override;};
///Совершение прыжка без проверок
class JumpCommand: public JCommands{public: void operator()() override;};
///Совершение прыжка с проверкой на эквивалентность
class JECommand: public JCommands{public: void operator()() override;};
///Совершение прыжка с проверкой на не эквивалентность
class JNECommand: public JCommands{public: void operator()() override;};
///Совершение прыжка с проверкой obj1<obj2
class JLCommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой obj1<=obj2
class JLECommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой obj1>obj2
class JGCommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой obj1>=obj2
class JGECommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой SF = 1
class JSCommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой OF = 1
class JOCommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой SF = 0
class JNSCommand: public JCommands {public: void operator()() override;};
///Совершение прыжка с проверкой OF = 0
class JNOCommand: public JCommands {public: void operator()() override;};