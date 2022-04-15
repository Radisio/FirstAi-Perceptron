//
// Created by ericp on 31-03-22.
//

#ifndef MYIALIBRARY_SEUIL_H
#define MYIALIBRARY_SEUIL_H

#include <vector>

class Seuil {
public:
    virtual double seuil (double)=0;
    virtual bool isActive(double) = 0;
    virtual int seuiledValue(double)=0;
    virtual std::vector<double> getInfo()=0;
};


#endif //MYIALIBRARY_SEUIL_H
