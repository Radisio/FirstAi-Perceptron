//
// Created by ericp on 10-04-22.
//

#ifndef MYIALIBRARY_GENERATORNORMALLAW_H
#define MYIALIBRARY_GENERATORNORMALLAW_H


#include "Generator.h"
#include <random>
#include <stdexcept>
class GeneratorNormalLaw: public Generator {
private:
    double mean;
    double sigma;
    double min;
    double max;
public:
    GeneratorNormalLaw(double,double);
    GeneratorNormalLaw(double,double,double,double);
    double generate() override;
};


#endif //MYIALIBRARY_GENERATORNORMALLAW_H
