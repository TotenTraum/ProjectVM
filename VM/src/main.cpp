#include <fstream>
#include <cstring>
#include <sstream>
#include <regex>
#include "include/cpu.h"

using namespace std;
//Определяет код команды
opcode identifyCmd(string& str)
{   static vector<string> commands={"STOP","INCF","INC","DECF","DEC","ADDF","ADD","SUBF","SUB",
								   "MULF","MUL","DIVF","DIV","CMPF","CMP","OR","AND","XOR","NOT",
								   "SAL","SAR","LEA","MOV","I2F","F2I","INPUTF","INPUT",
								   "OUTPUTF","OUTPUT","SAVE","LOAD","CALL","RTN","JUMP","JE",
							       "JNE","JLE","JL","JGE","JG","JS","JO","JNS","JNO","CLT","STT"};
	for (int i = 0; i < commands.size(); i++)
        if(str == commands[i])
			return static_cast<opcode>(i);
	char ch[256] = "undefined Opcode: ";
    throw UndefinedOpcodeException(strcat(ch,str.data()),__FILE__,__LINE__);
}
///Интерпретирует строку
void interpretLine(CPU_VM& CPU,string& str,address_t& index,regex& rgx)
{	///Исключение, которое можно получить, если загрузчик найдет необъявленный префикс
	class UndefinedPrefixException: public VMException
	{public:
		UndefinedPrefixException(const char* arg1,const char* arg2, unsigned int arg3):
			VMException(arg1,arg2,arg3){}
	};
	data_t value;
	instruction tmp;
	char tag = ' ';
	stringstream sstream(str);
	sstream >> tag;
	switch (tag)
	{case 'a'://Считывает адрес
		sstream >> index;
		break;
	case 'e'://Входной адрес
		sstream >> CPU.psw.IP;
		break;
	case 'c'://Считывает команду
		sstream>>str;
		tmp.cmd.code = identifyCmd(str);  //Считывает код команды
		getline(sstream,str);			  //Забираем остаток строки
		tmp.cmd.b = regex_search(str,rgx);//Определяем тип команды
		tmp.cmd.arg = stoi(regex_replace(str,regex("[^0-9\\-; ]+"),""));//Считывает аргумент
		for(int i=0;i<3;i++) CPU.mem[index++] = tmp.byte[i];
		break;
	case 'r'://Считывает вещественное число
		sstream>>value.Float;
		for (int j = 0; j < 4; j++)	CPU.mem[index++] = value.byte[j];
		break;
	case 'i'://Считывает целое число
		sstream>>value.Integer;
		for (int j = 0; j < 4; j++)	CPU.mem[index++] = value.byte[j];
		break;
	case ' ':
	case ';':
		break;
	default:
		str = "undefined prefix :";
		throw UndefinedPrefixException((str+=tag).data(),__FILE__,__LINE__);
	}
}
void loader(CPU_VM &CPU, const char *file)
{	ifstream filestream(file);
	vector<string> vectStr;
	string str;
	address_t index = 0;
	if (filestream.is_open())
	{
		while(getline(filestream,str))
			vectStr.push_back(str);
		filestream.close();
		regex rgx (":\\[[\\-0-9 ]?[0-9 ]+\\]");//Для определения наличия параметра b
		for (string& iter:vectStr)
			interpretLine(CPU,iter,index,rgx);			
	}
}
void VM_main(const char* path)
{
	CPU_VM cpu;
	loader(cpu,path);
	cpu.exec();
	cout<<"Завершение работы программы \""<<path<<"\""<<endl;	
}

int main(int argc, const char **argv)
{	
	if(argc>1)
		for(int i=1;i<argc;i++)
			VM_main(argv[i]);
	else 
	{
		string path;
		cout<<"Введите путь к файлу >> ";
		cin>>path;
		VM_main(path.c_str());
	}
}