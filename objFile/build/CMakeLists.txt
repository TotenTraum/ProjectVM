cmake_minimum_required(VERSION 3.0.0)

project(ObjFile)

set(CMAKE_C_COMpILER "/usr/bin/clang")
set(CMAKE_CXX_COMpILER "/usr/bin/clang++")

set (HEADERS "../include/Instruction.h")

#set(SOURCES )

add_executable(ObjFile "../main.cpp" ${HEADERS}) 