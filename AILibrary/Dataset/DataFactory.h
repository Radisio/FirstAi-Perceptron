//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_DATAFACTORY_H
#define MYIALIBRARY_DATAFACTORY_H


#include "Data.h"
#include <string>
#include "Util.h"
class DataFactory {
private:
    char floatingPoint;

public:
    DataFactory();
    DataFactory(char);
    Data getData(const std::string&);
};


#endif //MYIALIBRARY_DATAFACTORY_H
