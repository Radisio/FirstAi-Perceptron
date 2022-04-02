//
// Created by ericp on 02-04-22.
//

#include "SeuilPReLu.h"
SeuilPReLu::SeuilPReLu(double borneInf, double borneSup) {
    this->borneInf = borneInf;
    this->borneSup = borneSup;
}
double SeuilPReLu::seuil(double d) {
    return d>=0?this->borneSup:this->borneInf;
}