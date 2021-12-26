#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "include/catch.hpp"
using namespace std;

int main(int argc, char* argv[] )
{
    setlocale(LC_ALL, "Russian");
    int result = Catch::Session().run( argc, argv );
    cin.get();
    return result;
}