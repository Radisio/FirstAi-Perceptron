//
// Created by ericp on 12-02-22.
//

#include <stdexcept>
#include "Util.h"
bool Util::onlydigits(const std::string & dataString,const char floatingPoint) {
    int virgule = 0;
    for(const char&c : dataString){
        if(std::isdigit(c)==0){
            if(virgule>0)
                return false;
            if(c == floatingPoint)
            {
                virgule++;
            }
        }
    }
    return true;

}

double Util::randomNormalLaw(double mean, double sigma, double min, double max) {
    std::normal_distribution distribution(mean,sigma);
    std::default_random_engine generator;
    if(distribution.min()>max || distribution.max()<min)
        throw std::runtime_error("Min/Max error");
    while(true)
    {
        double number = distribution(generator);
        if(number >=min && number<=max)
        {
            return number;
        }
    }
}

double Util::randomNormalLaw(double mean, double sigma) {
    std::normal_distribution distribution(mean,sigma);
    std::default_random_engine generator;
    return distribution(generator);

}
