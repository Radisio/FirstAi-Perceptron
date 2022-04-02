//
// Created by ericp on 02-04-22.
//

#ifndef MYIALIBRARY_SEUILRELU_H
#define MYIALIBRARY_SEUILRELU_H

#include "Seuil.h"
class SeuilPReLu: public Seuil {
private:
    double borneInf, borneSup;
public:
    SeuilPReLu(double,double);
    double seuil(double) override;

};


#endif //MYIALIBRARY_SEUILRELU_H
