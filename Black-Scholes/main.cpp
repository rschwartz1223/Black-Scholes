/* Black-Scholes model to price a European vanilla call and
   put option. This model does not take into consideration
   dividend yield.
 
   Created by Robert Schwartz on 1/28/19.
   Copyright © 2019 Robert Schwartz. All rights reserved. */

#include "european_vanilla_option.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>

int main(int argc, const char * argv[])
{
    //open text file
    std::fstream options_file;
    options_file.open("options_data.txt");
    std::map<unsigned int, Option> options_list; //map of options from text file
    std::vector<double> option_prices(1530); //vector of option prices from text file, used to check calculations
    double option_number, volatility, time_in_days, strike_price, option_price; //variables for values in text file
    
    //TODO: Fix File Input
    //read data from options_data.txt
    while(options_file >> option_number >> volatility >> time_in_days >> strike_price >> option_price)
    {
        options_list.insert(std::pair<double, Option>(option_number, Option(100, strike_price, (time_in_days / 365), volatility) ) );
        option_prices.push_back(option_price);
    }
    //close file
    options_file.close();
    
//    auto it = options_list.begin();
//    std::cout << "CALCULATED VALUE:\tOPTION 1 CALL PRICE = " << it->second.call_price() << std::endl;
//    std::cout << "EXPECTED VALUE:\t\tOPTION 1 CALL PRICE = " << option_prices[0] << std::endl;
//
//
//    Option test_option(100.0, 100.0, 1.0, 0.2); //test option
//    
//    std::cout << "Underlying Asset Price:\t" << test_option.get_S() << std::endl;
//    std::cout << "Strike Price:\t\t\t" << test_option.get_K() << std::endl;
//    std::cout << "Maturity:\t\t\t\t" << test_option.get_T() << std::endl;
//    std::cout << "Volatility:\t\t\t\t" << test_option.get_sigma() << std::endl;
//    std::cout << "1 Year Treasury Rate:\t" << r << std::endl;
//    std::cout << "Call Price:\t\t\t\t" << test_option.call_price() << std::endl;
//    std::cout << "Put Price:\t\t\t\t" << test_option.put_price() << std::endl;
//    std::cout << "Call Delta:\t\t\t\t" << test_option.call_delta() << std::endl;
//    std::cout << "Put Delta:\t\t\t\t" << test_option.put_delta() << std::endl;
//    std::cout << "Option Gamma:\t\t\t" << test_option.gamma() << std::endl;
//    std::cout << "Call Theta:\t\t\t\t" << test_option.call_theta() << std::endl;
//    std::cout << "Put Theta:\t\t\t\t" << test_option.put_theta() << std::endl;
//    std::cout << "Vega:\t\t\t\t\t" << test_option.vega() << std::endl;
//    std::cout << "Call Rho:\t\t\t\t" << test_option.call_rho() << std::endl;
//    std::cout << "Put Rho:\t\t\t\t" << test_option.put_rho() << std::endl;
    
    return 0;
}
