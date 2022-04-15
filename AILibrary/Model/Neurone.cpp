//
// Created by ericp on 15-03-22.
//

#include <iostream>
#include "Neurone.h"
Neurone::Neurone(Seuil* seuil, Generator* generator) {
    this->seuil=seuil;
    this->lastOutput= NULL;
    this->generator = generator;
}

void Neurone::setNbSynapse(int nbSynapse) {
    for (int i = 0; i<=nbSynapse;i++)
    {
        /// Todo: Utiliser les différents types de générations
        std::cout<<"ON GENERE LALALAL"<<std::endl;
        this->synapse.push_back(this->generator->generate());
        this->Dw.push_back(0);
    }

}

Data Neurone::evaluateOutput(std::vector<Data> entry) {
    std::cout<<"On evalue la sortie : "<<std::endl;
    double returnVal = this->synapse[0];
    int nbCol = entry.size();
    for(int j=1,k=0;j<=nbCol;j++,k++)
    {
        returnVal += entry[k].getNumericData() * this->synapse[j];
    }
    if(this->lastOutput!=nullptr)
        delete this->lastOutput;
    this->lastOutput = new Data(DATA_TYPE_NUMERIC,std::to_string(this->seuil->seuil(returnVal)));
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

Neurone::Neurone(std::vector<double> synapses,Seuil* s) {
    this->synapse = synapses;
    this->lastOutput= NULL;
    this->seuil = s;

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
    if(this->lastOutput!=NULL)
    {
        delete this->lastOutput;
    }
    if(this->generator!=NULL)
    {
        delete this->generator;
    }

}

Data Neurone::getLastOutput() {
    return *this->lastOutput;
}

Seuil *Neurone::getSeuil() {
    return this->seuil;
}

std::vector<double> Neurone::getDw() {
    return this->Dw;
}


