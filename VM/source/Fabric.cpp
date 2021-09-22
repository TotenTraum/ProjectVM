#include "../include/Fabric.h"

Command* CommandFabric::make(const instruction& instruct)
{
    switch (instruct.code)
    {
    /*///
    /arithmetic with integer
    ///*/
    case INC:
        return new IncCommand(adder);

    case ADD:
        return new AddCommand(memory,instruct.address,adder,psw);
        
    case SUB:
        return new SubCommand(memory,instruct.address,adder,psw);
        
    case MUL:
        return new MulCommand(memory,instruct.address,adder,psw);
       
    case DIV:
        return new DivCommand(memory,instruct.address,adder,psw); 
    /*///
    /arithmetic with float
    ///*/
    case INCF:
        return new IncFloatCommand(adder);
        
    case ADDF:
        return new AddFloatCommand(memory,instruct.address,adder,psw);
        
    case SUBF:
        return new SubFloatCommand(memory,instruct.address,adder,psw);
        
    case MULF:
        return new MulFloatCommand(memory,instruct.address,adder,psw);
        
    case DIVF:
        return new DivFloatCommand(memory,instruct.address,adder,psw);
    /*///
    /INPUT/OUTPUT
    ///*/
    case READ:
        return new ReadCommand(memory,instruct.address);

    case READF:
        return new ReadFloatCommand(memory,instruct.address);

    case PRINT:
        return new PrintCommand(memory,instruct.address);

    case PRINTF:
        return new PrintFloatCommand(memory,instruct.address);
    /*///
    /
    ///*/
    case LEA:
        return new LeaCommand(instruct.address,registers);

    case MOV:
        return new MovCommand(memory,instruct.address,registers);
    /*///
    /
    ///*/
    case SAVEADDER:
        return new SaveAdderCommand(memory,instruct.address,adder);

    case LOADADDER:
        return new LoadAdderCommand(memory,instruct.address,adder);
    
    case SAVEADDERF:
        return new SaveAdderFloatCommand(memory,instruct.address,adder);

    case LOADADDERF:
        return new LoadAdderFloatCommand(memory,instruct.address,adder);
    /*///
    /Convertor
    ///*/
    case F2I:
        return new FloatToIntegerCommand(adder);
    
    case I2F:
        return new IntegerToFloatCommand(adder);
    /*///
    /
    ///*/
    case CALL:
        return new CallCommand(instruct.address,psw,registers);

    case CMP:
        return new CmpCommand(memory,instruct.address,psw,registers);  

    case CMPF:
        return new CmpFloatCommand(memory,instruct.address,psw,registers);
    
    case JUMP:
        return new JumpCommand(instruct.address,psw);  
    /*///
    /
    ///*/

    case JE:
        return new JECommand(instruct.address,psw); 

    case JNE:
        return new JNECommand(instruct.address,psw);

    case JL:
        return new JLCommand(instruct.address,psw);  

    case JLE:
        return new JLECommand(instruct.address,psw);      
    
    case JG:
        return new JGCommand(instruct.address,psw);  

    case JGE:
        return new JGECommand(instruct.address,psw); 
    /*///
    /
    ///*/
    case JZ:
        return new JZCommand(instruct.address,psw); 

    case JS:
        return new JSCommand(instruct.address,psw); 

    case JC:
        return new JCCommand(instruct.address,psw); 

    case JO:
        return new JOCommand(instruct.address,psw); 

    case JP:
        return new JPCommand(instruct.address,psw);
    /*///
    /
    ///*/
    case JNZ:
        return new JNZCommand(instruct.address,psw); 

    case JNS:
        return new JNSCommand(instruct.address,psw); 

    case JNC:
        return new JNCCommand(instruct.address,psw); 

    case JNO:
        return new JNOCommand(instruct.address,psw); 

    case JNP:
        return new JNPCommand(instruct.address,psw); 
     /*///
    /
    ///*/
    case ADDb:
        return new AddCommand(memory,registers->BP+instruct.address,adder,psw);
        
    case SUBb:
        return new SubCommand(memory,registers->BP+instruct.address,adder,psw);
        
    case MULb:
        return new MulCommand(memory,registers->BP+instruct.address,adder,psw);
        
    case DIVb:
        return new DivCommand(memory,registers->BP+instruct.address,adder,psw);
    /*///
    /
    ///*/
    case ADDFb:
        return new AddFloatCommand(memory,registers->BP+instruct.address,adder,psw);

    case SUBFb:
        return new SubFloatCommand(memory,registers->BP+instruct.address,adder,psw);

    case MULFb:
        return new MulFloatCommand(memory,registers->BP+instruct.address,adder,psw);

    case DIVFb:
        return new DivFloatCommand(memory,registers->BP+instruct.address,adder,psw);
    /*///
    /
    ///*/
    case READb:
        return new ReadCommand(memory,registers->BP+instruct.address);

    case READFb:
        return new ReadFloatCommand(memory,registers->BP+instruct.address);

    case PRINTb:
        return new PrintCommand(memory,registers->BP+instruct.address);

    case PRINTFb:
        return new PrintFloatCommand(memory,registers->BP+instruct.address);
    /*///
    /
    ///*/
    case LEAb:
        return new LeaCommand(registers->BP+instruct.address,registers);

    case MOVb:
        return new MovCommand(memory,registers->BP+instruct.address,registers);
    /*///
    /
    ///*/
    case SAVEADDERb:
        return new SaveAdderCommand(memory,registers->BP+instruct.address,adder);

    case LOADADDERb:
        return new LoadAdderCommand(memory,registers->BP+instruct.address,adder);
    
    case SAVEADDERFb:
        return new SaveAdderFloatCommand(memory,registers->BP+instruct.address,adder);

    case LOADADDERFb:
        return new LoadAdderFloatCommand(memory,registers->BP+instruct.address,adder);
    
    /*///
    /
    ///*/
    case CALLb:
        return new CallCommand(registers->BP+instruct.address,psw,registers);

    case RTNb:
        return new RtnCommand(registers->BP+instruct.address,psw,registers);

    case CMPb:
        return new CmpCommand(memory,registers->BP+instruct.address,psw,registers);  

    case CMPFb:
        return new CmpFloatCommand(memory,registers->BP+instruct.address,psw,registers);
    /*///
    /
    ///*/
    case JUMPb:
        return new JumpCommand(registers->BP+instruct.address,psw);  

    case JEb:
        return new JECommand(registers->BP+instruct.address,psw); 

    case JNEb:
        return new JNECommand(registers->BP+instruct.address,psw);

    case JLb:
        return new JLCommand(registers->BP+instruct.address,psw);  

    case JLEb:
        return new JLECommand(registers->BP+instruct.address,psw);      
    
    case JGb:
        return new JGCommand(registers->BP+instruct.address,psw);  

    case JGEb:
        return new JGECommand(registers->BP+instruct.address,psw); 
    /*///
    /
    ///*/
    case JZb:
        return new JZCommand(registers->BP+instruct.address,psw); 

    case JSb:
        return new JSCommand(registers->BP+instruct.address,psw); 

    case JCb:
        return new JCCommand(registers->BP+instruct.address,psw); 

    case JOb:
        return new JOCommand(registers->BP+instruct.address,psw); 

    case JPb:
        return new JPCommand(registers->BP+instruct.address,psw);
    /*///
    /
    ///*/
    case JNZb:
        return new JNZCommand(registers->BP+instruct.address,psw); 

    case JNSb:
        return new JNSCommand(registers->BP+instruct.address,psw); 

    case JNCb:
        return new JNCCommand(registers->BP+instruct.address,psw); 

    case JNOb:
        return new JNOCommand(registers->BP+instruct.address,psw); 

    case JNPb:
        return new JNPCommand(registers->BP+instruct.address,psw); 
    default:
        break;
    }
    return nullptr;
}