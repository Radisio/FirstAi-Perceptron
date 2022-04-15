//
// Created by ericp on 07-04-22.
//

#include "SeuilTangeanteHyperbolique.h"

double SeuilTangeanteHyperbolique::seuil(double x) {
    return (std::exp(x) - std::exp(-x)) / (std::exp(x) + std::exp(-x));
}

bool SeuilTangeanteHyperbolique::isActive(double d) {
    return d>0;
}

int SeuilTangeanteHyperbolique::seuiledValue(double x) {
    return (std::exp(x) - std::exp(-x)) / (std::exp(x) + std::exp(-x)) > 0 ?1:-1;

}

std::vector<double> SeuilTangeanteHyperbolique::getInfo() {
    return std::vector<double>();
}
