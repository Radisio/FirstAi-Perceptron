//
// Created by ericp on 15-03-22.
//

#include "Neurone.h"
Neurone::Neurone() {

}

void Neurone::setNbSynapse(int nbSynapse) {
    for (int i = 0; i<=nbSynapse;i++)
    {
        /// Todo: Utiliser les différents types de générations
        this->synapse.push_back(0);
    }

}

Data Neurone::evaluateOutput(std::vector<Data> entry) {
    double returnVal = this->synapse[0];
    int nbCol = entry.size();
    for(int j=1,k=0;j<=nbCol;j++,k++)
    {
        returnVal += strtod(entry[k].getData().c_str(),NULL) * this->synapse[j];
    }
    return Data(DATA_TYPE_NUMERIC,std::to_string(returnVal));
}

std::vector<double> Neurone::getSynapse() {
    return this->synapse;
}

void Neurone::correction(std::vector<Data> entry,double eta, double error) {
    int nbSynapse = this->synapse.size();
    for(int i =0;i<nbSynapse;i++)
    {
        this->synapse[i]=this->synapse[i]+error;
    }

    this->synapse[0]=this->synapse[0]+(eta*error);
    for(int j=1,k=0;j<nbSynapse;j++,k++)
    {
        ///w(t+1) = w(t)+ eta*error*xi
        this->synapse[j] =this->synapse[j]+(eta*error* entry[k].getNumericData());
    }
}

