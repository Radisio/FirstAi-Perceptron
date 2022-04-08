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
