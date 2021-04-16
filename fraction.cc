#include <numeric>
#include "fraction.h"
#include "exception.h"

// constant fields must use MIL 
Fraction::Fraction( const int& nom, const int& denom ):
    nominator{nom}, denominator{denom} {
    
    if ( denominator == 0 ) throw FractionReadException();    // invalid read ?  
    fixSign(); 
    simplify();
} // Fraction::Fraction

void Fraction::simplify() {
    if ( nominator == 0 ) {
        denominator = 1;
    } else {
        int gcd = std::gcd( nominator, denominator );
        nominator /= gcd;
        denominator /= gcd; 
    }
} // Fraction::simplify 

void Fraction::fixSign() {
    if ( denominator < 0 ) {
        denominator *= -1;
        nominator *= -1;
    }
} // Fraction::fixSign

int Fraction::getDenominator() const {
    return denominator;
} // Fraction::getDenominator

int Fraction::getNominator() const {
    return nominator; 
} // Fraction::nominator 

bool Fraction::zeroFraction() const {
    return nominator == 0; 
} // Fraction::zeroFraction 

Fraction Fraction::operator+( const Fraction& rhs ) const {
    int newDenom = denominator * rhs.denominator; 
    int newNom = nominator * rhs.denominator + rhs.nominator * denominator;
    return Fraction{ newNom, newDenom }; 
} // Fraction::operator+

Fraction Fraction::operator-( const Fraction& rhs ) const {
    int newDenom = denominator * rhs.denominator;
    int newNom = nominator* rhs.denominator - rhs.nominator * denominator;
    return Fraction{ newNom, newDenom }; 
} // Fraction::operator- 

Fraction Fraction::operator*( const Fraction& rhs ) const {
    int newDenom = denominator * rhs.denominator;
    int newNom = nominator* rhs.nominator;
    return Fraction{ newNom, newDenom };
} // Fraction::operator*

Fraction Fraction::operator/( const Fraction& rhs ) const {
    if ( rhs.zeroFraction() == true ) {
        throw FractionDivisionException(); 
    }
    int newDenom = denominator * rhs.nominator;
    int newNom = nominator * rhs.denominator;
    return Fraction{ newNom, newDenom }; 
} // Fraction::operator/

std::ostream& operator<<( std::ostream& out, const Fraction& f ) {
    out << f.nominator;
    if ( f.denominator != 1 ) out << "/" << f.denominator; 
    return out;
} // operator<< 