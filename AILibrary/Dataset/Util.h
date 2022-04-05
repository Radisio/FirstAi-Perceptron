//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_UTIL_H
#define MYIALIBRARY_UTIL_H
#include <string>
#include <random>
#include <vector>
#include "Data.h"

class Util {
private:
    Util(){}
public:
    static bool onlydigits(const std::string&, char );
    static void writeLog(std::ostream*, const std::string&);
    static void writeLogEndline(std::ostream*, const std::string&);
    static std::vector<std::string> parseString(std::string, std::string);
    static std::vector<double> stringVectorToDouble(std::vector<std::string>);
    static std::vector<double> dataVectorToDouble(std::vector<Data>);

    static std::vector<std::vector<double>> dataTabToDouble(std::vector<std::vector<Data>>);
    static std::vector<double> dataTabToDoubleVector(std::vector<std::vector<Data>>, int);

};


#endif //MYIALIBRARY_UTIL_H
