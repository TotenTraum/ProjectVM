#include "../../src/include/ArifmeticCommand.h"
#include "../include/catch.hpp"

CPU_VM cpu;
data tmp; 
void writeData(data& arg,address_t address = 0)
{   for (int j = 0; j < 4; j++)
	    cpu.mem[j+address] = arg.byte[j];
}
TEST_CASE("IntTestCase")
{   CommandCPU::setCPU(&cpu);
    SECTION("AddTestCase")
    {   AddCommand add;
        tmp.Integer = 15;
        writeData(tmp);
        add();
        CHECK(cpu.getAdder().Integer == 15);
        CHECK(cpu.Flags().OF == 0);
        CHECK(cpu.Flags().SF == 0);
        cpu.getAdder().Integer = INT32_MAX;
        add();
        CHECK(cpu.getAdder().Integer ==INT32_MIN + 14);
        CHECK(cpu.Flags().OF == 1);
        CHECK(cpu.Flags().SF == 1);
        cpu.reset();
    }
    SECTION("SubTestCase")
    {   SubCommand sub;
        tmp.Integer = 15;
        writeData(tmp);
        sub();
        CHECK(cpu.getAdder().Integer == -15);
        CHECK(cpu.Flags().OF == 0);
        CHECK(cpu.Flags().SF == 1);
        cpu.getAdder().Integer = INT32_MIN;
        sub();
        CHECK(cpu.getAdder().Integer == INT32_MAX-14);
        CHECK(cpu.Flags().OF == 1);
        CHECK(cpu.Flags().SF == 0);
        cpu.reset();
    }
    SECTION("MulTestCase")
    {   MulCommand mul;
        tmp.Integer = 15;
        writeData(tmp);
        mul();
        CHECK(cpu.getAdder().Integer == 0);
        cpu.getAdder().Integer = 2;
        mul();
        CHECK(cpu.getAdder().Integer == 30);
        cpu.reset();
    }
    SECTION("DivTestCase")
    {   DivCommand div;
        tmp.Integer = 15;
        writeData(tmp);
        div();
        CHECK(cpu.getAdder().Integer == 0);
        cpu.getAdder().Integer = 30;
        div();
        CHECK(cpu.getAdder().Integer == 2);
        cpu.reset();
    }
    SECTION("OrTestCase")
    {   OrCommand Or;
        tmp.Integer = 15;
        writeData(tmp);
        Or();
        CHECK(cpu.getAdder().Integer == 15);
        cpu.getAdder().Integer = 30;
        Or();
        CHECK(cpu.getAdder().Integer == 31);
        cpu.reset();
    }
    SECTION("AndTestCase")
    {   AndCommand And;
        tmp.Integer = 15;
        writeData(tmp);
        And();
        CHECK(cpu.getAdder().Integer == 0);
        cpu.getAdder().Integer = 17;
        And();
        CHECK(cpu.getAdder().Integer == 1);
        cpu.reset();
    }
    SECTION("XorTestCase")
    {   XorCommand Xor;
        tmp.Integer = 15;
        writeData(tmp);
        Xor();
        CHECK(cpu.getAdder().Integer == 15);
        cpu.getAdder().Integer = 16;
        Xor();
        CHECK(cpu.getAdder().Integer == 31);
        cpu.reset();
    }
    SECTION("SALTestCase")
    {   SALCommand SHL;
        tmp.Integer = 2;
        writeData(tmp);
        SHL();
        CHECK(cpu.getAdder().Integer == 0);
        cpu.getAdder().Integer = 1;
        SHL();
        CHECK(cpu.getAdder().Integer == 4);
        cpu.reset();
    }
    SECTION("SARTestCase")
    {   SARCommand SHR;
        tmp.Integer = 2;
        writeData(tmp);
        SHR();
        CHECK(cpu.getAdder().Integer == 0);
        cpu.getAdder().Integer = 4;
        SHR();
        CHECK(cpu.getAdder().Integer == 1);
        cpu.reset();
    }
    SECTION("CmpTestCase")
    {   CmpCommand cmp;
        SECTION("less")
        {
            tmp.Integer = 2;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF != cpu.Flags().OF; 
            CHECK(val);
        }
        SECTION("less equal")
        {
            tmp.Integer = 0;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF != cpu.Flags().OF || cpu.Flags().ZF;
            CHECK(val);
        }
        SECTION("great")
        {
            tmp.Integer = -2;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF == cpu.Flags().OF && !cpu.Flags().ZF; 
            CHECK(val);
        }
        SECTION("great equal")
        {
            tmp.Integer = 0;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF == cpu.Flags().OF; 
            CHECK(val);
        }
        SECTION("equal")
        {
            tmp.Integer = 0;
            writeData(tmp);
            cmp();
            CHECK(cpu.Flags().ZF);
        }
        SECTION("not equal")
        {
            tmp.Integer = 1;
            writeData(tmp);
            cmp();
            CHECK(!cpu.Flags().ZF);
        }
        cpu.reset();
    }
}

TEST_CASE("FloatTestCase")
{   CommandCPU::setCPU(&cpu);
    SECTION("AddTestCase")
    {   AddFloatCommand add;
        tmp.Float = 15;
        writeData(tmp);
        add();
        CHECK(cpu.getAdder().Float == 15);
        add();
        CHECK(cpu.getAdder().Float == 30);
        cpu.reset();
    }
    SECTION("SubTestCase")
    {   SubFloatCommand sub;
        tmp.Float = 15;
        writeData(tmp);
        sub();
        CHECK(cpu.getAdder().Float == -15);
        sub();
        CHECK(cpu.getAdder().Float == -30);
        cpu.reset();
    }
    SECTION("MulTestCase")
    {   MulFloatCommand mul;
        tmp.Float = 15;
        writeData(tmp);
        mul();
        CHECK(cpu.getAdder().Float == 0);
        cpu.getAdder().Float = 2;
        mul();
        CHECK(cpu.getAdder().Float == 30);
        cpu.reset();
    }
    SECTION("DivTestCase")
    {   DivFloatCommand div;
        tmp.Float = 15;
        writeData(tmp);
        div();
        CHECK(cpu.getAdder().Float == 0);
        cpu.getAdder().Float = 30;
        div();
        CHECK(cpu.getAdder().Float == 2);
        cpu.reset();
    }
    SECTION("CmpTestCase")
    {   CmpFloatCommand cmp;
        SECTION("less")
        {
            tmp.Float = 2;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF != cpu.Flags().OF; 
            CHECK(val);
        }
        SECTION("less equal")
        {
            tmp.Float = 0;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF != cpu.Flags().OF || cpu.Flags().ZF;
            CHECK(val);
        }
        SECTION("great")
        {
            tmp.Float = -2;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF == cpu.Flags().OF && !cpu.Flags().ZF; 
            CHECK(val);
        }
        SECTION("great equal")
        {
            tmp.Float = 0;
            writeData(tmp);
            cmp();
            bool val = cpu.Flags().SF == cpu.Flags().OF; 
            CHECK(val);
        }
        SECTION("equal")
        {
            tmp.Float = 0;
            writeData(tmp);
            cmp();
            CHECK(cpu.Flags().ZF);
        }
        SECTION("not equal")
        {
            tmp.Float = 1;
            writeData(tmp);
            cmp();
            CHECK(!cpu.Flags().ZF);
        }
        cpu.reset();
    }
}

TEST_CASE("ExceptionsCase")
{   CommandCPU::setCPU(&cpu);
    SECTION("int divide by zero")
    {   DivCommand div;
        tmp.Integer = 0;
        writeData(tmp);
        CHECK_THROWS_AS(div(),DivideByZeroException);
        cpu.reset();
    }
    SECTION("float divide by zero")
    {   DivFloatCommand div;
        tmp.Float = 0.0f;
        writeData(tmp);
        CHECK_THROWS_AS(div(),DivideByZeroException);
        cpu.reset();
    }
}