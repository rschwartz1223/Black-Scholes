/* Implementation of CDF using monte-carlo integration. Generates
   coordinates using the Golden Ratio and modf() as a pseudo-rng.
 
 Created by Robert Schwartz on 1/28/19.
 Copyright © 2019 Robert Schwartz. All rights reserved. */

#include <cmath> //pow(), exp(), modf()

const double golden_ratio = 1.61803398875; //golden ratio approximation

/* calculate the integral of function using Golden Ratio
 @param n amount of samples
 @return sum/n average value of all samples */
double integrate(int n)
{
    double x = 0.5; //starting position
    double intpart = 1.0; //intpart for modf()
    double sum = 0.0;
    
    //sum the sample values
    for (int i = 0; i < n; ++i)
        sum += pow(cos(modf((x + golden_ratio) * i, &intpart)), 2);
    
    return (sum / n);
}
