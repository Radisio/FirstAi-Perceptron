//
// Created by ericp on 07-04-22.
//

#include "SeuilSigmoide.h"

double SeuilSigmoide::seuil(double x) {
    return 1/(1+std::exp(-this->c*x));
}

SeuilSigmoide::SeuilSigmoide(double c) {
    this->c = c;

}

bool SeuilSigmoide::isActive(double d) {
    return d>=0.5;
}

int SeuilSigmoide::seuiledValue(double d) {
    return d >0.5?1:-0;
}

std::vector<double> SeuilSigmoide::getInfo() {
    return std::vector<double>({this->c});
}
