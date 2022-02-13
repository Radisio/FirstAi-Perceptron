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
    std::cout<<"NB ROW = " << nbRow << " NB COL = " <<nbCol<<std::endl;
    std::vector<std::vector<Data>> data = dataset.getData();
    for(int i = 0; i< nbRow; i++)
    {
        std::cout<<"ON EST LA"<<std::endl;
            std::vector<Data> vec;
            for(int j = 0 ;j<nbCol;j++)
            {
                if(j==resultCol)
                {
                    this->output.push_back(data[i][j]);
                }
                else {
                    std::cout << "On tourn dans les lignes baaaaa" << std::endl;
                    vec.push_back(data[i][j]);
                }
            }
            this->entry.push_back(vec);

    }
    std::cout<<"ON A FINI"<<std::endl;
    if(!this->entry.empty() and !this->output.empty()) {
        this->predictable = false;
        std::cout<<"PREDICTABLE EST FALSE"<<std::endl;
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
        std::cout<<"Initialisation poids synaptiques"<<std::endl;
        for(int i = 0;i<this->nbColEntry+1; i++)
        {
            //w.push_back(Util::randomNormalLaw(0,sigma,0,1));
            w.push_back(0.0);
        }
        std::cout<<"FIN Initialisation poids synaptiques"<<std::endl;
        std::cout<<"W size : " <<this->w.size()<<std::endl;

        int nbError = maxErrorAllowed+1;
        int nbOutput = this->output.size();
        while(nbError>maxErrorAllowed)
        {
            std::cout<<"ON TOURNE"<<std::endl;

            nbError=0;
            for(int i = 0;i<nbOutput;i++)
            {
                displayW();
                std::cout<<"On evalue les sorties du perceptron"<<std::endl;
                ///Sortie du perceptron = somme de tous les wi.xi (x0 = seuil)
                double potentiel = this->sum(i);
                double y = potentiel>=0? 1:0;
                std::cout<<"Sortie du perceptron : " << y << " sortie attendue : " << strtod(this->output[i].getData().c_str(),NULL)<<std::endl;
                double error = strtod(this->output[i].getData().c_str(),NULL) - y;
                std::cout<<"Error : " << error <<std::endl;
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
    std::cout<<"On fait la sum"<<std::endl;
    std::cout<<"Entry size : " << this->entry.size()<<std::endl;
    std::cout<<"I : " << i << std::endl;
    std::cout<<"Seuil: " << this->seuil << std::endl;
    std::cout<<"W[0] : " << this->w[0]<< std::endl;
    double returnVal = this->seuil*this->w[0];
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        std::cout<<"j = "<<j<<" Dans la boucle : entry vaut : "<<this->entry[i][k].getData() << " et w vaut "<<this->w[j] <<std::endl;
        returnVal += strtod(this->entry[i][k].getData().c_str(),NULL) * this->w[j];
    }
    std::cout<<"La somme vaut " << returnVal<<std::endl;
    return returnVal;
}

void Model::correctW(int i,double error) {
    std::cout<<"On corrige les poids synaptiques"<<std::endl;
    std::cout<<"Calcul de correction de W[0]="<<this->w[0]<<"+"<< this->eta << "*"<<error<<"*"<< this->seuil<<std::endl;
    this->w[0]=this->w[0]+(this->eta*error* this->seuil);
    std::cout<<"W[0] corrigé = " << w[0]<<std::endl;
    for(int j=1,k=0;j<=this->nbColEntry;j++,k++)
    {
        std::cout<<"W["<<j<<"] avant =" << this->w[j]<<std::endl;
        std::cout<<"Entry vaut : "<<strtod(this->entry[i][k].getData().c_str(),NULL)<<std::endl;
        std::cout<<"Eta : " << this->eta<<std::endl;
        std::cout<<"Calcul de correction de W["<<j<<"]="<<this->w[j]<<"+"<< this->eta << "*"<<error<<"*"<< strtod(this->entry[i][k].getData().c_str(),NULL)<<std::endl;
        std::cout<<"Evaluation membre de droite (a droite du multiplié : " << (this->eta*error* strtod(this->entry[i][k].getData().c_str(),NULL))<<std::endl;
        this->w[j] =this->w[j]+(this->eta*error* strtod(this->entry[i][k].getData().c_str(),NULL));
        std::cout<<"W["<<j<<"] après ="<<this->w[j]<<std::endl;
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
