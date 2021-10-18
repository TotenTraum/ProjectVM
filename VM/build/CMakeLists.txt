cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_C_FLAGS "-Wall -std=c99")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE  "-O4 -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(CMAKE_CXX_FLAGS                "-Wall -std=c++17 -g")
set(CMAKE_CXX_FLAGS_DEBUG          "-g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

project(projectVM)

set (HEADERS 
"../include/command.h" "../include/cpu.h" "../include/memory.h"
 "../include/psw.h" "../include/Instruction.h" "../include/types.h" 
)
 
set (SOURCES 
"../source/command.cpp" "../source/cpu.cpp" "../source/memory.cpp"
"../source/ArifmeticCommand.cpp" "../source/jumpCommands.cpp"
) 

add_executable(VM "../main.cpp" ${HEADERS} ${SOURCES})
