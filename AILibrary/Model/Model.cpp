//
// Created by ericp on 15-03-22.
//

#include "Model.h"

Model::Model(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<Data> output, double eta) {
    this->entry = entry;
    this->layers = layers;
    this->output = output;
    this->eta = eta;
}

Model::~Model(){}

void Model::initNbSynapticWeight() {
    ///Set le nombre de poids synaptiques de la première "vrai" couche (je ne compte pas l'entrée)
    /// +1 pour le w0
    this->layers[0].setNbSynapse(this->entry[0].size());
    int nbLayer = this->layers.size();
    for(int i = 1,k=0; i<nbLayer;i++,k++)
    {
        this->layers[i].setNbSynapse(this->layers[k].getNbNeurone());
    }
}

std::vector<Data> Model::evaluateOutput(std::vector<Data> singleEntry) {
    ///Il faut évaluer la sortie pour chaque layers (donc vecteur de donné)
    int nbLayer = this->layers.size();
    std::vector<Data> outputEval = this->layers[0].evaluateOutput(singleEntry);
    for (int i = 1; i<nbLayer;i++)
    {
        outputEval = this->layers[i].evaluateOutput(outputEval);
    }
    return outputEval;

}

void Model::debugSynapseWeight() {
    int nbLayer = this->layers.size();
    for (int i = 0;i<nbLayer;i++)
    {
        std::cout<<"Layer : "<< i << std::endl;
        this->layers[i].debugSynapseWeight();
        std::cout<<"///////////////////////////////////"<<std::endl;
    }
}




