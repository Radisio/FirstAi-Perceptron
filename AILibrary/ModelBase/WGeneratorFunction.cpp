//
// Created by ericp on 22-02-22.
//

#include "WGeneratorFunction.h"

double WGeneratorFunction::randomNormalLaw(double mean, double sigma, double min, double max) {
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

double WGeneratorFunction::randomNormalLaw(double mean, double sigma) {
    std::normal_distribution distribution(mean,sigma);
    std::default_random_engine generator;
    return distribution(generator);

}

double WGeneratorFunction::only0() {
    return 0.0;
}
