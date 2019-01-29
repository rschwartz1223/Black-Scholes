/* European vanilla options implementation file.
 
 Created by Robert Schwartz on 1/28/19.
 Copyright © 2019 Robert Schwartz. All rights reserved. */

#include "european_vanilla_option.h"
#include <cmath> //log10(), 

//calculate first parameter of CDF
double Call::d1(const double S, const double K, const double T, const double sigma, const double r)
{
    return (log10(S / K) + (r + (pow(sigma, 2)) / 2) * T) / (sigma * pow(T, 0.5));
}

//calculate second parameter of CDF
double Call::d2(const double
