#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

class BaseException {
  protected: 
    const std::string errorMsg;                                 // error message 
  public:
    BaseException( const std::string& = "" ); 
    virtual void what() = 0; 
}; 

class FractionException : public BaseException {
  public:
    FractionException( const std::string& = "" );
    virtual void what() = 0; 
};

// triggers when denominator of fraction is 0 
class FractionReadException : public FractionException {
  public:
    FractionReadException( const std::string& = "denominator is zero" );
    void what() override; 
};

// triggers when performing fraction division 
// and denominator fraction is 0 
class FractionDivisionException : public FractionException {
  public:
    FractionDivisionException( const std::string& = "division by zero" );
    void what() override;
};

class PolynomialException : public BaseException {
  public:
    PolynomialException( const std::string& = "" );
    virtual void what() = 0;
};

class PolynomialDivisionException : public PolynomialException {
  public:
    PolynomialDivisionException( const std::string& = "division by zero" ); 
    void what() override; 
};
#endif 