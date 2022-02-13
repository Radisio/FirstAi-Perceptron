//
// Created by ericp on 12-02-22.
//

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
