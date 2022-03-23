//
// Created by ericp on 22-03-22.
//

#ifndef MYIALIBRARY_LAYER_H
#define MYIALIBRARY_LAYER_H

#include <vector>
#include "../Dataset/Data.h"
#include "Neurone.h"
#include <iostream>
class Layer {
private:
    int nbNeurone;
    std::vector<Neurone> neurones;
public:
    Layer(int);
    void setNbSynapse(int);
    int getNbNeurone();
    std::vector<Data> evaluateOutput(std::vector<Data> entry);
    void debugSynapseWeight();
    void correction(std::vector<Data>,double,double);
};


#endif //MYIALIBRARY_LAYER_H
