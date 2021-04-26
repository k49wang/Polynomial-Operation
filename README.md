# Polynomial-Operation

Execution: <br />
    make <br />
    ./polynomialOperation < [ input-file ]

1.  Performs polynomial operations
    -   addition, subtraction, multiplication, division, mudulo 
    -   supports fraction operations as well 

2.  Program reads from input file, 
    each line represents a polynomial expression 

3.  While reading:
    -   first number read represents the highest exponent of the polynomial
    -   then every two numbers read forms each coefficient 
    -   from highest exponent to lowest exponent in order 
    -   if read fails, such as reading the coefficient with 0 being the denominator, exception is raised and strong guarantee is offered

4.  Sample input file:
    3 3 1 2 0 1 4 5 -1 6
    -   3 means the highest exponent of the polynomial 
    -   pair of (1, 2) represents 1/2 * x^3 
    -   pair of (0, 1) represents 0/1 * x^2
    -   pair of (4, 5) represents 4/5 * x^1 
    -   pair of (-1, 6) represents -1/6 * x^0
    -   if number of pairs read is less than the number of components in polynomial, then remaining coefficients will be zero by default