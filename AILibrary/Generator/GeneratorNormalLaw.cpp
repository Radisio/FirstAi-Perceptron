//
// Created by ericp on 10-04-22.
//

#include "GeneratorNormalLaw.h"

double GeneratorNormalLaw::generate() {
    std::normal_distribution distribution(this->mean,this->sigma);
    std::random_device rd;
    std::default_random_engine generator(rd());
    if(distribution.min()>this->max || distribution.max()<this->min)
        throw std::runtime_error("Min/Max error");
    while(true)
    {
        double number = distribution(generator);
        if(number >=this->min && number<=this->max)
        {
            return number;
        }
    }
}

GeneratorNormalLaw::GeneratorNormalLaw(double mean, double sigma, double min, double max) {
    this->mean = mean;
    this->sigma = sigma;
    this->min = min;
    this->max = max;
}

GeneratorNormalLaw::GeneratorNormalLaw(double mean, double sigma) : GeneratorNormalLaw(mean,sigma,-2,2) {
}
