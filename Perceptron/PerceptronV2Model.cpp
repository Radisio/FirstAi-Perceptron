//
// Created by ericp on 15-02-22.
//

#include "PerceptronV2Model.h"

void PerceptronV2Model::fit(int maxIteration) {
    ///Instanciation poids synaptique
    for(int j = 0;j<this->nbColEntry;j++)
    {
        this->w.push_back(Util::randomNormalLaw(this->mean, this->sigma));
    }
    int nbIter = 0;
    double emoy;
    ///Instanciation Dwi
    for(int j = 0;j<this->nbColEntry;j++)
    {
        this->Dw.push_back(0.0);
    }
    do{
        emoy = 0.0;
        this->Dw.clear();
        for(int j = 0;j<this->nbColEntry;j++)
        {
            double y = this->evaluateY(j);
            double error =strtod(this->output[j].getData().c_str(),NULL) - y;
            Dw[j] += this->eta*error*strtod(this->output[j].getData().c_str(),NULL);
            emoy += (error*error)/2;
        }
        ///Correction des poids synaptiques
        for(int j = 0;j< this->nbColEntry;j++)
        {

        }


    }while(emoy>this->seuil && nbIter<maxIteration);

}

double PerceptronV2Model::predict(double d, double d1) {
    return ModelBase::predict(d, d1);
}

void PerceptronV2Model::correctW(int i, double d) {
    ModelBase::correctW(i, d);
}

PerceptronV2Model::PerceptronV2Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma, double mean)
: ModelBase(dataset, resultCol, eta, seuil) {
    this->sigma = sigma;
    this->mean = mean;
}

