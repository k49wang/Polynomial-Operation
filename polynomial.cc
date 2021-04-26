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

bool Polynomial::zeroPolynomial() const { 
    for ( auto& fraction : expression ) {
        if ( fraction.zeroFraction() == false ) {
            return false; 
        }
    }
    return true;
} // Polynomial::zeroPolynomial 

Polynomial Polynomial::multiplySingleFraction( const Fraction& f, const int& exp ) const {
    Polynomial retval; 
    retval.maxExp = maxExp + exp;
    retval.expression.resize( retval.maxExp + 1 ); 
    for ( int i = 0; i <= maxExp; i++ ) {
        retval.expression.at( i + exp ) = expression.at( i ) * f; 
    }
    return retval;
}

Polynomial Polynomial::operator+( const Polynomial& rhs ) const {
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

Polynomial Polynomial::operator-( const Polynomial& rhs ) const {
    Polynomial retval;
    retval.maxExp = maxExp >= rhs.maxExp ? maxExp : rhs.maxExp; 
    retval.expression.resize( retval.maxExp + 1 ); 
    for ( int i = 0; i <= maxExp; i++ ) {
        retval.expression.at( i ) = expression.at( i );
    } // for
    for ( int i = 0; i <= rhs.maxExp; i++ ) {
        retval.expression.at( i ) = retval.expression.at( i ) - rhs.expression.at( i );
    } // for 
    while ( retval.expression.back().zeroFraction() == true ) {
        retval.maxExp -= 1;
        retval.expression.pop_back();
    }
    return retval; 
} // Polynomial::operator-

Polynomial Polynomial::operator*( const Polynomial& rhs ) const {
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

Polynomial Polynomial::operator/( const Polynomial& rhs ) const {
    if ( rhs.zeroPolynomial() == true ) {
        throw PolynomialDivisionException(); 
    }
    Polynomial retval;
    retval.maxExp = maxExp - rhs.maxExp; 
    retval.expression.resize( retval.maxExp + 1 ); 
    Polynomial temp = *this; 
    while ( temp.maxExp >= rhs.maxExp ) {
        int exp = temp.maxExp - rhs.maxExp; 
        Fraction coeff = temp.expression.back() / rhs.expression.back();
        Polynomial result = rhs.multiplySingleFraction( coeff, exp );
        temp = temp - result;
        retval.expression.at( exp ) = coeff; 
    }
    return retval; 
} // Polynomial::operator/ 

Polynomial Polynomial::operator%( const Polynomial& rhs ) const {
    Polynomial quotient = *this / rhs;
    Polynomial retval = *this - rhs * quotient;
    return retval;
} // Polynomial::operator%

std::ostream& operator<<( std::ostream& out, const Polynomial& poly ) {
    if ( poly.zeroPolynomial() == true ) {
        out << "0";
        return out; 
    }
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