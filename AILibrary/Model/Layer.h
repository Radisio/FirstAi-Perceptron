//
// Created by ericp on 22-03-22.
//

#ifndef MYIALIBRARY_LAYER_H
#define MYIALIBRARY_LAYER_H

#include <vector>
#include "../Dataset/Data.h"
#include "Neurone.h"
#include "../Seuil/Seuil.h"
#include <iostream>
#include <fstream>
#include "../Dataset/Util.h"
#include "../Seuil/SeuilUtil.h"
class Layer {
private:
    int nbNeurone;
    std::vector<Neurone*> neurones;

public:
    Layer(int, Seuil*, Generator*);
    Layer(std::vector<Neurone*>);
    ~Layer();
    void setNbSynapse(int);
    int getNbNeurone();
    std::vector<Data> evaluateOutput(std::vector<Data> entry);
    void debugSynapseWeight(std::ostream*);
    void correction(std::vector<Data>,double,double);
    void correction(std::vector<Data>,double,double,int);
    void correctionWDW();
    void setZeroDw();
    void save(std::ofstream*);
    void setDwToNeurone(std::vector<Data>,double,double);
    void setDwToNeurone(std::vector<Data>,double,double,int);
    std::vector<double> getSynapseNeurone(int);
    std::vector<std::vector<double>> getSynapsesLayer();
    Data getLastOutputNeurone(int);
    std::vector<Data> getLastOutputNeurones();
    Seuil* getSeuilNeurones();
    std::vector<std::vector<double>> getDwAllNeurones();
    std::vector<double> getSeuilInfos();
};


#endif //MYIALIBRARY_LAYER_H
