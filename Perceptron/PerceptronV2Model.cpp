//
// Created by ericp on 15-02-22.
//

#include "PerceptronV2Model.h"




PerceptronV2Model::PerceptronV2Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma, double mean)
: ModelBase(dataset, resultCol, eta, seuil) {
    this->sigma = sigma;
    this->mean = mean;
}

void PerceptronV2Model::fit(double seuilMin) {
    return this->fit(seuilMin,1000);
}

void PerceptronV2Model::fit(double seuilMin, int maxIteration) {
    ///Instanciation poids synaptique
    for(int j = 0;j<this->nbColEntry+1;j++)
    {
        this->w.push_back(Util::randomNormalLaw(this->mean, this->sigma));
    }
    int nbIter = 0;
    double emoy;
    ///Instanciation Dwi
    this->zeroDW();

    do{
        emoy = 0.0;
        for(int j = 0;j<this->nbColEntry+1;j++)
        {
            double y = this->evaluateY(j);
            double error =strtod(this->output[j].getData().c_str(),NULL) - y;
            std::cout<<"Error : " <<error<<std::endl;
            this->Dw[j] += error;
            emoy += (error*error)/2;
        }
        ///Correction des poids synaptiques
        for(int j = 0;j< this->nbColEntry+1;j++)
        {
            this->correctW(j,this->Dw[j]);
        }
        emoy /= this->nbColEntry;
        nbIter++;
        std::cout<<"Emoy : " << emoy << " seuilMin : " << seuilMin<<std::endl;
    }while(emoy>seuilMin && nbIter<maxIteration);
    if(emoy<seuilMin)
        this->predictable=true;
}

void PerceptronV2Model::zeroDW() {
    this->Dw.clear();
    for(int i = 0; i<this->nbColEntry+1;i++)
    {
        this->Dw.push_back(0.0);
    }
}

double PerceptronV2Model::predict(double d, double d1) {
    return ModelBase::predict(d, d1);
}
