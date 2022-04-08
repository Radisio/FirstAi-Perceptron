//
// Created by ericp on 07-04-22.
//

#ifndef MYIALIBRARY_SEUILTANGEANTEHYPERBOLIQUE_H
#define MYIALIBRARY_SEUILTANGEANTEHYPERBOLIQUE_H


#include "Seuil.h"
#include <math.h>
class SeuilTangeanteHyperbolique : public Seuil {
public:
    double seuil(double x) override;
};


#endif //MYIALIBRARY_SEUILTANGEANTEHYPERBOLIQUE_H
