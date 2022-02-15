//
// Created by ericp on 12-02-22.
//

#include "Model.h"

Model::Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output, double eta, double seuil)
: ModelBase(entry, output, eta, seuil){}

Model::Model(Dataset dataset, int resultCol,double eta, double seuil): ModelBase(dataset, resultCol,eta,seuil){}

Model::Model(std::vector<double> w): ModelBase(w){}

void Model::fit(int maxErrorAllowed) {
    if(!this->predictable){
        ///Initialisation des poids synaptiques (mise à 0)
        for(int i = 0;i<this->nbColEntry+1; i++)
        {
            this->w.push_back(0.0);
        }
        int nbError = maxErrorAllowed+1;
        int nbOutput = this->output.size();
        while(nbError>maxErrorAllowed)
        {
            nbError=0;
            for(int i = 0;i<nbOutput;i++)
            {
                ///Sortie du perceptron = somme de tous les wi.xi (x0 = seuil)
                double potentiel = this->sum(i);
                double y = potentiel>0;
                double error = strtod(this->output[i].getData().c_str(),NULL) - y;
                if(error!=0)
                {
                    correctW(i,error);
                    nbError++;
                }
            }
            std::cout<<"NBError = " << nbError<<std::endl;
        }

        this->predictable= true;
    }

}

double Model::predict(double x1, double x2) {
    double returnVal = 0;
    if(this->predictable){
        returnVal = this->w[0];
        returnVal += x1*this->w[1];
        returnVal += x2*this->w[2];
    }
    return returnVal>0;
}

double Model::sum(int i) {
    double returnVal = this->seuil*this->w[0];
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        returnVal += strtod(this->entry[i][k].getData().c_str(),NULL) * this->w[j];
    }
    return returnVal;
}

void Model::correctW(int i,double error) {
    this->w[0]=this->w[0]+(this->eta*error* this->seuil);
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        this->w[j] =this->w[j]+(this->eta*error* strtod(this->entry[i][k].getData().c_str(),NULL));
    }
}


