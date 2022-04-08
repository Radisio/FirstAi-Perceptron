//
// Created by ericp on 15-03-22.
//

#include <iostream>
#include "Neurone.h"
Neurone::Neurone(Seuil* seuil) {
    this->seuil=seuil;
}

void Neurone::setNbSynapse(int nbSynapse) {
    for (int i = 0; i<=nbSynapse;i++)
    {
        /// Todo: Utiliser les différents types de générations
        this->synapse.push_back(0);
        this->Dw.push_back(0);
    }

}

Data Neurone::evaluateOutput(std::vector<Data> entry) {
    std::cout<<"ICI "<<std::endl;
    double returnVal = this->synapse[0];
    int nbCol = entry.size();
    for(int j=1,k=0;j<=nbCol;j++,k++)
    {
        returnVal += entry[k].getNumericData() * this->synapse[j];
    }
    return Data(DATA_TYPE_NUMERIC,std::to_string(this->seuil->seuil(returnVal)));
}

std::vector<double> Neurone::getSynapse() {
    return this->synapse;
}

void Neurone::correction(std::vector<Data> entry,double eta, double error) {
    int nbSynapse = this->synapse.size();
    std::cout<<"Correction synapse " << 0 << " = " << this->synapse[0]<<"+"<<eta<<"*"<<error<<"*1"<<"=>";
    this->synapse[0]=this->synapse[0]+(eta*error);
    std::cout<<this->synapse[0]<<std::endl;
    for(int j=1,k=0;j<nbSynapse;j++,k++)
    {
        ///w(t+1) = w(t)+ eta*error*xi
        std::cout<<"Correction synapse " << j << " = " << this->synapse[j]<<"+"<<eta<<"*"<<error<<"*"<<entry[k].getNumericData()<<"=>";
        this->synapse[j] =this->synapse[j]+eta*error* entry[k].getNumericData();
        std::cout<<this->synapse[j]<<std::endl;
    }
}

Neurone::Neurone(std::vector<double> synapses) {
    this->synapse = synapses;
}

void Neurone::zeroDw() {
    int nbSynapse = this->synapse.size();
    this->Dw.clear();
    for (int i = 0; i<nbSynapse;i++)
    {
        this->Dw.push_back(0);
    }
}

void Neurone::correctionWDw() {
    int nbSynapse = this->synapse.size();
    for(int j=0;j<nbSynapse;j++)
    {
        this->synapse[j] = this->synapse[j]+this->Dw[j];
    }
}

void Neurone::setDwVec(std::vector<Data> line,double eta, double error) {
    int nbDw = this->Dw.size();
    std::cout << "Delta w 0 = " << this->Dw[0]<<"+"<<eta<<"*"<<error <<"*1";
    this->Dw[0] +=eta* error;
    std::cout<<"=>"<<this->Dw[0]<<std::endl;
    for(int j=1,k=0;j<nbDw;j++,k++)
    {
        std::cout << "Delta w "<<j<<" = " << this->Dw[j]<<"+"<<eta<<"*"<<error <<"*"<<line[k].getNumericData();
        this->Dw[j] += eta*error*line[k].getNumericData();
        std::cout<<"=>"<<this->Dw[j]<<std::endl;
    }
}

Neurone::~Neurone() {
    std::cout<<"DESTRUCTION NEURONE"<<std::endl;
    if(this->seuil!=NULL)
    {
        delete this->seuil;
    }

}


