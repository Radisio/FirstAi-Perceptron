//
// Created by ericp on 30-03-22.
//

#include "AdalineModel.h"

AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta,
                           double seuilMin) : Model(entry, layers, output, eta) {
    this->seuilMin=seuilMin;
    setSeuil(new SeuilPReLu(-1,1));
}

AdalineModel::AdalineModel(std::string filename) : Model(filename) {

}
AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta)
            : Model(entry,layers,output,eta){
    this->stopWhenNoError=true;
}

void AdalineModel::correction(std::vector<Data> line, double error, int i) {
    int lastLayer = this->layers.size()-1;
    ///Correction poids synaptique dernière couche

    for(int j = lastLayer;j>=0;j--)
    {
        this->layers[j].correction(line,this->eta, error,i);
    }
}

void AdalineModel::fit(int maxIteration) {
    int nbIter = 0;
    double emoy;
    int nbExemple = this->output.size();
    int nbOutput = this->output[0].size();
    bool errorBool = false;
    bool loop = false;
    do{
        emoy = 0.0;
        errorBool = false;
        for(int i = 0; i < nbExemple; i++) {
            for(int j =0;j<nbOutput;j++)
            {
                double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->output[i][j].getNumericData() - y;
                errorBool = errorBool || this->seuil->seuil(error) == this->output[i][j].getNumericData();
                emoy += (error * error) / 2;
                correction(this->entry[i], error,j);
            }
            debugSynapseWeight();
            Util::writeLogEndline(this->fp,"Iteration num :"+std::to_string(nbIter));
        }
        emoy /= nbExemple;
        Util::writeLogEndline(this->fp,"emoy :"+std::to_string(emoy));
        nbIter++;
        loop = this->stopWhenNoError?errorBool:emoy>this->seuilMin && nbIter<maxIteration;
    }while(loop);

}

std::vector<Data> AdalineModel::predict(std::vector<Data> vector) {
    return Model::predict(vector);
}

void AdalineModel::correction(std::vector<Data> vector, double d) {

}


