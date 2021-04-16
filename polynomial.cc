#include "polynomial.h"
#include "fraction.h"
#include "exception.h"

#include <iostream>

Polynomial::Polynomial( const int& n ): maxExp{ n } {
    expression = std::make_unique<Fraction*>( new Fraction[maxExp] ); 
} // Polynomial::Polynomial

Fraction* Polynomial::deepCopy() {
    Fraction* copy = new Fraction[maxExp];
    Fraction** source = expression.get();
    for ( int i = 0; i < maxExp; i++ ) {
        copy[i].setValues( source[i]->getNominator(), source[i]->getDenominator() ); 
    }
    return copy; 
} // Polynomial::deepCopy 

std::ostream& operator<<( std::ostream& out, const Polynomial& poly ) {

}