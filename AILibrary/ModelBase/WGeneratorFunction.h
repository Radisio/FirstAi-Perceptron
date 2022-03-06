//
// Created by ericp on 22-02-22.
//

#ifndef MYIALIBRARY_WGENERATORFUNCTION_H
#define MYIALIBRARY_WGENERATORFUNCTION_H
#include <string>
#include <random>
#include <stdexcept>
#define ONLY_0              0
#define RANDOM_NORMAL_LAW   1
class WGeneratorFunction {
public:
    static double only0();

    static double randomNormalLaw(double mean, double sigma,double min, double max);

    static double randomNormalLaw(double mean, double sigma);
};


#endif //MYIALIBRARY_WGENERATORFUNCTION_H
