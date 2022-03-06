//
// Created by ericp on 15-02-22.
//

#include "PerceptronV2Model.h"




PerceptronV2Model::PerceptronV2Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma, double mean)
: ModelBase(dataset, resultCol, eta, seuil) {
    this->sigma = sigma;
    this->mean = mean;
    this->wGenerationType = RANDOM_NORMAL_LAW;
}

void PerceptronV2Model::fit(double seuilMin) {
    return this->fit(seuilMin,1000);
}

void PerceptronV2Model::fit(double seuilMin, int maxIteration) {
    ///Instanciation poids synaptique
    for(int j = 0;j<this->nbColEntry+1;j++)
    {
        this->w.push_back(WGeneratorFunction::randomNormalLaw(this->mean, this->sigma));
    }
    int nbIter = 0;
    double emoy;
    int nbOutput = this->output.size();
    ///Instanciation Dwi
    this->zeroDW();
    do{
        emoy = 0.0;
        for(int i = 0;i<nbOutput;i++) {
            double y = this->evaluateY(i);
            double error = strtod(this->output[i].getData().c_str(), NULL) - y;
            std::cout << "Error : " << error << std::endl;
            addDwi(i,error);
            emoy += (error * error) / 2;

        }
        ///Correction des poids synaptiques
        for(int j = 0;j< this->nbColEntry+1;j++)
        {
            this->correctW(j);
        }
        emoy /= nbOutput;
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
        this->Dw.push_back(WGeneratorFunction::only0());
    }
}

double PerceptronV2Model::predict(double x1, double x2) {
    double returnVal = 0;
    if(this->predictable){
        returnVal = this->w[0];
        returnVal += x1*this->w[1];
        returnVal += x2*this->w[2];
    }
    return returnVal>=0;
}
void PerceptronV2Model::addDwi(int i,double error) {
    this->Dw[0] += this->eta*error*this->seuil;
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        this->Dw[j] += error*strtod(this->entry[i][k].getData().c_str(),NULL);
    }
}
void PerceptronV2Model::correctW(int i) {
    this->w[0]=this->w[0]+(this->eta*this->Dw[0]* this->seuil);
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        this->w[j] =this->w[j]+this->eta*this->Dw[j];
    }
}