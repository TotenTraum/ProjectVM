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
"../src/include/command.h" "../src/include/cpu.h" "../src/include/memory.h" "../src/include/exception.h"
 "../src/include/psw.h" "../src/include/Instruction.h" "../src/include/types.h"
 "../src/include/ArifmeticCommand.h" "../src/include/jumpCommands.h" "../src/include/TransferCommands.h"
)
 
set (SOURCES 
"../src/source/command.cpp" "../src/source/cpu.cpp" "../src/source/memory.cpp"
"../src/source/ArifmeticCommand.cpp" "../src/source/jumpCommands.cpp" "../src/source/TransferCommands.cpp"
) 

add_executable(VM01 "../src/main.cpp" ${HEADERS} ${SOURCES})

set (TEST_HEADERS
"../test/include/catch_reporter_automake.hpp" "../test/include/catch_reporter_sonarqube.hpp"
"../test/include/catch_reporter_tap.hpp" "../test/include/catch_reporter_teamcity.hpp"
"../test/include/catch.hpp"
)

set (TEST_CASES
"../test/testcases/arifmeticCmdCase.cpp" "../test/testcases/jumpCmdCase.cpp"
"../test/testcases/TransferCmdCase.cpp"
)

#add_executable(VM_TEST "../test/main.cpp" ${HEADERS} ${SOURCES} ${TEST_HEADERS} ${TEST_CASES})
