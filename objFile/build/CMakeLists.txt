cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(Parser)

set(HEADERS "../include/Instruction.h" "../include/parserVMT.h" "../include/Nodes.h")

set(SOURCES "../source/parserVMT.cpp" "../source/Nodes.cpp")

add_executable(objFile "../main.cpp" ${HEADERS} ${SOURCES})

if(MSVC)
  target_compile_options(objFile PRIVATE /W4 /WX )
else()
  target_compile_options(objFile PRIVATE -Wall -g -Wextra -pedantic -O2)
endif()
