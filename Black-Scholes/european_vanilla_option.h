/* European vanilla options header file.
 
   Created by Robert Schwartz on 1/28/19.
   Copyright © 2019 Robert Schwartz. All rights reserved. */

#ifndef european_vanilla_option_h
#define european_vanilla_option_h

//European vanilla call option
class Option
{
private:
    double S; //underlying asset price
    double K; //strike price
    double T; //maturity
    double sigma; //volatility of underlying asset
    
public:
    //default constructor
    Option()
    {
        this->S = 0.0;
        this->K = 0.0;
        this->T = 0.0;
        this->sigma = 0.0;
    }
    //constructor
    Option(double _S, double _K, double _T, double _sigma)
    {
        this->S = _S;
        this->K = _K;
        this->T = _T;
        this->sigma = _sigma;
    }
    //getters
    const double& get_S() { return S; }
    const double& get_K() { return K; }
    const double& get_T() { return T; }
    const double& get_sigma() { return sigma; }
    double d1(); //first parameter for cdf
    double d2(); //second parameter for cdf
    double cdf(double _d); //cumulative distribution function
    double price_call(); //calculate price of European vanilla call
    double price_put(); //calculate price of European vanilla put
    double price_delta(); //
};

#endif
