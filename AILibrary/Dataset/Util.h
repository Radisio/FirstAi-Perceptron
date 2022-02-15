//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_UTIL_H
#define MYIALIBRARY_UTIL_H
#include <string>
#include <random>

class Util {
private:
    Util(){}
public:
    static bool onlydigits(const std::string&, char );

    static double randomNormalLaw(double mean, double sigma,double min, double max);

    static double randomNormalLaw(double mean, double sigma);
};


#endif //MYIALIBRARY_UTIL_H
