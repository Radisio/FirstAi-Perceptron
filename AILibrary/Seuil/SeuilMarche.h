//
// Created by ericp on 31-03-22.
//

#ifndef MYIALIBRARY_SEUILMARCHE_H
#define MYIALIBRARY_SEUILMARCHE_H


#include "Seuil.h"

class SeuilMarche: public Seuil {
public:
    double seuil(double d) override;
};


#endif //MYIALIBRARY_SEUILMARCHE_H
