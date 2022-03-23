//
// Created by ericp on 15-03-22.
//

#ifndef MYIALIBRARY_MODEL_H
#define MYIALIBRARY_MODEL_H

///Contient les différentes couches de neurones et, lors de l'appel à la méthode fit, fait appels à ces différents neurones.

///Correction d'erreur propre au modèle
#include <vector>
#include "../Dataset/Data.h"
#include "Layer.h"
#include <iostream>
class Model {
protected:
    std::vector<std::vector<Data>> entry;
    std::vector<Layer> layers;
    std::vector<Data> output;

    std::vector<Data> evaluateOutput(std::vector<Data>);
    double eta;
public:
    Model(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<Data> output, double eta);
    ~Model();

    void initNbSynapticWeight();
    void debugSynapseWeight();
    virtual void correction(std::vector<Data>,double)=0;
    virtual void fit()=0;




};


#endif //MYIALIBRARY_MODEL_H
