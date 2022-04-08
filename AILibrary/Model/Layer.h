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
class Layer {
private:
    int nbNeurone;
    std::vector<Neurone*> neurones;

public:
    Layer(int, Seuil*);
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
    Data getLastOutputNeurone(int);
    std::vector<Data> getLastOutputNeurones();
};


#endif //MYIALIBRARY_LAYER_H
