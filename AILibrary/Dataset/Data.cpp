//
// Created by ericp on 12-02-22.
//

#include <stdexcept>
#include "Data.h"

Data::Data(int type, std::string data) {
    this->type = type;
    this->data = data;
}


int Data::getType() {
    return this->type;
}

std::string Data::getData() {
    return this->data;
}

void Data::setType(int type) {
    this->type = type;
}

void Data::setData(const std::string data) {
    this->data = data;
}

std::string Data::getFactorData() {
    if(this->type == DATA_TYPE_FACTOR)
        return this->data;
    else
        throw new std::runtime_error("Bad type");
}

double Data::getNumericData() {
    if(this->type == DATA_TYPE_NUMERIC)
        return strtod(this->data.c_str(),NULL);
    else
        throw new std::runtime_error("Bad type");
}
