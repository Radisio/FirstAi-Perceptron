//
// Created by ericp on 07-04-22.
//

#include "SeuilTangeanteHyperbolique.h"

double SeuilTangeanteHyperbolique::seuil(double x) {
    return (std::exp(x) - std::exp(-x)) / (std::exp(x) + std::exp(-x));
}
