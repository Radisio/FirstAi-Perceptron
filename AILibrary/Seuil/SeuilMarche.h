//
// Created by ericp on 31-03-22.
//

#ifndef MYIALIBRARY_SEUILMARCHE_H
#define MYIALIBRARY_SEUILMARCHE_H


#include "Seuil.h"

class SeuilMarche: public Seuil {
private:
    double marche;
public:
    SeuilMarche(double);
    double seuil(double d) override;

    bool isActive(double d) override;

    int seuiledValue(double d) override;

    std::vector<double> getInfo() override;
};


#endif //MYIALIBRARY_SEUILMARCHE_H
