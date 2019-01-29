/* European vanilla options implementation file.
 
 Created by Robert Schwartz on 1/28/19.
 Copyright © 2019 Robert Schwartz. All rights reserved. */

#define _USE_MATH_DEFINES

#include "european_vanilla_option.h"
#include <cmath> //pow(), exp(), modf(), M_PI, log10(), sqrt()

const double golden_ratio = 1.61803398875; //golden ratio approximation
const double r = 0.026; //1 year treasury rate (1/25/19)

/* calculate first and second parameters (d1 & d2) of CDF
   @return d1/d2 parameter for cumulative distribution function */
double Option::d1()
{
    double d1 = (log10(this->S / this->K) + (r + (pow(this->sigma, 2)) / 2) * this->T) / (this->sigma * sqrt(this->T));
    return d1;
}
double Option::d2()
{
    double d1 = Option::d1();
    double d2 = d1 - this->sigma * sqrt(this->T);
    return d2;
}

/* cumulative distribution function, calculate the integral using Golden Ratio.
 @param n amount of samples
 @param d value of d1 or d2
 @return cdf_d average value of all samples divided by sqrt(2PI) */
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
    cdf_d = (sum / n) / sqrt(2 * M_PI);
    return cdf_d;
}

double Option::price_call()
{
    return ((this->S) * cdf(1000, d1()) - (this->K) * exp(-r * this->T) * cdf(1000, d2()));
}

double Option::price_put()
{
    return ((this->K) * exp(-r * this->T) - this->S + this->price_call());
}
