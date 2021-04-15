#include <iostream>
#include "exception.h" 

// Base exception constructor 
BaseException::BaseException( const std::string& msg ):
    errorMsg{ msg } { }

// Fraction exception constructor 
FractionException::FractionException( const std::string& msg ):
    BaseException{ msg } { } 


// Fraction Read exception constructor 
FractionReadException::FractionReadException( const std::string& msg ):
    FractionException{ msg } { } 

// print Fraction Read exception error message
void FractionReadException::what() {
    std::cerr << "Error reading fraction: "; 
    std::cerr << errorMsg << std::endl;
} // FractionReadException::what

// Fraction Division exception constructor
FractionDivisionException::FractionDivisionException( const std::string& msg ):
    FractionException{ msg } { } 

// print Fraction Division exception error message 
void FractionDivisionException::what() {
    std::cerr << "Error performing fraction division: ";
    std::cerr << errorMsg << std::endl; 
} // FractionDivisionException::what 