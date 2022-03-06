//
// Created by ericp on 06-03-22.
//

#include "PerceptronV3Model.h"

PerceptronV3Model::PerceptronV3Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma, double mean)
        : ModelBase(dataset, resultCol, eta, seuil) {
    this->sigma = sigma;
    this->mean = mean;
    this->wGenerationType = RANDOM_NORMAL_LAW;
}

void PerceptronV3Model::fit(double seuilMin) {
    return this->fit(seuilMin,1000);
}

void PerceptronV3Model::fit(double seuilMin, int maxIteration) {
    ///Instanciation poids synaptique
    for(int j = 0;j<this->nbColEntry+1;j++)
    {
        this->w.push_back(WGeneratorFunction::randomNormalLaw(this->mean, this->sigma));
    }
    int nbIter = 0;
    double emoy;
    int nbOutput = this->output.size();
    do{
        emoy = 0.0;
        for(int i = 0;i<nbOutput;i++) {
            double y = this->evaluateY(i);
            double error = strtod(this->output[i].getData().c_str(), NULL) - y;
            std::cout << "Error : " << error << std::endl;
            emoy += (error * error) / 2;
            correctW(i, error);
        }
        emoy /= nbOutput;
        nbIter++;
        std::cout<<"Emoy : " << emoy << " seuilMin : " << seuilMin<<std::endl;
    }while(emoy>seuilMin && nbIter<maxIteration);
    if(emoy<seuilMin)
        this->predictable=true;
}


double PerceptronV3Model::predict(double x1, double x2) {
    double returnVal = 0;
    if(this->predictable){
        returnVal = this->w[0];
        returnVal += x1*this->w[1];
        returnVal += x2*this->w[2];
    }
    return returnVal>=0;
}

void PerceptronV3Model::correctW(int i, double error) {
    this->w[0]=this->w[0]+(this->eta*error* this->seuil);
    for(int j=1;j<=this->nbColEntry;j++)
    {
        this->w[j] =this->w[j]+this->eta*error;
    }
}