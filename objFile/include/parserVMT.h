#pragma once
#include <vector>
#include "string.h"
#include <cassert>
#include <iostream>
#include "Nodes.h"

class VMFile
{
public:
    void loadFile(const char* /*nameFile*/);
    void loadFile(std::ifstream&);
    void saveFile(const char* NameFile = "result.obj");
    void saveFile(std::ofstream&);
    void parse();
    void parse(char* ptr);
    char* parseCommand(char* ptr);
    char* parseAddress(char* ptr);
    char* parseInt(char* ptr);
    char* parseFloat(char* ptr);
    char* identify(char* ptr,instruction&,bool&);
    char* findComment(char* ptr);
    char* skipComment(char* ptr);
    char* skipWhiteSpaces(char* ptr);
    char* readUInt16(char* ptr,uint16_t& number);
    char* readInt32(char* ptr,int32_t& number);
    char* readFloat(char* ptr,float& number);
private:
    std::vector<Node*> _instructions;
    char* _text = nullptr;
};
