cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_C_COMPILER "/usr/bin/clang")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(projectVM)

set (HEADERS 
"../include/command.h" "../include/cpu.h" "../include/flags.h"
"../include/memory.h" "../include/psw.h" "../include/Instruction.h"
"../include/types.h" "../include/registers.h" "../include/Fabric.h"
)
 
set (SOURCES 
"../source/command.cpp" "../source/cpu.cpp" "../source/flags.cpp"
"../source/memory.cpp" "../source/psw.cpp"
"../source/types.cpp" "../source/registers.cpp" "../source/Fabric.cpp"
) 

add_executable(VM "../main.cpp" ${HEADERS} ${SOURCES})
