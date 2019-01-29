/* European vanilla options header file.
 
   Created by Robert Schwartz on 1/28/19.
   Copyright © 2019 Robert Schwartz. All rights reserved. */

#ifndef european_vanilla_option_h
#define european_vanilla_option_h

const double r = 0.026; //1 year treasury rate (1/25/19)

//European vanilla call option
class Call
{
private:
    double S; //underlying asset price
    double K; //strike price
    double T; //maturity
    double sigma; //volatility of underlying asset
    
public:
    void set_S(double a) { S = a; }
    void set_K(double b) { K = b; }
    void set_T(double c) { T = c; }
    void set_sigma(double d) { sigma = d; }
    
    const double& get_S() { return S; }
    const double& get_K() { return K; }
    const double& get_T() { return T; }
    const double& get_sigma() { return sigma; }
    
    double d1(const double S, const double K, const double T, const double sigma, const double r);
    double d2(const double sigma, const double T);
    
    //default constructor
    Call()
    {
        set_S(0.0);
        set_K(0.0);
        set_T(0.0);
        set_sigma(0.0);
    }
    //constructor
    Call(double _S, double _K, double _T, double _sigma)
    {
        set_S(_S);
        set_K(_K);
        set_T(_T);
        set_sigma(_sigma);
    }
    
};

//European vanilla put option
class Put
{
private:
    double S; //underlying asset price
    double K; //strike price
    double T; //maturity
    double sigma; //volatility of underlying asset
    
public:
    void set_S(double a) { S = a; }
    void set_K(double b) { K = b; }
    void set_T(double c) { T = c; }
    void set_sigma(double d) { sigma = d; }
    
    const double& get_S() { return S; }
    const double& get_K() { return K; }
    const double& get_T() { return T; }
    const double& get_sigma() { return sigma; }
    
    //default constructor
    Put()
    {
        set_S(0.0);
        set_K(0.0);
        set_T(0.0);
        set_sigma(0.0);
    }
    //constructor
    Put(double _S, double _K, double _T, double _sigma)
    {
        set_S(_S);
        set_K(_K);
        set_T(_T);
        set_sigma(_sigma);
    }
    
};

#endif
