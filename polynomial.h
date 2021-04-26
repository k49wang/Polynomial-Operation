#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>
#include <vector>

class Fraction; 

class Polynomial {
    int maxExp;                                         // highest exponent
    std::vector<Fraction> expression;                   // the expression 
  
    bool zeroPolynomial() const;                        // expression is zero  
    Polynomial multiplySingleFraction( const Fraction&, const int& ) const; 
  public:
    Polynomial();                                       // default constructor
    Polynomial( const Polynomial& );                    // copy construcor
    Polynomial operator=( const Polynomial& );          // copy assignment 

    Polynomial operator+( const Polynomial& ) const;    // addition
    Polynomial operator-( const Polynomial& ) const;    // substraction
    Polynomial operator*( const Polynomial& ) const;    // multiplication
    Polynomial operator/( const Polynomial& ) const;    // division
    Polynomial operator%( const Polynomial& ) const;    // modulo 

  friend std::ostream& operator<<( std::ostream&, const Polynomial& ); 
  friend std::istream& operator>>( std::istream&, Polynomial& );
};

std::ostream& operator<<( std::ostream&, const Polynomial& ); 
std::istream& operator>>( std::istream&, Polynomial& );

#endif