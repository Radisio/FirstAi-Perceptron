//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_UTIL_H
#define MYIALIBRARY_UTIL_H
#include <string>
#include <random>
#include <vector>
class Util {
private:
    Util(){}
public:
    static bool onlydigits(const std::string&, char );
    static void writeLog(std::ostream*, const std::string&);
    static void writeLogEndline(std::ostream*, const std::string&);
    static std::vector<std::string> parseString(std::string, std::string);
    static std::vector<double> stringVectorToDouble(std::vector<std::string>);

};


#endif //MYIALIBRARY_UTIL_H
