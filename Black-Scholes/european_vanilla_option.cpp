/* European vanilla options implementation file.
 
 Created by Robert Schwartz on 1/28/19.
 Copyright © 2019 Robert Schwartz. All rights reserved. */

#define _USE_MATH_DEFINES

#include "european_vanilla_option.h"
#include <cmath> //pow(), exp(), M_PI, log10(), sqrt()

/* calculate first and second parameters (d1 & d2) of CDF
   @return d1/d2 parameter for cumulative distribution function */
double Option::d1()
{
    double d1 = (log10(this->S / this->K) + (r + (pow(this->sigma, 2)) / 2) * (this->T)) / (this->sigma * sqrt(this->T));
    return d1;
}
double Option::d2()
{
    double d1 = Option::d1();
    double d2 = d1 - this->sigma * sqrt(this->T);
    return d2;
}

double Option::pdf(double d)
{
    return (1 / sqrt(2 * M_PI)) * exp(-pow(d, 2) / 2);
}

/* cumulative distribution function for standard normal distribution using recursion.
 @param d value of d1 or d2 */
double Option::cdf(double d)
{
    double k = 1.0 / (1.0 + 0.2316419 * d);
    double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    if (d >= 0.0)
        return (1.0 - (1.0 / (sqrt(2 * M_PI))) * pdf(d1()) * k_sum);
    else
        return (1.0 - cdf(-d));
}

double Option::call_price()
{
    return ((this->S) * cdf(d1()) - (this->K) * exp(-r * this->T) * cdf(d2()));
}

double Option::put_price()
{
    return ((this->K) * exp(-r * this->T) - this->S + this->call_price());
}

double Option::call_delta()
{
    return cdf(d1());
}

double Option::put_delta()
{
    return call_delta() - 1;
}

double Option::gamma()
{
    return (1 / (this->S * this->sigma * sqrt(this->T) * sqrt(2 * M_PI))) * pdf(d1());
}

double Option::call_theta()
{
    return ((1/365) * (-((this->S * this->sigma * pdf(d1())) / (2 * sqrt(this->T) * sqrt(2 * M_PI))) -
                      (r * this->K * exp(-r * this->T * cdf(d2())))));
}

double Option::put_theta()
{
    return ((1/365) * (-((this->S * this->sigma * pdf(d1())) / (2 * sqrt(this->T) * sqrt(2 * M_PI))) +
                      (r * this->K * exp(-r * this->T * cdf(-1 * d2())))));
}

double Option::vega()
{
    return (1 / 100) * this->S * sqrt(this->T) * (1 / sqrt(2 * M_PI)) * pdf(d1());
}

double Option::call_rho()
{
    return (1 / 100) * this->K * this->T * exp(-r * this->T) * cdf(d2());
}

double Option::put_rho()
{
    return (-1 / 100) * this->K * this->T * exp(-r * this->T) * cdf(-d2());
}
