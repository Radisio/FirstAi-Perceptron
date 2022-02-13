//
// Created by ericp on 12-02-22.
//

#include "Model.h"

Model::Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output){
    this->entry = entry;
    this->output = output;
    this->predictable=false;

}

Model::Model(Dataset dataset, int resultCol) {
    ///Fill the entry vector
    int nbRow, nbCol;
    nbRow = dataset.getNbRow();
    nbCol = dataset.getNbCol();
    std::vector<std::vector<Data>> data = dataset.getData();
    for(int i = 0; i< nbRow; i++)
    {
            std::vector<Data> vec;
            for(int j = 0 ;j<nbCol;j++)
            {
                if(j==resultCol)
                {
                    this->output.push_back(data[i][j]);
                }
                else {
                    vec.push_back(data[i][j]);
                }
            }
            this->entry.push_back(vec);

    }
    if(!this->entry.empty() and !this->output.empty()) {
        this->predictable = false;
    }
    else
        throw std::runtime_error("Error while loading entry/output");
    this->nbColEntry = nbCol-1;

}

Model::Model(std::vector<double> w) {
    this->w = w;
    this->predictable=true;
}

void Model::fit(double eta, int maxErrorAllowed,double seuil,double sigma) {
    if(!this->predictable){
        this->seuil=seuil;
        this->eta = eta;
        ///Initialisation des poids synaptiques (mise à 0)
        for(int i = 0;i<this->nbColEntry+1; i++)
        {
            //w.push_back(Util::randomNormalLaw(0,sigma,0,1));
            w.push_back(0.0);
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
                double y = potentiel>=0? 1:0;
                double error = strtod(this->output[i].getData().c_str(),NULL) - y;
                if(error!=0)
                {
                    correctW(i,error);
                    nbError++;
                }
            }
        }


    }

}

std::vector<double> Model::predict() {
    if(this->predictable){

    }
    return std::vector<double>();
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

void Model::displayW() {
    int size = this->w.size();
    std::cout<<"Display W"<<std::endl;
    for(int i = 0;i<size;i++)
    {
        std::cout<<"W["<<i<<"]:"<<this->w[i]<<std::endl;
    }
}

std::vector<double> Model::getW() {
    return this->w;
}
