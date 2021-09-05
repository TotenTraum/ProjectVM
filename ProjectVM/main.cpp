#define ENUM_COMMAND

#include <iostream>
#include "cpu.h"
#include "InstructionAndCodeOfCommand.h"

void interpret(DOUBLE number) {
	std::cout << number.sign * pow(2, number.exponent - 127) * (1.0 - number.fraction);
}

void output(DOUBLE number) {
	std::cout << number.sign<<' ' << number.exponent << ' ' << number.fraction<<std::endl;
}

void loader(char file[]) {

}

int main(int argc, const char* argv[]) {
	/*DOUBLE w = 0x1e20'0000;
	output(w);
	interpret(w);*/
	double d = 1.01;
	double c;
	int i = 1, o;
	c = d + i;
	o = d + i;
}
