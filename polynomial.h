#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <memory>

class Fraction; 

class Polynomial {
    unsigned int maxExp;                                // highest exponent
    std::unique_ptr<Fraction*> expression;              // the expression 
  public:
    Polynomial( const int& n ); 
    
};

#endif