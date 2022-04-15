//
// Created by ericp on 31-03-22.
//

#ifndef MYIALIBRARY_SEUILIDENTITE_H
#define MYIALIBRARY_SEUILIDENTITE_H


#include "Seuil.h"
/// >0
class SeuilIdentite: public Seuil {
public:
    double seuil(double val) override;

    bool isActive(double d) override;

    int seuiledValue(double d) override;

    std::vector<double> getInfo() override;
};


#endif //MYIALIBRARY_SEUILIDENTITE_H
