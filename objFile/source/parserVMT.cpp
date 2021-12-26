#include "../include/parserVMT.h"

void VMFile::loadFile(const char *nameFile)
{
    std::ifstream FILE(nameFile);
    loadFile(FILE);
}

void VMFile::loadFile(std::ifstream &FILE)
{
    delete[] _text;
    FILE.seekg(0, FILE.end);
    size_t size = FILE.tellg();
    FILE.seekg(0, FILE.beg);
    _text = new char[size + 1];
    FILE.read(_text, size);
}

void VMFile::saveFile(const char *NameFile)
{
    std::ofstream FILE(NameFile, std::ios::binary);
    saveFile(FILE);
}

void VMFile::saveFile(std::ofstream &FILE)
{
    for (size_t i = 0; i < _instructions.size(); i++)
        _instructions[i]->write(FILE);
}

char *VMFile::readUInt16(char *ptr, uint16_t &number)
{
    number = strtol(ptr, &ptr, 10);
    return ptr;
}

char *VMFile::readInt32(char *ptr, int32_t &number)
{
    number = strtol(ptr, &ptr, 10);
    return ptr;
}

char *VMFile::readFloat(char *ptr, float &number)
{
    number = strtof(ptr, &ptr);
    return ptr;
}

char *VMFile::skipWhiteSpaces(char *ptr)
{
    assert(ptr);
    while (*ptr == ' ' || *ptr == '\n')
        ++ptr;
    return ptr;
}

char *VMFile::findComment(char *ptr)
{
    assert(ptr);
    while (*ptr == ' ' && *ptr != ';' && *ptr)
        ++ptr;
    if (*ptr == ';')
        ++ptr;
    return ptr;
}

char *VMFile::skipComment(char *ptr)
{
    assert(ptr);
    while (*ptr && *ptr != '\n')
        ++ptr;
    if (*ptr == '\n')
        ++ptr;
    return ptr;
}

char *VMFile::identify(char *ptr, instruction &tmp, bool &not_found)
{
    static std::vector<const char *> commands = {"STOP", "INCF", "INC", "DECF", "DEC", "ADDF", "ADD",
                                                 "SUBF", "SUB", "MULF", "MUL", "DIVF", "DIV", "CMPF",
                                                 "CMP", "OR", "AND", "XOR", "NOT", "SAL", "SAR",
                                                 "LEA", "MOV", "I2F", "F2I", "INPUTF", "INPUT",
                                                 "OUTPUTF", "OUTPUT", "SAVE", "LOAD", "CALL", "RTN",
                                                 "JUMP", "JE", "JNE", "JLE", "JL", "JGE", "JG", "JS",
                                                  "JO", "JNS", "JNO", "CLT","STT"};
    uint8_t i;
    for (i = 0; i < commands.size(); i++)
        if (strncmp(ptr, commands[i], strlen(commands[i])) == 0)
        {
            std::cout << commands[i] << std::endl;
            tmp.code = (opcode)i;
            ptr += strlen(commands[i]);
            break;
        }
    if (i == commands.size())
        not_found = true;
    return ptr;
}

void VMFile::parse(char *ptr)
{
    static const char *strAddress = "ADDRESS";
    static const char *strInteger = "INTEGER";
    static const char *strFloat = "FLOAT";

    if (strncmp(ptr, strAddress, strlen(strAddress)) == 0)
    {
        ptr += strlen(strAddress);
        ptr = parseAddress(ptr);
    }
    else if (strncmp(ptr, strInteger, strlen(strInteger)) == 0)
    {
        ptr += strlen(strInteger);
        ptr = parseInt(ptr);
    }
    else if (strncmp(ptr, strFloat, strlen(strFloat)) == 0)
    {
        ptr += strlen(strFloat);
        ptr = parseFloat(ptr);
    }
    else
        ptr = parseCommand(ptr);

    ptr = findComment(ptr);
    ptr = skipComment(ptr);
    if (ptr != nullptr && *ptr)
        parse(ptr);
}

void VMFile::parse()
{
    parse(_text);
}

char *VMFile::parseCommand(char *ptr)
{
    bool not_found = false;
    instruction tmp;
    ptr = skipWhiteSpaces(ptr);
    ptr = identify(ptr, tmp, not_found);
    ptr = skipWhiteSpaces(ptr);
    if (*ptr == ':')
    {
        tmp.code = (opcode)(tmp.code | 128);
        ptr++;
    }
    ptr = skipWhiteSpaces(ptr);
    ptr = readUInt16(ptr, tmp.address);
    if(!not_found)
        _instructions.push_back(new CommandNode(tmp));
    return ptr;
}

char *VMFile::parseAddress(char *ptr)
{
    uint16_t tmp;
    ptr = readUInt16(ptr, tmp);
    _instructions.push_back(new AddressLineNode(tmp));
    return ptr;
}

char *VMFile::parseInt(char *ptr)
{
    int32_t tmp;
    ptr = readInt32(ptr, tmp);
    _instructions.push_back(new dataIntNode(tmp));
    return ptr;
}

char *VMFile::parseFloat(char *ptr)
{
    float tmp;
    ptr = readFloat(ptr, tmp);
    _instructions.push_back(new dataFloatNode(tmp));
    return ptr;
}
