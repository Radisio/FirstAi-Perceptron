//
// Created by ericp on 12-02-22.
//

#include "DataFactory.h"
DataFactory::DataFactory() {
    this->floatingPoint=',';
}

DataFactory::DataFactory(const char floatingPoint) {
    this->floatingPoint = floatingPoint;
}

Data DataFactory::getData(const std::string& dataString) {
    int type = DATA_TYPE_FACTOR;
    if(Util::onlydigits(dataString,this->floatingPoint)){
        type= DATA_TYPE_NUMERIC;
    }
    return {type, dataString};
}


