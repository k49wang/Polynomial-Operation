#include "polynomial.h"
#include "fraction.h"
#include "exception.h"

#include <sstream>

Polynomial::Polynomial(): maxExp{ 0 } { }

Polynomial::Polynomial( const Polynomial& poly ) {
    maxExp = poly.maxExp;
    if ( maxExp == 0 ) return; 
    expression.resize( maxExp + 1 );
    for ( int i = 0; i <= maxExp; i++ ) {
        expression.at( i ) = poly.expression.at( i );
    } // for
} // Polynomial::Polynomial

Polynomial Polynomial::operator=( const Polynomial& rhs ) {
    maxExp = rhs.maxExp;
    if ( maxExp == 0 ) return *this; 
    expression.resize( maxExp + 1);
    for ( int i = 0; i <= maxExp; i++ ) {
        expression.at( i ) = rhs.expression.at( i );
    }
    return *this; 
} // Polynomial::operator= 

Polynomial Polynomial::operator+( const Polynomial& rhs ) {
    Polynomial retval; 
    retval.maxExp = maxExp >= rhs.maxExp ? maxExp : rhs.maxExp; 
    retval.expression.resize( retval.maxExp + 1 );
    for ( int i = 0; i <= retval.maxExp; i++ ) {
        if ( i <= maxExp ) {
            retval.expression.at( i ) = retval.expression.at( i ) + expression.at( i );
        } // if
        if ( i <= rhs.maxExp ) {
            retval.expression.at( i ) = retval.expression.at( i ) + rhs.expression.at( i );
        } // if
    } // for
    return retval;
} // Polynomial::operator+

Polynomial Polynomial::operator-( const Polynomial& rhs ) {
    Polynomial retval;
    retval.maxExp = maxExp >= rhs.maxExp ? maxExp : rhs.maxExp; 
    retval.expression.resize( retval.maxExp + 1 ); 
    for ( int i = 0; i <= maxExp; i++ ) {
        retval.expression.at( i ) = expression.at( i );
    } // for
    for ( int i = 0; i <= rhs.maxExp; i++ ) {
        retval.expression.at( i ) = retval.expression.at( i ) - rhs.expression.at( i );
    } // for
    return retval; 
} // Polynomial::operator-

Polynomial Polynomial::operator*( const Polynomial& rhs ) {
    Polynomial retval;
    retval.maxExp = maxExp + rhs.maxExp;
    retval.expression.resize( retval.maxExp + 1 ); 
    for ( int i = 0; i <= maxExp; i++ ) {
        for ( int j = 0; j <= rhs.maxExp; j++ ) {
            retval.expression.at( i + j ) = 
                retval.expression.at( i + j ) + expression.at( i ) * rhs.expression.at( j );
        } // for
    } // for
    return retval; 
} // Polynomial::operator* 

std::ostream& operator<<( std::ostream& out, const Polynomial& poly ) {
    bool printPlus = false;
    for ( int i = poly.maxExp; i >= 0; i-- ) {
        if ( poly.expression.at( i ).zeroFraction() == true ) {
            continue; 
        } // if
        if ( printPlus == true ) {
            out << " + "; 
        } // if
        printPlus = true; 

        if ( ( i >= 1 && poly.expression.at( i ).oneFraction() == false ) || i == 0 ) {
            out << poly.expression.at( i );
        } // if
        if ( i > 1 ) { 
            out << "x^" << i; 
        } else if ( i == 1 ) {
            out << "x";
        } // if
    } // for
    return out; 
} // operator<< 

std::istream& operator>>( std::istream& in, Polynomial& poly ) {
    std::string line;
    std::getline( in, line );
    std::istringstream iss{ line }; 
    Polynomial temp = poly;
    try {
        iss >> temp.maxExp; 
        temp.expression.clear();
        temp.expression.resize( temp.maxExp + 1 ); 
        Fraction f; 
        for ( int i = 0; i <= temp.maxExp; i++ ) {
            iss >> f;
            temp.expression.at( temp.maxExp - i ) = f; 
        } // for
        poly = temp;
    } catch ( std::ios_base::failure& ) {
        poly = temp;
    } catch ( FractionReadException& e ) {
        e.what(); 
    } // try / catch 
    return in; 
} // operator>>