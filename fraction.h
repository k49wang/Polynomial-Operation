#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>

class Fraction {
    const int nominator;
    const int denominator; 

    public:
    Fraction( const int& nom = 0, const int& denom = 1 );   // constructor 

    int getDenominator() const;                             // accessor
    int getNominator() const;                               // accessor 

    // five basic operator overloading for fractions 
    Fraction operator+( const Fraction& rhs ) const;        // addition
    Fraction operator-( const Fraction& rhs ) const;        // subtraction
    Fraction operator*( const Fraction& rhs ) const;        // multiplication
    Fraction operator/( const Fraction& rhs ) const;        // division
    Fraction operator%( const Fraction& rhs ) const;        // modulo 

    friend std::istream& operator>>( std::istream&, Fraction& );
    friend std::ostream& operator<<( std::ostream&, const Fraction& );
};

std::istream& operator>>( std::istream&, Fraction& );       // read from input
std::ostream& operator<<( std::ostream&, const Fraction& ); // write to output

#endif 