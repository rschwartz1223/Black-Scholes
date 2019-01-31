/* Black-Scholes model to price a European vanilla call and
   put option. This model does not take into consideration
   dividend yield.
 
   Created by Robert Schwartz on 1/28/19.
   Copyright © 2019 Robert Schwartz. All rights reserved. */

#include "european_vanilla_option.h"
#include <iostream>

const double r = 0.026; //1 year treasury rate (1/25/19)

int main(int argc, const char * argv[])
{
    Option test_option(100.0, 100.0, 1.0, 0.2); //test option
    
    std::cout << "Underlying Asset Price:\t" << test_option.get_S() << std::endl;
    std::cout << "Strike Price:\t\t\t" << test_option.get_K() << std::endl;
    std::cout << "Maturity:\t\t\t\t" << test_option.get_T() << std::endl;
    std::cout << "Volatility:\t\t\t\t" << test_option.get_sigma() << std::endl;
    std::cout << "1 Year Treasury Rate:\t" << r << std::endl;
    std::cout << "Call Price:\t\t\t\t" << test_option.price_call() << std::endl;
    std::cout << "Put Price:\t\t\t\t" << test_option.price_put() << std::endl;
    std::cout << "Call Delta:\t\t\t\t" << test_option.call_delta() << std::endl;
    std::cout << "Put Delta:\t\t\t\t" << test_option.put_delta() << std::endl;
    std::cout << "Option Gamma:\t\t\t" << test_option.gamma() << std::endl;
    //std::cout << "Call Theta:\t\t\t\t" << test_option.call_theta() << std::endl;
    //std::cout << "Put Theta:\t\t\t\t" << test_option.put_theta() << std::endl;
    
    return 0;
}
