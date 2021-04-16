#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <memory>

class Fraction; 

class Polynomial {
    int maxExp;                                         // highest exponent
    std::unique_ptr<Fraction*> expression;              // the expression 
  
    Fraction* deepCopy();                               // deep copy the expression
  public:
    Polynomial( const int& n ); 

    Polynomial operator+( const Polynomial& );          // addition
    Polynomial operator-( const Polynomial& );          // substraction
    Polynomial operator*( const Polynomial& );          // multiplication
    Polynomial operator/( const Polynomial& );          // division
    Polynomial operator%( const Polynomial& );          // modulo 

  friend std::ostream& operator<<( std::ostream&, const Polynomial& ); 
  friend std::istream& operator>>( std::istream&, Polynomial& );
};

std::ostream& operator<<( std::ostream&, const Polynomial& ); 
std::istream& operator>>( std::istream&, Polynomial& );

#endif