//
// Created by ericp on 14-02-22.
//

#include "ModelBase.h"


ModelBase::ModelBase(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output, double eta, double seuil){
    this->entry = entry;
    this->output = output;
    this->predictable=false;
    this->seuil=seuil;
    this->eta = eta;
    this->nbColEntry = this->entry.size();

}

ModelBase::ModelBase(Dataset dataset, int resultCol,double eta, double seuil) {
    ///Fill the entry vector
    int nbRow, nbCol;
    this->seuil=seuil;
    this->eta = eta;
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

ModelBase::ModelBase(std::vector<double> w) {
    this->w = w;
    this->predictable=true;
}

void ModelBase::displayW() {
    int size = this->w.size();
    std::cout<<"Display W"<<std::endl;
    for(int i = 0;i<size;i++)
    {
        std::cout<<"W["<<i<<"]:"<<this->w[i]<<std::endl;
    }
}

void ModelBase::setEntry(const std::vector<std::vector<Data>> &entry) {
    ModelBase::entry = entry;
}

void ModelBase::setSeuil(double seuil) {
    ModelBase::seuil = seuil;
}

void ModelBase::setEta(double eta) {
    ModelBase::eta = eta;
}

void ModelBase::setOutput(const std::vector<Data> &output) {
    ModelBase::output = output;
}

std::vector<double> ModelBase::getW() {
    return this->w;
}

bool ModelBase::isPredictable() const {
    return predictable;
}

const std::vector<std::vector<Data>> &ModelBase::getEntry() const {
    return entry;
}

int ModelBase::getNbColEntry() const {
    return nbColEntry;
}

double ModelBase::getSeuil() const {
    return seuil;
}

double ModelBase::getEta() const {
    return eta;
}

const std::vector<Data> &ModelBase::getOutput() const {
    return output;
}
