#include <iostream>
#include "fraction.h"
#include "exception.h" 
#include "polynomial.h"

int main( int argc, char* argv[] ) {
    Polynomial poly1, poly2;
    std::cin >> poly1 >> poly2;
    std::cout << "First Polynomial: \t";
    std::cout << poly1 << std::endl;
    std::cout << "Second Polynomial: \t";
    std::cout << poly2 << std::endl;

    std::cout << "Addition: \t\t";
    std::cout << poly1 + poly2 << std::endl;
    std::cout << "Subtraction: \t\t";
    std::cout << poly1 - poly2 << std::endl;
    std::cout << "Multiplication: \t";
    std::cout << poly1 * poly2 << std::endl; 
    std::cout << "Division: \t\t";
    std::cout << poly1 / poly2 << std::endl; 
    std::cout << "Mudulo: \t\t";
    std::cout << poly1 % poly2 << std::endl; 
}