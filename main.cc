#include <iostream>
#include "fraction.h"
#include "exception.h" 

int main( int argc, char* argv[] ) {
    Fraction f{ -3, 10 };
    Fraction g{ 0, 10 };
    try {
        std::cout << f / g << std::endl;
    } catch ( BaseException& error ) {
        error.what();
    }
}