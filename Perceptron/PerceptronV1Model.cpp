//
// Created by ericp on 12-02-22.
//

#include "PerceptronV1Model.h"

PerceptronV1Model::PerceptronV1Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output, double eta, double seuil)
: ModelBase(entry, output, eta, seuil){}

PerceptronV1Model::PerceptronV1Model(Dataset dataset, int resultCol, double eta, double seuil): ModelBase(dataset, resultCol, eta, seuil){}

PerceptronV1Model::PerceptronV1Model(std::vector<double> w): ModelBase(w){}

void PerceptronV1Model::fit(int maxErrorAllowed) {
    if(!this->predictable){
        ///Initialisation des poids synaptiques (mise à 0)
        for(int i = 0;i<this->nbColEntry+1; i++)
        {
            this->w.push_back(Util::randomNormalLaw(0,1,0,1));
        }
        int nbError = maxErrorAllowed+1;
        int nbOutput = this->output.size();
        while(nbError>maxErrorAllowed)
        {
            nbError=0;
            for(int i = 0;i<nbOutput;i++)
            {
                ///Sortie du perceptron = somme de tous les wi.xi (x0 = seuil)
                double potentiel = this->evaluateY(i);
                double y = potentiel>=0;
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

double PerceptronV1Model::predict(double x1, double x2) {
    double returnVal = 0;
    if(this->predictable){
        returnVal = this->w[0];
        returnVal += x1*this->w[1];
        returnVal += x2*this->w[2];
    }
    return returnVal>0;
}



void PerceptronV1Model::correctW(int i, double error) {
    this->w[0]=this->w[0]+(this->eta*error* this->seuil);
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        this->w[j] =this->w[j]+(this->eta*error* strtod(this->entry[i][k].getData().c_str(),NULL));
    }
}


