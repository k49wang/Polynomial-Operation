#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>

class Fraction {
    int nominator;
    int denominator; 

    void simplify();                                        // let gcd( nom, denom ) = 1
    void fixSign();                                         // negative nominator if representing negative fractions
    public:
    Fraction( const int& nom = 0, const int& denom = 1 );   // constructor 

    int getDenominator() const;                             // accessor
    int getNominator() const;                               // accessor 
    bool zeroFraction() const;                              // equivalent to zero ?
    bool oneFraction() const;                               // equivalent to one 
    void setValues( const int& nom, const int& denom );     // mutator

    // four basic operator overloading for fractions 
    Fraction operator+( const Fraction& ) const;            // addition
    Fraction operator-( const Fraction& ) const;            // subtraction
    Fraction operator*( const Fraction& ) const;            // multiplication
    Fraction operator/( const Fraction& ) const;            // division
    Fraction& operator+=( const Fraction& );           // addition and assignment 
    friend std::ostream& operator<<( std::ostream&, const Fraction& );
};

std::ostream& operator<<( std::ostream&, const Fraction& ); // write to output
std::istream& operator>>( std::istream&, Fraction& );       // read from input

#endif 