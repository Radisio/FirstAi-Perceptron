//
// Created by ericp on 31-03-22.
//

#include "SeuilIdentite.h"

double SeuilIdentite::seuil(double val) {
    return val;
}

bool SeuilIdentite::isActive(double val) {
    return val>0;
}

int SeuilIdentite::seuiledValue(double d) {
    return d >0?1:-1;
}

std::vector<double> SeuilIdentite::getInfo() {
    return std::vector<double>();
}
