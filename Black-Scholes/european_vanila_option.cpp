/* European vanilla options implementation file.
 
 Created by Robert Schwartz on 1/28/19.
 Copyright © 2019 Robert Schwartz. All rights reserved. */

#define _USE_MATH_DEFINES

#include "european_vanilla_option.h"
#include <cmath> //pow(), exp(), modf(), M_PI, log10()

const double golden_ratio = 1.61803398875; //golden ratio approximation

/* cumulative distribution function, calculate the integral using Golden Ratio.
 @param n amount of samples
 @param d value of d1 or d2
 @return average value of all samples */
double Option::cdf(double n, double d)
{
    double x = d / 2; //starting position
    double intpart = 1.0; //intpart for modf()
    double sum = 0.0;
    double cdf_d;
    //sum the sample values
    for (int i = 0; i < n; ++i)
    {
        sum += pow(exp(modf((x + golden_ratio) * i, &intpart)), -(pow(d, 2) / 2));
    }
    cdf_d = (sum / n) / pow(2 * M_PI, 0.5);
    return cdf_d;
}

//calculate first parameter of CDF
double Option::d1(const double S, const double K, const double T, const double sigma, const double r)
{
    double d1 = (log10(S / K) + (r + (pow(sigma, 2)) / 2) * T) / (sigma * pow(T, 0.5));
    return d1;
}

//calculate second parameter of CDF
double Option::d2(const double S, const double K, const double T, const double sigma, const double r)
{
    double d1 = Option::d1(S, K, T, sigma, r);
    double d2 = d1 - sigma * pow(T, 0.5);
    return d2;
}
