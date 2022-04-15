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
#include "../Seuil/Seuil.h"
#include <iostream>
#include "../Seuil/SeuilIdentite.h"
#include "../Dataset/Util.h"
class Model {
protected:
    std::ostream* fp;
    std::vector<std::vector<Data>> entry;
    std::vector<Layer> layers;
    std::vector<std::vector<Data>> output;

    std::vector<Data> evaluateOutput(std::vector<Data>);
    double eta;
    void readLayersInFile(std::string);
    bool stopWhenNoError;
    bool multiLayer;
public:
    Model(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta);
    Model(std::string filename);
    ~Model();

    void initNbSynapticWeight();
    void debugSynapseWeight();
    virtual void correction(std::vector<Data>,double)=0;
    virtual void correction(std::vector<Data>, std::vector<double>)=0;
    virtual void fit(int=1000)=0;
    void debugLog(std::string="stdout");
    std::vector<Data> predict(std::vector<Data>);
    void zeroDw();
    void save(std::string);
    bool modelValid();
    std::vector<std::vector<double>> getSynapseLastLayer();
    Seuil* getSeuilLastLayer();


};


#endif //MYIALIBRARY_MODEL_H
