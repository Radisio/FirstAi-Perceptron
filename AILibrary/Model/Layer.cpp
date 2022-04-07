//
// Created by ericp on 22-03-22.
//

#include "Layer.h"

Layer::Layer(int nbNeurone) {
    this->nbNeurone = nbNeurone;
    for(int i = 0; i<nbNeurone;i++)
    {
        this->neurones.emplace_back();
    }
}

void Layer::setNbSynapse(int nbSynapse) {
    for(int i = 0; i<nbNeurone;i++)
    {
        this->neurones[i].setNbSynapse(nbSynapse);
    }
}

int Layer::getNbNeurone() {
    return this->nbNeurone;
}

std::vector<Data> Layer::evaluateOutput(std::vector<Data> entry) {
    std::vector<Data> output;
    for (int i = 0; i<this->nbNeurone;i++)
    {
        output.push_back(this->neurones[i].evaluateOutput(entry));
    }
    return output;
}

void Layer::debugSynapseWeight(std::ostream* fp) {
    for (int i =0;i<this->nbNeurone;i++)
    {
        *fp<<"Neurone (" << i <<")"<<std::endl;
        std::vector<double> synapses = this->neurones[i].getSynapse();
        int nbSynapses = synapses.size();
        for(int j=0;j<nbSynapses;j++)
        {
            *fp<<"w"<<j<<":"<<synapses[j]<<std::endl;
        }
        *fp<<"------------------------------------"<<std::endl;
    }
}

void Layer::correction(std::vector<Data> line,double eta,double error) {
    for (int i =0;i<this->nbNeurone;i++)
    {
        this->neurones[i].correction(line,eta,error);
    }
}

void Layer::save(std::ofstream* out) {
    for(int i =0;i< this->nbNeurone;i++)
    {
        int nbSynapse = this->neurones[i].getSynapse().size();
        for(int j = 0;j<nbSynapse;j++)
        {
            *out<<this->neurones[i].getSynapse()[j]<<',';
        }
        *out<<"|";
    }
}

Layer::Layer(std::vector<Neurone> neurones) {
    this->neurones = neurones;
    this->nbNeurone = neurones.size();
}

void Layer::setDwToNeurone(std::vector<Data> line,double eta, double error) {
    for (int i =0;i<this->nbNeurone;i++)
    {
        this->neurones[i].setDwVec(line,eta,error);
    }
}
void Layer::setDwToNeurone(std::vector<Data> line,double eta, double error, int i) {
    this->neurones[i].setDwVec(line,eta,error);
}
void Layer::correctionWDW() {
    for (int i =0;i<this->nbNeurone;i++)
    {
        this->neurones[i].correctionWDw();
    }
}

void Layer::setZeroDw() {
    for (int i =0;i<this->nbNeurone;i++)
    {
        this->neurones[i].zeroDw();
    }

}

void Layer::correction(std::vector<Data> line,double eta,double error, int i) {
    this->neurones[i].correction(line,eta,error);
}

std::vector<double> Layer::getSynapseNeurone(int i) {
    return this->neurones[i].getSynapse();
}


