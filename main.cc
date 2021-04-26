#include <iostream>
#include "fraction.h"
#include "exception.h" 
#include "polynomial.h"

int main( int argc, char* argv[] ) {
    Polynomial poly1, poly2;
    std::cin >> poly1 >> poly2;
    std::cout << poly1 << std::endl;
    std::cout << poly2 << std::endl;
    std::cout << poly1 / poly2 << std::endl; 
    std::cout << poly1 % poly2 << std::endl; 
}