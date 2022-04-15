//
// Created by ericp on 11-04-22.
//

#ifndef MYIALIBRARY_SCIPLOTHELPER_H
#define MYIALIBRARY_SCIPLOTHELPER_H
#include "../../sciplot/sciplot/sciplot.hpp"
#include "../Model/Model.h"
#include <string>
using namespace sciplot;
class SciplotHelper {
public:
    static Plot drawBoundariesDecisionLines(std::vector<double>, std::vector<double>, std::vector<std::vector<double>>, Model*,std::string);
    static Plot drawBoundariesDecisionZones(std::vector<double>, std::vector<double>, Model*,std::string);
    static Plot drawRegressionCurve(std::vector<double>, std::vector<double>, Model*,std::string);
    static void putEntries(std::vector<double>, std::vector<double>, std::string, std::string);
    static void putEntry(std::vector<double>, std::vector<double>, std::string, std::string);
};


#endif //MYIALIBRARY_SCIPLOTHELPER_H
