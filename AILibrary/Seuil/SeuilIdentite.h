//
// Created by ericp on 31-03-22.
//

#ifndef MYIALIBRARY_SEUILIDENTITE_H
#define MYIALIBRARY_SEUILIDENTITE_H


#include "Seuil.h"

class SeuilIdentite: public Seuil {
public:
    double seuil(double val) override;
};


#endif //MYIALIBRARY_SEUILIDENTITE_H
